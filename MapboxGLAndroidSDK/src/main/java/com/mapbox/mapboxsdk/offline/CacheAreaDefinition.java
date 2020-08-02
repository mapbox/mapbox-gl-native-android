package com.mapbox.mapboxsdk.offline;

import android.os.Parcel;
import android.os.Parcelable;

import androidx.annotation.Keep;
import androidx.annotation.NonNull;

import com.mapbox.mapboxsdk.geometry.LatLngBoundsZoom;

/**
 * A cache area defined by a style URL, an array of LatLngBoundsZoom, and
 * device pixel ratio.
 * <p>
 * pixelRatio must be &#x2265; 0 and should typically be 1.0 or 2.0.
 * <p>
 * if includeIdeographs is false, offline region will not include CJK glyphs
 */
public class CacheAreaDefinition implements Parcelable {

  @Keep
  private String styleURL;
  @Keep
  private LatLngBoundsZoom[] boundsZoomList;
  @Keep
  private float pixelRatio;
  @Keep
  private boolean includeIdeographs;

  /**
   * Constructor to create an CacheAreaDefinition from parameters.
   *
   * @param styleURL       the style
   * @param boundsZoomList the boundsZoomList
   * @param pixelRatio     pixel ratio of the device
   */
  @Keep
  public CacheAreaDefinition(
    String styleURL, LatLngBoundsZoom[] boundsZoomList, float pixelRatio) {
    this(styleURL, boundsZoomList, pixelRatio, false);
  }

  /**
   * Constructor to create an CacheAreaDefinition from parameters.
   *
   * @param styleURL          the style
   * @param boundsZoomList    the boundsZoomList
   * @param pixelRatio        pixel ratio of the device
   * @param includeIdeographs include glyphs for CJK languages
   */
  @Keep
  public CacheAreaDefinition(
    String styleURL, LatLngBoundsZoom[] boundsZoomList, float pixelRatio,
    boolean includeIdeographs) {
    // Note: Also used in JNI
    this.styleURL = styleURL;
    this.boundsZoomList = boundsZoomList;
    this.pixelRatio = pixelRatio;
    this.includeIdeographs = includeIdeographs;
  }

  /**
   * Constructor to create an CacheAreaDefinition from a Parcel.
   *
   * @param parcel the parcel to create the CacheAreaDefinition from
   */
  public CacheAreaDefinition(Parcel parcel) {
    this.styleURL = parcel.readString();
    parcel.readTypedArray(boundsZoomList, LatLngBoundsZoom.CREATOR);
    this.pixelRatio = parcel.readFloat();
    this.includeIdeographs = parcel.readByte() != 0;
  }

  public String getStyleURL() {
    return styleURL;
  }

  public float getPixelRatio() {
    return pixelRatio;
  }

  public boolean getIncludeIdeographs() {
    return includeIdeographs;
  }

  /*
   * Parceable
   */
  @Override
  public int describeContents() {
    return 0;
  }

  @Override
  public void writeToParcel(@NonNull Parcel dest, int flags) {
    dest.writeString(styleURL);
    dest.writeTypedArray(boundsZoomList, 0);
    dest.writeFloat(pixelRatio);
    dest.writeByte((byte) (includeIdeographs ? 1 : 0));
  }

  public static final Creator CREATOR = new Creator() {
    public CacheAreaDefinition createFromParcel(@NonNull Parcel in) {
      return new CacheAreaDefinition(in);
    }

    public CacheAreaDefinition[] newArray(int size) {
      return new CacheAreaDefinition[size];
    }
  };
}
