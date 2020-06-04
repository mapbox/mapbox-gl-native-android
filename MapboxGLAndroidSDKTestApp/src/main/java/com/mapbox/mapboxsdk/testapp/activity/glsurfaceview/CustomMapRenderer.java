package com.mapbox.mapboxsdk.testapp.activity.glsurfaceview;

import android.content.Context;
import android.opengl.GLSurfaceView;

import androidx.annotation.NonNull;

import com.mapbox.mapboxsdk.maps.renderer.MapRenderer;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import static android.opengl.GLSurfaceView.RENDERMODE_WHEN_DIRTY;

public class CustomMapRenderer extends MapRenderer implements GLSurfaceView.Renderer {

  @NonNull
  private final CustomGLSurfaceView glSurfaceView;

  public CustomMapRenderer(Context context, CustomGLSurfaceView glSurfaceView) {
    super(context, null);
    this.glSurfaceView = glSurfaceView;
    glSurfaceView.setRenderer(this);
    glSurfaceView.setRenderMode(RENDERMODE_WHEN_DIRTY);
    glSurfaceView.setPreserveEGLContextOnPause(true);
    glSurfaceView.setDetachedListener(new CustomGLSurfaceView.OnGLSurfaceViewDetachedListener() {
      @Override
      public void onGLSurfaceViewDetached() {
        // because the GL thread is destroyed when the view is detached from window,
        // we need to ensure releasing the native renderer as well.
        // This avoids releasing it only when the view is being recreated, which is already on a new GL thread,
        // and leads to JNI crashes like https://github.com/mapbox/mapbox-gl-native/issues/14618
        nativeReset();
      }
    });
  }

  @Override
  public void onStop() {
    glSurfaceView.onPause();
  }

  @Override
  public void onPause() {
    super.onPause();
  }

  @Override
  public void onDestroy() {
    super.onDestroy();
  }

  @Override
  public void onStart() {
    glSurfaceView.onResume();
  }

  @Override
  public void onResume() {
    super.onResume();
  }

  @Override
  public void onSurfaceCreated(GL10 gl, EGLConfig config) {
    super.onSurfaceCreated(gl, config);
  }

  @Override
  protected void onSurfaceDestroyed() {
    super.onSurfaceDestroyed();
  }

  @Override
  public void onSurfaceChanged(GL10 gl, int width, int height) {
    super.onSurfaceChanged(gl, width, height);
  }

  @Override
  public void onDrawFrame(GL10 gl) {
    super.onDrawFrame(gl);
  }

  /**
   * May be called from any thread.
   * <p>
   * Called from the renderer frontend to schedule a render.
   */
  @Override
  public void requestRender() {
    glSurfaceView.requestRender();
  }

  /**
   * May be called from any thread.
   * <p>
   * Schedules work to be performed on the MapRenderer thread.
   *
   * @param runnable the runnable to execute
   */
  @Override
  public void queueEvent(Runnable runnable) {
    glSurfaceView.queueEvent(runnable);
  }
}