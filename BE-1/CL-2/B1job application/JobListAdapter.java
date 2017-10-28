NAME:Tanmai Deshpande
BE Comp 1
402009

package com.example.jobseekerapp;

import java.util.ArrayList;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.RatingBar;
import android.widget.RatingBar.OnRatingBarChangeListener;
import android.widget.TextView;

public class JobListAdapter extends BaseAdapter {
	private ArrayList<JobBean> list;
	private LayoutInflater inflater;
	private DatabaseHelper databaseHelper;
	
	JobListAdapter(Context context,ArrayList<JobBean> list){
		this.list=list;
		inflater=(LayoutInflater)context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
		databaseHelper = new DatabaseHelper(context);
	}

	@Override
	public int getCount() {
		return list.size();
	}

	@Override
	public JobBean getItem(int position) {
		return list.get(position);
	}

	@Override
	public long getItemId(int position) {
		return position;
	}

	@Override
	public View getView(int position, View convertView, ViewGroup parent) {
		convertView=inflater.inflate(R.layout.list_item_job_layout, null);
		
		TextView textViewCompanyName=(TextView)convertView.findViewById(R.id.textViewCompanyName);
		TextView textViewLocation=(TextView)convertView.findViewById(R.id.textViewLocation);
		TextView textViewCagegory=(TextView)convertView.findViewById(R.id.textViewCagegory);
		TextView textViewSkill=(TextView)convertView.findViewById(R.id.textViewSkill);
		TextView textViewJobType=(TextView)convertView.findViewById(R.id.textViewJobType);
		
		//Set Data
		
		final JobBean dataBean=list.get(position);
		textViewCompanyName.setText("Company : "+ dataBean.getCompanyname());
		textViewLocation.setText("Location : " + dataBean.getLocation());
		textViewCagegory.setText("Category : "+dataBean.getCategory());
		textViewSkill.setText("Required skill : "+dataBean.getSkill());
		textViewJobType.setText("Job Type : "+dataBean.getJobtype());
		return convertView;
	}

}
