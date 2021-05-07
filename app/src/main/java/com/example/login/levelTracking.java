package com.example.leveltrackingmodel;

import androidx.appcompat.app.ActionBar;
import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import java.text.BreakIterator;

public class MainActivity<JNIEXPORT> extends AppCompatActivity {

    Button userPoints;
    Button userCurrentLevel;
    Button Achievements;
    int level = 0;
    int amountOfPoints;
    int currentLevel;
    private int Congratulations;

    public void levelTracking(View v){
        //level up after 50 points
        level = amountOfPoints/50;

    }
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Achievements = findViewById(R.id.Achievements);
        Achievements.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //level up after 50 points
                level = amountOfPoints/50;
                Toast.makeText(getApplicationContext(), "You've made it to level " + level, Toast.LENGTH_SHORT).show();

            }
        });
        userPoints = findViewById(R.id.userPoints);
        userPoints.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int totalQuestions = 25;
                int questionsCorrect = 0;
                int pointPerQuestion = 4;
                int totalPoints = 0;
                int goalPoints = 100;

                totalPoints = questionsCorrect*pointPerQuestion;
                Toast.makeText(getApplicationContext(), "You've earned " + amountOfPoints + " points", Toast.LENGTH_SHORT).show();

            }
        });
        userCurrentLevel = findViewById(R.id.userCurrentLevel);
        userCurrentLevel.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                currentLevel = level;
                Toast.makeText(getApplicationContext(), "Your current level is " + currentLevel, Toast.LENGTH_SHORT).show();

            }
        });
    }

 




   /* public void pointRewardSystem(View v) {
        //need track of how many questions they got right
        int questionsRight = 0;
        int pointPerQuestion = 4;
        int totalPoints = 0;
        int goalPoints = 100;

        totalPoints = questionsRight*pointPerQuestion;
        System.out.println("Total amount of points gained is: " + totalPoints);
*/



       /* BreakIterator input = null;
        int correctAnswer = Integer.parseInt(input.getText().toString());
        int wrongAnswer = 0;
        int rewardStatement;
        int userInput = 0;
        int points = 0;
        rewardStatement = Congratulations;
        BreakIterator message = null;
        if(userInput == correctAnswer){
            message.setText("Congratulations");
        }else if (userInput == wrongAnswer){
            message.setText("Try Again");
        }else{
            message.setText("You gained " + points + "points");

        }

        */
    }

   /* public class Reward {

        {

            {
                EditText input;
                TextView message;
                int TotalPoints = 4;
                int midRange = 50;
                int fullRange = 100;
                int belowRange = 25;

                @Override
                protected void onCreate (Bundle savedInstanceState){
                super.onCreate(savedInstanceState);
                setContentView(R.layout.activity_main);

                input = (EditText) findViewById(R.id.input);
                message = (TextView) findViewById(R.id.message);
            }
            }

            public void pointsGained (View v){
            int Results = Integer.parseInt(input.getText().toString());

            if (pointsGained < belowRange) {
                message.setText("Recovery Student");
            } else if (pointsGained < midRange) {
                message.setText("Dedicated Solver");
            }else{
                message.setText("Proficient Solver")
            }


        }
        }
    }

    */
