package com.example.login;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class ChooseGameActivity extends AppCompatActivity
{
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.choose_game_activity);

        Button agesRange5to7Button = findViewById(R.id.Ages5To7Button);
        agesRange5to7Button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                setAgeRangeTo5To7();
            }
        });

        Button agesRange7to8Button = findViewById(R.id.Age7To8Button);
        agesRange7to8Button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                setAgeRangeTo7To8();
            }
        });

        Button agesRange8to10Button = findViewById(R.id.Age8To10Button);
        agesRange8to10Button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                setAgeRangeTo8To10();
            }
        });

        Button startGameButton = findViewById(R.id.StartGameButton);
        startGameButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                switchToGameActivity();
            }
        });


    }

    private void switchToGameActivity()
    {
        Intent switchActivityIntent = new Intent(this, GameActivity.class);
        startActivity(switchActivityIntent);
        startGame();
    }

    public native void setAgeRangeTo5To7();
    public native void setAgeRangeTo7To8();
    public native void setAgeRangeTo8To10();

    public native void startGame();
}