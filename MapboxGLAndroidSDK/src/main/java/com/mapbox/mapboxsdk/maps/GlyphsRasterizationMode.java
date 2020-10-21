package com.mapbox.mapboxsdk.maps;

/**
 * Describes glyphs rasterization modes.
 */
public enum GlyphsRasterizationMode {
  /**
   * No glyphs are rasterized locally. All glyphs are loaded from the server.
   */
  NO_GLYPHS_RASTERIZED_LOCALLY,
  /**
   * Ideographs are rasterized locally, and they are not loaded from the server.
   */
  IDEOGRAPHS_RASTERIZED_LOCALLY,
  /**
   * All glyphs are rasterized locally. No glyphs are loaded from the server.
   */
  ALL_GLYPHS_RASTERIZED_LOCALLY;

  /**
   * Get GlyphsRasterizationMode from int  value
   *
   * @param value the value of the mode
   * @return one enum in GlyphsRasterizationMode
   */
  public static GlyphsRasterizationMode valueOf(int value) {
    switch (value) {
      case 1:
        return IDEOGRAPHS_RASTERIZED_LOCALLY;
      case 2:
        return ALL_GLYPHS_RASTERIZED_LOCALLY;
      default:
        return NO_GLYPHS_RASTERIZED_LOCALLY;
    }
  }
}
