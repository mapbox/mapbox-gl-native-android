package com.mapbox.mapboxsdk.testapp.utils.location;

import android.app.PendingIntent;
import android.location.Location;
import android.os.Looper;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import com.mapbox.android.core.location.LocationEngine;
import com.mapbox.android.core.location.LocationEngineCallback;
import com.mapbox.android.core.location.LocationEngineRequest;
import com.mapbox.android.core.location.LocationEngineResult;
import com.mapbox.mapboxsdk.location.CompassEngine;
import com.mapbox.mapboxsdk.location.CompassListener;

import java.io.InputStream;
import java.util.List;
import java.util.concurrent.CopyOnWriteArrayList;

public class MockLocationEngine implements LocationEngine, CompassEngine {
  private Location lastLocation = null;
  private float lastHeading = 0.0f;
  private float lastAccuracy = 0;
  private List<LocationEngineCallback<LocationEngineResult>> listeners = new CopyOnWriteArrayList<>();
  private List<CompassListener> compassListeners = new CopyOnWriteArrayList<>();

  private MockLocationProvider mockLocationProvider = new MockLocationProvider(new MockLocationProvider.MockSessionListener() {
    @Override
    public void onLocationChange(Location location) {
      for (CompassListener listener : compassListeners) {
        if (lastLocation != null) {
          listener.onCompassChanged(lastLocation.bearingTo(location));
          lastHeading = lastLocation.bearingTo(location);
          lastAccuracy = location.getAccuracy();
        }
      }
      lastLocation = location;
      for (LocationEngineCallback<LocationEngineResult> listener : listeners) {
        listener.onSuccess(LocationEngineResult.create(location));
      }
    }

    @Override
    public void onRouteFinished() {
      // STUB
    }
  });

  public void startLocationPlayback(@NonNull InputStream route, boolean repeat) {
    mockLocationProvider.playMockRoute(route, repeat);
  }

  @Override
  public void getLastLocation(@NonNull LocationEngineCallback<LocationEngineResult> callback) throws SecurityException {
    if (lastLocation != null) {
      callback.onSuccess(LocationEngineResult.create(lastLocation));
    } else {
      callback.onFailure(new Exception("failed to get last location"));
    }
  }

  @Override
  public void requestLocationUpdates(@NonNull LocationEngineRequest request, @NonNull LocationEngineCallback<LocationEngineResult> callback, @Nullable Looper looper) throws SecurityException {
    listeners.add(callback);
  }

  @Override
  public void requestLocationUpdates(@NonNull LocationEngineRequest request, PendingIntent pendingIntent) throws SecurityException {
    // STUB
  }

  @Override
  public void removeLocationUpdates(@NonNull LocationEngineCallback<LocationEngineResult> callback) {
    listeners.remove(callback);
  }

  @Override
  public void removeLocationUpdates(PendingIntent pendingIntent) {
    // STUB
  }

  @Override
  public void addCompassListener(@NonNull CompassListener compassListener) {
    compassListeners.add(compassListener);
  }

  @Override
  public void removeCompassListener(@NonNull CompassListener compassListener) {
    compassListeners.remove(compassListener);
  }

  @Override
  public float getLastHeading() {
    return lastHeading;
  }

  @Override
  public int getLastAccuracySensorStatus() {
    return (int) lastAccuracy;
  }
}