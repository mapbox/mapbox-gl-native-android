package com.mapbox.mapboxsdk.testapp.activity.glsurfaceview;

import android.os.Bundle;

import androidx.appcompat.app.AppCompatActivity;

import com.mapbox.mapboxsdk.maps.MapView;
import com.mapbox.mapboxsdk.maps.Style;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

/**
 * Example Activity showcasing how to inject a custom drawing surface and map renderer
 */
public class CustomGLSurfaceViewActivity extends AppCompatActivity {

  private MapView mapView;

  @Override
  protected void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    CustomGLSurfaceView customGLSurfaceView = new CustomGLSurfaceView(this);
    CustomMapRenderer customMapRenderer = new CustomMapRenderer(this, customGLSurfaceView);
    mapView = new MapView(this, null, customGLSurfaceView, customMapRenderer);
    setContentView(mapView);

    mapView.onCreate(savedInstanceState);
    mapView.getMapAsync(mapboxMap -> mapboxMap.setStyle(
      new Style.Builder().fromUri(Style.MAPBOX_STREETS)
    ));
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
  public void onLowMemory() {
    super.onLowMemory();
    mapView.onLowMemory();
  }

  @Override
  protected void onDestroy() {
    super.onDestroy();
    mapView.onDestroy();
  }

  @Override
  protected void onSaveInstanceState(Bundle outState) {
    super.onSaveInstanceState(outState);
    mapView.onSaveInstanceState(outState);
  }
}
