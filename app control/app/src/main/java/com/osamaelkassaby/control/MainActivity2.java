package com.osamaelkassaby.control;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.os.Handler;
import android.view.View;
import android.view.Window;
import android.view.WindowManager;
import android.widget.ImageButton;
import android.widget.TextView;
import android.widget.Toast;

import com.android.volley.AuthFailureError;
import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.StringRequest;
import com.android.volley.toolbox.Volley;

import java.util.HashMap;
import java.util.Map;

public class MainActivity2 extends AppCompatActivity {

    public  String  URL = "http://192.168.113.25/";
    int state1 ;
    int state2 ;
    int state3 ;
    int state4 ;

    Handler handler = new Handler();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        requestWindowFeature(Window.FEATURE_NO_TITLE);
        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,
                WindowManager.LayoutParams.FLAG_FULLSCREEN);
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);

        ImageButton btn1 = findViewById(R.id.btn1);
        ImageButton btn2 = findViewById(R.id.btn2);
        ImageButton btn3 = findViewById(R.id.btn3);
        ImageButton btn4 = findViewById(R.id.btn4);
        temp("temp");
        Humidity("Humidity");

        handler.postDelayed(runnable,5*1000);


        TextView r1 = findViewById(R.id.relay1);
        TextView r2 = findViewById(R.id.r2);
        TextView r3 = findViewById(R.id.r3);
        TextView r4 = findViewById(R.id.r4);
        btn1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if(state1 == 0){
                    request("ON1");
                    state1 = 1;
                    btn1.setBackgroundResource(R.drawable.raduis_input_sreen);
                    r1.setText("OFF1");

                }else {
                    request("OFF1");
                    state1 = 0;
                    btn1.setBackgroundResource(R.drawable.raduis_btn);
                    r1.setText("ON1");

                }
            }
        });


        btn2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if(state2 == 0){
                    btn2.setBackgroundResource(R.drawable.raduis_input_sreen);

                    request("ON2");
                    state2 = 1;
                    r2.setText("OFF2");

                }else {
                    request("OFF2");
                    state2 = 0;
                    btn2.setBackgroundResource(R.drawable.raduis_btn);
                    r2.setText("ON2");

                }
            }
        });

        btn3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if(state3 == 0){
                    request("ON3");
                    state3 = 1;
                    btn3.setBackgroundResource(R.drawable.raduis_input_sreen);
                    r3.setText("OFF3");

                }else {
                    request("OFF3");
                    state3 = 0;
                    btn3.setBackgroundResource(R.drawable.raduis_btn);
                    r3.setText("ON3");

                }


            }
        });


        btn4.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if(state4 == 0){
                    request("ON4");
                    state4 = 1;
                    btn4.setBackgroundResource(R.drawable.raduis_input_sreen);
                    r4.setText("OFF3");


                }else {
                    request("OFF4");
                    state4 = 0;
                    btn4.setBackgroundResource(R.drawable.raduis_btn);
                    r4.setText("ON4");

                }


            }
        });

    }

    private  void request(String cmd){
        StringRequest request = new StringRequest(Request.Method.GET, URL+cmd, new Response.Listener<String>() {
            @Override
            public void onResponse(String response) {

            }
        }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {
                Toast.makeText(MainActivity2.this , error.toString() , Toast.LENGTH_LONG).show();

            }
        }){
            protected Map<String, String> getParams() throws AuthFailureError {
                Map<String, String> data = new HashMap<>();
                data.put("vv", "");

                return data;
            }
        };
        RequestQueue requestQueue = Volley.newRequestQueue(getApplicationContext());
        requestQueue.add(request);
    }
    private  void temp(String cmd){
        StringRequest request = new StringRequest(Request.Method.GET, URL+cmd, new Response.Listener<String>() {
            @Override
            public void onResponse(String response) {
                TextView textView = findViewById(R.id.temp);
                textView.setText(response);

            }
        }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {
                Toast.makeText(MainActivity2.this , error.toString() , Toast.LENGTH_LONG).show();

            }
        }){
            protected Map<String, String> getParams() throws AuthFailureError {
                Map<String, String> data = new HashMap<>();
                data.put("vv", "");

                return data;
            }
        };
        RequestQueue requestQueue_temp = Volley.newRequestQueue(getApplicationContext());
        requestQueue_temp.add(request);
    }
    private  void Humidity(String cmd ){
        StringRequest request = new StringRequest(Request.Method.GET, URL+cmd, new Response.Listener<String>() {
            @Override
            public void onResponse(String response) {
                TextView textView = findViewById(R.id.Humidity);
                textView.setText(response.trim()+" %");
            }
        }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {
                Toast.makeText(MainActivity2.this , error.toString() , Toast.LENGTH_LONG).show();

            }
        }){
            protected Map<String, String> getParams() throws AuthFailureError {
                Map<String, String> data = new HashMap<>();
                data.put("vv", "");

                return data;
            }
        };
        RequestQueue requestQueue_Humidity = Volley.newRequestQueue(getApplicationContext());
        requestQueue_Humidity.add(request);
    }

    Runnable runnable = new Runnable() {
        @Override
        public void run() {
            temp("temp");
            Humidity("Humidity");


            handler.postDelayed(runnable,5*1000);

        }
    };

}