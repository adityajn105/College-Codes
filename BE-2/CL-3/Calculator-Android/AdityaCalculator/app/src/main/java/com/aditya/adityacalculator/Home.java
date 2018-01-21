package com.aditya.adityacalculator;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import java.math.*;
import java.text.DecimalFormat;

public class Home extends AppCompatActivity {

    EditText screen;
    String currOp="=";
    int opdone = 0;
    boolean screenCleared = true;
    double prevValue=0.0;
    String advOp = "=";
    DecimalFormat df;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_home);
        df = new DecimalFormat("#.###");

        screen = (EditText) findViewById(R.id.screen);
        Button one = (Button)findViewById(R.id.one);
        Button two = (Button)findViewById(R.id.two);
        Button three = (Button)findViewById(R.id.three);
        Button four = (Button)findViewById(R.id.four);
        Button five = (Button)findViewById(R.id.five);
        Button six = (Button)findViewById(R.id.six);
        Button seven = (Button)findViewById(R.id.seven);
        Button eight = (Button)findViewById(R.id.eight);
        Button nine = (Button)findViewById(R.id.nine);
        Button zero = (Button)findViewById(R.id.zero);
        Button dot = (Button)findViewById(R.id.dot);

        Button add = (Button)findViewById(R.id.add);
        Button sub = (Button)findViewById(R.id.sub);
        Button mul = (Button)findViewById(R.id.mul);
        Button div = (Button)findViewById(R.id.div);
        Button eq = (Button)findViewById(R.id.equal);
        Button sin = (Button)findViewById(R.id.sin);
        Button cos = (Button)findViewById(R.id.cos);
        Button tan = (Button)findViewById(R.id.tan);
        Button sqrt = (Button)findViewById(R.id.sqrt);

        Button del = (Button)findViewById(R.id.del);
        del.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String num = screen.getText().toString();
                if(num.length()>0) {
                    screen.setText(num.substring(0, num.length() - 1));
                }
            }
        });
        one.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                numClicked("1");
            }
        });
        two.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                numClicked("2");
            }
        });
        three.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                numClicked("3");
            }
        });
        four.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                numClicked("4");
            }
        });
        five.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                numClicked("5");
            }
        });
        six.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                numClicked("6");
            }
        });
        seven.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                numClicked("7");
            }
        });
        eight.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                numClicked("8");
            }
        });
        nine.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                numClicked("9");
            }
        });
        zero.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                numClicked("0");
            }
        });
        dot.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                numClicked(".");
            }
        });
        add.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                performOp("+");
            }
        });
        sub.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                performOp("-");
            }
        });
        mul.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                performOp("x");
            }
        });
        div.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                performOp("/");
            }
        });
        eq.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                equal();
            }
        });

        sin.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                performOp("sin");
            }
        });
        cos.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                performOp("cos");
            }
        });
        tan.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                performOp("tan");
            }
        });
        sqrt.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                performOp("sqrt");
            }
        });

    }

    String getEquation() {
        String eq = "";

        if ((prevValue == Math.floor(prevValue)) && !Double.isInfinite(prevValue))
        { eq = eq + (int)prevValue; } else { eq = eq + df.format(prevValue); }

        eq = eq  + currOp ;

        double val= getScreenValue();
        if ((val == Math.floor(val)) && !Double.isInfinite(val)) { eq = eq +(int)val;}
        else { eq = eq +  df.format(val);}

        return eq;
    }

    void equal(){
        if(currOp.equals("=")){
            return;
        }
        String equation;
        if(!advOp.equals("=") && !screen.getText().toString().equals("") ){
            switch (advOp){
                case "sin":
                    prevValue  = Math.sin(getScreenValue()*Math.PI/180);
                    break;
                case "cos":
                    prevValue = Math.cos(getScreenValue()*Math.PI/180);
                    break;
                case "tan":
                    prevValue = Math.tan(getScreenValue()*Math.PI/180);
                    break;
                case "sqrt":
                    prevValue =Math.sqrt(getScreenValue());
                    break;
            }
            currOp = "=";
            equation = advOp + "(" + df.format(getScreenValue()) + ")";
            advOp = "=";
        }
        else {
            equation = getEquation();
        }
        switch (currOp) {
            case "+":
                prevValue = prevValue + getScreenValue();
                break;
            case "-":
                prevValue = prevValue - getScreenValue();
                break;
            case "x":
                prevValue = prevValue * getScreenValue();
                break;
            case "/":
                prevValue = prevValue / getScreenValue();
                break;
            default:
                break;
        }
        screen.setText(equation+"\n"+df.format(prevValue)+ "");
        opdone++;
        currOp="=";
        screenCleared=false;
    }

    void performOp(String op){
        if(!advOp.equals("=") && !screen.getText().toString().equals("") ){
            advOp = "=";
            switch (advOp){
                case "sin":
                    prevValue  = Math.sin(getScreenValue()*Math.PI/180);
                    break;
                case "cos":
                    prevValue = Math.cos(getScreenValue()*Math.PI/180);
                    break;
                case "tan":
                    prevValue = Math.tan(getScreenValue()*Math.PI/180);
                    break;
                case "sqrt":
                    prevValue =Math.sqrt(getScreenValue());
                    break;
            }
            currOp = op;
            screenCleared = false;
            return;
        }
        switch (op){
            case "sin":
                advOp = "sin";break;
            case "cos":
                advOp = "cos";break;
            case "tan":
                advOp = "tan";break;
            case "sqrt":
                advOp = "sqrt";break;
            default:
                break;
        }

        if(!advOp.equals("=")){
            currOp="=";
        }

        switch (currOp) {
            case "+":
                prevValue = prevValue + getScreenValue();
                break;
            case "-":
                prevValue = prevValue - getScreenValue();
                break;
            case "x":
                prevValue = prevValue * getScreenValue();
                break;
            case "/":
                prevValue = prevValue / getScreenValue();
                break;
            default:
                if(opdone==0) {
                    prevValue = getScreenValue();
                }
                break;
        }

        currOp=op;
        screenCleared = false;
    }

    public double getScreenValue(){
        if(screen.getText().toString().equals("")){
            return 0.0;
        }
        return Double.parseDouble(screen.getText().toString());
    }

    public void numClicked(String digit){
        if(currOp.equals("=")){
            prevValue=0.0;
            opdone=0;
        }

        if(!screenCleared) {
            screen.setText("");
            screenCleared=true;
        }

        if(!digit.equals(".")){
            screen.setText(screen.getText().toString()+digit);
        }
        else{
            if(!screen.getText().toString().contains(".")){
                screen.setText(screen.getText().toString()+".");
            }
        }
    }
}
