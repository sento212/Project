package com.sento.hope;

import androidx.fragment.app.FragmentActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.google.android.gms.maps.CameraUpdateFactory;
import com.google.android.gms.maps.GoogleMap;
import com.google.android.gms.maps.OnMapReadyCallback;
import com.google.android.gms.maps.SupportMapFragment;
import com.google.android.gms.maps.model.BitmapDescriptorFactory;
import com.google.android.gms.maps.model.LatLng;
import com.google.android.gms.maps.model.Marker;
import com.google.android.gms.maps.model.MarkerOptions;
import com.sento.hope.databinding.ActivityMapsBinding;

import java.util.HashMap;
import java.util.Random;

public class MapsActivity extends FragmentActivity implements OnMapReadyCallback, GoogleMap.OnMapClickListener{

    private GoogleMap mMap;
    private ActivityMapsBinding binding;
    private EditText latd, lotd;
    private Button save12;
    Marker markerName = null;
    SupportMapFragment mapFragment;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMapsBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        // Obtain the SupportMapFragment and get notified when the map is ready to be used.
         mapFragment = (SupportMapFragment) getSupportFragmentManager().findFragmentById(R.id.map);
        mapFragment.getMapAsync(this);

        latd = findViewById(R.id.latd);
        lotd = findViewById(R.id.lotd);
        save12 = findViewById(R.id.save12);


    }

    /**
     * Manipulates the map once available.
     * This callback is triggered when the map is ready to be used.
     * This is where we can add markers or lines, add listeners or move the camera. In this case,
     * we just add a marker near Sydney, Australia.
     * If Google Play services is not installed on the device, the user will be prompted to install
     * it inside the SupportMapFragment. This method will only be triggered once the user has
     * installed Google Play services and returned to the app.
     */
    @Override
    public void onMapReady(GoogleMap googleMap) {
        mMap = googleMap;

        // Add a marker in Sydney and move the camera
        LatLng sydney = new LatLng(-34, 151);
        mMap.moveCamera(CameraUpdateFactory.newLatLng(sydney));

        if (markerName == null )
        {
         mMap.setOnMapClickListener(this);
        }
        if (markerName !=null)
        {
            mMap.setOnMapClickListener(null);
        }
    }

    @Override
    public void onMapClick(LatLng latLng) {

           if (markerName == null)
           {
               markerName = mMap.addMarker(new MarkerOptions().position(latLng).title("new marker").icon(BitmapDescriptorFactory.defaultMarker(new Random().nextInt(360))));
               latd.setText(""+latLng.latitude);
               lotd.setText(""+latLng.longitude);
               mMap.getUiSettings().setAllGesturesEnabled(false);
           }


        Dao dao =new Dao();
        save12.setOnClickListener(view ->
                {
                    HashMap<String,Object> hashMap = new HashMap<>();
                    hashMap.put("latitude",latd.getText().toString());
                    hashMap.put("longtitude",lotd.getText().toString());
                    dao.update("-MzlMDG_rhCwVAd21Fv-",hashMap).addOnSuccessListener(suc->
                    {
                        Toast.makeText(this,"data saved",Toast.LENGTH_SHORT).show();
                    });
                    markerName=null;
                    mMap.getUiSettings().setAllGesturesEnabled(true);
                }
        );

    }

}