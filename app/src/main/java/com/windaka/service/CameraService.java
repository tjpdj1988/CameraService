package com.windaka.service;

import android.app.Service;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.os.Handler;
import android.os.IBinder;
import android.os.Looper;
import android.support.annotation.Nullable;
import android.util.Log;

/**
 * Created by tsjmpg on 16-4-22.
 */
public class CameraService extends Service {
    final String TAG = "CameraService";

    static {
        System.loadLibrary("camera");
    }
    private Handler handler = new Handler(Looper.getMainLooper());

    BroadcastReceiver receiver = new BroadcastReceiver() {
        @Override
        public void onReceive(Context context, Intent intent) {
            String callstate = intent.getStringExtra("callstate");
            switch (callstate){
                case "OutgoingInit":
                    open();
                    break;
                case "Released":
                    close();
                    break;
                default:
            }
        }
    };

    @Nullable
    //@Override
    public IBinder onBind(Intent intent) {
        return null;
    }


    @Override
    public void onCreate() {
        super.onCreate();
        IntentFilter filter = new IntentFilter("com.windaka.sip.callstate");
        registerReceiver(receiver, filter);
        Log.i(TAG, "Register CameraService Receiver: com.windaka.sip.callstate, bundle=[callstate@String]");
    }

    @Override
    public void onDestroy() {
        unregisterReceiver(receiver);
        super.onDestroy();
    }

    private native void open();

    private native void close();


}
