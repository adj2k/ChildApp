package com.example.login;

import androidx.appcompat.app.AppCompatActivity;

import android.content.ContentValues;
import android.content.Intent;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class CreateAccount extends AppCompatActivity
{
   public SQLiteOpenHelper openHelper;
   public SQLiteDatabase db;

   public EditText Name;
   public EditText Email;
   public EditText Username;
   public EditText Password;
   public EditText VerifyPassword;
   public EditText ChildAge;
   public Button CreateAccountBTN;


    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_create_account);

        openHelper=new Database(this);
        Name = (EditText) findViewById(R.id.etNameEntry);
        Email = (EditText) findViewById(R.id.etEmailEntry);
        Username = (EditText) findViewById(R.id.etUserNameEntry);
        Password = (EditText) findViewById(R.id.etPasswordEntry);
        VerifyPassword = (EditText) findViewById(R.id.etPasswordConfirmation);
        ChildAge = (EditText) findViewById(R.id.etChildAgeEntry);
        CreateAccountBTN = (Button) findViewById(R.id.btnCreateAccount);

        CreateAccountBTN.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View view) {

                db = openHelper.getWritableDatabase();
                String dbName = Name.getText().toString();
                String dbEmail = Email.getText().toString();
                String dbUsername = Username.getText().toString();
                String dbPassword = Password.getText().toString();
                String dbChildAge = ChildAge.getText().toString();


                if (dbName.matches("")) {
                    Toast.makeText(getApplicationContext(), "Please enter your name.", Toast.LENGTH_LONG).show();
                } else if (dbEmail.matches("")) {
                    Toast.makeText(getApplicationContext(), "Please enter your email.", Toast.LENGTH_LONG).show();
                } else if (dbUsername.matches("")) {
                    Toast.makeText(getApplicationContext(), "Please enter your username.", Toast.LENGTH_LONG).show();
                } else if (dbPassword.matches("")) {
                    Toast.makeText(getApplicationContext(), "Please enter your password.", Toast.LENGTH_LONG).show();
                } else if (VerifyPassword.getText().toString().matches("")) {
                    Toast.makeText(getApplicationContext(), "Please confirm your password.", Toast.LENGTH_LONG).show();
                } else if (dbChildAge.matches("")) {
                    Toast.makeText(getApplicationContext(), "Please enter your child's age.", Toast.LENGTH_LONG).show();
                }

                else
                {



                    if (Password.getText().toString().equals(VerifyPassword.getText().toString()))  {
                        insertdata(dbName, dbEmail, dbUsername, dbPassword, dbChildAge);
                        startActivity(new Intent(CreateAccount.this, LogIn.class));

                        Toast.makeText(getApplicationContext(), "Account successfully created", Toast.LENGTH_LONG).show();
                    } else {
                        Toast.makeText(getApplicationContext(), "Make sure password's match.", Toast.LENGTH_LONG).show();
                    }

                }
            }
        });

    }

    public void insertdata(String dbName, String dbEmail, String dbUsername, String dbPassword, String dbChildAge)
    {
        ContentValues contentValues = new ContentValues();
        contentValues.put(Database.COL_2, dbName);
        contentValues.put(Database.COL_3, dbEmail);
        contentValues.put(Database.COL_4, dbUsername);
        contentValues.put(Database.COL_5, dbPassword);
        contentValues.put(Database.COL_6, dbChildAge);
        long id = db.insert(Database.TABLE_NAME, null, contentValues);

    }
}