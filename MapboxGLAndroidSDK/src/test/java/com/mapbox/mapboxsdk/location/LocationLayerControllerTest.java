package com.mapbox.mapboxsdk.location;

import android.graphics.Bitmap;

import androidx.annotation.NonNull;

import com.google.gson.JsonElement;
import com.mapbox.geojson.Feature;
import com.mapbox.geojson.Point;
import com.mapbox.mapboxsdk.geometry.LatLng;
import com.mapbox.mapboxsdk.location.modes.RenderMode;
import com.mapbox.mapboxsdk.maps.MapboxMap;
import com.mapbox.mapboxsdk.maps.Style;
import com.mapbox.mapboxsdk.style.layers.Layer;
import com.mapbox.mapboxsdk.style.sources.GeoJsonSource;

import org.junit.Before;
import org.junit.Test;
import org.mockito.Mockito;
import org.mockito.invocation.InvocationOnMock;
import org.mockito.stubbing.Answer;

import java.util.HashSet;
import java.util.Set;

import static com.mapbox.mapboxsdk.location.LocationComponentConstants.ACCURACY_LAYER;
import static com.mapbox.mapboxsdk.location.LocationComponentConstants.BACKGROUND_ICON;
import static com.mapbox.mapboxsdk.location.LocationComponentConstants.BACKGROUND_LAYER;
import static com.mapbox.mapboxsdk.location.LocationComponentConstants.BACKGROUND_STALE_ICON;
import static com.mapbox.mapboxsdk.location.LocationComponentConstants.BEARING_ICON;
import static com.mapbox.mapboxsdk.location.LocationComponentConstants.BEARING_LAYER;
import static com.mapbox.mapboxsdk.location.LocationComponentConstants.FOREGROUND_ICON;
import static com.mapbox.mapboxsdk.location.LocationComponentConstants.FOREGROUND_LAYER;
import static com.mapbox.mapboxsdk.location.LocationComponentConstants.FOREGROUND_STALE_ICON;
import static com.mapbox.mapboxsdk.location.LocationComponentConstants.LOCATION_SOURCE;
import static com.mapbox.mapboxsdk.location.LocationComponentConstants.PROPERTY_ACCURACY_RADIUS;
import static com.mapbox.mapboxsdk.location.LocationComponentConstants.PROPERTY_COMPASS_BEARING;
import static com.mapbox.mapboxsdk.location.LocationComponentConstants.PROPERTY_FOREGROUND_ICON_OFFSET;
import static com.mapbox.mapboxsdk.location.LocationComponentConstants.PROPERTY_GPS_BEARING;
import static com.mapbox.mapboxsdk.location.LocationComponentConstants.PROPERTY_SHADOW_ICON_OFFSET;
import static com.mapbox.mapboxsdk.location.LocationComponentConstants.PULSING_CIRCLE_LAYER;
import static com.mapbox.mapboxsdk.location.LocationComponentConstants.SHADOW_ICON;
import static com.mapbox.mapboxsdk.location.LocationComponentConstants.SHADOW_LAYER;
import static com.mapbox.mapboxsdk.location.MapboxAnimator.ANIMATOR_LAYER_ACCURACY;
import static com.mapbox.mapboxsdk.location.MapboxAnimator.ANIMATOR_LAYER_COMPASS_BEARING;
import static com.mapbox.mapboxsdk.location.MapboxAnimator.ANIMATOR_LAYER_GPS_BEARING;
import static com.mapbox.mapboxsdk.location.MapboxAnimator.ANIMATOR_LAYER_LATLNG;
import static junit.framework.Assert.assertEquals;
import static junit.framework.Assert.assertNull;
import static org.mockito.ArgumentMatchers.any;
import static org.mockito.ArgumentMatchers.anyBoolean;
import static org.mockito.ArgumentMatchers.anyString;
import static org.mockito.ArgumentMatchers.eq;
import static org.mockito.Mockito.mock;
import static org.mockito.Mockito.times;
import static org.mockito.Mockito.verify;
import static org.mockito.Mockito.when;

public class LocationLayerControllerTest {

  private MapboxMap mapboxMap = mock(MapboxMap.class);
  private Style style = mock(Style.class);
  private LocationLayerRenderer indicatorRenderer = mock(LocationLayerRenderer.class);

  @Before
  public void before() {
    when(mapboxMap.getStyle()).thenReturn(style);
    when(style.isFullyLoaded()).thenReturn(true);
  }

  @Test
  public void onInitialization_locationSourceIsAdded() {
    OnRenderModeChangedListener internalRenderModeChangedListener = mock(OnRenderModeChangedListener.class);
    OnIndicatorPositionChangedListener internalIndicatorPositionChangedListener =
        mock(OnIndicatorPositionChangedListener.class);
    LayerSourceProvider sourceProvider = buildLayerProvider();
    GeoJsonSource locationSource = mock(GeoJsonSource.class);
    when(sourceProvider.generateSource(any(Feature.class))).thenReturn(locationSource);
    LayerBitmapProvider bitmapProvider = mock(LayerBitmapProvider.class);
    LocationComponentOptions options = mock(LocationComponentOptions.class);

    new LocationLayerController(mapboxMap, mapboxMap.getStyle(), sourceProvider, buildFeatureProvider(options),
      bitmapProvider, options, internalRenderModeChangedListener, internalIndicatorPositionChangedListener, false);

    verify(style).addSource(locationSource);
  }

  @Test
  public void onInitialization_shadowLayerIsAdded() {
    OnRenderModeChangedListener internalRenderModeChangedListener = mock(OnRenderModeChangedListener.class);
    OnIndicatorPositionChangedListener internalIndicatorPositionChangedListener =
        mock(OnIndicatorPositionChangedListener.class);
    LayerSourceProvider sourceProvider = buildLayerProvider();
    Layer shadowLayer = mock(Layer.class);
    when(sourceProvider.generateLayer(SHADOW_LAYER)).thenReturn(shadowLayer);
    GeoJsonSource locationSource = mock(GeoJsonSource.class);
    when(sourceProvider.generateSource(any(Feature.class))).thenReturn(locationSource);
    LayerBitmapProvider bitmapProvider = mock(LayerBitmapProvider.class);
    LocationComponentOptions options = mock(LocationComponentOptions.class);

    new LocationLayerController(mapboxMap, mapboxMap.getStyle(), sourceProvider, buildFeatureProvider(options),
      bitmapProvider, options, internalRenderModeChangedListener, internalIndicatorPositionChangedListener, false);

    verify(style).addLayerBelow(shadowLayer, BACKGROUND_LAYER);
  }

