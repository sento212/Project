package com.ocsa.tutorialandroidgallery;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;

import android.Manifest;
import android.content.pm.PackageManager;
import android.content.res.Resources;
import android.database.Cursor;
import android.database.MergeCursor;
import android.net.Uri;
import android.os.AsyncTask;
import android.os.Bundle;
import android.provider.MediaStore;
import android.util.DisplayMetrics;
import android.widget.GridView;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;

public class MainActivity extends AppCompatActivity {

    GridView galleryGridView;
    LoadAlbum loadAlbumTask;
    static final int REQUEST_PERMISSION_CODE = 1;
    ArrayList<HashMap<String, String>> albumList = new ArrayList<>();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        galleryGridView = findViewById(R.id.gridViewGallery);

        int iDisplayWidth = getResources().getDisplayMetrics().widthPixels;
        Resources resources = getApplicationContext().getResources();
        DisplayMetrics displayMetrics = resources.getDisplayMetrics();
        float dp = iDisplayWidth / (displayMetrics.densityDpi / 160f);
        if(dp < 360) {
            dp = (dp - 17) / 2;
            float px = Function.convertDpToPixel(dp, getApplicationContext());
            galleryGridView.setColumnWidth(Math.round(px));
        }

        String permissions[] = {Manifest.permission.READ_EXTERNAL_STORAGE, Manifest.permission.WRITE_EXTERNAL_STORAGE};
        if(!Function.hasPermissions(this, permissions)) {
            ActivityCompat.requestPermissions(this, permissions, REQUEST_PERMISSION_CODE);
        }
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
        switch (requestCode) {
            case REQUEST_PERMISSION_CODE:
                if(grantResults.length > 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
                    loadAlbumTask = new LoadAlbum();
                    loadAlbumTask.execute();
                } else {
                    Toast.makeText(this,
                            "You must choose 'allow' to make this application work properly",
                            Toast.LENGTH_LONG).show();
                }
        }
    }

    class LoadAlbum extends AsyncTask<String, Void, String> {

        @Override
        protected void onPreExecute() {
            super.onPreExecute();
            albumList.clear();
        }

        @Override
        protected String doInBackground(String... strings) {
            Uri uriInternal = MediaStore.Images.Media.INTERNAL_CONTENT_URI;
            Uri uriExternal = MediaStore.Images.Media.EXTERNAL_CONTENT_URI;

            String[] projection = {MediaStore.MediaColumns.DATA,
                    MediaStore.MediaColumns.BUCKET_DISPLAY_NAME, MediaStore.MediaColumns.BUCKET_ID,
                    MediaStore.MediaColumns.DATE_MODIFIED};
            Cursor cursorInternal =
                    getContentResolver().query(uriInternal, projection, null, null, null);
            Cursor cursorExternal =
                    getContentResolver().query(uriExternal, projection, null, null, null);
            Cursor mergeCursor = new MergeCursor(new Cursor[] {cursorExternal, cursorInternal});
            while (mergeCursor.moveToNext()) {
                String path = mergeCursor.getString(mergeCursor.getColumnIndex(MediaStore.MediaColumns.DATA));
                String album = mergeCursor.getString(mergeCursor.getColumnIndex(MediaStore.MediaColumns.BUCKET_DISPLAY_NAME));
                String timestamp = mergeCursor.getString(mergeCursor.getColumnIndex(MediaStore.MediaColumns.DATE_MODIFIED));
                String time = Function.convertToTime(timestamp);
                String count = Function.getCounts(getApplicationContext(), album);
                albumList.add(Function.mappingData(album, path, timestamp, time, count));
            }
            mergeCursor.close();

            Collections.sort(albumList, new MapComparator(Function.KEY_TIMESTAMP, "desc"));
            return "";
        }

        @Override
        protected void onPostExecute(String s) {
            super.onPostExecute(s);

            AlbumAdapter albumAdapter = new AlbumAdapter(MainActivity.this, albumList);
            galleryGridView.setAdapter(albumAdapter);
        }
    }

    @Override
    protected void onResume() {
        super.onResume();
        String permissions[] = {Manifest.permission.READ_EXTERNAL_STORAGE, Manifest.permission.WRITE_EXTERNAL_STORAGE};
        if(!Function.hasPermissions(this, permissions)) {
            ActivityCompat.requestPermissions(this, permissions, REQUEST_PERMISSION_CODE);
        } else {
            loadAlbumTask = new LoadAlbum();
            loadAlbumTask.execute();
        }
    }
}