package com.anshul.practical11;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;

import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import com.google.android.material.snackbar.Snackbar;

public class LoggedInActivity extends AppCompatActivity {

    private AlertDialog.Builder builder;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_logged_in);

        TextView textView = (TextView) findViewById(R.id.textView);
        ConstraintLayout layout = (ConstraintLayout) findViewById(R.id.layout);
        Button btn = (Button) findViewById(R.id.button);

        Intent intent = getIntent();
        String username = intent.getStringExtra("username");
        Snackbar.make(layout,
                "Welcome "+username+"!", Snackbar.LENGTH_SHORT).show();
        textView.setText("Welcome "+username+"!\nYou are logged in.");

        btn.setOnClickListener(new View.OnClickListener(){

            @Override
            public void onClick(View v) {
                logoutDialogBox();
            }
        });
    }

    @Override
    public void onBackPressed(){
        logoutDialogBox();
    }

    public void logoutDialogBox(){
        builder = new AlertDialog.Builder(LoggedInActivity.this);
        builder.setMessage("Do you want to logout ?");
        builder.setTitle("Alert !");
        builder.setCancelable(false);

        builder.setPositiveButton("Yes", new DialogInterface.OnClickListener() {

            @Override
            public void onClick(DialogInterface dialog, int which)
            {
                finish();
            }
        });
        builder.setNegativeButton("No", new DialogInterface.OnClickListener() {

            @Override
            public void onClick(DialogInterface dialog, int which)
            {
                dialog.cancel();
            }
        });

        AlertDialog alertDialog = builder.create();
        alertDialog.show();
    }
}