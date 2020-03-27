package com.mapbox.mapboxsdk.testapp.activity.maplayout

import android.annotation.SuppressLint
import android.os.Bundle
import android.view.MenuItem
import android.widget.Button
import androidx.appcompat.app.AppCompatActivity
import com.mapbox.geojson.Feature
import com.mapbox.geojson.LineString
import com.mapbox.mapboxsdk.Mapbox
import com.mapbox.mapboxsdk.camera.CameraUpdateFactory
import com.mapbox.mapboxsdk.geometry.LatLng
import com.mapbox.mapboxsdk.location.LocationComponent
import com.mapbox.mapboxsdk.location.LocationComponentActivationOptions
import com.mapbox.mapboxsdk.location.LocationComponentOptions
import com.mapbox.mapboxsdk.location.modes.CameraMode
import com.mapbox.mapboxsdk.location.modes.RenderMode
import com.mapbox.mapboxsdk.maps.MapView
import com.mapbox.mapboxsdk.maps.MapboxMap
import com.mapbox.mapboxsdk.maps.OnMapReadyCallback
import com.mapbox.mapboxsdk.maps.Style
import com.mapbox.mapboxsdk.style.layers.LineLayer
import com.mapbox.mapboxsdk.style.sources.GeoJsonSource
import com.mapbox.mapboxsdk.testapp.R
import com.mapbox.mapboxsdk.testapp.utils.NavUtils
import com.mapbox.mapboxsdk.testapp.utils.location.MockLocationEngine
import java.io.IOException


/**
 * Test activity showcasing a simple MapView without any MapboxMap interaction.
 */
class SimpleMapActivity : AppCompatActivity() {
  private var mapView: MapView? = null
  override fun onCreate(savedInstanceState: Bundle?) {
    super.onCreate(savedInstanceState)
    setContentView(R.layout.activity_map_simple)
    mapView = findViewById(R.id.mapView)
    mapView?.onCreate(savedInstanceState)
    mapView?.getMapAsync(OnMapReadyCallback { mapboxMap: MapboxMap ->
      mapboxMap.moveCamera(CameraUpdateFactory.newLatLngZoom(LatLng(35.2090642, 137.03786731), 14.0))
    })
  }

  @SuppressLint("MissingPermission")
  fun doLP(mapboxMap: MapboxMap, style: Style) {
//    val mockLocationEngine = MockLocationEngine()
//    try {
//      mockLocationEngine.startLocationPlayback(
//        applicationContext.assets.open("route_manual.gpx"),
//        true
//      )
//    } catch (ex: IOException) {
//      ex.printStackTrace();
//    }
    val locationComponent = mapboxMap.locationComponent
    locationComponent.activateLocationComponent(
      LocationComponentActivationOptions.builder(this, style)
        .useDefaultLocationEngine(true)
//        .locationEngine(mockLocationEngine)
        .locationComponentOptions(
          LocationComponentOptions.builder(this)
            .elevation(150f)
            .layerAbove("on-labels-daymode")
            .accuracyAlpha(0f)
            .trackingGesturesManagement(true)
            .build()
        )
        .build()
    )
    locationComponent.renderMode = RenderMode.GPS
    locationComponent.cameraMode = CameraMode.TRACKING_GPS
    locationComponent.isLocationComponentEnabled = true

    findViewById<Button>(R.id.set_tracking).setOnClickListener {
      locationComponent.setCameraMode(CameraMode.TRACKING_GPS, 500L, 17.0, null, 45.0, null)
    }

    doFps(mapboxMap, locationComponent)
  }

  fun doFps(mapboxMap: MapboxMap, locationComponent: LocationComponent) {
    mapboxMap.addOnCameraIdleListener {
      val zoom: Double = mapboxMap.cameraPosition.zoom
      val maxAnimationFps: Int
      maxAnimationFps = when {
        zoom < 5 -> 3
        zoom < 10 -> 5
        zoom < 15 -> 7
        zoom < 18 -> 15
        else -> Int.MAX_VALUE
      }
      locationComponent.setMaxAnimationFps(maxAnimationFps)
    }
  }

  override fun onStart() {
    super.onStart()
    mapView!!.onStart()
  }

  override fun onResume() {
    super.onResume()
    mapView!!.onResume()
  }

  override fun onPause() {
    super.onPause()
    mapView!!.onPause()
  }

  override fun onStop() {
    super.onStop()
    mapView!!.onStop()
  }

  override fun onLowMemory() {
    super.onLowMemory()
    mapView!!.onLowMemory()
  }

  override fun onDestroy() {
    super.onDestroy()
    mapView!!.onDestroy()
  }

  override fun onSaveInstanceState(outState: Bundle) {
    super.onSaveInstanceState(outState)
    mapView!!.onSaveInstanceState(outState)
  }

  override fun onOptionsItemSelected(item: MenuItem): Boolean {
    when (item.itemId) {
      android.R.id.home -> {
        // activity uses singleInstance for testing purposes
// code below provides a default navigation when using the app
        onBackPressed()
        return true
      }
    }
    return super.onOptionsItemSelected(item)
  }

  override fun onBackPressed() { // activity uses singleInstance for testing purposes
// code below provides a default navigation when using the app
    NavUtils.navigateHome(this)
  }
}