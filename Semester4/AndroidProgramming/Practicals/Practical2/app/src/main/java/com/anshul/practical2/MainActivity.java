package com.anshul.practical2;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.os.Bundle;
import android.util.Log;
import android.view.Gravity;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Log.d("MainActivity", "onCreate Called!");

        Context context = getApplicationContext();
        Toast toast = Toast.makeText(context, "onCreate Called!", Toast.LENGTH_SHORT);
        toast.show();
    }

    @Override
    protected void onStart() {
        super.onStart();
        Context context = getApplicationContext();
        Toast toast = Toast.makeText(context, "onStart Called!", Toast.LENGTH_SHORT);
        toast.setGravity(Gravity.LEFT| Gravity.BOTTOM, 0, 0);
        toast.show();

        Log.d("MainActivity", "onStart Called!");
    }

    @Override
    protected void onResume() {
        super.onResume();
        Context context = getApplicationContext();
        Toast toast = Toast.makeText(context, "onResume Called!", Toast.LENGTH_SHORT);
        toast.setGravity(Gravity.RIGHT|Gravity.BOTTOM, 0, 0);
        toast.show();

        Log.d("MainActivity", "onResume Called!");
    }

    @Override
    protected void onPause() {
        super.onPause();
        Context context = getApplicationContext();
        Toast toast = Toast.makeText(context, "onPause Called!", Toast.LENGTH_SHORT);
        toast.show();

        Log.d("MainActivity", "onPause Called!");
    }

    @Override
    protected void onStop() {
        super.onStop();
        Context context = getApplicationContext();
        Toast toast = Toast.makeText(context, "onStop Called!", Toast.LENGTH_SHORT);
        toast.show();

        Log.d("MainActivity", "onStop Called!");
    }

    @Override
    protected void onRestart() {
        super.onRestart();
        Context context = getApplicationContext();
        Toast toast = Toast.makeText(context, "onRestart Called!", Toast.LENGTH_SHORT);
        toast.show();

        Log.d("MainActivity", "onRestart Called!");
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        Context context = getApplicationContext();
        Toast toast = Toast.makeText(context, "onDestroy Called!", Toast.LENGTH_SHORT);
        toast.setGravity(Gravity.LEFT|Gravity.BOTTOM, 0, 0);
        toast.show();

        Log.d("MainActivity", "onDestroy Called!");
    }
}