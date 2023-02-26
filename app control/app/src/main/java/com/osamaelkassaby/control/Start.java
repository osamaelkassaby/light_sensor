package com.osamaelkassaby.control;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.view.Window;
import android.view.WindowManager;

public class Start extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {

        requestWindowFeature(Window.FEATURE_NO_TITLE);
        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,
                WindowManager.LayoutParams.FLAG_FULLSCREEN);
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_start);
        Handler handler = new Handler();

        Runnable runnable = new Runnable() {
            @Override
            public void run() {

                Intent intent = new Intent(Start.this , MainActivity2.class);
                startActivity(intent);

            }
        };

        handler.postDelayed(runnable,3*1000);

    }
}