package com.example.login;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class LogIn extends AppCompatActivity
{

    public SQLiteOpenHelper openHelper;
    public SQLiteDatabase db;

    private EditText Username;
    private EditText Password;
    private Button Login;
    private int counter = 5;
    private TextView CreateAccountTXT;
    Cursor cursor;




    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);

        openHelper = new Database(this);
        db= openHelper.getReadableDatabase();
        Username = (EditText) findViewById(R.id.etUserName);
        Password = (EditText) findViewById(R.id.etPassword);
        Login = (Button) findViewById(R.id.btnLogin);
        CreateAccountTXT = (TextView) findViewById(R.id.tvCreateAccount);



        Login.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View view)
            {
                String username = Username.getText().toString();
                String password = Password.getText().toString();
                cursor = db.rawQuery(" SELECT * FROM " + Database.TABLE_NAME + " WHERE " + Database.COL_4 + " =? AND " + Database.COL_5 + " =? ", new String[]{username, password});
                if (cursor != null)
                {
                    if (cursor.getCount() > 0)
                    {
                        Intent toHomeScreen = new Intent (LogIn.this, HomeScreen.class);
                        startActivity(toHomeScreen);
                        Toast.makeText(getApplicationContext(), "Login Successful!", Toast.LENGTH_LONG).show();
                    }
                    else
                        {
                        counter--;
                        Toast.makeText(getApplicationContext(), "Incorrect username or password", Toast.LENGTH_SHORT).show();

                        if (counter == 0)
                        {

                            Toast.makeText(getApplicationContext(), "Your account has been locked due to too many failed attempts.", Toast.LENGTH_SHORT).show();
                            Login.setEnabled(false);
                        }
                    }
                }
            }
        });

        CreateAccountTXT.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View view)
            {
                startActivity(new Intent(LogIn.this, CreateAccount.class));
            }

        });

    }
}