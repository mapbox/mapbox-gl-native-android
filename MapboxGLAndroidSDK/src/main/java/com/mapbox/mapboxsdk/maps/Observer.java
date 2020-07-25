package com.mapbox.mapboxsdk.maps;

import androidx.annotation.NonNull;

import com.mapbox.mapboxsdk.log.Logger;

public abstract class Observer {

    private long nativePtr = 0;

    public Observer() {
        nativeInitialize();
    }

    protected native void nativeInitialize();

    @Override
    protected native void finalize() throws Throwable;

    public abstract void notifyEvent(@NonNull ObservableEvent event);

}