  @Test
  public void onInitialization_backgroundLayerIsAdded() {
    OnRenderModeChangedListener internalRenderModeChangedListener = mock(OnRenderModeChangedListener.class);
    OnIndicatorPositionChangedListener internalIndicatorPositionChangedListener =
        mock(OnIndicatorPositionChangedListener.class);
    LayerSourceProvider sourceProvider = buildLayerProvider();
    Layer backgroundLayer = mock(Layer.class);
    when(sourceProvider.generateLayer(BACKGROUND_LAYER)).thenReturn(backgroundLayer);
    GeoJsonSource locationSource = mock(GeoJsonSource.class);
    when(sourceProvider.generateSource(any(Feature.class))).thenReturn(locationSource);
    LayerBitmapProvider bitmapProvider = mock(LayerBitmapProvider.class);
    LocationComponentOptions options = mock(LocationComponentOptions.class);

    new LocationLayerController(mapboxMap, mapboxMap.getStyle(), sourceProvider, buildFeatureProvider(options),
      bitmapProvider, options, internalRenderModeChangedListener, internalIndicatorPositionChangedListener, false);

    verify(style).addLayerBelow(backgroundLayer, FOREGROUND_LAYER);
  }

  @Test
  public void onInitialization_foregroundLayerIsAdded() {
    OnRenderModeChangedListener internalRenderModeChangedListener = mock(OnRenderModeChangedListener.class);
    OnIndicatorPositionChangedListener internalIndicatorPositionChangedListener =
        mock(OnIndicatorPositionChangedListener.class);
    LayerSourceProvider sourceProvider = buildLayerProvider();
    Layer foregroundLayer = mock(Layer.class);
    when(sourceProvider.generateLayer(FOREGROUND_LAYER)).thenReturn(foregroundLayer);
    GeoJsonSource locationSource = mock(GeoJsonSource.class);
    when(sourceProvider.generateSource(any(Feature.class))).thenReturn(locationSource);
    LayerBitmapProvider bitmapProvider = mock(LayerBitmapProvider.class);
    LocationComponentOptions options = mock(LocationComponentOptions.class);

    new LocationLayerController(mapboxMap, mapboxMap.getStyle(), sourceProvider, buildFeatureProvider(options),
      bitmapProvider, options, internalRenderModeChangedListener, internalIndicatorPositionChangedListener, false);

    verify(style).addLayerBelow(foregroundLayer, BEARING_LAYER);
  }

  @Test
  public void onInitialization_bearingLayerIsAdded() {
    OnRenderModeChangedListener internalRenderModeChangedListener = mock(OnRenderModeChangedListener.class);
    OnIndicatorPositionChangedListener internalIndicatorPositionChangedListener =
        mock(OnIndicatorPositionChangedListener.class);
    LayerSourceProvider sourceProvider = buildLayerProvider();
    Layer bearingLayer = mock(Layer.class);
    when(sourceProvider.generateLayer(BEARING_LAYER)).thenReturn(bearingLayer);
    GeoJsonSource locationSource = mock(GeoJsonSource.class);
    when(sourceProvider.generateSource(any(Feature.class))).thenReturn(locationSource);
    LayerBitmapProvider bitmapProvider = mock(LayerBitmapProvider.class);
    LocationComponentOptions options = mock(LocationComponentOptions.class);
    String layerBelow = "layer-below";
    when(options.layerBelow()).thenReturn(layerBelow);

    new LocationLayerController(mapboxMap, mapboxMap.getStyle(), sourceProvider, buildFeatureProvider(options),
      bitmapProvider, options, internalRenderModeChangedListener, internalIndicatorPositionChangedListener, false);

    verify(style).addLayerBelow(bearingLayer, layerBelow);
  }

  @Test
  public void onInitialization_accuracyLayerIsAdded() {
    OnRenderModeChangedListener internalRenderModeChangedListener = mock(OnRenderModeChangedListener.class);
    OnIndicatorPositionChangedListener internalIndicatorPositionChangedListener =
        mock(OnIndicatorPositionChangedListener.class);
    LayerSourceProvider sourceProvider = buildLayerProvider();
    Layer accuracyLayer = mock(Layer.class);
    when(sourceProvider.generateAccuracyLayer()).thenReturn(accuracyLayer);
    GeoJsonSource locationSource = mock(GeoJsonSource.class);
    when(sourceProvider.generateSource(any(Feature.class))).thenReturn(locationSource);
    LayerBitmapProvider bitmapProvider = mock(LayerBitmapProvider.class);
    LocationComponentOptions options = mock(LocationComponentOptions.class);

    new LocationLayerController(mapboxMap, mapboxMap.getStyle(), sourceProvider, buildFeatureProvider(options),
      bitmapProvider, options, internalRenderModeChangedListener, internalIndicatorPositionChangedListener, false);

    verify(style).addLayerBelow(accuracyLayer, BACKGROUND_LAYER);
  }

  @Test
  public void onInitialization_pulsingCircleLayerIsAdded() {
    OnRenderModeChangedListener internalRenderModeChangedListener = mock(OnRenderModeChangedListener.class);
    OnIndicatorPositionChangedListener internalIndicatorPositionChangedListener =
        mock(OnIndicatorPositionChangedListener.class);
    LayerSourceProvider sourceProvider = buildLayerProvider();
    Layer pulsingCircleLayer = mock(Layer.class);
    when(sourceProvider.generatePulsingCircleLayer()).thenReturn(pulsingCircleLayer);
    GeoJsonSource locationSource = mock(GeoJsonSource.class);
    when(sourceProvider.generateSource(any(Feature.class))).thenReturn(locationSource);
    LayerBitmapProvider bitmapProvider = mock(LayerBitmapProvider.class);
    LocationComponentOptions options = mock(LocationComponentOptions.class);

    new LocationLayerController(mapboxMap, mapboxMap.getStyle(), sourceProvider, buildFeatureProvider(options),
        bitmapProvider, options, internalRenderModeChangedListener, internalIndicatorPositionChangedListener, false);

    verify(style).addLayerBelow(pulsingCircleLayer, ACCURACY_LAYER);
  }

