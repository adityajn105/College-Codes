
package com.example.pedometercm;

import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.Locale;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.Bundle;
import android.os.Handler;
import android.os.SystemClock;
import android.util.FloatMath;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends Activity implements SensorEventListener,
		OnClickListener {

	private static int STEP_COUNT = 0;
	private static String START_TIME;
	private long START_MILI;
	private static String STOP_TIME;
	private float lastX, lastY, lastZ, deltaX, deltaY, deltaZ;
	private TextView numberOfSteps,tvTimeCount;
	private Button buttonStart, buttonStop;

	private SensorManager senSensorManager;
	private Sensor acceleroMeter;
	
	private int seconds;
	private int minutes;
	private int hours;
	private Handler myHandler;
	private long lastStepTakenTime;
	
	private Runnable updateTimerMethod = new Runnable() {

	

		public void run() {

			long timeInMillies = SystemClock.uptimeMillis() - START_MILI;
			int totalseconds = (int) (timeInMillies / 1000);
			minutes = totalseconds / 60;
			hours = minutes / 60;
			seconds = totalseconds % 60;
			tvTimeCount.setText(String.format("%02d", hours) + ":"
					+ String.format("%02d", minutes) + ":"
					+ String.format("%02d", seconds));
			myHandler.postDelayed(this, 0);
		}

	};


	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
	
		// Initialize UI components
		numberOfSteps = (TextView) findViewById(R.id.numberOfSteps);
		tvTimeCount = (TextView) findViewById(R.id.timeCount);
		buttonStart = (Button) findViewById(R.id.buttonStart);
		buttonStop = (Button) findViewById(R.id.buttonStop);
		buttonStop.setEnabled(false);
		
		//set Listener 
		buttonStart.setOnClickListener(this);
		buttonStop.setOnClickListener(this);
		intializeSensors();
		//start Handler thread
		myHandler=new Handler();

	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {

		int id = item.getItemId();
		if (id == R.id.action_history) {
			Intent intent=new Intent(this,DetailsListActivity.class);
			startActivity(intent);
		}
		return super.onOptionsItemSelected(item);
	}

	@Override
	public void onSensorChanged(SensorEvent sensorEvent) {
		final float[] values = sensorEvent.values;
		final Sensor sensor = sensorEvent.sensor;
		
		if (sensor.getType() == Sensor.TYPE_ACCELEROMETER) {
			stepDetector(values, sensorEvent.timestamp / (500 * 10 ^ 6l));
		}

	}

	private void intializeSensors() {
		senSensorManager = (SensorManager) getSystemService(Context.SENSOR_SERVICE);
		acceleroMeter = senSensorManager
				.getDefaultSensor(Sensor.TYPE_ACCELEROMETER);
	}

	private void stepDetector(float[] values, long timeStap) {

		float x = values[0];
		float y = values[1];
		float z = values[2];

		deltaX = lastX - x;
		deltaY = lastY - y;
		deltaZ = lastZ - z;

		lastX = x;
		lastY = y;
		lastZ = z;

		@SuppressWarnings("deprecation")
		//calculate Total Accelaration 
		float totalAccel = FloatMath.sqrt((x - deltaX) * (x - deltaX)
				+ (y - deltaY) * (y - deltaY) + (z - deltaZ) * (z - deltaZ))
				- SensorManager.GRAVITY_EARTH;

		Log.v("FFSPA", "totalAcceleration : " + totalAccel);
		
		long timeBetweenTwoSteps=SystemClock.uptimeMillis()-lastStepTakenTime;
		if (totalAccel > 8 && timeBetweenTwoSteps>300) {
			STEP_COUNT++;
			lastStepTakenTime=SystemClock.uptimeMillis();
			publishData(STEP_COUNT);
		}

	}

	@Override
	public void onAccuracyChanged(Sensor sensor, int accuracy) {

	}

	private void resetPedo() {
		STEP_COUNT = 0;
		publishData(000);
	}

	private void publishData(int steps) {
		numberOfSteps.setText(String.format("%03d", steps));
		tvTimeCount.setText("00.00.00");
	}

	@Override
	public void onClick(View clickView) {
		if (clickView.getId() == R.id.buttonStart) {
			resetPedo();
			startPedo();
			buttonStart.setEnabled(false);
			buttonStop.setEnabled(true);
		}
		if (clickView.getId() == R.id.buttonStop) {
			stopPedo();
			buttonStop.setEnabled(false);
			buttonStart.setEnabled(true);
		}

	}

 

	private void startPedo() {

		senSensorManager.registerListener(this, acceleroMeter,
				SensorManager.SENSOR_DELAY_NORMAL);
		START_TIME=getDateTime();
		START_MILI = SystemClock.uptimeMillis();
		myHandler.postDelayed(updateTimerMethod, 0);

	}

	private void stopPedo() {
		senSensorManager.unregisterListener(this, acceleroMeter);
		STOP_TIME=getDateTime();
		saveData(START_TIME,STOP_TIME,STEP_COUNT);
		myHandler.removeCallbacks(updateTimerMethod);
	}
	
	private void saveData(String startTime, String stopTime, int stepCount) {
		// Initialize database
		 DatabaseHelper database=new DatabaseHelper(getApplicationContext()); 
		 database.saveData(startTime,stopTime,stepCount);
	}

	public  String getDateTime() {
		Calendar c = Calendar.getInstance();
		SimpleDateFormat formatter = new SimpleDateFormat(
				"dd-MMM-yyyy HH:mm:ss", Locale.US);
		String formattedDate = formatter.format(c.getTime());
		String s = formattedDate;
		return s;
	}
}
