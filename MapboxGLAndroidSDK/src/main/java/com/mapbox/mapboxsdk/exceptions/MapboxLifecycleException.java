package com.mapbox.mapboxsdk.exceptions;

import android.content.Context;

/**
 * A MapboxLifecycleException is thrown by MapView when it's lifecycle hasn't been properly integrated.
 * <p>
 * This occurs either when {@link com.mapbox.mapboxsdk.Mapbox} is not correctly initialised or the provided access token
 * through {@link com.mapbox.mapboxsdk.Mapbox#getInstance(Context, String)} isn't valid.
 * </p>
 *
 * @see com.mapbox.mapboxsdk.Mapbox#getInstance(Context, String)
 */
public class MapboxLifecycleException extends RuntimeException {

  /**
   * Creates a Mapbox lifecycle exception thrown by MapView when it's lifecycle hasn't been properly integrated.
   */
  public MapboxLifecycleException() {
    super("MapView requires calling the correct Activity lifecycle methods: onCreate, onStart, onStop and onDestroy.");
  }
}
