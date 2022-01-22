package com.anshul.practical9b;

import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;
import androidx.lifecycle.ViewModelStoreOwner;

import android.graphics.Color;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.LinearLayout;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    ConstraintLayout layout;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        layout = (ConstraintLayout) findViewById(R.id.layoutParent);
        Button btnRed = (Button) findViewById(R.id.btnRed);
        Button btnGreen = (Button) findViewById(R.id.btnGreen);
        Button btnBlue = (Button) findViewById(R.id.btnBlue);
        Button btnReset = (Button) findViewById(R.id.btnReset);

        btnRed.setOnClickListener(this);
        btnGreen.setOnClickListener(this);
        btnBlue.setOnClickListener(this);
        btnReset.setOnClickListener(this);
    }

    @Override
    public void onClick(View v) {
        switch(v.getId()){
            case R.id.btnRed:
                layout.setBackgroundColor(Color.RED);
                break;
            case R.id.btnGreen:
                layout.setBackgroundColor(Color.GREEN);
                break;
            case R.id.btnBlue:
                layout.setBackgroundColor(Color.BLUE);
                break;
            case R.id.btnReset:
                layout.setBackgroundColor(Color.TRANSPARENT);
                break;
            default:
                layout.setBackgroundColor(Color.TRANSPARENT);
                break;
        }
    }
}