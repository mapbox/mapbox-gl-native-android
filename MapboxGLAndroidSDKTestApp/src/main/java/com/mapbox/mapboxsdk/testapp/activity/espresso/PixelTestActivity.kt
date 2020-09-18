package com.mapbox.mapboxsdk.testapp.activity.espresso

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import com.mapbox.mapboxsdk.maps.MapView
import com.mapbox.mapboxsdk.maps.MapboxMap
import com.mapbox.mapboxsdk.maps.OnMapReadyCallback
import com.mapbox.mapboxsdk.maps.Style
import com.mapbox.mapboxsdk.testapp.R

/**
 * Test activity used for instrumentation tests that require a specific device size.
 */
class PixelTestActivity : AppCompatActivity(), OnMapReadyCallback {

  lateinit var mapView: MapView
  lateinit var mapboxMap: MapboxMap

  override fun onCreate(savedInstanceState: Bundle?) {
    super.onCreate(savedInstanceState)
    setContentView(R.layout.activity_pixel_test)
    mapView = findViewById(R.id.mapView)
    mapView.onCreate(savedInstanceState)
    mapView.getMapAsync(this)
    mapView.attachLifeCycle(this)
  }

  override fun onMapReady(map: MapboxMap) {
    mapboxMap = map
    mapboxMap.setStyle(Style.MAPBOX_STREETS)
  }


  override fun onSaveInstanceState(outState: Bundle) {
    super.onSaveInstanceState(outState)
    mapView.onSaveInstanceState(outState)
  }

  override fun onLowMemory() {
    super.onLowMemory()
    mapView.onLowMemory()
  }
}