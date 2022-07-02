package com.sento.hope;

import com.google.android.gms.tasks.Task;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;

import java.util.HashMap;

public class Dao {
    private DatabaseReference mFirebaseDatabase;
    public Dao(){
        FirebaseDatabase db = FirebaseDatabase.getInstance();
        mFirebaseDatabase = db.getReference(save_point.class.getSimpleName());
    }
public Task<Void> add(save_point sp)
{
    return mFirebaseDatabase.push().setValue(sp);
}
public Task<Void> update(String key, HashMap<String ,Object> hashMap)
{
    return mFirebaseDatabase.child(key).updateChildren(hashMap);
}
}
