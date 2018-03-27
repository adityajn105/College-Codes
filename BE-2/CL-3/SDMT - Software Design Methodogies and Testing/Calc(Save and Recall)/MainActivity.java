package com.example.lenovo.calcibasic;

import android.content.pm.ActivityInfo;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.text.method.ScrollingMovementMethod;
import android.view.View;
import android.view.Window;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.TextView;

import java.util.ArrayList;
import java.util.List;


public class MainActivity extends AppCompatActivity implements View.OnClickListener {
    public TextView outputResult, outputResult2;
    private List<String> history = new ArrayList<String>();
    private String inputToBeParsed = "";
    private String resultObject = "";
    private String lastData = "0";
    private String major_str = "";
    private String currentDisplayedInput = "";
    private double result;
    private Button button0, button1, button2, button3, button4, button5, button6, button7,
            button8, button9, buttonClear, buttonDivide, buttonMultiply, buttonSubtract,
            buttonAdd, buttonPercentage, buttonEqual, buttonDecimal, closeParenthesis, openParenthesis, buttonClearHist,
            buttonSingleDelete, H;

    private Button buttonSin, buttonLn, buttonCos, buttonLog, buttonTan, buttonSquareRoot, buttonXSquare, buttonYPowerX,
            buttonfactorial, buttonPi, buttonCubeRoot, buttonCube, buttonRecall;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        requestWindowFeature(Window.FEATURE_NO_TITLE);
        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN, WindowManager.LayoutParams.FLAG_FULLSCREEN);
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_PORTRAIT);
        outputResult = (TextView) findViewById(R.id.display);
        outputResult2 = (TextView) findViewById(R.id.display2);
        outputResult.setText("");
        button0 = (Button) findViewById(R.id.zero_button);
        button1 = (Button) findViewById(R.id.one_button);
        button2 = (Button) findViewById(R.id.two_button);
        button3 = (Button) findViewById(R.id.three_button);
        button4 = (Button) findViewById(R.id.four_button);
        button5 = (Button) findViewById(R.id.five_button);
        button6 = (Button) findViewById(R.id.six_button);
        button7 = (Button) findViewById(R.id.seven_button);
        button8 = (Button) findViewById(R.id.eight_button);
        button9 = (Button) findViewById(R.id.nine_button);
        buttonDivide = (Button) findViewById(R.id.division);
        buttonMultiply = (Button) findViewById(R.id.multiplication);
        buttonSubtract = (Button) findViewById(R.id.subtraction);
        buttonAdd = (Button) findViewById(R.id.addition);
        buttonPercentage = (Button) findViewById(R.id.percent);
        buttonDecimal = (Button) findViewById(R.id.dot);
        closeParenthesis = (Button) findViewById(R.id.close_bracket);
        openParenthesis = (Button) findViewById(R.id.open_bracket);
        buttonSquareRoot = (Button) findViewById(R.id.square_root);
        buttonXSquare = (Button) findViewById(R.id.x_square);
        buttonYPowerX = (Button) findViewById(R.id.x_power_y);
        buttonSin = (Button) findViewById(R.id.sin_sign);
        buttonCos = (Button) findViewById(R.id.cos_sign);
        buttonTan = (Button) findViewById(R.id.tan_sign);
        buttonLn = (Button) findViewById(R.id.natural_log);
        buttonLog = (Button) findViewById(R.id.log);
        buttonClear = (Button) findViewById(R.id.clear);
        H = (Button) findViewById(R.id.h);
        buttonSingleDelete = (Button) findViewById(R.id.single_delete);
        buttonEqual = (Button) findViewById(R.id.equal_sign);
        buttonClearHist = (Button) findViewById(R.id.CH);
        buttonfactorial = (Button) findViewById(R.id.factorial);
        buttonPi = (Button) findViewById(R.id.pi);
        buttonCubeRoot = (Button) findViewById(R.id.cube_root);
        buttonCube = (Button) findViewById(R.id.cube);
        buttonRecall = (Button) findViewById(R.id.recall);


        outputResult.setMovementMethod(new ScrollingMovementMethod());

        buttonPi.setOnClickListener(this);
        buttonCubeRoot.setOnClickListener(this);
        buttonCube.setOnClickListener(this);
        buttonDecimal.setOnClickListener(this);
        button0.setOnClickListener(this);
        button1.setOnClickListener(this);
        button2.setOnClickListener(this);
        button3.setOnClickListener(this);
        button4.setOnClickListener(this);
        button5.setOnClickListener(this);
        button6.setOnClickListener(this);
        button7.setOnClickListener(this);
        button8.setOnClickListener(this);
        button9.setOnClickListener(this);
        buttonClear.setOnClickListener(this);
        buttonfactorial.setOnClickListener(this);
        buttonDivide.setOnClickListener(this);
        buttonMultiply.setOnClickListener(this);
        buttonSubtract.setOnClickListener(this);
        buttonAdd.setOnClickListener(this);
        buttonPercentage.setOnClickListener(this);
        buttonEqual.setOnClickListener(this);
        closeParenthesis.setOnClickListener(this);
        openParenthesis.setOnClickListener(this);
        buttonSingleDelete.setOnClickListener(this);
        buttonSquareRoot.setOnClickListener(this);
        buttonXSquare.setOnClickListener(this);
        buttonYPowerX.setOnClickListener(this);
        buttonSin.setOnClickListener(this);
        buttonCos.setOnClickListener(this);
        buttonTan.setOnClickListener(this);
        buttonLn.setOnClickListener(this);
        buttonLog.setOnClickListener(this);
        buttonClearHist.setOnClickListener(this);
        buttonRecall.setOnClickListener(this);
        H.setOnClickListener(this);
    }

    private void obtainInputValues(String input) {
        switch (input) {
            case "!":
                currentDisplayedInput += "!(";
                inputToBeParsed += "!";
                break;

            case "0":
                currentDisplayedInput += "0";
                inputToBeParsed += "0";
                break;
            case "1":
                currentDisplayedInput += "1";
                inputToBeParsed += "1";
                break;
            case "2":
                currentDisplayedInput += "2";
                inputToBeParsed += "2";
                break;
            case "3":
                currentDisplayedInput += "3";
                inputToBeParsed += "3";
                break;
            case "4":
                currentDisplayedInput += "4";
                inputToBeParsed += "4";
                break;
            case "5":
                currentDisplayedInput += "5";
                inputToBeParsed += "5";
                break;
            case "6":
                currentDisplayedInput += "6";
                inputToBeParsed += "6";
                break;
            case "7":
                currentDisplayedInput += "7";
                inputToBeParsed += "7";
                break;
            case "8":
                currentDisplayedInput += "8";
                inputToBeParsed += "8";
                break;
            case "9":
                currentDisplayedInput += "9";
                inputToBeParsed += "9";
                break;
            case ".":
                currentDisplayedInput += ".";
                inputToBeParsed += ".";
                break;
            case "+":
                currentDisplayedInput += "+";
                inputToBeParsed += "+";
                break;
            case "-":
                currentDisplayedInput += "-";
                inputToBeParsed += "-";
                break;
            case "/":
                currentDisplayedInput += "/";
                inputToBeParsed += "/";
                break;
            case "x":
                currentDisplayedInput += "*";
                inputToBeParsed += "*";
                break;
            case "(":
                currentDisplayedInput += "(";
                inputToBeParsed += "(";
                break;
            case ")":
                currentDisplayedInput += ")";
                inputToBeParsed += ")";
                break;
            case "%":
                currentDisplayedInput += "%";
                inputToBeParsed += "%";
                break;
            case "ln":
                currentDisplayedInput += "ln(";
                inputToBeParsed += "ln(";
                break;
            case "log":
                currentDisplayedInput += "log(";
                inputToBeParsed += "log(";
                break;
            case "√":
                currentDisplayedInput += "√(";
                inputToBeParsed += "sqrt(";
                break;
            case "x^y":
                currentDisplayedInput += "^";
                inputToBeParsed += "^";
                break;
            case "sin":
                currentDisplayedInput += "sin(";
                inputToBeParsed += "sin(";
                break;
            case "cos":
                currentDisplayedInput += "cos(";
                inputToBeParsed += "cos(";
                break;
            case "π":
                currentDisplayedInput += "π";
                inputToBeParsed += "pi";
                break;
            case "3√":
                currentDisplayedInput += "3√(";
                inputToBeParsed += "crt(";
                break;
            case "tan":
                currentDisplayedInput += "tan(";
                inputToBeParsed += "tan(";
                break;
            case "exp":
                currentDisplayedInput += "E";
                inputToBeParsed += "E0";
                break;
            case "x^2":

                currentDisplayedInput += "^2";
                inputToBeParsed += "^2";
                break;

            case "n^3":
                currentDisplayedInput += "^3";
                inputToBeParsed += "^3";
                break;

        }
        outputResult.setText(currentDisplayedInput);
    }

    @Override
    public void onClick(View view) {
        Button button = (Button) view;

        String data = button.getText().toString();
        //Toast.makeText(this, "Click " + data, Toast.LENGTH_LONG).show();
        if (data.equals("AC")) {
            outputResult.setText("");
            outputResult2.setText("");
            currentDisplayedInput = "";
            inputToBeParsed = "";
        } else if (data.equals("DEL")) {
            String enteredInput = outputResult.getText().toString();
            if (enteredInput.length() > 0) {
                enteredInput = enteredInput.substring(0, enteredInput.length() - 1);
                currentDisplayedInput = enteredInput;
                inputToBeParsed = enteredInput;
                outputResult.setText(currentDisplayedInput);
            }
        } else if (data.equals("=")) {
            String str = "";
            result = eval(inputToBeParsed);
            resultObject = Double.toString(result);
            str = inputToBeParsed + "=" + resultObject;
            history.add(str);
            lastData = resultObject;
            outputResult.setText(inputToBeParsed);
            inputToBeParsed = "";
            currentDisplayedInput = "";
            outputResult2.setText(removeTrailingZero(resultObject));
        } else if (data.equals("CH")) {
            major_str = "";
            history.clear();
            outputResult.setText("");
            outputResult2.setText("");
            inputToBeParsed = "";
            currentDisplayedInput = "";
        } else if (data.equals("H")) {
            for (int i = 0; i < history.size(); i++) {
                major_str += history.get(i) + "\n";
            }
            outputResult.setText(major_str);
        } else if (data.equals("Recall")) {
            inputToBeParsed = lastData;
            currentDisplayedInput = lastData;
            outputResult.setText(currentDisplayedInput);
        } else {
            obtainInputValues(data);
        }
    }

    private String removeTrailingZero(String formattingInput) {
        if (!formattingInput.contains(".")) {
            return formattingInput;
        }
        int dotPosition = formattingInput.indexOf(".");
        String newValue = formattingInput.substring(dotPosition, formattingInput.length());
        if (newValue.equals(".0")) {
            return formattingInput.substring(0, dotPosition);
        }
        return formattingInput;
    }

    public double eval(final String str) {
        return new Object() {
            int pos = -1, ch;

            void nextChar() {
                ch = (++pos < str.length()) ? str.charAt(pos) : -1;
            }

            boolean eat(int charToEat) {
                while (ch == ' ') nextChar();
                if (ch == charToEat) {
                    nextChar();
                    return true;
                }
                return false;
            }

            double parse() {
                nextChar();
                double x = parseExpression();
                if (pos < str.length()) outputResult.setText("Error");
                return x;
            }

            // Grammar:
            // expression = term | expression `+` term | expression `-` term
            // term = factor | term `*` factor | term `/` factor
            // factor = `+` factor | `-` factor | `(` expression `)`
            //        | number | functionName factor | factor `^` factor

            double parseExpression() {
                double x = parseTerm();
                for (; ; ) {
                    if (eat('+')) x += parseTerm(); // addition
                    else if (eat('-')) x -= parseTerm(); // subtraction
                    else return x;
                }
            }

            double parseTerm() {
                double x = parseFactor();
                for (; ; ) {
                    if (eat('*')) x *= parseFactor(); // multiplication
                    else if (eat('/')) x /= parseFactor(); // division
                    else if (eat('%')) {
                        double t = 0, y = 0, m = 0, r = 0;
                        t = parseFactor();
                        y = x / t;
                        m = y - (int) y;
                        x = m * t;
                    } else if (eat('!')) {
                        x = parseFactor();
                        x = factorial(x);
                    } else return x;
                }
            }

            public double factorial(double n) {
                double fact = 1; // this  will be the result
                for (int i = 1; i <= n; i++) {
                    fact *= i;
                }
                return fact;
            }


            private double parseFactor() {
                if (eat('+')) return parseFactor(); // unary plus
                if (eat('-')) return -parseFactor(); // unary minus
                double t = 0;
                double x = 0;
                int startPos = this.pos;
                if (eat('(')) { // parentheses
                    x = parseExpression();
                    eat(')');
                } else if ((ch >= '0' && ch <= '9') || ch == '.') { // numbers
                    while ((ch >= '0' && ch <= '9') || ch == '.') nextChar();
                    x = Double.parseDouble(str.substring(startPos, this.pos));
                } else if (ch >= 'a' && ch <= 'z') { // functions
                    while (ch >= 'a' && ch <= 'z') nextChar();

                    String func = str.substring(startPos, this.pos);
                    x = parseFactor();
                    t = parseFactor();
                    if (func.equals("sqrt")) x = Math.sqrt(x);
                    else if (func.equals("sin")) x = Math.sin(Math.toRadians(x));
                    else if (func.equals("cos")) x = Math.cos(Math.toRadians(x));
                    else if (func.equals("tan")) x = Math.tan(Math.toRadians(x));
                    else if (func.equals("log")) x = Math.log10(x);
                    else if (func.equals("ln")) x = Math.log(x);
                    else x = 3.14;

                }
                if (eat('^')) x = Math.pow(x, parseFactor()); // exponentiation
                //if (eat('%')) x = (x*t/100);
                return x;
            }
        }.parse();
    }
}