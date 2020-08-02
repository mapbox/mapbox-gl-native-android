package com.mapbox.mapboxsdk.testapp.activity.offline

import android.graphics.Color
import android.os.Bundle
import android.os.Handler
import android.view.View
import androidx.appcompat.app.AppCompatActivity
import com.mapbox.geojson.*
import com.mapbox.mapboxsdk.camera.CameraPosition
import com.mapbox.mapboxsdk.geometry.LatLng
import com.mapbox.mapboxsdk.geometry.LatLngBoundsZoom
import com.mapbox.mapboxsdk.maps.MapboxMap
import com.mapbox.mapboxsdk.maps.Style
import com.mapbox.mapboxsdk.offline.CacheAreaDefinition
import com.mapbox.mapboxsdk.offline.OfflineManager
import com.mapbox.mapboxsdk.style.layers.FillLayer
import com.mapbox.mapboxsdk.style.layers.PropertyFactory.fillColor
import com.mapbox.mapboxsdk.style.layers.PropertyFactory.fillOpacity
import com.mapbox.mapboxsdk.style.sources.GeoJsonSource
import com.mapbox.mapboxsdk.testapp.R
import com.mapbox.turf.TurfMeasurement
import kotlin.collections.ArrayList
import kotlinx.android.synthetic.main.activity_map_simple.*
import kotlinx.android.synthetic.main.activity_region_download.*
import timber.log.Timber

/**
 * Example showcasing how to download an offline region headless, allows to test pausing and resuming the download.
 */
class PrefetchAmbientCacheActivity : AppCompatActivity() {
  private val handler: Handler = Handler()
  private lateinit var offlineManager: OfflineManager
  private lateinit var mapboxMap: MapboxMap
  private var downloading = false
  private var downloaded = false
  private var canceled = false
  private var prefetchAmbientCacheRequestId: Long? = null

  override fun onCreate(savedInstanceState: Bundle?) {
    super.onCreate(savedInstanceState)
    setContentView(R.layout.activity_prefetch_ambient_cache)
    mapView.onCreate(savedInstanceState)
    mapView.getMapAsync {
      mapboxMap = it
      mapboxMap.isDebugActive = true
      it.setStyle(styleUri) { style -> setupFillLayer(style) }
    }
    offlineManager = OfflineManager.getInstance(this)
    offlineManager.setMaximumAmbientCacheSize(Long.MAX_VALUE, null)
    initUi()

    clearAmbientCache {
      fab.visibility = View.VISIBLE
    }
  }

  private fun setupFillLayer(style: Style) {
    val geoJsonSource = GeoJsonSource("boundingBoxes", featureCollection)
    val fillLayer = FillLayer("fillLayer", "boundingBoxes")
    fillLayer.setProperties(
      fillColor(Color.GRAY),
      fillOpacity(0.7f)
    )
    style.addSource(geoJsonSource)
    style.addLayer(fillLayer)
  }

  override fun onStart() {
    super.onStart()
    mapView.onStart()
  }

  override fun onResume() {
    super.onResume()
    mapView.onResume()
  }

  override fun onPause() {
    super.onPause()
    mapView.onPause()
  }

  override fun onStop() {
    super.onStop()
    mapView.onStop()
  }

  override fun onLowMemory() {
    super.onLowMemory()
    mapView.onLowMemory()
  }

  override fun onDestroy() {
    super.onDestroy()
    mapView.onDestroy()
  }

  override fun onSaveInstanceState(outState: Bundle) {
    super.onSaveInstanceState(outState)
    mapView.onSaveInstanceState(outState)
  }

