package com.test.jnitest;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private TextView textView;
    private JniUtils utils;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        textView = findViewById(R.id.text_view);
        utils = new JniUtils();
    }

    public void staticCall(View view) {
        textView.setText(utils.staticCallHello());
    }

    public void dynamicCall(View view) {
        textView.setText(utils.dynamicCallHello());
    }

}