  @Test
  public void onInitialization_numberOfCachedLayerIdsIsConstant() {
    OnRenderModeChangedListener internalRenderModeChangedListener = mock(OnRenderModeChangedListener.class);
    OnIndicatorPositionChangedListener internalIndicatorPositionChangedListener =
        mock(OnIndicatorPositionChangedListener.class);
    LayerSourceProvider sourceProvider = buildLayerProvider();
    GeoJsonSource locationSource = mock(GeoJsonSource.class);
    when(sourceProvider.generateSource(any(Feature.class))).thenReturn(locationSource);
    Set<String> layerSet = new HashSet<>();
    when(sourceProvider.getEmptyLayerSet()).thenReturn(layerSet);
    LayerBitmapProvider bitmapProvider = mock(LayerBitmapProvider.class);
    LocationComponentOptions options = mock(LocationComponentOptions.class);

    LocationLayerController controller =
      new LocationLayerController(mapboxMap, mapboxMap.getStyle(), sourceProvider, buildFeatureProvider(options),
        bitmapProvider, options, internalRenderModeChangedListener, internalIndicatorPositionChangedListener, false);

    controller.initializeComponents(mapboxMap.getStyle(), options);

    assertEquals(6, layerSet.size());
  }

  @Test
  public void applyStyle_styleShadowWithValidElevation() {
    OnRenderModeChangedListener internalRenderModeChangedListener = mock(OnRenderModeChangedListener.class);
    OnIndicatorPositionChangedListener internalIndicatorPositionChangedListener =
        mock(OnIndicatorPositionChangedListener.class);
    LayerSourceProvider sourceProvider = buildLayerProvider();
    when(sourceProvider.generateSource(any(Feature.class))).thenReturn(mock(GeoJsonSource.class));
    LayerBitmapProvider bitmapProvider = mock(LayerBitmapProvider.class);
    Bitmap bitmap = mock(Bitmap.class);
    when(bitmapProvider.generateShadowBitmap(any(LocationComponentOptions.class))).thenReturn(bitmap);
    LocationComponentOptions options = mock(LocationComponentOptions.class);
    when(options.elevation()).thenReturn(2f);

    // Style is applied on initialization
    new LocationLayerController(mapboxMap, mapboxMap.getStyle(), sourceProvider, buildFeatureProvider(options),
      bitmapProvider, options, internalRenderModeChangedListener, internalIndicatorPositionChangedListener, false);

    verify(style).addImage(SHADOW_ICON, bitmap);
  }

  @Test
  public void applyStyle_ignoreStyleShadowWithInvalidElevation() {
    OnRenderModeChangedListener internalRenderModeChangedListener = mock(OnRenderModeChangedListener.class);
    OnIndicatorPositionChangedListener internalIndicatorPositionChangedListener =
        mock(OnIndicatorPositionChangedListener.class);
    LayerSourceProvider sourceProvider = buildLayerProvider();
    when(sourceProvider.generateSource(any(Feature.class))).thenReturn(mock(GeoJsonSource.class));
    LayerBitmapProvider bitmapProvider = mock(LayerBitmapProvider.class);
    Bitmap bitmap = mock(Bitmap.class);
    when(bitmapProvider.generateShadowBitmap(any(LocationComponentOptions.class))).thenReturn(bitmap);
    LocationComponentOptions options = mock(LocationComponentOptions.class);
    when(options.elevation()).thenReturn(0f);

    new LocationLayerController(mapboxMap, mapboxMap.getStyle(), sourceProvider, buildFeatureProvider(options),
      bitmapProvider, options, internalRenderModeChangedListener, internalIndicatorPositionChangedListener, false);

    verify(style, times(0)).addImage(SHADOW_ICON, bitmap);
  }

  @Test
  public void applyStyle_styleForegroundFromOptions() {
    OnRenderModeChangedListener internalRenderModeChangedListener = mock(OnRenderModeChangedListener.class);
    OnIndicatorPositionChangedListener internalIndicatorPositionChangedListener =
        mock(OnIndicatorPositionChangedListener.class);
    LayerSourceProvider sourceProvider = buildLayerProvider();
    when(sourceProvider.generateSource(any(Feature.class))).thenReturn(mock(GeoJsonSource.class));
    LocationComponentOptions options = mock(LocationComponentOptions.class);
    int drawableResId = 123;
    int tintColor = 456;
    when(options.foregroundDrawable()).thenReturn(drawableResId);
    when(options.foregroundTintColor()).thenReturn(tintColor);
    LayerBitmapProvider bitmapProvider = mock(LayerBitmapProvider.class);
    Bitmap bitmap = mock(Bitmap.class);
    when(bitmapProvider.generateBitmap(drawableResId, tintColor)).thenReturn(bitmap);

    new LocationLayerController(mapboxMap, mapboxMap.getStyle(), sourceProvider, buildFeatureProvider(options),
      bitmapProvider, options, internalRenderModeChangedListener, internalIndicatorPositionChangedListener, false);

    verify(style).addImage(FOREGROUND_ICON, bitmap);
  }

  @Test
  public void applyStyle_styleForegroundStaleFromOptions() {
    OnRenderModeChangedListener internalRenderModeChangedListener = mock(OnRenderModeChangedListener.class);
    OnIndicatorPositionChangedListener internalIndicatorPositionChangedListener =
        mock(OnIndicatorPositionChangedListener.class);
    LayerSourceProvider sourceProvider = buildLayerProvider();
    when(sourceProvider.generateSource(any(Feature.class))).thenReturn(mock(GeoJsonSource.class));
    LocationComponentOptions options = mock(LocationComponentOptions.class);
    int drawableResId = 123;
    int tintColor = 456;
    when(options.foregroundDrawableStale()).thenReturn(drawableResId);
    when(options.foregroundStaleTintColor()).thenReturn(tintColor);
    LayerBitmapProvider bitmapProvider = mock(LayerBitmapProvider.class);
    Bitmap bitmap = mock(Bitmap.class);
    when(bitmapProvider.generateBitmap(drawableResId, tintColor)).thenReturn(bitmap);

    new LocationLayerController(mapboxMap, mapboxMap.getStyle(), sourceProvider, buildFeatureProvider(options),
      bitmapProvider, options, internalRenderModeChangedListener, internalIndicatorPositionChangedListener, false);

    verify(style).addImage(FOREGROUND_STALE_ICON, bitmap);
  }

