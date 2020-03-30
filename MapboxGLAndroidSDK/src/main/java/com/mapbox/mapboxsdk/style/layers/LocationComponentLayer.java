// This file is generated. Edit android/platform/scripts/generate-style-code.js, then run `make android-style-code`.

package com.mapbox.mapboxsdk.style.layers;

import androidx.annotation.ColorInt;
import androidx.annotation.Keep;
import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.annotation.UiThread;

import static com.mapbox.mapboxsdk.utils.ColorUtils.rgbaToColor;

import com.google.gson.JsonArray;
import com.google.gson.JsonElement;
import com.mapbox.mapboxsdk.style.expressions.Expression;
import com.mapbox.mapboxsdk.style.layers.TransitionOptions;

/**
 * 
 *
 * @see <a href="https://www.mapbox.com/mapbox-gl-style-spec/#layers-location-component">The online documentation</a>
 */
@UiThread
public class LocationComponentLayer extends Layer {

  /**
   * Creates a LocationComponentLayer.
   *
   * @param nativePtr pointer used by core
   */
  @Keep
  LocationComponentLayer(long nativePtr) {
    super(nativePtr);
  }

  /**
   * Creates a LocationComponentLayer.
   *
   * @param layerId the id of the layer
   */
  public LocationComponentLayer(String layerId) {
    super();
    initialize(layerId);
  }

  @Keep
  protected native void initialize(String layerId);

  /**
   * Get the source id.
   *
   * @return id of the source
   */
  @NonNull
  public String getSourceId() {
    checkThread();
    return nativeGetSourceId();
  }

  /**
   * Get the source layer.
   *
   * @return sourceLayer the source layer to get
   */
  @NonNull
  public String getSourceLayer() {
    checkThread();
    return nativeGetSourceLayer();
  }

  /**
   * Set a single expression filter.
   *
   * @param filter the expression filter to set
   */
  public void setFilter(@NonNull Expression filter) {
    checkThread();
    nativeSetFilter(filter.toArray());
  }

  /**
   * Set a single expression filter.
   *
   * @param filter the expression filter to set
   * @return This
   */
  @NonNull
  public LocationComponentLayer withFilter(@NonNull Expression filter) {
    setFilter(filter);
    return this;
  }

  /**
   * Get a single expression filter.
   *
   * @return the expression filter to get
   */
  @Nullable
  public Expression getFilter() {
    checkThread();
    JsonElement jsonElement = nativeGetFilter();
    if (jsonElement != null) {
      return Expression.Converter.convert(jsonElement);
    } else {
      return null;
    }
  }

  /**
   * Set a property or properties.
   *
   * @param properties the var-args properties
   * @return This
   */
  @NonNull
  public LocationComponentLayer withProperties(@NonNull PropertyValue<?>... properties) {
    setProperties(properties);
    return this;
  }

  // Property getters

  /**
   * Get the TopImage property
   *
   * @return property wrapper value around String
   */
  @NonNull
  @SuppressWarnings("unchecked")
  public PropertyValue<String> getTopImage() {
    checkThread();
    return (PropertyValue<String>) new PropertyValue("top-image", nativeGetTopImage());
  }

  /**
   * Get the BearingImage property
   *
   * @return property wrapper value around String
   */
  @NonNull
  @SuppressWarnings("unchecked")
  public PropertyValue<String> getBearingImage() {
    checkThread();
    return (PropertyValue<String>) new PropertyValue("bearing-image", nativeGetBearingImage());
  }

  /**
   * Get the ShadowImage property
   *
   * @return property wrapper value around String
   */
  @NonNull
  @SuppressWarnings("unchecked")
  public PropertyValue<String> getShadowImage() {
    checkThread();
    return (PropertyValue<String>) new PropertyValue("shadow-image", nativeGetShadowImage());
  }

  /**
   * Get the Location property
   *
   * @return property wrapper value around Float[]
   */
  @NonNull
  @SuppressWarnings("unchecked")
  public PropertyValue<Float[]> getLocation() {
    checkThread();
    return (PropertyValue<Float[]>) new PropertyValue("location", nativeGetLocation());
  }

  /**
   * Get the Bearing property
   *
   * @return property wrapper value around Float
   */
  @NonNull
  @SuppressWarnings("unchecked")
  public PropertyValue<Float> getBearing() {
    checkThread();
    return (PropertyValue<Float>) new PropertyValue("bearing", nativeGetBearing());
  }

  /**
   * Get the AccuracyRadius property
   *
   * @return property wrapper value around Float
   */
  @NonNull
  @SuppressWarnings("unchecked")
  public PropertyValue<Float> getAccuracyRadius() {
    checkThread();
    return (PropertyValue<Float>) new PropertyValue("accuracy-radius", nativeGetAccuracyRadius());
  }

  /**
   * Get the TopImageSize property
   *
   * @return property wrapper value around Float
   */
  @NonNull
  @SuppressWarnings("unchecked")
  public PropertyValue<Float> getTopImageSize() {
    checkThread();
    return (PropertyValue<Float>) new PropertyValue("top-image-size", nativeGetTopImageSize());
  }

  /**
   * Get the BearingImageSize property
   *
   * @return property wrapper value around Float
   */
  @NonNull
  @SuppressWarnings("unchecked")
  public PropertyValue<Float> getBearingImageSize() {
    checkThread();
    return (PropertyValue<Float>) new PropertyValue("bearing-image-size", nativeGetBearingImageSize());
  }

