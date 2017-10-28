
package com.example.jobseekerapp;

import android.app.Activity;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.SharedPreferences.Editor;
import android.os.Bundle;
import android.preference.PreferenceManager;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.RadioButton;
import android.widget.RadioGroup;

public class SearchActivity extends Activity {

	Button btn_search;
	RadioGroup rbJobType, rbSkill, sbCategory, sbLocation;
	RadioButton radiofresher, radioexp, radiofull, radiopart, radioJava,
			radioNet, radioAndroid, radiopune, radiomumabai, radiobang,
			radiohyd, radioPHP;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_search);

		radiofresher = (RadioButton) findViewById(R.id.radiofresher);
		radioexp = (RadioButton) findViewById(R.id.radioexp);

		radiofull = (RadioButton) findViewById(R.id.radiofull);
		radiopart = (RadioButton) findViewById(R.id.radiopart);

		radioJava = (RadioButton) findViewById(R.id.radioJava);
		radioNet = (RadioButton) findViewById(R.id.radioNet);
		radioAndroid = (RadioButton) findViewById(R.id.radioandroid);
		radioPHP = (RadioButton) findViewById(R.id.radiophp);

		radiopune = (RadioButton) findViewById(R.id.radiopune);
		radiomumabai = (RadioButton) findViewById(R.id.radiomumabai);
		radiobang = (RadioButton) findViewById(R.id.radiobang);
		radiohyd = (RadioButton) findViewById(R.id.radiohyd);

		btn_search = (Button) findViewById(R.id.btn_search);

		btn_search.setOnClickListener(new View.OnClickListener() {

			@Override
			public void onClick(View v) {
				// Save Data In Shared Preferences
				saveSharedPreferences();

				Intent intent = new Intent(SearchActivity.this,
						JobsListActivity.class);
				startActivity(intent);

			}
		});

		getDataFromSharedPrefereces();

	}

	private void getDataFromSharedPrefereces() {

		if (getDataLocal(KeysValues.CATEGORY).equals(
				KeysValues.CATEGORY_FRESHER)) {
			radiofresher.setChecked(true);
		} else {
			radioexp.setChecked(true);
		}

		if (getDataLocal(KeysValues.JOBTYPE)
				.equals(KeysValues.JOBTYPE_FULLTIME)) {
			radiofull.setChecked(true);
		} else {
			radiopart.setChecked(true);
		}

		if (getDataLocal(KeysValues.SKILL).equals(KeysValues.SKILL_JAVA)) {
			radioJava.setChecked(true);
		}
		if (getDataLocal(KeysValues.SKILL).equals(KeysValues.SKILL_NET)) {
			radioNet.setChecked(true);
		} else if (getDataLocal(KeysValues.SKILL).equals(
				KeysValues.SKILL_ANDROID)) {
			radioAndroid.setChecked(true);
		} else {
			radioPHP.setChecked(true);
		}

		if (getDataLocal(KeysValues.LOCATION).equals(KeysValues.LOCATION_PUNE)) {
			radiopune.setChecked(true);
		} else if (getDataLocal(KeysValues.LOCATION).equals(
				KeysValues.LOCATION_MUMBAI)) {
			radiomumabai.setChecked(true);
		} else if (getDataLocal(KeysValues.LOCATION).equals(
				KeysValues.LOCATION_HYDRABAD)) {
			radiohyd.setChecked(true);
		} else {
			radiobang.setChecked(true);
		}

	}

	private void saveSharedPreferences() {
		if (radiofresher.isChecked()) {
			saveDataLocal(KeysValues.CATEGORY, KeysValues.CATEGORY_FRESHER);
		} else {
			saveDataLocal(KeysValues.CATEGORY, KeysValues.CATEGORY_EXPERIENCE);
		}

		if (radiofull.isChecked()) {
			saveDataLocal(KeysValues.JOBTYPE, KeysValues.JOBTYPE_FULLTIME);
		} else {
			saveDataLocal(KeysValues.JOBTYPE, KeysValues.JOBTYPE_PARTTIME);
		}

		if (radioJava.isChecked()) {
			saveDataLocal(KeysValues.SKILL, KeysValues.SKILL_JAVA);
		} else if (radioNet.isChecked()) {
			saveDataLocal(KeysValues.SKILL, KeysValues.SKILL_NET);
		} else if (radioAndroid.isChecked()) {
			saveDataLocal(KeysValues.SKILL, KeysValues.SKILL_ANDROID);
		} else {
			saveDataLocal(KeysValues.SKILL, KeysValues.SKILL_PHP);
		}

		if (radiopune.isChecked()) {
			saveDataLocal(KeysValues.LOCATION, KeysValues.LOCATION_PUNE);
		} else if (radiomumabai.isChecked()) {
			saveDataLocal(KeysValues.LOCATION, KeysValues.LOCATION_MUMBAI);
		} else if (radiohyd.isChecked()) {
			saveDataLocal(KeysValues.LOCATION, KeysValues.LOCATION_HYDRABAD);
		} else {
			saveDataLocal(KeysValues.LOCATION, KeysValues.LOCATION_BANGLORE);
		}

	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.search, menu);
		return true;
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		int id = item.getItemId();
		if (id == R.id.action_add_new_job) {
			Intent intent = new Intent(this, AddNewJobActivity.class);
			startActivity(intent);
		}
		return super.onOptionsItemSelected(item);
	}

	private void saveDataLocal(String key, String value) {
		SharedPreferences preferences = PreferenceManager
				.getDefaultSharedPreferences(this);
		Editor editor = preferences.edit();
		editor.putString(key, value);
		editor.commit();
	}

	private String getDataLocal(String key) {
		SharedPreferences preferences = PreferenceManager
				.getDefaultSharedPreferences(this);
		String value = preferences.getString(key, "");
		return value;
	}

}
