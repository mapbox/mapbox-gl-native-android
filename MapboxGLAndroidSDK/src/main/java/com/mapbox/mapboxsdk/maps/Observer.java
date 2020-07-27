package com.mapbox.mapboxsdk.maps;

import androidx.annotation.NonNull;

import java.util.concurrent.atomic.AtomicInteger;

/**
 * @brief Observer interface used to subscribe for an \sa Observable events.
 */
public abstract class Observer {

  private static AtomicInteger idCounter = new AtomicInteger(0);
  private final int id;

  public Observer() {
    id = idCounter.incrementAndGet();
  }

  /**
   * @return observer id
   * @brief Gets observer id
   */
  public int getId() {
    return id;
  }

  /**
   * @param event an \sa Event
   * @brief Notifies an Observer about an \sa Event.
   */
  public abstract void notify(@NonNull ObservableEvent event);
}
