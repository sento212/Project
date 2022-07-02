package com.sento.multi2;

import android.content.Context;
import android.content.pm.PackageManager;
import android.content.res.Resources;
import android.database.Cursor;
import android.database.MergeCursor;
import android.net.Uri;
import android.os.Build;
import android.provider.MediaStore;
import android.util.DisplayMetrics;

import androidx.core.app.ActivityCompat;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.HashMap;

public class Function {

    static final String KEY_ALBUM = "album";
    static final String KEY_PATH = "path";
    static final String KEY_TIMESTAMP = "timestamp";
    static final String KEY_TIME = "time";
    static final String KEY_COUNT = "count";

    public static boolean hasPermissions(Context context, String[] permissions) {
        if(Build.VERSION.SDK_INT >= Build.VERSION_CODES.M &&
            context != null && permissions != null) {
            for(String permission : permissions) {
                if(ActivityCompat.checkSelfPermission(context, permission) != PackageManager.PERMISSION_GRANTED) {
                    return false;
                }
            }
        }
        return true;
    }

    public static float convertDpToPixel(float dp, Context context) {
        Resources resources = context.getResources();
        DisplayMetrics displayMetrics = resources.getDisplayMetrics();
        float px = dp * (displayMetrics.densityDpi / 160f);
        return px;
    }

    public static HashMap<String, String> mappingData(String album, String path, String timestamp, String time, String count) {
        HashMap<String, String> map = new HashMap<>();
        map.put(KEY_ALBUM, album);
        map.put(KEY_PATH, path);
        map.put(KEY_TIMESTAMP, timestamp);
        map.put(KEY_TIME, time);
        map.put(KEY_COUNT, count);
        return map;
    }

    public static String convertToTime(String timestamp) {
        long datetime = Long.parseLong(timestamp);
        Date date = new Date(datetime);
        DateFormat dateFormat = new SimpleDateFormat("dd/MM HH:mm");
        return dateFormat.format(date);
    }

    public static String getCounts(Context context, String albumName) {
        Uri uriInternal = MediaStore.Images.Media.INTERNAL_CONTENT_URI;
        Uri uriExternal = MediaStore.Images.Media.EXTERNAL_CONTENT_URI;

        String[] projection = {MediaStore.MediaColumns.DATA};
        Cursor cursorInternal =
                context.getContentResolver().query(uriInternal, projection, null, null, null);
        Cursor cursorExternal =
                context.getContentResolver().query(uriExternal, projection, null, null, null);
        Cursor mergeCursor = new MergeCursor(new Cursor[] {cursorExternal, cursorInternal});
        return mergeCursor.getCount() + " Photos";
    }
}