  @Test
  public void applyStyle_styleBackgroundFromOptions() {
    OnRenderModeChangedListener internalRenderModeChangedListener = mock(OnRenderModeChangedListener.class);
    OnIndicatorPositionChangedListener internalIndicatorPositionChangedListener =
        mock(OnIndicatorPositionChangedListener.class);
    LayerSourceProvider sourceProvider = buildLayerProvider();
    when(sourceProvider.generateSource(any(Feature.class))).thenReturn(mock(GeoJsonSource.class));
    LocationComponentOptions options = mock(LocationComponentOptions.class);
    int drawableResId = 123;
    int tintColor = 456;
    when(options.backgroundDrawable()).thenReturn(drawableResId);
    when(options.backgroundTintColor()).thenReturn(tintColor);
    LayerBitmapProvider bitmapProvider = mock(LayerBitmapProvider.class);
    Bitmap bitmap = mock(Bitmap.class);
    when(bitmapProvider.generateBitmap(drawableResId, tintColor)).thenReturn(bitmap);

    new LocationLayerController(mapboxMap, mapboxMap.getStyle(), sourceProvider, buildFeatureProvider(options),
      bitmapProvider, options, internalRenderModeChangedListener, internalIndicatorPositionChangedListener, false);

    verify(style).addImage(BACKGROUND_ICON, bitmap);
  }

  @Test
  public void applyStyle_styleBackgroundStaleFromOptions() {
    OnRenderModeChangedListener internalRenderModeChangedListener = mock(OnRenderModeChangedListener.class);
    OnIndicatorPositionChangedListener internalIndicatorPositionChangedListener =
        mock(OnIndicatorPositionChangedListener.class);
    LayerSourceProvider sourceProvider = buildLayerProvider();
    when(sourceProvider.generateSource(any(Feature.class))).thenReturn(mock(GeoJsonSource.class));
    LocationComponentOptions options = mock(LocationComponentOptions.class);
    int drawableResId = 123;
    int tintColor = 456;
    when(options.backgroundDrawableStale()).thenReturn(drawableResId);
    when(options.backgroundStaleTintColor()).thenReturn(tintColor);
    LayerBitmapProvider bitmapProvider = mock(LayerBitmapProvider.class);
    Bitmap bitmap = mock(Bitmap.class);
    when(bitmapProvider.generateBitmap(drawableResId, tintColor)).thenReturn(bitmap);

    new LocationLayerController(mapboxMap, mapboxMap.getStyle(), sourceProvider, buildFeatureProvider(options),
      bitmapProvider, options, internalRenderModeChangedListener, internalIndicatorPositionChangedListener, false);

    verify(style).addImage(BACKGROUND_STALE_ICON, bitmap);
  }

  @Test
  public void applyStyle_styleBearingFromOptions() {
    OnRenderModeChangedListener internalRenderModeChangedListener = mock(OnRenderModeChangedListener.class);
    OnIndicatorPositionChangedListener internalIndicatorPositionChangedListener =
        mock(OnIndicatorPositionChangedListener.class);
    LayerSourceProvider sourceProvider = buildLayerProvider();
    when(sourceProvider.generateSource(any(Feature.class))).thenReturn(mock(GeoJsonSource.class));
    LocationComponentOptions options = mock(LocationComponentOptions.class);
    int drawableResId = 123;
    int tintColor = 456;
    when(options.bearingDrawable()).thenReturn(drawableResId);
    when(options.bearingTintColor()).thenReturn(tintColor);
    LayerBitmapProvider bitmapProvider = mock(LayerBitmapProvider.class);
    Bitmap bitmap = mock(Bitmap.class);
    when(bitmapProvider.generateBitmap(drawableResId, tintColor)).thenReturn(bitmap);

    new LocationLayerController(mapboxMap, mapboxMap.getStyle(), sourceProvider, buildFeatureProvider(options),
      bitmapProvider, options, internalRenderModeChangedListener, internalIndicatorPositionChangedListener, false);

    verify(style).addImage(BEARING_ICON, bitmap);
  }

  @Test
  public void applyStyle_specializedLayer_ignoreBitmapNames() {
    OnRenderModeChangedListener internalRenderModeChangedListener = mock(OnRenderModeChangedListener.class);
    OnIndicatorPositionChangedListener internalIndicatorPositionChangedListener =
        mock(OnIndicatorPositionChangedListener.class);
    LayerSourceProvider sourceProvider = buildLayerProvider();
    LocationComponentOptions options = mock(LocationComponentOptions.class);
    when(options.foregroundName()).thenReturn("new_name");
    LayerBitmapProvider bitmapProvider = mock(LayerBitmapProvider.class);

    new LocationLayerController(mapboxMap, mapboxMap.getStyle(), sourceProvider, buildFeatureProvider(options),
      bitmapProvider, options, internalRenderModeChangedListener, internalIndicatorPositionChangedListener, true);

    verify(indicatorRenderer).updateIconIds(eq(FOREGROUND_ICON), anyString(), anyString(), anyString(), anyString());
  }

