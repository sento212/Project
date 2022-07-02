package com.sento.last_tugs2;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class login extends AppCompatActivity {

    private EditText LoginUsername, LoginPassword;
        private Button buttonLogin;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);

        LoginUsername = findViewById(R.id.LoginUsername);
        LoginPassword = findViewById(R.id.loginPassword);
        buttonLogin = findViewById(R.id.buttonLogin);



    }

    public void login2(View v){
        String username = LoginUsername.getText().toString();
        String password = LoginPassword.getText().toString();
        Intent intent = getIntent();
        String user = intent.getStringExtra("user");
        String pass = intent.getStringExtra("pass");
        if(username.equals(user)&&password.equals(pass)){
            Intent intent2 = new Intent(this, home.class);
            intent2.putExtra("user2",username);
            startActivity(intent2);
        }
        else if(username.length()==0)
        {
            LoginUsername.setError("");
            Toast.makeText(getBaseContext(),"Username field is empty",Toast.LENGTH_LONG).show();
        }
        else if(password.length()==0)
        {
            LoginPassword.setError("");
            Toast.makeText(getBaseContext(),"Password Field is empty",Toast.LENGTH_LONG).show();
        }
        else if(!username.equals(user))
        {
            LoginUsername.setError("");
            Toast.makeText(getBaseContext(),"Wrong Username",Toast.LENGTH_LONG).show();
        }
        else if(!password.equals(pass))
        {
            LoginPassword.setError("");
            Toast.makeText(getBaseContext(),"Wrong Password",Toast.LENGTH_LONG).show();
        }
    }
}