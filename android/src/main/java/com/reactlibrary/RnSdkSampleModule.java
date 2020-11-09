package com.reactlibrary;

import android.widget.Toast;

import com.facebook.react.bridge.Callback;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.saltosystems.justinmobile.sdk.ble.IJustinBleResultAndDiscoverCallbacks;
import com.saltosystems.justinmobile.sdk.ble.JustinBle;
import com.saltosystems.justinmobile.sdk.common.OpResult;
import com.saltosystems.justinmobile.sdk.exceptions.JustinException;
import com.saltosystems.justinmobile.sdk.model.MobileKey;
import com.saltosystems.justinmobile.sdk.model.Result;

public class RnSdkSampleModule extends ReactContextBaseJavaModule {
    private static final String RECEIVED_MOBILE_KEY =
            "C0020100C120C3BD00E770C1F62B89F1223D8D2E5EBAAE16BB54A246254B7193EBD485533C45C210EC4D4A0C8FF1D6F529A9864145DC1ADE";

    private final ReactApplicationContext reactContext;
    private String alertText = "";

    public RnSdkSampleModule(ReactApplicationContext reactContext) {
        super(reactContext);
        this.reactContext = reactContext;
    }

    @Override
    public String getName() {
        return "RnSdkSample";
    }

    @ReactMethod
    public void sampleMethod(String key, Callback callback) {
        //TODO: Replace RECEIVED_MOBILE_KEY with actual key
        try {
            final MobileKey mobileKey = new MobileKey(RECEIVED_MOBILE_KEY);
            JustinBle.getInstance(reactContext).startOpening(mobileKey, new IJustinBleResultAndDiscoverCallbacks() {
                @Override
                public void onPeripheralFound() {
                    Toast.makeText(reactContext, "onPeripheralFound", Toast.LENGTH_LONG).show();
                }

                @Override
                public void onSuccess(Result result) {

                    if (result.getOpResult() == OpResult.AUTH_SUCCESS_ACCESS_REJECTED) {
                        alertText = "Access rejected";
                    } else if (result.getOpResult()
                            == OpResult.AUTH_SUCCESS_ACCESS_GRANTED) {
                        alertText = "Access granted";
                    }

                    if (alertText.length() != 0) {
                        Toast.makeText(reactContext, alertText, Toast.LENGTH_LONG).show();
                    }
                }

                @Override
                public void onFailure(JustinException e) {
                    alertText = "Error: " + e.getMessage();
                    Toast.makeText(reactContext, "Error: " + e.getMessage(), Toast.LENGTH_LONG)
                            .show();
                }
            });
        } catch (JustinException e) {
            alertText = "Error: " + e.getMessage();
            e.printStackTrace();
        }
        callback.invoke(alertText);
    }
}
