NAME:Tanmai Deshpande
BE Comp 1
402009

package com.example.jobseekerapp;

import java.util.ArrayList;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.preference.PreferenceManager;
import android.view.View;
import android.widget.ListView;
import android.widget.TextView;

public class JobsListActivity extends Activity {

	private JobListAdapter jobListAdapter;
	private ListView listView;
	private TextView noMatchesFound;
	private DatabaseHelper databaseHelper;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_jobs_list);
		listView = (ListView) findViewById(R.id.list);
		noMatchesFound = (TextView) findViewById(R.id.noMatchesFound);
		databaseHelper = new DatabaseHelper(getApplicationContext());

		// get Values from Shared preferences

		SharedPreferences preferences = PreferenceManager
				.getDefaultSharedPreferences(this);
		String jobType = preferences.getString(KeysValues.JOBTYPE,
				KeysValues.JOBTYPE_PARTTIME);
		String category = preferences.getString(KeysValues.CATEGORY,
				KeysValues.CATEGORY_FRESHER);
		String skill = preferences.getString(KeysValues.SKILL,
				KeysValues.SKILL_JAVA);
		String location = preferences.getString(KeysValues.LOCATION,
				KeysValues.LOCATION_PUNE);

		ArrayList<JobBean> list = databaseHelper.getJobList(jobType, category,
				skill, location);

		if (list.size() == 0) {
			listView.setVisibility(View.GONE);
			noMatchesFound.setVisibility(View.VISIBLE);

		} else {
			listView.setVisibility(View.VISIBLE);
			noMatchesFound.setVisibility(View.GONE);
		}

		jobListAdapter = new JobListAdapter(getApplicationContext(), list);
		listView.setAdapter(jobListAdapter);
	}

	@Override
	public void onBackPressed() {
		finish();
	}
}
