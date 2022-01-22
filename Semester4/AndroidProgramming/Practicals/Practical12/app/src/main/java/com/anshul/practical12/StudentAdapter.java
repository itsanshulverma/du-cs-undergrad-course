package com.anshul.practical12;

import android.content.Context;
import android.database.Cursor;
import android.view.View;
import android.content.DialogInterface;
import android.database.sqlite.SQLiteDatabase;
import android.view.LayoutInflater;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AlertDialog;
import androidx.constraintlayout.widget.ConstraintLayout;

import com.google.android.material.snackbar.Snackbar;

import java.util.List;

public class StudentAdapter extends ArrayAdapter<Student> {

    Context mCtx;
    int listLayoutRes;
    List<Student> studentList;
    SQLiteDatabase studentDB;

    public StudentAdapter(Context mCtx, int listLayoutRes, List<Student> studentList, SQLiteDatabase studentDB) {
        super(mCtx, listLayoutRes, studentList);

        this.mCtx = mCtx;
        this.listLayoutRes = listLayoutRes;
        this.studentList = studentList;
        this.studentDB = studentDB;
    }

    public void updateStudent(Student student){
        AlertDialog.Builder builder = new AlertDialog.Builder(mCtx);

        LayoutInflater inflater = LayoutInflater.from(mCtx);
        View view = inflater.inflate(R.layout.update_layout, null);
        builder.setView(view);

        EditText editTextRollNo = (EditText) view.findViewById(R.id.editTextRollNo);
        EditText editTextName = (EditText) view.findViewById(R.id.editTextName);
        EditText editTextEmail = (EditText) view.findViewById(R.id.editTextEmail);
        Spinner spinnerCourses = (Spinner) view.findViewById(R.id.spinnerCourse);
        Button btnUpdate = (Button) view.findViewById(R.id.buttonUpdate);

        editTextName.setText(student.getName());
        editTextRollNo.setText(String.valueOf(student.getRollNo()));
        editTextEmail.setText(student.getEmail());
        TextView genderTV = view.findViewById(R.id.tVGender);
        genderTV.setText("Gender: "+student.getGender());
        ArrayAdapter adapter = ArrayAdapter.createFromResource(mCtx,
                R.array.courses, R.layout.spinner_item);
        spinnerCourses.setAdapter(adapter);

        final AlertDialog dialog = builder.create();
        dialog.show();

        btnUpdate.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String rollNo = editTextRollNo.getText().toString().trim();
                String name = editTextName.getText().toString().trim();
                String email = editTextEmail.getText().toString().trim();
                String course = spinnerCourses.getSelectedItem().toString().trim();

                if (rollNo.isEmpty()) {
                    editTextRollNo.setError("Please enter a name");
                    editTextRollNo.requestFocus();
                }

                if (name.isEmpty()) {
                    editTextName.setError("Please enter a name");
                    editTextName.requestFocus();
                }

                if (email.isEmpty() || !email.contains("@")) {
                    editTextEmail.setError("Please enter an email.");
                    editTextEmail.requestFocus();
                }

                String sql = "UPDATE students \n" +
                        "SET id = " + rollNo + ", \n" +
                        "name = ?, \n" +
                        "email = ?, \n" +
                        "course = ? \n" +
                        "WHERE id = ?;\n";

                studentDB.execSQL(sql, new String[]{name, email, course, String.valueOf(student.getRollNo())});

                Toast.makeText(mCtx, "Student Updated Successfully!", Toast.LENGTH_SHORT).show();
                reloadStudentsFromDB();

                dialog.dismiss();
            }
        });
    }

    private void reloadStudentsFromDB() {
        Cursor cursorStudents = studentDB.rawQuery("SELECT * FROM students", null);
        if (cursorStudents.moveToFirst()) {
            studentList.clear();
            do {
                studentList.add(new Student(
                        cursorStudents.getInt(0),
                        cursorStudents.getString(1),
                        cursorStudents.getString(2),
                        cursorStudents.getString(3),
                        cursorStudents.getString(4)
                ));
            } while (cursorStudents.moveToNext());
        }
        cursorStudents.close();
        notifyDataSetChanged();
    }

    @NonNull
    @Override
    public View getView(int position, @Nullable View convertView, @NonNull ViewGroup parent) {
        LayoutInflater inflater = LayoutInflater.from(mCtx);
        View view = inflater.inflate(listLayoutRes, null);

        //getting student of the specified position
        Student student = studentList.get(position);

        //getting views
        TextView textViewName = view.findViewById(R.id.textViewName);
        TextView textViewRollNo = view.findViewById(R.id.textViewRollNo);
        TextView textViewGender = view.findViewById(R.id.textViewGender);
        TextView textViewEmail = view.findViewById(R.id.textViewEmail);
        TextView textViewCourse = view.findViewById(R.id.textViewCourse);

        //adding data to views
        textViewName.setText(student.getName());
        textViewRollNo.setText(String.valueOf(student.getRollNo()));
        textViewGender.setText(student.getGender());
        textViewEmail.setText(student.getEmail());
        textViewCourse.setText(student.getCourse());

        //we will use these buttons later for update and delete operation
        Button buttonDelete = view.findViewById(R.id.buttonDeleteStudent);
        Button buttonEdit = view.findViewById(R.id.buttonEditStudent);

        buttonEdit.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                updateStudent(student);
            }
        });

        buttonDelete.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                AlertDialog.Builder builder = new AlertDialog.Builder(mCtx);
                builder.setTitle("Are you sure?");
                builder.setCancelable(false);
                builder.setPositiveButton("Yes", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialogInterface, int i) {
                        String sql = "DELETE FROM students WHERE id = ?";
                        studentDB.execSQL(sql, new Integer[]{student.getRollNo()});
                        reloadStudentsFromDB();
                    }
                });
                builder.setNegativeButton("Cancel", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialogInterface, int i) {
                        dialogInterface.cancel();
                    }
                });
                AlertDialog dialog = builder.create();
                dialog.show();
            }
        });

        return view;
    }
}
