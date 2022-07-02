package edu.ftiuksw.testapi;

import java.util.ArrayList;

import retrofit2.Call;
import retrofit2.http.GET;
import retrofit2.http.Headers;
import retrofit2.http.Query;

public interface APIList {

    @GET("mahasiswa")
    Call<ArrayList<Mahasiswa>> getAllMahasiswa();

    @GET("pegawai")
    Call<ArrayList<Pegawai>> getAllPegawai();

    @Headers({"Accept: application/json"})
    @GET("mahasiswa")
    Call<ArrayList<Mahasiswa>> getMahasiswaByNIM(@Query("nim") String nim);
}
