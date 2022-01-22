package com.anshul.practical4;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        EditText inputTxt = findViewById(R.id.editTextInput);
        Button btn = findViewById(R.id.btnSend);

        // Button OnCLick Event Listener
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String input = inputTxt.getText().toString();
                Intent intent = new Intent(Intent.ACTION_SEND);
                intent.setType("text/plain");

                // Adding data to intent
                intent.putExtra(Intent.EXTRA_TEXT, input);
                startActivity(Intent.createChooser(intent, "Choose an app:"));
            }
        });
    }
}