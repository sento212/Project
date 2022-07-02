package com.sento.fragment;


import android.content.Context;
import android.content.Intent;
import android.os.Build;
import android.os.Bundle;
import android.support.v4.app.ListFragment;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.ListView;



public class HeadlinesFragment extends ListFragment {

    OnHeadlineSelectedListener mCallBack;
    public interface OnHeadlineSelectedListener {
        public void onArticleSelected(int position);
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        int layout;
        if(Build.VERSION.SDK_INT >= Build.VERSION_CODES.HONEYCOMB) {
            layout = android.R.layout.simple_list_item_activated_1;
        } else {
            layout = android.R.layout.simple_list_item_1;
        }
        int charactersLimit = 30;
        int charactersLimit2 = 10;
        String[] yourLargeString = Ipsum.article;
        String[] yourLargeString2 = Ipsum.headlines;
        String[] lines2 = new String[yourLargeString.length];
        String S = null;
        String b = null;
        for(int i=0;i<yourLargeString.length;i++)
        {
            S=yourLargeString[i];
            String a = S.substring(0, Math.min(S.length(), charactersLimit));
            b=yourLargeString2[i];
            String c = b.substring(0, Math.min(b.length(), charactersLimit2));
            lines2[i]=c+"..."+ "\n" + a+"...";
        }
        setListAdapter(new ArrayAdapter<String>(getActivity(), layout, lines2));


    }

    @Override
    public void onListItemClick(ListView l, View v, int position, long id) {
        super.onListItemClick(l, v, position, id);
        mCallBack.onArticleSelected(position);
        getListView().setItemChecked(position, true);
    }

    @Override
    public void onStart() {
        super.onStart();
        if(getFragmentManager().findFragmentById(R.id.article_fragment) != null) {
            getListView().setChoiceMode(ListView.CHOICE_MODE_SINGLE);
        }
    }

    @Override
    public void onAttach(Context context) {
        super.onAttach(context);
        try {
            mCallBack = (OnHeadlineSelectedListener) context;
        } catch (ClassCastException ex) {
            throw new ClassCastException(context.toString() + " must implement OnHeadlineSelectedListener");
        }
    }
}