  @Test
  public void applyStyle_layerBelowChanged() {
    OnRenderModeChangedListener internalRenderModeChangedListener = mock(OnRenderModeChangedListener.class);
    OnIndicatorPositionChangedListener internalIndicatorPositionChangedListener =
        mock(OnIndicatorPositionChangedListener.class);
    LayerSourceProvider sourceProvider = buildLayerProvider();
    when(sourceProvider.generateSource(any(Feature.class))).thenReturn(mock(GeoJsonSource.class));

    LocationComponentOptions options = mock(LocationComponentOptions.class);
    LayerBitmapProvider bitmapProvider = mock(LayerBitmapProvider.class);
    Bitmap bitmap = mock(Bitmap.class);
    when(bitmapProvider.generateShadowBitmap(any(LocationComponentOptions.class))).thenReturn(bitmap);

    LocationLayerController layerController =
      new LocationLayerController(mapboxMap, mapboxMap.getStyle(), sourceProvider, buildFeatureProvider(options),
        bitmapProvider, options, internalRenderModeChangedListener, internalIndicatorPositionChangedListener, false);

    Layer bearingLayer2 = mock(Layer.class);
    when(sourceProvider.generateLayer(BEARING_LAYER)).thenReturn(bearingLayer2);
    Layer foregroundLayer2 = mock(Layer.class);
    when(sourceProvider.generateLayer(FOREGROUND_LAYER)).thenReturn(foregroundLayer2);
    Layer backgroundLayer2 = mock(Layer.class);
    when(sourceProvider.generateLayer(BACKGROUND_LAYER)).thenReturn(backgroundLayer2);
    Layer shadowLayer2 = mock(Layer.class);
    when(sourceProvider.generateLayer(SHADOW_LAYER)).thenReturn(shadowLayer2);
    Layer accuracyLayer2 = mock(Layer.class);
    when(sourceProvider.generateAccuracyLayer()).thenReturn(accuracyLayer2);
    String layerBelow = "layer-below";
    when(options.layerBelow()).thenReturn(layerBelow);

    layerController.applyStyle(options);

    verify(style).removeLayer(BEARING_LAYER);
    verify(style).removeLayer(FOREGROUND_LAYER);
    verify(style).removeLayer(BACKGROUND_LAYER);
    verify(style).removeLayer(SHADOW_LAYER);
    verify(style).removeLayer(ACCURACY_LAYER);

    verify(style).addLayerBelow(bearingLayer2, layerBelow);
    verify(style).addLayerBelow(foregroundLayer2, BEARING_LAYER);
    verify(style).addLayerBelow(backgroundLayer2, FOREGROUND_LAYER);
    verify(style).addLayerBelow(shadowLayer2, BACKGROUND_LAYER);
    verify(style).addLayerBelow(accuracyLayer2, BACKGROUND_LAYER);
  }

  @Test
  public void applyStyle_layerBelowNotChanged() {
    OnRenderModeChangedListener internalRenderModeChangedListener = mock(OnRenderModeChangedListener.class);
    OnIndicatorPositionChangedListener internalIndicatorPositionChangedListener =
        mock(OnIndicatorPositionChangedListener.class);
    LayerSourceProvider sourceProvider = buildLayerProvider();
    when(sourceProvider.generateSource(any(Feature.class))).thenReturn(mock(GeoJsonSource.class));
    LocationComponentOptions options = mock(LocationComponentOptions.class);
    LayerBitmapProvider bitmapProvider = mock(LayerBitmapProvider.class);
    Bitmap bitmap = mock(Bitmap.class);
    when(bitmapProvider.generateShadowBitmap(any(LocationComponentOptions.class))).thenReturn(bitmap);

    String layerBelow = "layer-below";
    when(options.layerBelow()).thenReturn(layerBelow);

    LocationLayerController layerController =
      new LocationLayerController(mapboxMap, mapboxMap.getStyle(), sourceProvider, buildFeatureProvider(options),
        bitmapProvider, options, internalRenderModeChangedListener, internalIndicatorPositionChangedListener, false);

    options = mock(LocationComponentOptions.class);
    layerBelow = "layer-below";
    when(options.layerBelow()).thenReturn(layerBelow);
    layerController.applyStyle(options);

    verify(style, times(0)).removeLayer(any(String.class));
    verify(style, times(6)).addLayerBelow(any(Layer.class), any(String.class));
  }

  @Test
  public void applyStyle_layerBelowNotChangedNull() {
    OnRenderModeChangedListener internalRenderModeChangedListener = mock(OnRenderModeChangedListener.class);
    OnIndicatorPositionChangedListener internalIndicatorPositionChangedListener =
        mock(OnIndicatorPositionChangedListener.class);
    LayerSourceProvider sourceProvider = buildLayerProvider();
    when(sourceProvider.generateSource(any(Feature.class))).thenReturn(mock(GeoJsonSource.class));
    LocationComponentOptions options = mock(LocationComponentOptions.class);
    LayerBitmapProvider bitmapProvider = mock(LayerBitmapProvider.class);
    Bitmap bitmap = mock(Bitmap.class);
    when(bitmapProvider.generateShadowBitmap(any(LocationComponentOptions.class))).thenReturn(bitmap);

    LocationLayerController layerController =
      new LocationLayerController(mapboxMap, mapboxMap.getStyle(), sourceProvider, buildFeatureProvider(options),
        bitmapProvider, options, internalRenderModeChangedListener, internalIndicatorPositionChangedListener, false);

    options = mock(LocationComponentOptions.class);
    layerController.applyStyle(options);

    verify(style, times(0)).removeLayer(any(String.class));
    verify(style, times(1)).addLayer(any(Layer.class));
    verify(style, times(5)).addLayerBelow(any(Layer.class), Mockito.<String>any());
  }

  @Test
  public void updateForegroundOffset_foregroundIconPropertyIsUpdated() {
    OnRenderModeChangedListener internalRenderModeChangedListener = mock(OnRenderModeChangedListener.class);
    OnIndicatorPositionChangedListener internalIndicatorPositionChangedListener =
        mock(OnIndicatorPositionChangedListener.class);
    LayerSourceProvider sourceProvider = buildLayerProvider();
    GeoJsonSource locationSource = mock(GeoJsonSource.class);
    when(sourceProvider.generateSource(any(Feature.class))).thenReturn(locationSource);
    LayerBitmapProvider bitmapProvider = mock(LayerBitmapProvider.class);
    LocationComponentOptions options = mock(LocationComponentOptions.class);
    Feature locationFeature = mock(Feature.class);
    LocationLayerController layer = new LocationLayerController(
      mapboxMap, mapboxMap.getStyle(), sourceProvider, buildFeatureProvider(locationFeature, options),
      bitmapProvider, options, internalRenderModeChangedListener, internalIndicatorPositionChangedListener, false);

    layer.cameraTiltUpdated(2d);

    verify(locationFeature).addProperty(eq(PROPERTY_FOREGROUND_ICON_OFFSET), any(JsonElement.class));
  }

