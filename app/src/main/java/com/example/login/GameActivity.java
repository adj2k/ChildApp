package com.example.login;

import androidx.annotation.RequiresApi;
import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;

import android.content.Context;
import android.content.Intent;
import android.os.Build;
import android.os.Bundle;
import android.view.Gravity;
import android.view.View;
import android.view.LayoutInflater;
import android.view.ViewGroup.LayoutParams;
import android.widget.Button;
import android.widget.PopupWindow;
import android.widget.TextView;
import android.widget.Toast;

import com.google.android.material.textfield.TextInputEditText;

public class GameActivity extends AppCompatActivity
{
    static {
        System.loadLibrary("native-lib");
    }
    TextView questionTextView;
    TextView gameInfoTextView;
    TextView gameProgressTextView;
    TextInputEditText submissionBoxInput;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.game_activity);

        questionTextView = findViewById(R.id.QuestionText);
        questionTextView.setText(getQuestion());

        gameInfoTextView = findViewById(R.id.GameInfoText);
        gameInfoTextView.setText(getGameDetails());
        
        gameProgressTextView = findViewById(R.id.GameProgressText);
        gameProgressTextView.setText(getQuestionsAmount());

        submissionBoxInput = findViewById(R.id.SubmissionBoxInput);



        Button submitButton = findViewById(R.id.SubmitButton);
        submitButton.setOnClickListener(new View.OnClickListener() {
            @RequiresApi(api = Build.VERSION_CODES.M)
            @Override
            public void onClick(View v) {
                boolean correct = submitAnswer(submissionBoxInput.getText().toString());

                if (correct){
                    Toast.makeText(getApplicationContext(), "Correct answer", Toast.LENGTH_SHORT).show();
                    correctQuestion();
                    if (isGameOver())
                    {
                        endGame();
                        switchToChooseGame();
                    }
                }
                else{
                    Toast.makeText(getApplicationContext(), "Incorrect answer", Toast.LENGTH_SHORT).show();
                    incorrectQuestion();
                    if (isGameOver()){
                        endGame();
                        switchToChooseGame();
                    }
                }
                questionTextView.setText(getQuestion());
                gameProgressTextView.setText(getQuestionsAmount());
            }
        });


    }

    void switchToChooseGame()
    {
        Intent switchActivityIntent = new Intent(this, ChooseGameActivity.class);
        startActivity(switchActivityIntent);
    }

    public native String getGameDetails();
    public native String getQuestion();
    public native boolean submitAnswer(String answer);
    public native void correctQuestion();
    public native void incorrectQuestion();
    public native boolean isGameOver();
    public native void endGame();
    public native String getQuestionsAmount();
}