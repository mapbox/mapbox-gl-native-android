package com.mapbox.mapboxsdk.testapp.activity.style;

import android.os.Bundle;

import androidx.appcompat.app.AppCompatActivity;

import com.mapbox.mapboxsdk.maps.MapView;
import com.mapbox.mapboxsdk.maps.MapboxMap;
import com.mapbox.mapboxsdk.maps.Style;
import com.mapbox.mapboxsdk.testapp.R;

/**
 * Test activity used for instrumentation tests of fill extrusion.
 */
public class FillExtrusionStyleTestActivity extends AppCompatActivity {

  public MapView mapView;
  private MapboxMap mapboxMap;

  @Override
  protected void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    setContentView(R.layout.activity_extrusion_test);

    // Initialize map as normal
    mapView = (MapView) findViewById(R.id.mapView);
    mapView.onCreate(savedInstanceState);
    mapView.attachLifeCycle(this);
    mapView.getMapAsync(mapboxMap ->
      mapboxMap.setStyle(new Style.Builder().fromUri(Style.MAPBOX_STREETS),
        style -> FillExtrusionStyleTestActivity.this.mapboxMap = mapboxMap
      )
    );
  }

  public MapboxMap getMapboxMap() {
    return mapboxMap;
  }

  @Override
  protected void onSaveInstanceState(Bundle outState) {
    super.onSaveInstanceState(outState);
    mapView.onSaveInstanceState(outState);
  }

  @Override
  public void onLowMemory() {
    super.onLowMemory();
    mapView.onLowMemory();
  }
}
