package com.anshul.geodata;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    EditText populationInput, literacyInput, hospitalsInput, povertyInput;
    Spinner states;
    Button submitBtn;

    public boolean isPositiveNumber(String str){
        try{
            double d = Double.parseDouble(str);
            if(d >= 0){
                return true;
            } else {
                return false;
            }
        } catch (NumberFormatException nfe){
            return false;
        }
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        populationInput = findViewById(R.id.editTextPopulation);
        literacyInput = findViewById(R.id.editTextLR);
        hospitalsInput = findViewById(R.id.editTextHospitals);
        povertyInput = findViewById(R.id.editTextPR);
        states = findViewById(R.id.spinnerState);
        submitBtn = findViewById(R.id.button);

        submitBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // Getting inputs
                String population = populationInput.getText().toString();
                String literacy = populationInput.getText().toString();
                String hospitals = populationInput.getText().toString();
                String poverty = populationInput.getText().toString();
                String state = states.getSelectedItem().toString();

                // Validation
                if(isPositiveNumber(population) &&
                        isPositiveNumber(literacy) &&
                        isPositiveNumber(hospitals) &&
                        isPositiveNumber(poverty)){
                    Toast.makeText(MainActivity.this,
                            "Validation Successful!", Toast.LENGTH_LONG).show();
                } else {
                    Toast.makeText(MainActivity.this,
                            "Validation Unsuccessful!", Toast.LENGTH_LONG).show();
                }
            }
        });
    }
}