  @Test
  public void updateForegroundOffset_shadowPropertyIsUpdated() {
    OnRenderModeChangedListener internalRenderModeChangedListener = mock(OnRenderModeChangedListener.class);
    OnIndicatorPositionChangedListener internalIndicatorPositionChangedListener =
        mock(OnIndicatorPositionChangedListener.class);
    LayerSourceProvider sourceProvider = buildLayerProvider();
    GeoJsonSource locationSource = mock(GeoJsonSource.class);
    when(sourceProvider.generateSource(any(Feature.class))).thenReturn(locationSource);
    LayerBitmapProvider bitmapProvider = mock(LayerBitmapProvider.class);
    LocationComponentOptions options = mock(LocationComponentOptions.class);
    Feature locationFeature = mock(Feature.class);
    LocationLayerController layer = new LocationLayerController(
      mapboxMap, mapboxMap.getStyle(), sourceProvider, buildFeatureProvider(locationFeature, options),
      bitmapProvider, options, internalRenderModeChangedListener, internalIndicatorPositionChangedListener, false);
    layer.cameraTiltUpdated(2d);

    verify(locationFeature).addProperty(eq(PROPERTY_SHADOW_ICON_OFFSET), any(JsonElement.class));
  }

  @Test
  public void onNewLatLngValue_locationFeatureIsUpdated() {
    OnRenderModeChangedListener internalRenderModeChangedListener = mock(OnRenderModeChangedListener.class);
    OnIndicatorPositionChangedListener internalIndicatorPositionChangedListener =
        mock(OnIndicatorPositionChangedListener.class);
    GeoJsonSource locationSource = mock(GeoJsonSource.class);
    when(style.getSourceAs(LOCATION_SOURCE)).thenReturn(locationSource);
    LayerSourceProvider sourceProvider = buildLayerProvider();
    when(sourceProvider.generateSource(any(Feature.class))).thenReturn(locationSource);
    LayerBitmapProvider bitmapProvider = mock(LayerBitmapProvider.class);
    LocationComponentOptions options = mock(LocationComponentOptions.class);
    Feature locationFeature = mock(Feature.class);
    when(locationFeature.toJson()).thenReturn("expected_geojson_string");
    LocationLayerController layer = new LocationLayerController(
      mapboxMap, mapboxMap.getStyle(), sourceProvider, buildFeatureProvider(locationFeature, options),
      bitmapProvider, options, internalRenderModeChangedListener, internalIndicatorPositionChangedListener, false);

    getAnimationListener(ANIMATOR_LAYER_LATLNG, layer.getAnimationListeners()).onNewAnimationValue(new LatLng());

    // wanted twice (once for initialization)
    verify(locationSource, times(2)).setGeoJson("expected_geojson_string");
    verify(internalIndicatorPositionChangedListener).onIndicatorPositionChanged(any(Point.class));
  }

  @Test
  public void onNewGpsBearingValue_locationFeatureIsUpdated() {
    OnRenderModeChangedListener internalRenderModeChangedListener = mock(OnRenderModeChangedListener.class);
    OnIndicatorPositionChangedListener internalIndicatorPositionChangedListener =
        mock(OnIndicatorPositionChangedListener.class);
    GeoJsonSource locationSource = mock(GeoJsonSource.class);
    when(style.getSourceAs(LOCATION_SOURCE)).thenReturn(locationSource);
    LayerSourceProvider sourceProvider = buildLayerProvider();
    when(sourceProvider.generateSource(any(Feature.class))).thenReturn(locationSource);
    LayerBitmapProvider bitmapProvider = mock(LayerBitmapProvider.class);
    LocationComponentOptions options = mock(LocationComponentOptions.class);
    Feature locationFeature = mock(Feature.class);
    LocationLayerController layer = new LocationLayerController(
      mapboxMap, mapboxMap.getStyle(), sourceProvider, buildFeatureProvider(locationFeature, options),
      bitmapProvider, options, internalRenderModeChangedListener, internalIndicatorPositionChangedListener, false);
    layer.setRenderMode(RenderMode.GPS);
    float gpsBearing = 2f;

    getAnimationListener(ANIMATOR_LAYER_GPS_BEARING, layer.getAnimationListeners()).onNewAnimationValue(gpsBearing);

    verify(locationFeature).addNumberProperty(PROPERTY_GPS_BEARING, gpsBearing);
  }

  @Test
  public void onNewGpsBearingValue_updateIgnoredWithInvalidRenderMode() {
    OnRenderModeChangedListener internalRenderModeChangedListener = mock(OnRenderModeChangedListener.class);
    OnIndicatorPositionChangedListener internalIndicatorPositionChangedListener =
        mock(OnIndicatorPositionChangedListener.class);
    GeoJsonSource locationSource = mock(GeoJsonSource.class);
    when(style.getSourceAs(LOCATION_SOURCE)).thenReturn(locationSource);
    LayerSourceProvider sourceProvider = buildLayerProvider();
    when(sourceProvider.generateSource(any(Feature.class))).thenReturn(locationSource);
    LayerBitmapProvider bitmapProvider = mock(LayerBitmapProvider.class);
    LocationComponentOptions options = mock(LocationComponentOptions.class);
    Feature locationFeature = mock(Feature.class);
    LocationLayerController layer = new LocationLayerController(
      mapboxMap, mapboxMap.getStyle(), sourceProvider, buildFeatureProvider(locationFeature, options),
      bitmapProvider, options, internalRenderModeChangedListener, internalIndicatorPositionChangedListener, false);
    layer.setRenderMode(RenderMode.COMPASS);
    float gpsBearing = 2f;

    assertNull(getAnimationListener(ANIMATOR_LAYER_GPS_BEARING, layer.getAnimationListeners()));
    verify(locationFeature, times(0)).addNumberProperty(PROPERTY_GPS_BEARING, gpsBearing);
  }

  @Test
  public void onNewCompassBearingValue_locationFeatureIsUpdated() {
    OnRenderModeChangedListener internalRenderModeChangedListener = mock(OnRenderModeChangedListener.class);
    OnIndicatorPositionChangedListener internalIndicatorPositionChangedListener =
        mock(OnIndicatorPositionChangedListener.class);
    GeoJsonSource locationSource = mock(GeoJsonSource.class);
    when(style.getSourceAs(LOCATION_SOURCE)).thenReturn(locationSource);
    LayerSourceProvider sourceProvider = buildLayerProvider();
    when(sourceProvider.generateSource(any(Feature.class))).thenReturn(locationSource);
    LayerBitmapProvider bitmapProvider = mock(LayerBitmapProvider.class);
    LocationComponentOptions options = mock(LocationComponentOptions.class);
    Feature locationFeature = mock(Feature.class);
    LocationLayerController layer = new LocationLayerController(
      mapboxMap, mapboxMap.getStyle(), sourceProvider, buildFeatureProvider(locationFeature, options),
      bitmapProvider, options, internalRenderModeChangedListener, internalIndicatorPositionChangedListener, false);
    layer.setRenderMode(RenderMode.COMPASS);
    float compassBearing = 2f;

    getAnimationListener(ANIMATOR_LAYER_COMPASS_BEARING, layer.getAnimationListeners())
      .onNewAnimationValue(compassBearing);

    verify(locationFeature).addNumberProperty(PROPERTY_COMPASS_BEARING, compassBearing);
  }

