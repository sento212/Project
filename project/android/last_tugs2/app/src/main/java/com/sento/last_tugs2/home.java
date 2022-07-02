package com.sento.last_tugs2;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.widget.TextView;

public class home extends AppCompatActivity {
TextView txtWelcome;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.home);
        txtWelcome = findViewById(R.id.txtWelcome);

        Intent intent2 = getIntent();
        String user = intent2.getStringExtra("user2");
        txtWelcome.setText("Welcome, "+user);
    }
}