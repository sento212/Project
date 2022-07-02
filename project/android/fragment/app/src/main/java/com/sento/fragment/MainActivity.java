package com.sento.fragment;
import android.content.Intent;
import android.os.Bundle;

import android.support.v4.app.FragmentActivity;
import android.support.v4.app.FragmentTransaction;
import android.view.View;
import android.widget.Button;
import android.widget.ListView;

public class MainActivity extends FragmentActivity implements
        HeadlinesFragment.OnHeadlineSelectedListener {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        if(findViewById(R.id.frame_container) != null) {
            if(savedInstanceState != null)
                return;
            HeadlinesFragment headlinesFragment = new HeadlinesFragment();
            headlinesFragment.setArguments(getIntent().getExtras());
            getSupportFragmentManager().beginTransaction()
                    .add(R.id.frame_container, headlinesFragment).commit();
        }

    }

    public void next(View v){

        Intent intent2 = new Intent(this, enter.class);
        startActivity(intent2);

    }

    public void onArticleSelected(int position) {
        boolean is_landscape = getApplicationContext().getResources().getBoolean(R.bool.is_landscape);
        if(is_landscape) {
            ArticleFragment articleFragment = (ArticleFragment) getSupportFragmentManager()
                    .findFragmentById(R.id.article_fragment);
            articleFragment.updateArticleView(position);
        } else {
            Bundle args = new Bundle();
            args.putInt(ArticleFragment.ARG_POSITION, position);
            ArticleFragment newArticleFragment = new ArticleFragment();
            newArticleFragment.setArguments(args);
            FragmentTransaction fragmentTransaction = getSupportFragmentManager().beginTransaction();

            fragmentTransaction.replace(R.id.frame_container, newArticleFragment);
            fragmentTransaction.addToBackStack(null);

            fragmentTransaction.commit();
        }
    }
}