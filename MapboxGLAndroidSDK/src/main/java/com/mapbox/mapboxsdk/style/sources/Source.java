package com.mapbox.mapboxsdk.style.sources;

import android.text.TextUtils;

import androidx.annotation.Keep;
import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import com.mapbox.mapboxsdk.LibraryLoader;
import com.mapbox.mapboxsdk.utils.ThreadUtils;

/**
 * Base Peer class for sources. see source.hpp for the other half of the peer.
 */
public abstract class Source {

  private static final String TAG = "Mbgl-Source";

  @Keep
  private long nativePtr;

  protected boolean detached;

  static {
    LibraryLoader.load();
  }

  /**
   * Internal use
   *
   * @param nativePtr - pointer to native peer
   */
  @Keep
  protected Source(long nativePtr) {
    checkThread();
    this.nativePtr = nativePtr;
  }

  public Source() {
    checkThread();
  }

  /**
   * Validates if source interaction is happening on the UI thread
   */
  protected void checkThread() {
    ThreadUtils.checkThread(TAG);
  }

  /**
   * Retrieve the source id
   *
   * @return the source id
   */
  @NonNull
  public String getId() {
    checkThread();
    return nativeGetId();
  }

  /**
   * Retrieve the source attribution.
   * <p>
   * Will return an empty String if no attribution is available.
   * </p>
   *
   * @return the string representation of the attribution in html format
   */
  @NonNull
  public String getAttribution() {
    checkThread();
    return nativeGetAttribution();
  }

  /**
   * Retrieve current pre-fetching zoom delta.
   *
   * @return current zoom delta or null if not set.
   */
  @Nullable
  public Integer getPrefetchZoomDelta() {
    String delta = nativeGetPrefetchZoomDelta();
    return TextUtils.isEmpty(delta) ? null : Integer.valueOf(delta);
  }

  /**
   * Set the tile pre-fetching zoom delta for current source. Pre-fetching makes sure that a low-resolution
   * tile at the (current_zoom_level - delta) is rendered as soon as possible at the
   * expense of a little bandwidth.
   * If delta has not been set or set to null, it will use the value in MapboxMap instance.
   *
   * @param delta zoom delta
   */
  public void setPrefetchZoomDelta(@Nullable Integer delta) {
    nativeSetPrefetchZoomDelta(delta == null ? null : String.valueOf(delta));
  }

  /**
   * Internal use
   *
   * @return the native peer pointer
   */
  public long getNativePtr() {
    return nativePtr;
  }

  @NonNull
  @Keep
  protected native String nativeGetId();

  @NonNull
  @Keep
  protected native String nativeGetAttribution();

  @NonNull
  @Keep
  protected native String nativeGetPrefetchZoomDelta();

  @NonNull
  @Keep
  protected native void nativeSetPrefetchZoomDelta(String delta);

  public void setDetached() {
    detached = true;
  }
}
