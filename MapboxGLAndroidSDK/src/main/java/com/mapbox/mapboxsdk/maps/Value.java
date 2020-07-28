package com.mapbox.mapboxsdk.maps;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import java.util.ArrayList;
import java.util.HashMap;

/**
 * Wrapper class for value, complies to the mapbox type system.
 */
public class Value {

  @Nullable
  private Object contents;

  /**
   * Create a value from an object.
   *
   * @param obj object to wrap
   */
  private Value(@Nullable Object obj) {
    contents = obj;
  }

  /**
   * Create a value from a double.
   *
   * @param d double to wrap
   */
  public Value(double d) {
    contents = d;
  }

  /**
   * Create a value from a long.
   *
   * @param l long to wrap
   */
  public Value(long l) {
    contents = l;
  }

  /**
   * Create a value from a boolean.
   *
   * @param b boolean to wrap
   */
  public Value(boolean b) {
    contents = b;
  }

  /**
   * Create a value from a string.
   *
   * @param str string to wrap
   */
  public Value(@NonNull String str) {
    contents = str;
  }

  /**
   * Create a value from an list.
   *
   * @param array list to wrap
   */
  public Value(@NonNull ArrayList<Value> array) {
    contents = array;
  }

  /**
   * Create a value from a map.
   *
   * @param map map to wrap
   */
  public Value(@NonNull HashMap<String, Value> map) {
    contents = map;
  }

  /**
   * Get the contents of the value
   *
   * @return the wrapped value
   */
  @Nullable
  public Object getContents() {
    return contents;
  }

  @Override
  public String toString() {
    return contents.toString();
  }
}
