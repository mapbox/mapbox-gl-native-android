#!/usr/bin/env node
/* eslint-disable no-console */

const AWS = require('aws-sdk');
const path = require('path');
const fs = require('fs');
const mime = require('mime');

/**
 * Pass the directory containing 
 * the version number you would 
 * like to archive (../src/X.X.X)
 * */
let OLD_DOC_PATH = process.argv[2];
const BASE_PATH = path.basename(OLD_DOC_PATH);

const KEY_PREFIX = path.join('archive/android/maps/api', BASE_PATH); // TODO: extract this to a constant or something

/**
 * Pass the bucket name you 
 * would like to target.
 * Defaults to `docs.mapbox.com-staging`
 * */
let BUCKET_NAME = process.argv[3];

if (!OLD_DOC_PATH) throw new Error("Path to target docs not provided");
if (!BUCKET_NAME) console.log("Bucket name not provided. Defaulting to docs.mapbox.com-staging");

// From publisher, just in case.
function isPrivateBucket(bucket) {
    return bucket !== 'www.mapbox.com' && bucket !== 'staging.mapbox.com';
}

const uploadDocs = (s3Path, bucketName) => {
    let s3 = new AWS.S3();

    const visitPaths = (currentPathDir, callback) => {
        fs.readdirSync(currentPathDir).forEach(name => {
            var filePath = path.join(currentPathDir, name);
            var stat = fs.statSync(filePath);
            if (stat.isFile()) {
                callback(filePath, stat);
            } else if (stat.isDirectory()) {
                visitPaths(filePath, callback);
            }
        });
    }

    visitPaths(s3Path, (filePath, stat) => {
        let cacheControl = 'max-age=120';
        const contentType = mime.getType(filePath);
        // We want to make sure the client always uses a fresh html
        // to avoid breaking the website, see https://github.com/mapbox/publisher/issues/214
        if (contentType && contentType.includes('text/html')) {
            cacheControl = 'max-age=0';
        }
        
        // In order to remove local directory structure, only get the path that follows the BASE_PATH
        // "src/docs/1.1.1/pages/file.html" becomes "/pages/file.html"
        const localFilePath = filePath.split(BASE_PATH)[1];
        const fullFilePath = path.join(KEY_PREFIX, localFilePath);

        let params = {
            Bucket: bucketName,
            Key: fullFilePath,
            Body: fs.readFileSync(filePath),
            CacheControl: cacheControl,
            ContentType: contentType
        }

        // For any buckets that will be served to the wider world, we
        // need to provide public-read access on objects.
        if (!isPrivateBucket(BUCKET_NAME)) {
            params.ACL = 'public-read';
        }

        s3.putObject(params, (err, data) => {
            if(err) {
                throw new Error(err);
            } else {
                console.log(`Successfully uploaded ${fullFilePath} to ${bucketName}`);
                console.log(data);
            }
        });
    });
}

const removeOldDocs = "blah"; // TODO: remove old docs (or maybe just place in an untracked directory to facilitate undo)

uploadDocs(OLD_DOC_PATH, BUCKET_NAME || 'docs.mapbox.com-staging');


// Notes: files are uploaded but not accessible. Browser just tries to download them.
// Needs some parameters: https://github.com/mapbox/publisher/blob/master/lib/deployer/s3-sync/s3-api-helpers.js#L37
