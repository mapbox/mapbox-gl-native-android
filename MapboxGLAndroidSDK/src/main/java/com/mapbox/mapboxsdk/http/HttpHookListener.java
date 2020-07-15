package com.mapbox.mapboxsdk.http;

/**
 * Interface definition for performing http requests.
 * <p>
 * This allows to provide alternative implementations for the http interaction of this library.
 * </p>
 */
public interface HttpHookListener {

  void onResultCode(int code);
}
