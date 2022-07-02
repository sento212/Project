package edu.ftiuksw.testapi;

import retrofit2.Retrofit;
import retrofit2.converter.gson.GsonConverterFactory;

public class RetrofitClient {

    //SINGLETON

    private static Retrofit retrofit;
    private static final String BASE_URL = "https://my-json-server.typicode.com/pratyaksaocsa/testgit/";

    public static Retrofit getRetrofitClient() {
        if(retrofit == null) {
            //HttpLoggingInterceptor interceptor = new HttpLoggingInterceptor();
            //interceptor.setLevel(HttpLoggingInterceptor.Level.BODY);
            //OkHttpClient client = new OkHttpClient.Builder().addInterceptor(interceptor).build();
            retrofit = new Retrofit.Builder().
                    baseUrl(BASE_URL)./*client(client).*/
                    addConverterFactory(GsonConverterFactory.create()).
                    build();
        }
        return retrofit;
    }
}