  @Test
  public void onNewCompassBearingValue_updateIgnoredWithInvalidRenderMode() {
    OnRenderModeChangedListener internalRenderModeChangedListener = mock(OnRenderModeChangedListener.class);
    OnIndicatorPositionChangedListener internalIndicatorPositionChangedListener =
        mock(OnIndicatorPositionChangedListener.class);
    GeoJsonSource locationSource = mock(GeoJsonSource.class);
    when(style.getSourceAs(LOCATION_SOURCE)).thenReturn(locationSource);
    LayerSourceProvider sourceProvider = buildLayerProvider();
    when(sourceProvider.generateSource(any(Feature.class))).thenReturn(locationSource);
    LayerBitmapProvider bitmapProvider = mock(LayerBitmapProvider.class);
    LocationComponentOptions options = mock(LocationComponentOptions.class);
    Feature locationFeature = mock(Feature.class);
    LocationLayerController layer = new LocationLayerController(
      mapboxMap, mapboxMap.getStyle(), sourceProvider, buildFeatureProvider(locationFeature, options),
      bitmapProvider, options, internalRenderModeChangedListener, internalIndicatorPositionChangedListener, false);
    layer.setRenderMode(RenderMode.GPS);
    float compassBearing = 2f;

    assertNull(getAnimationListener(ANIMATOR_LAYER_COMPASS_BEARING, layer.getAnimationListeners()));
    verify(locationFeature, times(0)).addNumberProperty(PROPERTY_COMPASS_BEARING, compassBearing);
  }

  @Test
  public void onNewAccuracyRadiusValue_locationFeatureIsUpdated() {
    OnRenderModeChangedListener internalRenderModeChangedListener = mock(OnRenderModeChangedListener.class);
    OnIndicatorPositionChangedListener internalIndicatorPositionChangedListener =
        mock(OnIndicatorPositionChangedListener.class);
    GeoJsonSource locationSource = mock(GeoJsonSource.class);
    when(style.getSourceAs(LOCATION_SOURCE)).thenReturn(locationSource);
    LayerSourceProvider sourceProvider = buildLayerProvider();
    when(sourceProvider.generateSource(any(Feature.class))).thenReturn(locationSource);
    LayerBitmapProvider bitmapProvider = mock(LayerBitmapProvider.class);
    LocationComponentOptions options = mock(LocationComponentOptions.class);
    Feature locationFeature = mock(Feature.class);
    LocationLayerController layer = new LocationLayerController(
      mapboxMap, mapboxMap.getStyle(), sourceProvider, buildFeatureProvider(locationFeature, options),
      bitmapProvider, options, internalRenderModeChangedListener, internalIndicatorPositionChangedListener, false);
    layer.setRenderMode(RenderMode.NORMAL);
    float accuracyRadiusValue = 2f;

    getAnimationListener(ANIMATOR_LAYER_ACCURACY, layer.getAnimationListeners())
      .onNewAnimationValue(accuracyRadiusValue);

    verify(locationFeature).addNumberProperty(PROPERTY_ACCURACY_RADIUS, accuracyRadiusValue);
  }

  @Test
  public void onNewAccuracyRadiusValue_updateIgnoredWithInvalidRenderMode() {
    OnRenderModeChangedListener internalRenderModeChangedListener = mock(OnRenderModeChangedListener.class);
    OnIndicatorPositionChangedListener internalIndicatorPositionChangedListener =
        mock(OnIndicatorPositionChangedListener.class);
    GeoJsonSource locationSource = mock(GeoJsonSource.class);
    when(style.getSourceAs(LOCATION_SOURCE)).thenReturn(locationSource);
    LayerSourceProvider sourceProvider = buildLayerProvider();
    when(sourceProvider.generateSource(any(Feature.class))).thenReturn(locationSource);
    LayerBitmapProvider bitmapProvider = mock(LayerBitmapProvider.class);
    LocationComponentOptions options = mock(LocationComponentOptions.class);
    Feature locationFeature = mock(Feature.class);
    LocationLayerController layer = new LocationLayerController(
      mapboxMap, mapboxMap.getStyle(), sourceProvider, buildFeatureProvider(locationFeature, options),
      bitmapProvider, options, internalRenderModeChangedListener, internalIndicatorPositionChangedListener, false);
    layer.setRenderMode(RenderMode.GPS);
    float accuracyRadiusValue = 2f;

    assertNull(getAnimationListener(ANIMATOR_LAYER_ACCURACY, layer.getAnimationListeners()));
    verify(locationFeature, times(0))
      .addNumberProperty(PROPERTY_ACCURACY_RADIUS, accuracyRadiusValue);
  }

  @Test
  public void renderModeChanged_doNotNotifyAboutDuplicates_NORMAL() {
    OnRenderModeChangedListener internalRenderModeChangedListener = mock(OnRenderModeChangedListener.class);
    OnIndicatorPositionChangedListener internalIndicatorPositionChangedListener =
        mock(OnIndicatorPositionChangedListener.class);
    LayerSourceProvider sourceProvider = buildLayerProvider();
    GeoJsonSource locationSource = mock(GeoJsonSource.class);
    when(sourceProvider.generateSource(any(Feature.class))).thenReturn(locationSource);
    LayerBitmapProvider bitmapProvider = mock(LayerBitmapProvider.class);
    LocationComponentOptions options = mock(LocationComponentOptions.class);

    LocationLayerController controller =
      new LocationLayerController(mapboxMap, mapboxMap.getStyle(), sourceProvider, buildFeatureProvider(options),
        bitmapProvider, options, internalRenderModeChangedListener, internalIndicatorPositionChangedListener, false);

    controller.setRenderMode(RenderMode.NORMAL);
    controller.setRenderMode(RenderMode.NORMAL);

    verify(internalRenderModeChangedListener, times(1)).onRenderModeChanged(RenderMode.NORMAL);
  }

