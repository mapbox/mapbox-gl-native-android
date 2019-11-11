package com.mapbox.mapboxsdk.utils;

import android.content.Context;
import android.support.annotation.NonNull;
import android.view.accessibility.AccessibilityManager;

import com.mapbox.mapboxsdk.log.Logger;

import java.lang.reflect.Method;

public class AccessibilityUtils {

  private static final String TAG = "Mbgl-AccessibilityUtils";
  private static final String METHOD_HIGH_TEXT_CONTRAST_ENABLED = "isHighTextContrastEnabled";
  private static final String ERROR_HIGH_CONTRAST_LOOKUP = "Could not detect high text contrast accessibility setting";

  @SuppressWarnings("JavaReflectionMemberAccess")
  public static boolean isHighContrastEnabled(@NonNull Context context) {
    AccessibilityManager accessibility = (AccessibilityManager) context.getSystemService(Context.ACCESSIBILITY_SERVICE);
    try {
      Method m = accessibility.getClass().getMethod(METHOD_HIGH_TEXT_CONTRAST_ENABLED);
      Object result = m.invoke(accessibility);
      if (result instanceof Boolean) {
        return (Boolean) result;
      }
    } catch (Exception exception) {
      Logger.i(TAG, ERROR_HIGH_CONTRAST_LOOKUP , exception);
    }
    return false;
  }
}
