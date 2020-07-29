package com.mapbox.mapboxsdk.maps;

import androidx.annotation.Keep;
import androidx.annotation.NonNull;

import java.util.concurrent.atomic.AtomicInteger;

/**
 * Observer interface used to subscribe for an Observable events.
 */
@Keep
public abstract class Observer {

  private static AtomicInteger idCounter = new AtomicInteger(0);
  private final int id;

  public Observer() {
    id = idCounter.incrementAndGet();
  }

  /**
   * Gets observer id
   *
   * @return observer id
   */
  public int getId() {
    return id;
  }

  /**
   * Notifies an Observer about an Event.
   *
   * @param event an Event
   */
  public abstract void notify(@NonNull ObservableEvent event);
}
