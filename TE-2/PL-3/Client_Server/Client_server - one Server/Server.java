import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.Scanner;

public class Server extends Thread{
	ServerSocket server;
	public Server() throws IOException {
		server=new ServerSocket(7956);
		System.out.println("Server Started");
	}
	public void run(){
		try {
			while(true){
				Socket client= server.accept();
				System.out.println("Connected to "+client.getInetAddress().toString());
				new Sender(client).start();
				new Reciever(client).start();
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	public static void main(String[] args) throws IOException{
		Server server=new Server();
		server.start();
	}
}

class DateUtils {


	  public static String now(String dateFormat) {
	    Calendar cal = Calendar.getInstance();
	    SimpleDateFormat sdf = new SimpleDateFormat(dateFormat);
	    return sdf.format(cal.getTime());

	  }
}
class Reciever extends Thread{
	Socket client;
	BufferedReader input;
	PrintStream output;
	public Reciever(Socket c) {
		this.client=c;
	}
	public void run(){
		try {
			input = new BufferedReader(new InputStreamReader(client.getInputStream()));
			output = new PrintStream(client.getOutputStream());
			while(true) {
				String s=input.readLine();
				System.out.println(client.getInetAddress().toString().substring(1)+" >>>"+ s);
				output.println("ACK for message "+s+" sent at "+DateUtils.now("H:mm:ss:SSS"));
				if(s==null) break;
			}
			output.close();
			input.close();
			client.close();
		}
		catch (IOException e) {
		e.printStackTrace();
		}
	}
}
class Sender extends Thread{
	Socket client;
	BufferedReader input;
	PrintStream output;
	public Sender(Socket c) {
		this.client=c;
	}
	public void run(){
		try {
			output = new PrintStream(client.getOutputStream());
			input = new BufferedReader(new InputStreamReader(System.in));
			while(true) {
				String s=input.readLine();
				System.out.println(">>> " +s );
				output.println(s);
				if(!client.isConnected() || client.isClosed()) break;
			}
			input.close();
			client.close();
			output.close();
		}
		catch (IOException e) {
		e.printStackTrace();
		}
	}
}