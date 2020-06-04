package com.mapbox.mapboxsdk.integration

import androidx.test.annotation.UiThreadTest
import androidx.test.ext.junit.runners.AndroidJUnit4
import androidx.test.rule.ActivityTestRule
import com.mapbox.mapboxsdk.maps.MapView
import com.mapbox.mapboxsdk.testapp.activity.FeatureOverviewActivity
import com.mapbox.mapboxsdk.testapp.activity.glsurfaceview.CustomGLSurfaceView
import com.mapbox.mapboxsdk.testapp.activity.glsurfaceview.CustomMapRenderer
import junit.framework.Assert.assertEquals
import org.junit.Rule
import org.junit.Test
import org.junit.runner.RunWith
import java.lang.IllegalArgumentException

@RunWith(AndroidJUnit4::class)
class CustomSurfaceTest {

  @get:Rule
  var activityRule: ActivityTestRule<FeatureOverviewActivity> = ActivityTestRule(
    FeatureOverviewActivity::class.java)

  @UiThreadTest
  @Test
  fun setCustomDrawingSurface() {
    val context = activityRule.activity
    val mapView = MapView(context)
    val customGLSurfaceView = CustomGLSurfaceView(context)
    val customMapRenderer = CustomMapRenderer(context, customGLSurfaceView)
    mapView.setCustomDrawingSurface(customGLSurfaceView, customMapRenderer)
    mapView.onCreate(null)
    assertEquals("View should match", customGLSurfaceView, mapView.renderView)
    mapView.onDestroy()
  }

  @UiThreadTest
  @Test(expected = IllegalArgumentException::class)
  fun throwCustomDrawingSurface() {
    val context = activityRule.activity
    val mapView = MapView(context)
    mapView.onCreate(null)
    val customGLSurfaceView = CustomGLSurfaceView(context)
    val customMapRenderer = CustomMapRenderer(context, customGLSurfaceView)
    mapView.setCustomDrawingSurface(customGLSurfaceView, customMapRenderer)
  }
}