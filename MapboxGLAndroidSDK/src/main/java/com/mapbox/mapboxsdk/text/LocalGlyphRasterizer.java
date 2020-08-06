package com.mapbox.mapboxsdk.text;

import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Bitmap;
import android.graphics.Rect;
import android.graphics.Typeface;
import androidx.annotation.Keep;
import androidx.annotation.NonNull;
import androidx.annotation.WorkerThread;

/**
 * LocalGlyphRasterizer is the Android-specific platform implementation used
 * by the portable local_glyph_rasterizer.hpp
 */
@Keep
public class LocalGlyphRasterizer {

  @Keep
  public class GlyphMetrics {
    public int width;
    public int height;
    public int top;
    public int left;
    public int ascender;
    public int descender;
    public int advance;
    public Bitmap glyphBitmap;
  }

  @NonNull
  private final GlyphMetrics glyphMetrics;
  @NonNull
  private final Rect bounds;
  @NonNull
  private final Paint paint;
  @NonNull
  private final Canvas canvas;

  LocalGlyphRasterizer() {
    glyphMetrics = new GlyphMetrics();
    glyphMetrics.glyphBitmap = Bitmap.createBitmap(35, 35, Bitmap.Config.ARGB_8888);

    bounds = new Rect();

    paint = new Paint();
    paint.setAntiAlias(true);
    paint.setTextSize(24);

    canvas = new Canvas();
    canvas.setBitmap(glyphMetrics.glyphBitmap);
  }

  /***
   * Uses Android-native drawing code to encapsulate the glyph metrics and a raterized
   * square {@link Bitmap} to a single structure which can be returned to portable
   * code for transformation into the native glyph data structure.
   *
   * @param fontFamily Font family string to pass to Typeface.create
   * @param bold If true, use Typeface.BOLD option
   * @param glyphID 16-bit Unicode BMP codepoint to draw
   *
   * @return Return GlyphMetrics that contains all the necessary information to display
   *         the character in the requested tile.
   */
  @WorkerThread
  protected GlyphMetrics getGlyphMetrics(String fontFamily, boolean bold, char glyphID) {
    paint.setTypeface(Typeface.create(fontFamily, bold ? Typeface.BOLD : Typeface.NORMAL));

    // Get font metrics
    Paint.FontMetricsInt metrics = paint.getFontMetricsInt();
    glyphMetrics.ascender = Math.abs(metrics.top);
    glyphMetrics.descender = Math.abs(metrics.bottom);

    String glyph = String.valueOf(glyphID);
    paint.getTextBounds(glyph, 0, 1, bounds);
    glyphMetrics.left = bounds.left;
    glyphMetrics.width = bounds.right - bounds.left;
    glyphMetrics.height = bounds.bottom - bounds.top;
    glyphMetrics.top = Math.abs(bounds.top);
    glyphMetrics.advance = Math.round(paint.measureText(glyph, 0, 1));

    if (glyphMetrics.width == 0 && glyphMetrics.height == 0) {
      return glyphMetrics;
    }
    // Draw glyph on the canvas with the 3 pixels' boarder padding from the left and top
    float x = 3 - bounds.left;
    float y = 3 - bounds.top;
    canvas.drawColor(Color.WHITE);
    canvas.drawText(glyph, x, y, paint);

    return glyphMetrics;
  }
}