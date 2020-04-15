package com.mapbox.mapboxsdk.testapp.activity.style;

import android.graphics.Bitmap;
import android.graphics.Color;
import android.graphics.PointF;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;

import com.google.gson.JsonObject;
import com.google.gson.JsonPrimitive;
import com.mapbox.geojson.Feature;
import com.mapbox.geojson.FeatureCollection;
import com.mapbox.geojson.Point;
import com.mapbox.mapboxsdk.geometry.LatLng;
import com.mapbox.mapboxsdk.maps.ImageContent;
import com.mapbox.mapboxsdk.maps.ImageStretches;
import com.mapbox.mapboxsdk.maps.MapView;
import com.mapbox.mapboxsdk.maps.MapboxMap;
import com.mapbox.mapboxsdk.maps.OnMapReadyCallback;
import com.mapbox.mapboxsdk.maps.Style;
import com.mapbox.mapboxsdk.style.expressions.Expression;
import com.mapbox.mapboxsdk.style.layers.Property;
import com.mapbox.mapboxsdk.style.layers.PropertyFactory;
import com.mapbox.mapboxsdk.style.layers.SymbolLayer;
import com.mapbox.mapboxsdk.style.sources.GeoJsonSource;
import com.mapbox.mapboxsdk.style.sources.Source;
import com.mapbox.mapboxsdk.testapp.R;
import com.mapbox.mapboxsdk.utils.BitmapUtils;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Objects;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import static com.mapbox.mapboxsdk.style.expressions.Expression.FormatOption.formatFontScale;
import static com.mapbox.mapboxsdk.style.expressions.Expression.FormatOption.formatTextColor;
import static com.mapbox.mapboxsdk.style.expressions.Expression.NumberFormatOption.currency;
import static com.mapbox.mapboxsdk.style.expressions.Expression.NumberFormatOption.locale;
import static com.mapbox.mapboxsdk.style.expressions.Expression.format;
import static com.mapbox.mapboxsdk.style.expressions.Expression.formatEntry;
import static com.mapbox.mapboxsdk.style.expressions.Expression.literal;
import static com.mapbox.mapboxsdk.style.expressions.Expression.match;
import static com.mapbox.mapboxsdk.style.expressions.Expression.numberFormat;
import static com.mapbox.mapboxsdk.style.expressions.Expression.stop;
import static com.mapbox.mapboxsdk.style.expressions.Expression.switchCase;
import static com.mapbox.mapboxsdk.style.expressions.Expression.toBool;
import static com.mapbox.mapboxsdk.style.layers.PropertyFactory.iconAllowOverlap;
import static com.mapbox.mapboxsdk.style.layers.PropertyFactory.iconAnchor;
import static com.mapbox.mapboxsdk.style.layers.PropertyFactory.iconColor;
import static com.mapbox.mapboxsdk.style.layers.PropertyFactory.iconIgnorePlacement;
import static com.mapbox.mapboxsdk.style.layers.PropertyFactory.iconImage;
import static com.mapbox.mapboxsdk.style.layers.PropertyFactory.iconOpacity;
import static com.mapbox.mapboxsdk.style.layers.PropertyFactory.iconSize;
import static com.mapbox.mapboxsdk.style.layers.PropertyFactory.iconTextFit;
import static com.mapbox.mapboxsdk.style.layers.PropertyFactory.textAllowOverlap;
import static com.mapbox.mapboxsdk.style.layers.PropertyFactory.textAnchor;
import static com.mapbox.mapboxsdk.style.layers.PropertyFactory.textColor;
import static com.mapbox.mapboxsdk.style.layers.PropertyFactory.textField;
import static com.mapbox.mapboxsdk.style.layers.PropertyFactory.textIgnorePlacement;
import static com.mapbox.mapboxsdk.style.layers.PropertyFactory.textRotationAlignment;
import static com.mapbox.mapboxsdk.style.layers.PropertyFactory.textSize;

