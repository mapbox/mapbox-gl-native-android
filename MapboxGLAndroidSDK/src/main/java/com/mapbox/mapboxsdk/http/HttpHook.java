package com.mapbox.mapboxsdk.http;

/**
 * Interface definition for performing http requests.
 * <p>
 * This allows to provide alternative implementations for the http interaction of this library.
 * </p>
 */
public class HttpHook {

  private static HttpHookListener hookListener;

  public static void setHookListener(HttpHookListener hookListener) {
    HttpHook.hookListener = hookListener;
  }

  public static void onResultCode(int code) {
    if (hookListener != null) {
      hookListener.onResultCode(code);
    }
  }
}

