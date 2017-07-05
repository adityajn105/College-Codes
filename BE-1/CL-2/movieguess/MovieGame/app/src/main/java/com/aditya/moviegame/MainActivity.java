package com.aditya.moviegame;

import android.os.AsyncTask;
import android.support.design.widget.TextInputEditText;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.BufferedInputStream;
import java.io.InputStream;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {

    private TextView clues;
    private Button submit;
    private TextInputEditText answer;
    private TextView next;
    private TextView prev;
    private TextView hint;
    private TextView cscore;
    private ArrayList<Movies> movies;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        new MovieFetcher().execute("http://127.0.0.1:5000/getmovie");


        submit=(Button)findViewById(R.id.submit);
        answer=(TextInputEditText)findViewById(R.id.answer);
        clues=(TextView)findViewById(R.id.clue);
        next=(TextView)findViewById(R.id.next);
        prev=(TextView)findViewById(R.id.prev);
        cscore=(TextView)findViewById(R.id.cscore);
        hint=(TextView)findViewById(R.id.hint);
        submit.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                onSubmitClicked(v);
            }
        });
        hint.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                onHintClicked(v);
            }
        });
        next.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                onNextClicked(v);
            }
        });
        prev.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                onPrevClicked(v);
            }
        });
    }

    private class MovieFetcher extends AsyncTask<String, Void, ArrayList<Movies>> {
        protected ArrayList<Movies> doInBackground(String... urls) {
            ArrayList<Movies> movielist=new ArrayList<>();
            try{
                URL url = new URL(urls[0]);
                HttpURLConnection urlConnection = (HttpURLConnection) url.openConnection();
                InputStream in = new BufferedInputStream(urlConnection.getInputStream());

            }
            catch(Exception e) {
                e.fillInStackTrace();
            }
            urlConnection.disconnect();
            return movielist;

        }
        protected void onPostExecute(ArrayList<Movies> data) {
            movies=data;
        }
    }


    public void onHintClicked(View view){

    }
    public void onPrevClicked(View view){

    }
    public void onNextClicked(View view){

    }

    public void onSubmitClicked(View v){
        String ans = answer.getText().toString();

        try {
            JSONObject obj = new JSONObject("");
            String pageName = obj.getJSONObject("pageInfo").getString("pageName");

            JSONArray arr = obj.getJSONArray("posts");
            for (int i = 0; i < arr.length(); i++) {
                String post_id = arr.getJSONObject(i).getString("post_id");

            }
        }
        catch (JSONException j){
            Log.d("TAG", "onSubmitClicked: "+j.getMessage());
        }


    }

}

