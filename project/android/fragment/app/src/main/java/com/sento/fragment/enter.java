package com.sento.fragment;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ListView;

public class enter extends AppCompatActivity {
    ListView listView;
    private EditText title, content;
    private Button button;
    int a;
    @Override
    protected void onCreate( Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.input);
        title = findViewById(R.id.title2);
        content = findViewById(R.id.content2);
        button = findViewById(R.id.button);

    }

    public void return2(View v){

        String Title = title.getText().toString();
        String Content = content.getText().toString();
        Intent intent = new Intent(this, MainActivity.class);
        intent.putExtra("title", Title);
        intent.putExtra("content", Content);
        startActivity(intent);


    }

}
