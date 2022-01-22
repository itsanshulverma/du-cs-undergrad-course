package com.anshul.practical1;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        TextView greet = (TextView) findViewById(R.id.textView);
        EditText txt = (EditText) findViewById(R.id.editTextPersonName);
        Button btn = (Button) findViewById(R.id.button);

        btn.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                String name = txt.getText().toString();
                greet.setText("Hello " + name + "!");
                txt.setText("");
            }
        });
    }
}