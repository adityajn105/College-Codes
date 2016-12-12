package com.example.aditya.osinfo;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;
public class MainActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        TextView sysversion=(TextView)findViewById(R.id.sysversion);
        sysversion.setText(System.getenv("os.version"));
        
        TextView osname=(TextView)findViewById(R.id.osname);
        osname.setText(System.getProperty("os.name"));
        
        TextView osarch=(TextView)findViewById(R.id.arch);
        osarch.setText(System.getProperty("os.arch"));
        
        TextView manufacturer=(TextView)findViewById(R.id.manufacturer);
        manufacturer.setText(android.os.Build.MANUFACTURER);
    }
}
