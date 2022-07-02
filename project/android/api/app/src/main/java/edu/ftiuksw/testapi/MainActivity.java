package edu.ftiuksw.testapi;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.ArrayList;

import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;

public class MainActivity extends AppCompatActivity {

    private TextView txtNama,txtNama1;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        txtNama = findViewById(R.id.txtNama);
        txtNama1 = findViewById(R.id.txtNama1);
    }

    public void GetDataFromServer(View v) {
        APIList apis = RetrofitClient.getRetrofitClient().create(APIList.class);
        Call<ArrayList<Mahasiswa>> call = apis.getAllMahasiswa();
        Call<ArrayList<Pegawai>> call2 = apis.getAllPegawai();
        /*//Use this code instead when you want to create a request with header & parameter
        Call<ArrayList<Mahasiswa>> call = apis.getMahasiswaByNIM("992017547");
        * */
        call.enqueue(new Callback<ArrayList<Mahasiswa>>() {
            @Override
            public void onResponse(Call<ArrayList<Mahasiswa>> call, Response<ArrayList<Mahasiswa>> response) {
                if(response.isSuccessful()) {
                    ArrayList<Mahasiswa> data = response.body();
                    Log.i("MyLog", data.size()+"");

txtNama1.setText("get data from mahasiswa : "+data.get(1).getNama()+"\n");

                }
            }

            @Override
            public void onFailure(Call<ArrayList<Mahasiswa>> call, Throwable t) {
                Log.e("MyLog", t.getCause().getMessage());
                Toast.makeText(getApplicationContext(),"Something wrong. Please try again later.",Toast.LENGTH_SHORT).show();
            }
        });

        call2.enqueue(new Callback<ArrayList<Pegawai>>() {
            @Override
            public void onResponse(Call<ArrayList<Pegawai>> call, Response<ArrayList<Pegawai>> response) {
                String number = null;
                BigDecimal a = new BigDecimal("0");
float aa;

                if(response.isSuccessful()) {
                    ArrayList<Pegawai> data = response.body();
                    Log.i("MyLog", data.size()+"");

                        for(int x = 0; x < data.size(); x++)
                        {
                            number = data.get(x).getSalary();
                            number = number.replaceAll("\\D+","");
                            BigDecimal d = new BigDecimal(number);
                            a = a.add(d);

                        }
                        a = a.divide(BigDecimal.valueOf(data.size()));
                        String sala = a.toString();
                        String sala2 = new StringBuilder().append(sala.substring(0,3)).append(",").append(sala.substring(3,6)).append(",").append(sala.substring(6,12)).toString();
                    txtNama.setText("The average salary of employees : Rp. "+sala2);

                }
            }

            @Override
            public void onFailure(Call<ArrayList<Pegawai>> call, Throwable t) {
                Log.e("MyLog", t.getCause().getMessage());
                Toast.makeText(getApplicationContext(),"Something wrong. Please try again later.",Toast.LENGTH_SHORT).show();
            }
        });
    }
}
