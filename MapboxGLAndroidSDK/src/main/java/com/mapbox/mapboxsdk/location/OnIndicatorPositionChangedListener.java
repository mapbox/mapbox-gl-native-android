package com.mapbox.mapboxsdk.location;

import androidx.annotation.NonNull;
import com.mapbox.geojson.Point;

/**
 * Listener that gets invoked when indicator position changes.
 */
public interface OnIndicatorPositionChangedListener {
  /**
   * This method is called on each position change of the location indicator, including each animation frame.
   *
   * @param point indicator's position
   */
  void onIndicatorPositionChanged(@NonNull Point point);
}
