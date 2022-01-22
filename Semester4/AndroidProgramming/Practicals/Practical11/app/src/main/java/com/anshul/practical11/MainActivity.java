package com.anshul.practical11;

import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import com.google.android.material.snackbar.Snackbar;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        ConstraintLayout layout = (ConstraintLayout) findViewById(R.id.layout);
        EditText username = (EditText) findViewById(R.id.editTextTextPersonName);
        EditText password = (EditText) findViewById(R.id.editTextTextPassword);
        Button btn = (Button) findViewById(R.id.button);

        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if(username.getText().toString().equals("admin") &&
                        password.getText().toString().equals("pass")){

                    String usernameTxt = username.getText().toString();
                    Intent intent = new Intent(MainActivity.this, LoggedInActivity.class);
                    intent.putExtra("username", usernameTxt);
                    startActivity(intent);
                    
                    password.setText("");
                }
                else{
                    Snackbar.make(layout,
                            "Wrong Credentials!", Snackbar.LENGTH_LONG).show();
                }
            }
        });
    }
}