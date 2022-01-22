package com.anshul.practical12;

import androidx.appcompat.app.AppCompatActivity;

import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.widget.ListView;

import java.util.ArrayList;
import java.util.List;

public class ViewAllActivity extends AppCompatActivity {

    List<Student> studentList;
    SQLiteDatabase studentsDB;
    ListView listViewStudents;
    StudentAdapter adapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_view_all);

        listViewStudents = (ListView) findViewById(R.id.listViewStudents);
        studentList = new ArrayList<>();
        studentsDB = openOrCreateDatabase(MainActivity.DATABASE_NAME, MODE_PRIVATE, null);

        Cursor cursorStudents = studentsDB.rawQuery("SELECT * FROM students", null);

        //if the cursor has some data
        if (cursorStudents.moveToFirst()) {
            //looping through all the records
            do {
                //pushing each record in the list
                studentList.add(new Student(
                        cursorStudents.getInt(0),
                        cursorStudents.getString(1),
                        cursorStudents.getString(2),
                        cursorStudents.getString(3),
                        cursorStudents.getString(4)
                ));
            } while (cursorStudents.moveToNext());
        }
        //closing the cursor
        cursorStudents.close();

        //creating the adapter object
        adapter = new StudentAdapter(this, R.layout.list_layout, studentList, studentsDB);

        //adding the adapter to listview
        listViewStudents.setAdapter(adapter);
    }
}