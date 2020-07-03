package com.mapbox.mapboxsdk.geometry;

import android.os.Parcel;
import android.os.Parcelable;

import androidx.annotation.FloatRange;
import androidx.annotation.Keep;
import androidx.annotation.NonNull;

import com.mapbox.mapboxsdk.constants.GeometryConstants;

import static com.mapbox.mapboxsdk.constants.GeometryConstants.MAX_LATITUDE;
import static com.mapbox.mapboxsdk.constants.GeometryConstants.MIN_LATITUDE;

/**
 * A geographical area representing a latitude/longitude aligned rectangle and the zoom level.
 * <p>
 * This class does not wrap values to the world bounds.
 * </p>
 */
public class LatLngBoundsZoom implements Parcelable {

  @Keep
  private final LatLngBounds bounds;

  @Keep
  private final double zoom;

  /**
   * Construct a new LatLngBoundsZoom based on its corners, given in NESW
   * order and the zoom level.
   * <p>
   *
   * @param bounds the LatLngBounds
   * @param zoom   the zoom level
   * @since 7.0.0 LatLngBounds cannot be wrapped any more, i.e longitudeWest has to be
   * less or equal to longitudeEast.
   * <p>
   * For example, to represent bounds spanning 20 degrees crossing antimeridian with
   * the NE point as (10, -170) and the SW point as (-10, 170),
   * use (10, -190) and (-10, -170), or (10, -170) and (-10, -150).
   */
  @Keep
  LatLngBoundsZoom(final LatLngBounds bounds, final double zoom) {
    this.bounds = bounds;
    this.zoom = zoom;
  }

  /**
   * Construct a new LatLngBoundsZoom based on its corners, given in NESW
   * order and zoom level.
   * <p>
   *
   * @param northLatitude Northern Latitude
   * @param eastLongitude Eastern Longitude
   * @param southLatitude Southern Latitude
   * @param westLongitude Western Longitude
   * @param zoom          Zoom level
   * @since 7.0.0 LatLngBounds cannot be wrapped any more, i.e longitudeWest has to be
   * less or equal to longitudeEast.
   * <p>
   * For example, to represent bounds spanning 20 degrees crossing antimeridian with
   * the NE point as (10, -170) and the SW point as (-10, 170),
   * use (10, -190) and (-10, -170), or (10, -170) and (-10, -150).
   */
  @Keep
  LatLngBoundsZoom(final double northLatitude, final double eastLongitude,
                   final double southLatitude, final double westLongitude,
                   final double zoom) {
    this.bounds = LatLngBounds.from(northLatitude, eastLongitude, southLatitude, westLongitude);
    this.zoom = zoom;
  }

  /**
   * Get the LatLngBounds of the LatLngBoundsZoom.
   *
   * @return LatLngBounds
   */
  public LatLngBounds getLatLngBounds() {
    return this.bounds;
  }

  /**
   * Get the zoom level of the LatLngBoundsZoom.
   *
   * @return double zoom level
   */
  public double getZoom() {
    return this.zoom;
  }

  /**
   * Returns a string representation of the object.
   *
   * @return the string representation
   */
  @NonNull
  @Override
  public String toString() {
    return "Bounds: {" + this.bounds + "}, Zoom: " + this.zoom;
  }

  /**
   * Constructs a LatLngBoundsZoom from doubles representing a LatLng pair and zoom level.
   * <p>
   * This values of latNorth and latSouth should be in the range of [-90, 90],
   * see {@link GeometryConstants#MIN_LATITUDE} and {@link GeometryConstants#MAX_LATITUDE},
   * otherwise IllegalArgumentException will be thrown.
   * latNorth should be greater or equal latSouth, otherwise  IllegalArgumentException will be thrown.
   * <p>
   * This method doesn't recalculate most east or most west boundaries.
   * Note @since 7.0.0  lonEast and lonWest will NOT be wrapped to be in the range of [-180, 180],
   * see {@link GeometryConstants#MIN_LONGITUDE} and {@link GeometryConstants#MAX_LONGITUDE}
   * lonEast should be greater or equal lonWest, otherwise  IllegalArgumentException will be thrown.
   * </p>
   */
  public static LatLngBoundsZoom from(
    @FloatRange(from = MIN_LATITUDE, to = MAX_LATITUDE) double latNorth,
    double lonEast,
    @FloatRange(from = MIN_LATITUDE, to = MAX_LATITUDE) double latSouth,
    double lonWest,
    double zoom) {

    return new LatLngBoundsZoom(LatLngBounds.from(latNorth, lonEast, latSouth, lonWest), zoom);
  }

