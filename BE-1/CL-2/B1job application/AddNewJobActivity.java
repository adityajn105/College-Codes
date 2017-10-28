NAME:Tanmai Deshpande
BE Comp 1
402009

package com.example.jobseekerapp;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemSelectedListener;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.Toast;

public class AddNewJobActivity extends Activity implements OnClickListener {
	private EditText editTextCompanyName;
	private Spinner spnrCategory, spnrJobType, spnrSkill, spnrLocation;
	private Button buttonAddNew;
	private ArrayAdapter<String> categoryAdapter, jobTypeAdapter, skillAdapter,
			locationAdapter;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_add_new_job);
	
		/*
		 * Initialize UI compounds
		 */
		editTextCompanyName = (EditText) findViewById(R.id.editTextCompanyName);
		spnrCategory = (Spinner) findViewById(R.id.spnrCategory);
		spnrJobType = (Spinner) findViewById(R.id.spnrJobType);
		spnrSkill = (Spinner) findViewById(R.id.spnrSkill);
		spnrLocation = (Spinner) findViewById(R.id.spnrLocation);

		/*
		 * Initialize Spinner Adapters
		 */
		categoryAdapter = new ArrayAdapter<String>(this,
				android.R.layout.simple_list_item_1, getResources()
						.getStringArray(R.array.category));

		locationAdapter = new ArrayAdapter<String>(this,
				android.R.layout.simple_list_item_1, getResources()
						.getStringArray(R.array.location));
		jobTypeAdapter = new ArrayAdapter<String>(this,
				android.R.layout.simple_list_item_1, getResources()
						.getStringArray(R.array.jobtype));
		skillAdapter = new ArrayAdapter<String>(this,
				android.R.layout.simple_list_item_1, getResources()
						.getStringArray(R.array.skill));
		buttonAddNew = (Button) findViewById(R.id.buttonAddNew);

		/*
		 * Set Adapters to spinners 
		 */
		spnrCategory.setAdapter(categoryAdapter);
		spnrJobType.setAdapter(jobTypeAdapter);
		spnrSkill.setAdapter(skillAdapter);
		spnrLocation.setAdapter(locationAdapter);

		// set Click Listener to  Button
		buttonAddNew.setOnClickListener(this);

	}

	 

	@Override
	public void onClick(View v) {
		if (!editTextCompanyName.getText().toString().equals("")) {
			String companyName = editTextCompanyName.getText().toString();
			String jobType = spnrJobType.getSelectedItem().toString();
			String category = spnrCategory.getSelectedItem().toString();
			String skill = spnrSkill.getSelectedItem().toString();
			String location = spnrLocation.getSelectedItem().toString();
			saveJobInDatabase(companyName, jobType, category, skill,
					location);
			onBackPressed();

		} else {
			editTextCompanyName.setError("Enter Company Name !");
		}

	}
/**
 * Save Data in data Base
 * @param companyName
 * @param jobType
 * @param category
 * @param skill
 * @param location
 */
	private void saveJobInDatabase(String companyName, String jobType,
			String category, String skill, String location) {
		 // Initialize Database
		DatabaseHelper databaseHelper = new DatabaseHelper(getApplicationContext());
		databaseHelper.addNewJob(companyName, jobType, category, skill,
				location);
	}



	@Override
	public void onBackPressed() {
		finish();
	}
	
 
}
