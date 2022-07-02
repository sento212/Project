package com.sento.fragment;

import android.os.Bundle;
import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

public class ArticleFragment extends Fragment {
    final static String ARG_POSITION = "position";
    int mCurrentPosition = 0;
    private TextView txtArticle;
    private TextView txtArticle2;
    private ImageView image;
    private View view;

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        if(savedInstanceState != null) {
            mCurrentPosition = savedInstanceState.getInt(ARG_POSITION);
        }
        view = inflater.inflate(R.layout.article_view, container, false);
        txtArticle = view.findViewById(R.id.article);
        txtArticle2 = view.findViewById(R.id.article2);
        image = view.findViewById(R.id.image);
        return view;
    }

    @Override
    public void onStart() {
        super.onStart();
        Bundle args = getArguments();
        if(args != null) {
            updateArticleView(args.getInt(ARG_POSITION));
        } else {
            updateArticleView(mCurrentPosition);
        }
    }

    public void updateArticleView(int position) {
        txtArticle2.setText(Ipsum.headlines[position]);
        image.setImageResource(Ipsum.gambar[position]);
        txtArticle.setText(Ipsum.article[position]);
        mCurrentPosition = position;
    }


    @Override
    public void onSaveInstanceState(@NonNull Bundle outState) {
        super.onSaveInstanceState(outState);
        outState.putInt(ARG_POSITION, mCurrentPosition);
    }
}