  /**
   * Get the ShadowImageSize property
   *
   * @return property wrapper value around Float
   */
  @NonNull
  @SuppressWarnings("unchecked")
  public PropertyValue<Float> getShadowImageSize() {
    checkThread();
    return (PropertyValue<Float>) new PropertyValue("shadow-image-size", nativeGetShadowImageSize());
  }

  /**
   * Get the PerspectiveCompensation property
   *
   * @return property wrapper value around Float
   */
  @NonNull
  @SuppressWarnings("unchecked")
  public PropertyValue<Float> getPerspectiveCompensation() {
    checkThread();
    return (PropertyValue<Float>) new PropertyValue("perspective-compensation", nativeGetPerspectiveCompensation());
  }

  /**
   * Get the ImageTiltDisplacement property
   *
   * @return property wrapper value around Float
   */
  @NonNull
  @SuppressWarnings("unchecked")
  public PropertyValue<Float> getImageTiltDisplacement() {
    checkThread();
    return (PropertyValue<Float>) new PropertyValue("image-tilt-displacement", nativeGetImageTiltDisplacement());
  }

  /**
   * Get the AccuracyRadiusColor property
   *
   * @return property wrapper value around String
   */
  @NonNull
  @SuppressWarnings("unchecked")
  public PropertyValue<String> getAccuracyRadiusColor() {
    checkThread();
    return (PropertyValue<String>) new PropertyValue("accuracy-radius-color", nativeGetAccuracyRadiusColor());
  }

  /**
   * The color for drawing the accuracy radius, as a circle. To adjust transparency, set the alpha component of the color accordingly.
   *
   * @return int representation of a rgba string color
   * @throws RuntimeException thrown if property isn't a value
   */
  @ColorInt
  public int getAccuracyRadiusColorAsInt() {
    checkThread();
    PropertyValue<String> value = getAccuracyRadiusColor();
    if (value.isValue()) {
      return rgbaToColor(value.getValue());
    } else {
      throw new RuntimeException("accuracy-radius-color was set as a Function");
    }
  }

  /**
   * Get the AccuracyRadiusColor property transition options
   *
   * @return transition options for String
   */
  @NonNull
  public TransitionOptions getAccuracyRadiusColorTransition() {
    checkThread();
    return nativeGetAccuracyRadiusColorTransition();
  }

  /**
   * Set the AccuracyRadiusColor property transition options
   *
   * @param options transition options for String
   */
  public void setAccuracyRadiusColorTransition(@NonNull TransitionOptions options) {
    checkThread();
    nativeSetAccuracyRadiusColorTransition(options.getDuration(), options.getDelay());
  }

  /**
   * Get the AccuracyRadiusBorderColor property
   *
   * @return property wrapper value around String
   */
  @NonNull
  @SuppressWarnings("unchecked")
  public PropertyValue<String> getAccuracyRadiusBorderColor() {
    checkThread();
    return (PropertyValue<String>) new PropertyValue("accuracy-radius-border-color", nativeGetAccuracyRadiusBorderColor());
  }

  /**
   * The color for drawing the accuracy radius border. To adjust transparency, set the alpha component of the color accordingly.
   *
   * @return int representation of a rgba string color
   * @throws RuntimeException thrown if property isn't a value
   */
  @ColorInt
  public int getAccuracyRadiusBorderColorAsInt() {
    checkThread();
    PropertyValue<String> value = getAccuracyRadiusBorderColor();
    if (value.isValue()) {
      return rgbaToColor(value.getValue());
    } else {
      throw new RuntimeException("accuracy-radius-border-color was set as a Function");
    }
  }

  /**
   * Get the AccuracyRadiusBorderColor property transition options
   *
   * @return transition options for String
   */
  @NonNull
  public TransitionOptions getAccuracyRadiusBorderColorTransition() {
    checkThread();
    return nativeGetAccuracyRadiusBorderColorTransition();
  }

  /**
   * Set the AccuracyRadiusBorderColor property transition options
   *
   * @param options transition options for String
   */
  public void setAccuracyRadiusBorderColorTransition(@NonNull TransitionOptions options) {
    checkThread();
    nativeSetAccuracyRadiusBorderColorTransition(options.getDuration(), options.getDelay());
  }

  @NonNull
  @Keep
  private native Object nativeGetTopImage();

  @NonNull
  @Keep
  private native Object nativeGetBearingImage();

  @NonNull
  @Keep
  private native Object nativeGetShadowImage();

  @NonNull
  @Keep
  private native Object nativeGetLocation();

  @NonNull
  @Keep
  private native Object nativeGetBearing();

  @NonNull
  @Keep
  private native Object nativeGetAccuracyRadius();

  @NonNull
  @Keep
  private native Object nativeGetTopImageSize();

  @NonNull
  @Keep
  private native Object nativeGetBearingImageSize();

  @NonNull
  @Keep
  private native Object nativeGetShadowImageSize();

  @NonNull
  @Keep
  private native Object nativeGetPerspectiveCompensation();

  @NonNull
  @Keep
  private native Object nativeGetImageTiltDisplacement();

  @NonNull
  @Keep
  private native Object nativeGetAccuracyRadiusColor();

  @NonNull
  @Keep
  private native TransitionOptions nativeGetAccuracyRadiusColorTransition();

  @Keep
  private native void nativeSetAccuracyRadiusColorTransition(long duration, long delay);

  @NonNull
  @Keep
  private native Object nativeGetAccuracyRadiusBorderColor();

  @NonNull
  @Keep
  private native TransitionOptions nativeGetAccuracyRadiusBorderColorTransition();

  @Keep
  private native void nativeSetAccuracyRadiusBorderColorTransition(long duration, long delay);

  @Override
  @Keep
  protected native void finalize() throws Throwable;

}