/**
 * Test stretchable image as a background for text..
 */
public class StretchableImageActivity extends AppCompatActivity implements MapboxMap.OnMapClickListener, OnMapReadyCallback {
  private static final String NAME_POPUP ="NAME_POPUP";
  private static final String NAME_POPUP_DEBUG ="NAME_POPUP_DEBUG";

  private MapboxMap mapboxMap;
  private MapView mapView;

  @Override
  public void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    setContentView(R.layout.activity_stretchable_image);
    mapView = findViewById(R.id.mapView);
    mapView.onCreate(savedInstanceState);

    mapView.getMapAsync(this);
    mapView.onCreate(savedInstanceState);

  }

  @Override
  public void onMapReady(@NonNull MapboxMap mapboxMap) {
    this.mapboxMap = mapboxMap;
    mapboxMap.setStyle(Style.MAPBOX_STREETS, new Style.OnStyleLoaded() {
      @Override
      public void onStyleLoaded(@NonNull Style style) {
        Bitmap popup = BitmapUtils.getBitmapFromDrawable(getResources().getDrawable(R.drawable.popup));
        Bitmap popupDebug = BitmapUtils.getBitmapFromDrawable(getResources().getDrawable(R.drawable.popup_debug));

        // The two (blue) columns of pixels that can be stretched horizontally:
        //   - the pixels between x: 25 and x: 55 can be stretched
        //   - the pixels between x: 85 and x: 115 can be stretched.
        List<ImageStretches> stretchX = new ArrayList<>();
        stretchX.add(new ImageStretches(25, 55));
        stretchX.add(new ImageStretches(85, 115));

        // The one (red) row of pixels that can be stretched vertically:
        //   - the pixels between y: 25 and y: 100 can be stretched
        List<ImageStretches> stretchY = new ArrayList<>();
        stretchY.add(new ImageStretches(25, 100));

        // This part of the image that can contain text ([x1, y1, x2, y2]):
        ImageContent content = new ImageContent(25, 25, 115, 100);

        style.addImage(NAME_POPUP, popup, stretchX, stretchY, content);
        style.addImage(NAME_POPUP_DEBUG, popupDebug, stretchX, stretchY, content);
      }
    });

    Bitmap popup = BitmapUtils.getBitmapFromDrawable(
      getResources().getDrawable(R.drawable.popup));

    // marker source
    markerCollection = FeatureCollection.fromFeatures(new Feature[] {
      Feature.fromGeometry(Point.fromLngLat(4.91638, 52.35673), featureProperties("1", "Android")),
      Feature.fromGeometry(Point.fromLngLat(4.91638, 52.34673), featureProperties("2", "Car"))
    });
    markerSource = new GeoJsonSource(MARKER_SOURCE, markerCollection);

    // marker layer
    markerSymbolLayer = new SymbolLayer(MARKER_LAYER, MARKER_SOURCE)
      .withProperties(
        iconImage(get(TITLE_FEATURE_PROPERTY)),
        iconIgnorePlacement(true),
        iconAllowOverlap(true),
        iconSize(switchCase(toBool(get(SELECTED_FEATURE_PROPERTY)), literal(1.5f), literal(1.0f))),
        iconAnchor(Property.ICON_ANCHOR_BOTTOM),
        iconColor(Color.BLUE),
        textField(TEXT_FIELD_EXPRESSION),
        textFont(NORMAL_FONT_STACK),
        textColor(Color.BLUE),
        textAllowOverlap(true),
        textIgnorePlacement(true),
        textAnchor(Property.TEXT_ANCHOR_TOP),
        textSize(10f)
      );

    // mapbox sign layer
    Source mapboxSignSource = new GeoJsonSource(MAPBOX_SIGN_SOURCE, Point.fromLngLat(4.91638, 52.3510));
    mapboxSignSymbolLayer = new SymbolLayer(MAPBOX_SIGN_LAYER, MAPBOX_SIGN_SOURCE);
    shuffleMapboxSign();

    // number format layer
    Source numberFormatSource = new GeoJsonSource(NUMBER_FORMAT_SOURCE, Point.fromLngLat(4.92756, 52.3516));
    numberFormatSymbolLayer = new SymbolLayer(NUMBER_FORMAT_LAYER, NUMBER_FORMAT_SOURCE);

    numberFormatSymbolLayer.setProperties(
      textField(
        numberFormat(123.456789, locale("nl-NL"), currency("EUR"))
      )
    );


    // Stretch image layer
    Source mapboxTextSource = new GeoJsonSource(TEXT_FORMAT_SOURCE, Point.fromLngLat(4.91638, 52.3410));
    textSymbolLayer = new SymbolLayer(TEXT_FORMAT_LAYER, TEXT_FORMAT_SOURCE);
    textSymbolLayer.withProperties(PropertyFactory.iconImage("icon"),
      textField(
        literal("mapboxmapbox")
      ),
      textColor(Color.BLACK),
      textFont(BOLD_FONT_STACK),
      textSize(25f),
      textRotationAlignment(Property.TEXT_ROTATION_ALIGNMENT_MAP),
      iconTextFit(literal("both")));

    Bitmap icon = BitmapUtils.getBitmapFromDrawable(getResources().getDrawable(R.drawable.ic_us));
    float border = 10;
    int width = icon.getWidth();

    List<ImageStretches> stretchX = new ArrayList<>();
    stretchX.add(new ImageStretches(border, (width - border) / 2));
    stretchX.add(new ImageStretches((width + border) / 2, width - border));
    List<ImageStretches> stretchY = new ArrayList<>();
    stretchY.add(new ImageStretches(border, (width - border) / 2));
    stretchY.add(new ImageStretches((width + border) / 2, width - border));
    ImageContent content = new ImageContent(border, border, width - border, width - border);

    mapboxMap.setStyle(new Style.Builder()
      .fromUri("asset://streets.json")
      .withImage("Car", Objects.requireNonNull(carBitmap), false)
      .withImage("icon", Objects.requireNonNull(icon), false, stretchX, stretchY, content)
      .withSources(markerSource, mapboxSignSource, numberFormatSource, mapboxTextSource)
      .withLayers(markerSymbolLayer, mapboxSignSymbolLayer, numberFormatSymbolLayer, textSymbolLayer)
    );

    // Set a click-listener so we can manipulate the map
    mapboxMap.addOnMapClickListener(StretchableImageActivity.this);
  }

  @Override
  public boolean onMapClick(@NonNull LatLng point) {
    // Query which features are clicked
    PointF screenLoc = mapboxMap.getProjection().toScreenLocation(point);
    List<Feature> markerFeatures = mapboxMap.queryRenderedFeatures(screenLoc, MARKER_LAYER);
    if (!markerFeatures.isEmpty()) {
      for (Feature feature : Objects.requireNonNull(markerCollection.features())) {
        if (feature.getStringProperty(ID_FEATURE_PROPERTY)
          .equals(markerFeatures.get(0).getStringProperty(ID_FEATURE_PROPERTY))) {

          // use DDS
          boolean selected = feature.getBooleanProperty(SELECTED_FEATURE_PROPERTY);
          feature.addBooleanProperty(SELECTED_FEATURE_PROPERTY, !selected);

          // validate symbol flicker regression for #13407
          markerSymbolLayer.setProperties(iconOpacity(match(
            get(ID_FEATURE_PROPERTY), literal(1.0f),
            stop(feature.getStringProperty("id"), selected ? 0.3f : 1.0f)
          )));
        }
      }
      markerSource.setGeoJson(markerCollection);
    } else {
      List<Feature> mapboxSignFeatures = mapboxMap.queryRenderedFeatures(screenLoc, MAPBOX_SIGN_LAYER);
      if (!mapboxSignFeatures.isEmpty()) {
        shuffleMapboxSign();
      }
    }

    return false;
  }

  private void toggleTextSize() {
    if (markerSymbolLayer != null) {
      Number size = markerSymbolLayer.getTextSize().getValue();
      if (size != null) {
        markerSymbolLayer.setProperties((float) size > 10 ? textSize(10f) : textSize(20f));
      }
    }
  }

  private void toggleTextField() {
    if (markerSymbolLayer != null) {
      if (TEXT_FIELD_EXPRESSION.equals(markerSymbolLayer.getTextField().getExpression())) {
        markerSymbolLayer.setProperties(textField("āA"));
      } else {
        markerSymbolLayer.setProperties(textField(TEXT_FIELD_EXPRESSION));
      }
    }
  }

  private void toggleTextFont() {
    if (markerSymbolLayer != null) {
      if (Arrays.equals(markerSymbolLayer.getTextFont().getValue(), NORMAL_FONT_STACK)) {
        markerSymbolLayer.setProperties(textFont(BOLD_FONT_STACK));
      } else {
        markerSymbolLayer.setProperties(textFont(NORMAL_FONT_STACK));
      }
    }
  }

  private void shuffleMapboxSign() {
    if (mapboxSignSymbolLayer != null) {
      mapboxSignSymbolLayer.setProperties(
        textField(
          format(
            formatEntry("M", formatFontScale(2)),
            getRandomColorEntryForString("a"),
            getRandomColorEntryForString("p"),
            getRandomColorEntryForString("b"),
            getRandomColorEntryForString("o"),
            getRandomColorEntryForString("x")
          )
        ),
        textColor(Color.BLACK),
        textFont(BOLD_FONT_STACK),
        textSize(25f),
        textRotationAlignment(Property.TEXT_ROTATION_ALIGNMENT_MAP)
      );
    }
  }

  private Expression.FormatEntry getRandomColorEntryForString(@NonNull String string) {
    return formatEntry(string,
      formatTextColor(
        rgb(
          random.nextInt(256),
          random.nextInt(256),
          random.nextInt(256)
        )
      ));
  }

  private JsonObject featureProperties(@NonNull String id, @NonNull String title) {
    JsonObject object = new JsonObject();
    object.add(ID_FEATURE_PROPERTY, new JsonPrimitive(id));
    object.add(TITLE_FEATURE_PROPERTY, new JsonPrimitive(title));
    object.add(SELECTED_FEATURE_PROPERTY, new JsonPrimitive(false));
    return object;
  }

  @Override
  protected void onStart() {
    super.onStart();
    mapView.onStart();
  }

  @Override
  protected void onResume() {
    super.onResume();
    mapView.onResume();
  }

  @Override
  protected void onPause() {
    super.onPause();
    mapView.onPause();
  }

  @Override
  protected void onStop() {
    super.onStop();
    mapView.onStop();
  }

  @Override
  public void onSaveInstanceState(Bundle outState) {
    super.onSaveInstanceState(outState);
    mapView.onSaveInstanceState(outState);
  }

  @Override
  public void onLowMemory() {
    super.onLowMemory();
    mapView.onLowMemory();
  }

  @Override
  public void onDestroy() {
    super.onDestroy();
    if (mapboxMap != null) {
      mapboxMap.removeOnMapClickListener(this);
    }
    mapView.onDestroy();
  }

  @Override
  public boolean onCreateOptionsMenu(Menu menu) {
    getMenuInflater().inflate(R.menu.menu_symbol_layer, menu);
    return true;
  }

  @Override
  public boolean onOptionsItemSelected(MenuItem item) {
    switch (item.getItemId()) {
      case R.id.action_toggle_text_size:
        toggleTextSize();
        return true;
      case R.id.action_toggle_text_field:
        toggleTextField();
        return true;
      case R.id.action_toggle_text_font:
        toggleTextFont();
        return true;
      default:
        return super.onOptionsItemSelected(item);
    }
  }
}
