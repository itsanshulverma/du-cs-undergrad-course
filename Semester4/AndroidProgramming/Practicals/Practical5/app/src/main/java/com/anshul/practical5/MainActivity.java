package com.anshul.practical5;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.Spinner;

public class MainActivity extends AppCompatActivity implements AdapterView.OnItemSelectedListener {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Add event listener to spinner
        Spinner spinner = (Spinner) findViewById(R.id.spinner);
        spinner.setOnItemSelectedListener(this);

        // Applying own style to spinner
        ArrayAdapter adapter = ArrayAdapter.createFromResource(this,
                R.array.planets_array, R.layout.spinner_item);
        spinner.setAdapter(adapter);
    }

    @Override
    public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
        // Check selected item and change image
        String item = parent.getItemAtPosition(position).toString();
        ImageView imgView = (ImageView) findViewById(R.id.imageView);
        if(item.equalsIgnoreCase("Mercury"))
            imgView.setImageResource(R.drawable.mercury);
        if(item.equalsIgnoreCase("Venus"))
            imgView.setImageResource(R.drawable.venus);
        if(item.equalsIgnoreCase("Mars"))
            imgView.setImageResource(R.drawable.mars);
        if(item.equalsIgnoreCase("Earth"))
            imgView.setImageResource(R.drawable.earth);
        if(item.equalsIgnoreCase("Jupiter"))
            imgView.setImageResource(R.drawable.jupiter);
        if(item.equalsIgnoreCase("Saturn"))
            imgView.setImageResource(R.drawable.saturn);
        if(item.equalsIgnoreCase("Uranus"))
            imgView.setImageResource(R.drawable.uranus);
        if(item.equalsIgnoreCase("Neptune"))
            imgView.setImageResource(R.drawable.neptune);
    }

    @Override
    public void onNothingSelected(AdapterView<?> parent) {
        // Do nothing
    }
}