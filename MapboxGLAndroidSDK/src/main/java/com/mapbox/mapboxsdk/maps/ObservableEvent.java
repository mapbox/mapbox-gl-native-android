package com.mapbox.mapboxsdk.maps;

import androidx.annotation.NonNull;

import java.util.Date;

/**
 * @brief Generic Event type used to notify \sa Observer.
 */
public final class ObservableEvent {

  @NonNull
  private final String type;
  @NonNull
  private final Date begin;
  @NonNull
  private final Date end;

  public ObservableEvent(@NonNull String type,
                         @NonNull Date begin,
                         @NonNull Date end) {
    this.type = type;
    this.begin = begin;
    this.end = end;
  }

  /**
   * Type of an event. Matches an original event type used for a subscription.
   */
  @NonNull
  public String getType() {
    return type;
  }

  /**
   * Timestamp taken at the time of an event creation.
   */
  @NonNull
  public Date getBegin() {
    return begin;
  }

  /**
   * Timestamp taken at the time of an event completion. For a non-interval
   * (single-shot) events, migth be equal to an event's `begin` timestamp.
   */
  @NonNull
  public Date getEnd() {
    return end;
  }

  @Override
  public String toString() {
    return "[" + "type: " + type + ", " + "begin: " + begin.toString() + ", " + "end: " + end.toString() + ", "
      + "data: " + "]";
  }
}
