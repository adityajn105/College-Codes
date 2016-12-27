import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;
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
				new Connection(client).start();
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
class Connection extends Thread{
	Socket client;
	BufferedReader input;
	PrintStream output;
	public Connection(Socket c) {
		this.client=c;
	}
	public void run(){
		try {
			input = new BufferedReader(new InputStreamReader(client.getInputStream()));
			while(Boolean.parseBoolean(input.readLine())) {
				output = new PrintStream(client.getOutputStream());
				int choice=Integer.parseInt(input.readLine());
				String inputs = input.readLine();
				Scanner scan =new Scanner(inputs);
				scan.useDelimiter(",");
				int a=Integer.parseInt(scan.next());
				int b=Integer.parseInt(scan.next());
				switch (choice){
					case 1: System.out.println("Addition Request from client@" + client.getInetAddress().toString() + " :" +inputs );
							output.println(CalculatorAPI.addition(a,b));
							break;
					case 2: System.out.println("Subtraction Request from client@" + client.getInetAddress().toString() + " :" +inputs );
							output.println(CalculatorAPI.subtraction(a,b));
							break;
					case 3:	System.out.println("Multiplication Request from client@" + client.getInetAddress().toString() + " :" +inputs );
							output.println(CalculatorAPI.multiplication(a,b));
							break;
					case 4:	System.out.println("Division Request from client@" + client.getInetAddress().toString() + " :" +inputs );
							output.println(CalculatorAPI.division(a,b));
							break;
				}
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

class CalculatorAPI{
	public static int addition(int a,int b){ return a+b;};
	public static int subtraction(int a,int b){ return a-b;};
	public static int multiplication(int a, int b){return a*b;}
	public static int division(int a,int b){return a/b;};
}