  private fun prefetchAmbientCache() {

    val latLngBoundsZoomList = ArrayList<LatLngBoundsZoom>()
    featureCollection.features()?.forEach {
      latLngBoundsZoomList.add((it.geometry() as Polygon).toLatLngBoundsZoom(15.0))
    }

    // Add a new LatLngBoundsZoom of a camera position
    val camera = mapboxMap.getLatLngBoundsZoomFromCamera(
      CameraPosition.Builder().target(LatLng(60.18566891184874, 24.827537834644318)).zoom(15.0).build())
    latLngBoundsZoomList.add(camera)

    val definition = CacheAreaDefinition(
      styleUri,
      latLngBoundsZoomList.toTypedArray(),
      resources.displayMetrics.density
    )

    prefetchAmbientCacheRequestId = offlineManager.prefetchAmbientCache(definition, object : OfflineManager.PrefetchAmbientCacheCallback {
      override fun onSuccess(requestId: Long) {
        handler.post {
          if (canceled) {
            fab.visibility = View.VISIBLE
            logMessage("Ambient cache request with id $requestId canceled.")
            download_status.text = "Canceled"
          } else {
            fab.visibility = View.INVISIBLE
            logMessage("Ambient cache request with id $requestId succeeded.")
            download_status.text = "Completed"
          }
        }
        fab.setImageResource(R.drawable.ic_play_arrow_black_24dp)
        canceled = false
      }

      override fun onError(requestId: Long, error: String?) {
        logMessage("Failed to prefetch ambient cache: $error, request id: $requestId.")
        fab.setImageResource(R.drawable.ic_play_arrow_black_24dp)
      }
    })
    logMessage("Prefetching ambient cache, request id: $prefetchAmbientCacheRequestId")
    startDownload()
  }

  private fun startDownload() {
    downloading = true
    fab.setImageResource(R.drawable.ic_pause_black_24dp)
    logMessage("Downloading...")
    download_status.text = "Downloading..."
  }

  private fun cancelDownload(id: Long) {
    downloading = false
    canceled = true
    fab.setImageResource(R.drawable.ic_play_arrow_black_24dp)
    logMessage("canceling prefetchAmbientCacheRequest $id ...")
    download_status.text = "Cancelling..."
    offlineManager.cancelPrefetchAmbientCacheRequest(id)
  }

  private fun logMessage(message: String) {
    Timber.d(message)
    log_text.append(message)
    log_text.append("\n")
  }

  private fun clearAmbientCache(onCompleted: () -> Unit) {
    offlineManager.clearAmbientCache(object : OfflineManager.FileSourceCallback {
      override fun onSuccess() {
        logMessage("Done deleting ambient cache")
        onCompleted()
      }

      override fun onError(message: String) {
        logMessage("Failed to clear ambient cache: $message")
        onCompleted()
      }
    })
  }

  // ui
  private fun initUi() {
    initFab()
  }

  private fun initFab() {
    fab.setOnClickListener {
      if (!downloaded && !downloading) {
        prefetchAmbientCache()
      } else {
        prefetchAmbientCacheRequestId?.let {
          cancelDownload(it)
        }
      }
    }
  }

  companion object {
    private const val styleUri = Style.MAPBOX_STREETS
    private val featureCollection = FeatureCollection.fromJson("""
      
      {
        "type": "FeatureCollection",
        "features": [
          {
            "type": "Feature",
            "properties": {},
            "geometry": {
              "type": "Polygon",
              "coordinates": [
                [
                  [
                    24.934673309326172,
                    60.16840397564771
                  ],
                  [
                    24.939265251159668,
                    60.16840397564771
                  ],
                  [
                    24.939265251159668,
                    60.170282576016206
                  ],
                  [
                    24.934673309326172,
                    60.170282576016206
                  ],
                  [
                    24.934673309326172,
                    60.16840397564771
                  ]
                ]
              ]
            }
          },
          {
            "type": "Feature",
            "properties": {},
            "geometry": {
              "type": "Polygon",
              "coordinates": [
                [
                  [
                    24.939136505126953,
                    60.16975956738537
                  ],
                  [
                    24.945294857025146,
                    60.16975956738537
                  ],
                  [
                    24.945294857025146,
                    60.17082692309542
                  ],
                  [
                    24.939136505126953,
                    60.17082692309542
                  ],
                  [
                    24.939136505126953,
                    60.16975956738537
                  ]
                ]
              ]
            }
          },
          {
            "type": "Feature",
            "properties": {},
            "geometry": {
              "type": "Polygon",
              "coordinates": [
                [
                  [
                    24.94515538215637,
                    60.17061345472757
                  ],
                  [
                    24.95044469833374,
                    60.17061345472757
                  ],
                  [
                    24.95044469833374,
                    60.17426890901826
                  ],
                  [
                    24.94515538215637,
                    60.17426890901826
                  ],
                  [
                    24.94515538215637,
                    60.17061345472757
                  ]
                ]
              ]
            }
          }
        ]
      }
    """.trimIndent())
  }
}

private fun Polygon.toLatLngBoundsZoom(zoom: Double): LatLngBoundsZoom {
  val boundingBox = TurfMeasurement.bbox(this)
  return LatLngBoundsZoom.from(boundingBox[3], boundingBox[2], boundingBox[1], boundingBox[0], zoom)
}