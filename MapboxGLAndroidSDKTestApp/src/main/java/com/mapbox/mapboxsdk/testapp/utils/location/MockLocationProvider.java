package com.mapbox.mapboxsdk.testapp.utils.location;

import android.location.Location;
import android.os.CountDownTimer;

import androidx.annotation.NonNull;

import java.io.InputStream;
import java.util.List;

public class MockLocationProvider {

private final static long STEP_DURATION = 300L;

  private final MockSessionListener listener;
  private int index;
  private boolean repeat;
  private List<Location> gpxLocationList;

  public MockLocationProvider(MockSessionListener mockSessionListener) {
    this.listener = mockSessionListener;
  }

  public void playMockRoute(InputStream inputStream, boolean repeat) {
    this.repeat = repeat;
    new ParseGpxTask(new GpxParser(), new ParseGpxTask.Listener() {
      @Override
      public void onParseComplete(@NonNull List<Location> gpxLocationList) {
        MockLocationProvider.this.gpxLocationList = gpxLocationList;
        animateRoute(gpxLocationList);
      }

      @Override
      public void onParseError(Exception exception) {
        throw new IllegalStateException(exception);
      }
    }).execute(inputStream);
  }

  private void animateRoute(List<Location> locations) {
    new CountDownTimer((locations.size() - 1) * STEP_DURATION, STEP_DURATION) {
      public void onTick(long millisUntilFinished) {
        listener.onLocationChange(locations.get(index));
        index++;
      }

      public void onFinish() {
        if (repeat) {
          index = 0;
          animateRoute(gpxLocationList);
        } else {
          listener.onRouteFinished();
        }
      }
    }.start();
  }

  public interface MockSessionListener {
    void onLocationChange(Location location);

    void onRouteFinished();
  }
}