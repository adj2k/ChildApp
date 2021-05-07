package com.example.login;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;


public class Statistics extends AppCompatActivity
{
    private Button Back;
    public native int getWrong();
    public native int getRight();
    public native int getTotal();

    private TextView Total;
    private TextView Right;
    private TextView Wrong;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_statistics);
        int t = getTotal();
        int r = getRight();
        int w = getWrong();

        Back = (Button) findViewById(R.id.backButton);
        Total = (TextView) findViewById(R.id.total);
        Total.setText(t, TextView.BufferType.NORMAL);

        Right = (TextView) findViewById(R.id.right);
        Right.setText(r, TextView.BufferType.NORMAL);

        Wrong = (TextView) findViewById(R.id.wrong);
        Wrong.setText(w, TextView.BufferType.NORMAL);

        Back.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View view)
            {
                Intent toHomeScreen = new Intent (Statistics.this, HomeScreen.class);
                startActivity(toHomeScreen);
            }
        });
    }

}
