package com.aditya.movieguess

import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.support.design.widget.TextInputEditText
import android.widget.Button
import android.widget.TextView
import android.widget.Toast
import org.json.JSONArray
import org.json.JSONObject
import java.io.IOException
import java.util.*

data class Movie(
        val country: String,
        val genre: String,
        val lang:String,
        val name:String,
        val hints : List<String>,
        val release:String
        )

class MainActivity : AppCompatActivity() {
    private var cScore : TextView ?= null
    private var tScore : TextView ?= null
    private var hint : TextView ?= null
    private var name : TextView ?= null
    private lateinit var movieList: ArrayList<Movie>
    private lateinit var hintList : List<String>

    private var hintno : Int = 0
    private var currhintno :Int = 0
    private var movieNo : Int=0
    private var current = 10;
    private var total = 0;

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        findViewById<Button>(R.id.check).setOnClickListener {onCheckClicked()}
        findViewById<Button>(R.id.showhint).setOnClickListener { onShowHintClicked() }
        findViewById<TextView>(R.id.next).setOnClickListener { onNextHint() }
        findViewById<TextView>(R.id.prev).setOnClickListener { onPrevHint() }
        cScore = findViewById<TextView>(R.id.cscore)
        tScore = findViewById<TextView>(R.id.tscore)
        hint = findViewById<TextView>(R.id.hint)
        name = findViewById<TextInputEditText>(R.id.name)
        cScore?.text=current.toString()
        tScore?.text=total.toString()
        movieList = loadMovies()
        hint?.text = movieList[movieNo].hints[currhintno]
        hintList = movieList[movieNo].hints
    }

    fun onCheckClicked(){
        if(movieNo>=movieList.size) {
            Toast.makeText(applicationContext,"You are true winner!! Have a nice Day.",
                    Toast.LENGTH_LONG).show()
            return
        }
        if(movieList[movieNo].name.toLowerCase() == name?.text.toString()){
            tScore?.text=(total+current).toString()
            total+=current
            cScore?.text="10"
            current=10
            Toast.makeText(applicationContext,"Correct!!",Toast.LENGTH_LONG).show()
            movieNo++
            if(movieNo<movieList.size) {
                currhintno=0
                hintno = 0
                hint?.text = movieList[movieNo].hints[currhintno]
                hintList = movieList[movieNo].hints
                name?.text = ""
            }
            else{
                Toast.makeText(applicationContext,"You are true winner!! Have a nice Day.",
                        Toast.LENGTH_LONG).show()
            }
        }
        else{
            Toast.makeText(applicationContext,"Wrong!!",Toast.LENGTH_LONG).show()
        }
    }

    fun onShowHintClicked(){
        if(hintno < hintList.size){
            hintno++
            currhintno=hintno
            hint?.text = hintList[currhintno]
            current-=2
            cScore?.text=current.toString()
        }
    }

    fun onNextHint(){
        if(currhintno<hintno){
            currhintno++
            hint?.text = hintList[currhintno]
        }
    }

    fun onPrevHint(){
        if(currhintno>0){
            currhintno--
            hint?.text = hintList[currhintno]
        }
    }

    fun loadMovies():ArrayList<Movie>{
        var data:String = "[]"
        try {
            val stream = assets.open("movies.sample.json")
            val size = stream.available()
            val buffer = ByteArray(size)
            stream.read(buffer)
            stream.close()
            data= String(buffer)
        } catch (e: IOException) { }

        val list : ArrayList<Movie> = ArrayList()
        var arr:JSONArray = JSONArray(data)
        var i:Int=0
        while(i<arr.length()){
            var obj:JSONObject = arr.getJSONObject(i)
            var movie = Movie(
                    obj.getString("country"),
                    obj.getString("genre"),
                    obj.getString("lang"),
                    obj.getString("name"),
                    obj.getString("summary").split("."),
                    obj.getString("release")
            )
            list.add(movie)
            i++
        }
        Collections.shuffle(list)
        return list
    }

}
