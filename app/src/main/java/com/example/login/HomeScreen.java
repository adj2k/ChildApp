package com.example.login;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class HomeScreen extends AppCompatActivity implements View.OnClickListener {



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_home_screen);

        Button button1 = findViewById(R.id.button1);
        Button button2 = findViewById(R.id.button2);
        Button button3 = findViewById(R.id.button3);
        Button button4 = findViewById(R.id.button4);

        button1.setOnClickListener(this);
        button2.setOnClickListener(this);
        button3.setOnClickListener(this);
        button4.setOnClickListener(this);

    }
    //  Assign buttons to correct pages
    @Override
    public void onClick(View v) {
        switch (v.getId()){
            case R.id.button1:
                Intent intent = new Intent(getApplicationContext(), ChooseGameActivity.class);
                startActivity(intent);
                break;
            case R.id.button2:
                intent = new Intent(getApplicationContext(),Statistics.class);
                startActivity(intent);
                break;
            case R.id.button3:
                intent = new Intent(getApplicationContext(), levelTracking.class);
                startActivity(intent);
                break;
            case R.id.button4:
                intent = new Intent(getApplicationContext(), profilePage.class);
                startActivity(intent);
                break;

        }
    }

    //    The drop down menu for homepage
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.my_menu, menu);
        return super.onCreateOptionsMenu(menu);
    }

    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {
        switch (item.getItemId()) {
            case R.id.logOut:
                Toast.makeText(this, "log out", Toast.LENGTH_SHORT).show();
                return true;

            default:
                return super.onOptionsItemSelected(item);
        }
    }
}
