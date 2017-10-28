NAME:Tanmai Deshpande
BE Comp 1
402009

package com.example.jobseekerapp;

import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Locale;

import android.R.id;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.util.Log;

/**
 * This class being used to perform database operations
 * 
 * @author bharat
 *
 */
public class DatabaseHelper extends SQLiteOpenHelper {
	private static final String TAG = DatabaseHelper.class.getName();
	public static final String DATABASE_NAME = "BOOKSYSTEM";
	private static final int DATABASE_VERSION = 1;
	private static final String TABLE_QUERY = "CREATE TABLE USERFILING( ID INTEGER PRIMARY KEY AUTOINCREMENT, COMPANY TEXT NOT NULL, CATEGORY TEXT NOT NULL,JOBTYPE TEXT NOT NULL,SKILL TEXT NOT NULL,LOCATION TEXT)";

	private static DatabaseHelper sDbInstance = null;
	private Context context;

	public DatabaseHelper(Context context) {
		super(context, DATABASE_NAME, null, DATABASE_VERSION);
		this.context = context;
	}

	@Override
	public void onCreate(SQLiteDatabase db) {
		db.execSQL(TABLE_QUERY);
	}

	@Override
	public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
	}

	public static DatabaseHelper getInstance(Context context) {
		if (sDbInstance == null) {
			sDbInstance = new DatabaseHelper(context);
		}
		return sDbInstance;
	}

	/**
	 * Method to execute SQL Query
	 * 
	 * @param s
	 *            SQL Query
	 * @return cursor of returned results
	 */
	public synchronized Cursor ExecuteRawSql(String s) {// Select Query
		try {
			SQLiteDatabase sqLiteDb = getReadableDatabase();
			Cursor cursor = sqLiteDb.rawQuery(s, null);
			return cursor;

		} catch (Exception e) {
			e.printStackTrace();
			return null;
		}
	}

	/**
	 * Method to execute SQL Query
	 * 
	 * @param s
	 *            SQL Query
	 * @return true if query was successfully executed.
	 */
	public synchronized boolean ExecuteSql(String s) {// Update Query
		try {
			Log.d(TAG, "Actual Query--->>" + s);
			SQLiteDatabase sqLiteDb = getWritableDatabase();
			sqLiteDb.execSQL(s);
			return true;
		} catch (Exception e) {
			e.printStackTrace();
			return false;
		}
	}

	public boolean addNewJob(String companyName, String jobType,
			String category, String skill, String location) {
		String qry = "INSERT INTO USERFILING (COMPANY,JOBTYPE,SKILL,CATEGORY,LOCATION) VALUES('"
				+ companyName
				+ "','"
				+ jobType
				+ "','"
				+ skill
				+ "','"
				+ category + "','" + location + "');";
		return ExecuteSql(qry);
	}

	public boolean rateBook(int bookId, float rating) {
		String qry = "UPDATE BOOKSYSTEM SET RATING=" + rating + " WHERE id="
				+ bookId + "";
		return ExecuteSql(qry);
	}

	public ArrayList<JobBean> getJobList(String jobType, String category,
			String skill, String location) {

		ArrayList<JobBean> list = new ArrayList<JobBean>();
		String qry = "SELECT ID,COMPANY,JOBTYPE,CATEGORY,SKILL,LOCATION FROM USERFILING WHERE JOBTYPE='"
				+ jobType
				+ "' AND CATEGORY='"
				+ category
				+ "' AND SKILL='"
				+ skill
				+ "' AND LOCATION='" + location + "'";

		Cursor cursor = ExecuteRawSql(qry);
		if (cursor != null && cursor.moveToFirst()) {
			do {
				JobBean bookName = new JobBean();
				bookName.setId(cursor.getInt(0));
				bookName.setCompanyname(cursor.getString(1));
				bookName.setJobtype(cursor.getString(2));
				bookName.setCategory(cursor.getString(3));
				bookName.setSkill(cursor.getString(4));
				bookName.setLocation(cursor.getString(5));
				list.add(bookName);
			} while (cursor.moveToNext());
		}
		return list;
	}

	public String getDateTime() {
		Calendar c = Calendar.getInstance();
		SimpleDateFormat formatter = new SimpleDateFormat("dd-MMM-yyyy",
				Locale.US);
		String formattedDate = formatter.format(c.getTime());
		String s = formattedDate;
		return s;
	}

}
