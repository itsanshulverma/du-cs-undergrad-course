package com.anshul.practical12;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.Spinner;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    public static final String DATABASE_NAME = "student_info";

    TextView textViewViewStudents;
    EditText editTextName, editTextEmail, editTextRollNo;
    Spinner spinnerCourses;
    RadioGroup rgGender;
    Button btnAdd;

    SQLiteDatabase studentsDB;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        textViewViewStudents = (TextView) findViewById(R.id.textViewViewAll);
        editTextRollNo = (EditText) findViewById(R.id.editTextRollNo);
        editTextName = (EditText) findViewById(R.id.editTextName);
        editTextEmail = (EditText) findViewById(R.id.editTextEmail);
        spinnerCourses = (Spinner) findViewById(R.id.spinnerCourse);
        rgGender = (RadioGroup) findViewById(R.id.radioGroupGender);
        btnAdd = (Button) findViewById(R.id.buttonAdd);

        btnAdd.setOnClickListener(this);
        textViewViewStudents.setOnClickListener(this);
        ArrayAdapter adapter = ArrayAdapter.createFromResource(this,
                R.array.courses, R.layout.spinner_item);
        spinnerCourses.setAdapter(adapter);

        studentsDB = openOrCreateDatabase(DATABASE_NAME, MODE_PRIVATE, null);
    }

    private boolean validateInput(String rollNo, String name, String email) {

        if (rollNo.isEmpty()) {
            editTextRollNo.setError("Please enter a name");
            editTextRollNo.requestFocus();
            return false;
        }

        if (name.isEmpty()) {
            editTextName.setError("Please enter a name");
            editTextName.requestFocus();
            return false;
        }

        if (email.isEmpty() || !email.contains("@")) {
            editTextEmail.setError("Please enter an email.");
            editTextEmail.requestFocus();
            return false;
        }
        return true;
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.buttonAdd:
                addStudent();
                break;
            case R.id.textViewViewAll:
                startActivity(new Intent(this, ViewAllActivity.class));
                break;
        }
    }

    private void addStudent() {
        // Creating the table
        studentsDB.execSQL(
                "CREATE TABLE IF NOT EXISTS students (\n" +
                        "id int NOT NULL CONSTRAINT students_pk PRIMARY KEY,\n" +
                        "name varchar(200) NOT NULL,\n" +
                        "email varchar(200) NOT NULL,\n" +
                        "gender char(10) NOT NULL,\n" +
                        "course varchar(200) NOT NULL\n" +
                        ");"
        );

        // Adding data to table
        String rollNo = editTextRollNo.getText().toString().trim();
        String name = editTextName.getText().toString().trim();
        String email = editTextEmail.getText().toString().trim();
        String course = spinnerCourses.getSelectedItem().toString().trim();

        int id = rgGender.getCheckedRadioButtonId();
        RadioButton radioBtn = (RadioButton) findViewById(id);
        String gender = radioBtn.getText().toString().trim();

        if (validateInput(rollNo, name, email)) {
            int rollNumber = Integer.parseInt(rollNo);
            String insertSQL = "INSERT INTO students \n" +
                    "(id, name, email, gender, course)\n" +
                    "VALUES \n" +
                    "("+rollNumber+", ?, ?, ?, ?);";
            studentsDB.execSQL(insertSQL, new String[]{name, email, gender, course});

            Toast.makeText(this, "Student Added Successfully!", Toast.LENGTH_SHORT).show();

            editTextRollNo.setText("");
            editTextName.setText("");
            editTextEmail.setText("");
        }
    }
}