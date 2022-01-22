package com.anshul.practical7;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.RadioButton;
import android.widget.RadioGroup;

import com.google.android.material.snackbar.Snackbar;

import java.util.HashMap;

public class MainActivity extends AppCompatActivity {

    private HashMap<String, String> courseMap;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        RadioGroup courses = (RadioGroup) findViewById(R.id.radioGroup);

        if (courseMap == null){
            courseMap = new HashMap<>();
            courseMap.put("B.Sc. (Hons.) Computer Science", "Dr. V.S. Dixit");
            courseMap.put("B.Sc. (Hons.) Mathematics", "Dr. Raj Kumar Bhagat");
            courseMap.put("B.A. (Hons.) English", "Dr. Shubha Dwivedi");
            courseMap.put("B.A. (Hons.) Economics", "Dr. Arpa Sinha");
            courseMap.put("B.Com. (Hons.)", "Dr. Manika Jain");

            for (String course: courseMap.keySet()){
                RadioButton radioBtn = new RadioButton(MainActivity.this);
                radioBtn.setText(course);
                radioBtn.setTextSize(20);
                courses.addView(radioBtn);
            }

            courses.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(RadioGroup group, int checkedId) {
                    int id = courses.getCheckedRadioButtonId();
                    RadioButton radioBtn = (RadioButton) findViewById(id);
                    Snackbar.make(courses, courseMap.get(radioBtn.getText()),
                            Snackbar.LENGTH_SHORT).show();
                }
            });
        }
    }
}