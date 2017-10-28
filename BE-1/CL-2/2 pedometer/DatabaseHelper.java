

package com.example.pedometercm;

import java.util.ArrayList;

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
	public static final String DATABASE_NAME = "pedometer";
	private static final int DATABASE_VERSION = 1;
	private static final String TABLE_QUERY = "CREATE TABLE PEDODATA( ID INTEGER PRIMARY KEY AUTOINCREMENT, STARTTIME TEXT NOT NULL, STOPTIME TEXT NOT NULL, STEPS INT)";

	private static DatabaseHelper sDbInstance = null;

	private Context mContext = null;

	public DatabaseHelper(Context context) {
		super(context, DATABASE_NAME, null, DATABASE_VERSION);
		mContext = context;
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

	public boolean saveData(String startTime, String stopTime, int stepCount) {
		String qry = "INSERT INTO PEDODATA (STARTTIME,STOPTIME,STEPS) VALUES('"
				+ startTime + "','" + stopTime + "','" + stepCount + "');";
		return ExecuteSql(qry);
	}

	public ArrayList<String> getData() {
		ArrayList<String> list = new ArrayList<String>();
		String qry = "SELECT STARTTIME,STOPTIME,STEPS FROM PEDODATA ORDER BY ID DESC";
		Cursor cursor = ExecuteRawSql(qry);
		if (cursor != null && cursor.moveToFirst()) {
			do {
				String startTime = cursor.getString(0);
				String stopTime = cursor.getString(1);
				int stepCount = cursor.getInt(2);

				String time = "From : " + startTime + " \nTo : " + stopTime;
				String steps = " \nSteps : " + stepCount;
				list.add(time + steps);

			} while (cursor.moveToNext());
		}
		return list;
	}

}
