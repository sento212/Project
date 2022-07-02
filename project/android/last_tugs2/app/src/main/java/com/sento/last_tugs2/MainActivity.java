package com.sento.last_tugs2;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.text.TextUtils;
import android.util.Patterns;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import org.w3c.dom.Text;

public class MainActivity extends AppCompatActivity {

    private EditText TextUsername,TextName, TextPassword, TextCPassword;
    private Button  buttonRegister;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        TextUsername = findViewById(R.id.TextUsername);
        TextName = findViewById(R.id.TextName);
        TextPassword = findViewById(R.id.TextPassword);
        TextCPassword = findViewById(R.id.TextCPassword);
        buttonRegister = findViewById(R.id.buttonRegister);
    }


    public void login(View v){
        String username = TextUsername.getText().toString();
        String name = TextName.getText().toString();
        String password = TextPassword.getText().toString();
        String Cpassword = TextCPassword.getText().toString();
        if(username.length()==0){
            TextUsername.setError("");
            Toast.makeText(getBaseContext(),"Username Field is empty",Toast.LENGTH_LONG).show();
        }
        else if(name.length()==0)
        {
            TextName.setError("");
            Toast.makeText(getBaseContext(),"Name Field is empty",Toast.LENGTH_LONG).show();
        }
        else if(password.length()==0)
        {
            TextPassword.setError("");
            Toast.makeText(getBaseContext(),"Password Field is empty",Toast.LENGTH_LONG).show();
        }
        else if(Cpassword.length()==0)
        {
            TextCPassword.setError("");
            Toast.makeText(getBaseContext(),"Confrim Password Field is empty",Toast.LENGTH_LONG).show();
        }

        else if(!Cpassword.equals(password))
        {
            TextCPassword.setError("");
            Toast.makeText(getBaseContext(),"Unidentical Confrim Password with password",Toast.LENGTH_LONG).show();
        }
        else {
            Intent intent = new Intent(this, login.class);
            intent.putExtra("user", username);
            intent.putExtra("pass", password);
            startActivity(intent);
        }
    }
}