  /**
   * Constructs a LatLngBounds from a Tile identifier.
   * <p>
   * Returned bounds will have latitude in the range of Mercator projection.
   *
   * @param z Tile zoom level.
   * @param x Tile X coordinate.
   * @param y Tile Y coordinate.
   * @see GeometryConstants#MIN_MERCATOR_LATITUDE
   * @see GeometryConstants#MAX_MERCATOR_LATITUDE
   */
  public static LatLngBoundsZoom from(int z, int x, int y) {
    return new LatLngBoundsZoom(LatLngBounds.from(z, x, y), z);
  }

  /**
   * Construct a new LatLngBoundsZoom based on its corners, given in NESW
   * order and the zoom level.
   * <p>
   *
   * @param bounds the LatLngBounds
   * @param zoom   the zoom level
   * @since 7.0.0 LatLngBounds cannot be wrapped any more, i.e longitudeWest has to be
   * less or equal to longitudeEast.
   * <p>
   * For example, to represent bounds spanning 20 degrees crossing antimeridian with
   * the NE point as (10, -170) and the SW point as (-10, 170),
   * use (10, -190) and (-10, -170), or (10, -170) and (-10, -150).
   */
  public static LatLngBoundsZoom from(final LatLngBounds bounds, final double zoom) {
    return new LatLngBoundsZoom(bounds, zoom);
  }

  /**
   * Determines whether this LatLngBounds matches another one via LatLng.
   *
   * @param o another object
   * @return a boolean indicating whether the LatLngBounds are equal
   */
  @Override
  public boolean equals(final Object o) {
    if (this == o) {
      return true;
    }
    if (o instanceof LatLngBoundsZoom) {
      LatLngBoundsZoom other = (LatLngBoundsZoom) o;
      return bounds == other.getLatLngBounds()
        && zoom == other.getZoom();
    }
    return false;
  }

  /**
   * Inner class responsible for recreating Parcels into objects.
   */
  public static final Creator<LatLngBoundsZoom> CREATOR =
    new Creator<LatLngBoundsZoom>() {
      @Override
      public LatLngBoundsZoom createFromParcel(@NonNull final Parcel in) {
        return readFromParcel(in);
      }

      @Override
      public LatLngBoundsZoom[] newArray(final int size) {
        return new LatLngBoundsZoom[size];
      }
    };

  /**
   * Returns a hash code value for the object.
   *
   * @return the hash code
   */
  @Override
  public int hashCode() {
    return (int) (bounds.hashCode() + 31 * zoom);
  }

  /**
   * Describe the kinds of special objects contained in this Parcelable instance's marshaled representation.
   *
   * @return a bitmask indicating the set of special object types marshaled by this Parcelable object instance.
   */
  @Override
  public int describeContents() {
    return 0;
  }

  /**
   * Flatten this object in to a Parcel.
   *
   * @param out   The Parcel in which the object should be written.
   * @param flags Additional flags about how the object should be written
   */
  @Override
  public void writeToParcel(@NonNull final Parcel out, final int flags) {
    out.writeDouble(this.bounds.getLatNorth());
    out.writeDouble(this.bounds.getLonEast());
    out.writeDouble(this.bounds.getLatSouth());
    out.writeDouble(this.bounds.getLonWest());
    out.writeDouble(this.zoom);
  }

  private static LatLngBoundsZoom readFromParcel(final Parcel in) {
    final double northLat = in.readDouble();
    final double eastLon = in.readDouble();
    final double southLat = in.readDouble();
    final double westLon = in.readDouble();
    final double zoom = in.readDouble();
    return LatLngBoundsZoom.from(northLat, eastLon, southLat, westLon, zoom);
  }
}
