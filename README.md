# [Mapbox Maps SDK for Android](https://www.mapbox.com/android-sdk/)

[![Circle CI build status](https://circleci.com/gh/mapbox/mapbox-gl-native-android/tree/master.svg?style=shield)](https://circleci.com/gh/mapbox/mapbox-gl-native-android/tree/master)


[![](https://www.mapbox.com/android-docs/assets/overview-map-sdk-322-9abe118316efb5910b6101e222a2e57c.png)](https://docs.mapbox.com/android/maps/overview/)

The Mapbox Maps SDK for Android is a library based on Mapbox GL Native for embedding interactive map views with scalable, customizable vector maps onto Android devices.

## Getting Started

This particular README is for people who are interested in working on and improving the Maps SDK for Android. If you're looking for more general information and instructions on the Maps SDK:

Visit [https://docs.mapbox.com/android/maps/overview](https://docs.mapbox.com/android/maps/overview/) to see current documentation on the Maps SDK for Android.

Visit [https://docs.mapbox.com/android/api/map-sdk](https://docs.mapbox.com/android/api/map-sdk/) to view the Maps SDK's current API reference Javadoc files.

See [the Mapbox website's Android install flow](https://www.mapbox.com/install/android/) to install and use the Mapbox Maps SDK for Android in an application.

### Setup environment

These instructions are for developers interested in making code-level contributions to the SDK itself. If you instead want to use the SDK in your app, see above.

#### Getting the source

Clone the git repository and pull in submodules:

```bash
git clone git@github.com:mapbox/mapbox-gl-native-android.git && cd mapbox-gl-native-android
git submodule update --init --recursive
```

#### Installing dependencies

- Latest stable [Android Studio](https://developer.android.com/studio/index.html) and Android SDK.

### Opening the project

Open the root folder of this repository in Android Studio.

### Project configuration

#### Setup Mapbox Access token for dependency download

Add a Mapbox access token with scope set to `DOWNLOADS:READ` in the root `build.gradle`.

```groovy
allprojects {
    repositories {
        maven {
            url 'https://api.mapbox.com/downloads/v2/releases/maven'
            authentication {
                basic(BasicAuthentication)
            }
            credentials {
                username = "mapbox"
                password = "INSERT_MAPBOX_ACCESS_TOKEN_HERE"
            }
        }
    }
}
```

#### Setup Checkstyle

Mapbox uses specific IDE settings related to code and check style.
See [checkstyle guide](https://github.com/mapbox/mapbox-gl-native-android/wiki/Setting-up-Mapbox-checkstyle) for configuration details.

##### Setup Mapbox Access Token for Mapbox vector tiles

_The test application (used for development purposes) uses Mapbox vector tiles, which require a Mapbox account and API access token. Obtain a free access token on the [Mapbox account page](https://www.mapbox.com/studio/account/tokens/)._

With the first gradle invocation, gradle will take the value of the `MAPBOX_ACCESS_TOKEN` environment variable and save it to `MapboxGLAndroidSDKTestApp/src/main/res/values/developer-config.xml`. If the environment variable wasn't set, you can edit `developer-config.xml` manually and add your access token to the `mapbox_access_token` resource.

### Additional resources

#### Symbolicating native crashes

When hitting native crashes you can use ndk-stack to symbolicate crashes.
More information in [this](https://github.com/mapbox/mapbox-gl-native-android/wiki/Getting-line-numbers-from-an-Android-crash-with-ndk-stack) guide.
