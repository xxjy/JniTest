package com.test.jnitest;

public class JniUtils {

    static {
        System.loadLibrary("JniTest");
    }

    public native String helloWorld();

    public native String staticCallHello();

    public native String dynamicCallHello();
}
