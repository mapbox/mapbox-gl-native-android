package com.mapbox.mapboxsdk.location;

import android.location.Location;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import java.util.Collections;
import java.util.List;

/**
 * A class that contains the location update configuration.
 *
 * @see LocationComponent#forceLocationUpdate(LocationUpdate)
 */
public class LocationUpdate {

  @NonNull
  private final Location location;
  @NonNull
  private final List<Location> intermediatePoints;
  @Nullable
  private final Long animationDuration;

  private LocationUpdate(
    @NonNull Location location,
    @NonNull List<Location> intermediatePoints,
    @Nullable Long animationDuration
  ) {
    this.location = location;
    this.intermediatePoints = intermediatePoints;
    this.animationDuration = animationDuration;
  }

  /**
   * @return target location of the transition
   */
  @NonNull
  public Location getLocation() {
    return location;
  }

  /**
   * @return list of locations that are on the path to the target location for animation interpolation
   */
  @NonNull
  public List<Location> getIntermediatePoints() {
    return intermediatePoints;
  }

  /**
   * @return If set, all of the transitions to this update (puck's and possibly camera's if tracking mode is engaged)
   * will have the provided duration. If null, the duration will be calculated internally.
   * <p>
   * <b>{@link LocationComponentOptions.Builder#trackingAnimationDurationMultiplier(float)}
   * is ignored if this value is provided.</b>
   */
  @Nullable
  public Long getAnimationDuration() {
    return animationDuration;
  }

  @Override
  public String toString() {
    return "LocationUpdate{" + "location=" + location + ", intermediatePoints=" + intermediatePoints
      + ", animationDuration=" + animationDuration + '}';
  }

  @Override
  public boolean equals(Object o) {
    if (this == o) {
      return true;
    }
    if (o == null || getClass() != o.getClass()) {
      return false;
    }

    LocationUpdate that = (LocationUpdate) o;

    if (!location.equals(that.location)) {
      return false;
    }
    if (!intermediatePoints.equals(that.intermediatePoints)) {
      return false;
    }
    return animationDuration != null
      ? animationDuration.equals(that.animationDuration)
      : that.animationDuration == null;
  }

  @Override
  public int hashCode() {
    int result = location.hashCode();
    result = 31 * result + intermediatePoints.hashCode();
    result = 31 * result + (animationDuration != null ? animationDuration.hashCode() : 0);
    return result;
  }

  public static class Builder {

    @Nullable
    private Location location;
    @NonNull
    private List<Location> intermediatePoints = Collections.emptyList();
    @Nullable
    private Long animationDuration;

    /**
     * Target location.
     */
    public Builder location(@Nullable Location location) {
      this.location = location;
      return this;
    }

    /**
     * This method can be used to provide the list of locations that are on the path to the target location.
     * Those intermediate points are used as the animation path.
     * The puck and the camera will be animated between each of the points linearly until reaching the target.
     */
    public Builder intermediatePoints(@NonNull List<Location> intermediatePoints) {
      this.intermediatePoints = intermediatePoints;
      return this;
    }

    /**
     * If set, all of the transitions to this update (puck's and possibly camera's if tracking mode is engaged) will
     * have the provided duration. If null, the duration will be calculated internally.
     * <p>
     * This can also be used to disable transition animation by providing a duration equal to zero.
     * <p>
     * <b>{@link LocationComponentOptions.Builder#trackingAnimationDurationMultiplier(float)}
     * is ignored if this value is provided.</b>
     */
    public Builder animationDuration(@Nullable Long animationDuration) {
      this.animationDuration = animationDuration;
      return this;
    }

    /**
     * Builds a new {@link LocationUpdate}.
     */
    public LocationUpdate build() {
      if (location == null) {
        throw new IllegalArgumentException("target location has to be provided when constructing the LocationUpdate");
      }

      return new LocationUpdate(location, intermediatePoints, animationDuration);
    }
  }
}
