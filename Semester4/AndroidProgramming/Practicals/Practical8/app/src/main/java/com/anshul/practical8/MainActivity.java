package com.anshul.practical8;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.TextView;

import com.google.android.material.snackbar.Snackbar;

import java.util.HashMap;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        HashMap<String, String> courseMap = new HashMap<>();
        courseMap.put("B.Sc. (Hons.) Computer Science", "Deptt. of CS - Dr. V.S. Dixit");
        courseMap.put("B.Sc. (Hons.) Mathematics", "Deptt. of Maths - Dr. Raj Kumar Bhagat");
        courseMap.put("B.A. (Hons.) English", "Deptt. of English - Dr. Shubha Dwivedi");
        courseMap.put("B.A. (Hons.) Economics", "Deptt. of Economics - Dr. Arpa Sinha");
        courseMap.put("B.Com. (Hons.)", "Deptt. of Commerce - Dr. Manika Jain");

        ListView listView = (ListView) findViewById(R.id.listView);
        ArrayAdapter<String> adapter = new ArrayAdapter<String>(this,
                R.layout.list_item, R.id.textView, courseMap.keySet().toArray(new String[0]));
        listView.setAdapter(adapter);

        listView.setOnItemClickListener(new AdapterView.OnItemClickListener(){
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                String value = courseMap.get(adapter.getItem(position));
                Snackbar.make(listView, value,
                        Snackbar.LENGTH_LONG).show();
            }
        });
    }
}