  @Test
  public void renderModeChanged_doNotNotifyAboutDuplicates_GPS() {
    OnRenderModeChangedListener internalRenderModeChangedListener = mock(OnRenderModeChangedListener.class);
    OnIndicatorPositionChangedListener internalIndicatorPositionChangedListener =
        mock(OnIndicatorPositionChangedListener.class);
    LayerSourceProvider sourceProvider = buildLayerProvider();
    GeoJsonSource locationSource = mock(GeoJsonSource.class);
    when(sourceProvider.generateSource(any(Feature.class))).thenReturn(locationSource);
    LayerBitmapProvider bitmapProvider = mock(LayerBitmapProvider.class);
    LocationComponentOptions options = mock(LocationComponentOptions.class);

    LocationLayerController controller =
      new LocationLayerController(mapboxMap, mapboxMap.getStyle(), sourceProvider, buildFeatureProvider(options),
        bitmapProvider, options, internalRenderModeChangedListener, internalIndicatorPositionChangedListener, false);

    controller.setRenderMode(RenderMode.GPS);
    controller.setRenderMode(RenderMode.GPS);

    verify(internalRenderModeChangedListener, times(1)).onRenderModeChanged(RenderMode.GPS);
  }

  @Test
  public void layerHidden_renderModeChanged_layerShown_foregroundIconUpdated() {
    OnRenderModeChangedListener internalRenderModeChangedListener = mock(OnRenderModeChangedListener.class);
    OnIndicatorPositionChangedListener internalIndicatorPositionChangedListener =
        mock(OnIndicatorPositionChangedListener.class);
    LayerSourceProvider sourceProvider = buildLayerProvider();
    when(sourceProvider.generateSource(any(Feature.class))).thenReturn(mock(GeoJsonSource.class));
    LocationComponentOptions options = mock(LocationComponentOptions.class);
    int drawableResId = 123;
    int tintColor = 456;
    when(options.foregroundDrawable()).thenReturn(drawableResId);
    when(options.foregroundTintColor()).thenReturn(tintColor);
    LayerBitmapProvider bitmapProvider = mock(LayerBitmapProvider.class);
    Bitmap bitmap = mock(Bitmap.class);
    when(bitmapProvider.generateBitmap(drawableResId, tintColor)).thenReturn(bitmap);

    LocationLayerController controller =
      new LocationLayerController(mapboxMap, mapboxMap.getStyle(), sourceProvider, buildFeatureProvider(options),
        bitmapProvider, options, internalRenderModeChangedListener, internalIndicatorPositionChangedListener, false);

    verify(style).addImage(FOREGROUND_ICON, bitmap);

    int drawableGpsResId = 789;
    when(options.gpsDrawable()).thenReturn(drawableGpsResId);

    Bitmap bitmapGps = mock(Bitmap.class);
    when(bitmapProvider.generateBitmap(drawableGpsResId, tintColor)).thenReturn(bitmapGps);

    controller.hide();

    controller.setRenderMode(RenderMode.GPS);

    controller.show();

    verify(style).addImage(FOREGROUND_ICON, bitmapGps);
  }

  private LayerFeatureProvider buildFeatureProvider(@NonNull LocationComponentOptions options) {
    LayerFeatureProvider provider = mock(LayerFeatureProvider.class);
    when(provider.generateLocationFeature(null, options.enableStaleState())).thenReturn(mock(Feature.class));
    return provider;
  }

  private LayerFeatureProvider buildFeatureProvider(Feature feature, @NonNull LocationComponentOptions options) {
    LayerFeatureProvider provider = mock(LayerFeatureProvider.class);
    when(provider.generateLocationFeature(null, options.enableStaleState())).thenReturn(feature);
    return provider;
  }

  private LayerSourceProvider buildLayerProvider() {
    final LayerSourceProvider layerSourceProvider = mock(LayerSourceProvider.class);
    when(layerSourceProvider.getIndicatorLocationLayerRenderer()).thenReturn(indicatorRenderer);
    when(layerSourceProvider.getSymbolLocationLayerRenderer(any(LayerFeatureProvider.class), anyBoolean())).thenAnswer(
      new Answer<LocationLayerRenderer>() {
        @Override
        public LocationLayerRenderer answer(InvocationOnMock invocation) {
          LayerFeatureProvider featureProvider = invocation.getArgument(0);
          boolean isStale = invocation.getArgument(1);
          return new SymbolLocationLayerRenderer(layerSourceProvider, featureProvider, isStale);
        }
      }
    );

    Layer shadowLayer = mock(Layer.class);
    when(shadowLayer.getId()).thenReturn(SHADOW_LAYER);
    when(layerSourceProvider.generateLayer(SHADOW_LAYER)).thenReturn(shadowLayer);

    Layer backgroundLayer = mock(Layer.class);
    when(backgroundLayer.getId()).thenReturn(BACKGROUND_LAYER);
    when(layerSourceProvider.generateLayer(BACKGROUND_LAYER)).thenReturn(backgroundLayer);

    Layer foregroundLayer = mock(Layer.class);
    when(foregroundLayer.getId()).thenReturn(FOREGROUND_LAYER);
    when(layerSourceProvider.generateLayer(FOREGROUND_LAYER)).thenReturn(foregroundLayer);

    Layer bearingLayer = mock(Layer.class);
    when(bearingLayer.getId()).thenReturn(BEARING_LAYER);
    when(layerSourceProvider.generateLayer(BEARING_LAYER)).thenReturn(bearingLayer);

    Layer accuracyLayer = mock(Layer.class);
    when(accuracyLayer.getId()).thenReturn(ACCURACY_LAYER);
    when(layerSourceProvider.generateAccuracyLayer()).thenReturn(accuracyLayer);
    Layer pulsingCircleLayer = mock(Layer.class);
    when(pulsingCircleLayer.getId()).thenReturn(PULSING_CIRCLE_LAYER);
    when(layerSourceProvider.generatePulsingCircleLayer()).thenReturn(pulsingCircleLayer);
    return layerSourceProvider;
  }

  private <T> MapboxAnimator.AnimationsValueChangeListener<T> getAnimationListener(
    @MapboxAnimator.Type int animatorType,
    Set<AnimatorListenerHolder> holders) {
    for (AnimatorListenerHolder holder : holders) {
      @MapboxAnimator.Type int type = holder.getAnimatorType();
      if (type == animatorType) {
        return holder.getListener();
      }
    }
    return null;
  }
}