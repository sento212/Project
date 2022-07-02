package com.ocsa.tutorialandroid;

import androidx.fragment.app.FragmentActivity;
import androidx.fragment.app.FragmentTransaction;

import android.os.Bundle;

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