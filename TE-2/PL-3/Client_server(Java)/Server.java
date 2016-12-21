
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;


public class Server extends Thread{
	ServerSocket server;
	public Server() throws IOException {
		server=new ServerSocket(7956);
		System.out.println("Server Started");
	}
	public void run(){
		try {
				Socket client= server.accept();
				System.out.println("Connected to "+client.getInetAddress().toString());
				new Connection(client).start();
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
				String str = input.readLine();
				if (str != null) {
					System.out.println("Message from client@" + client.getInetAddress().toString() + " :" + str);
					output = new PrintStream(client.getOutputStream());
					output.println("Ack-message( " + str + ")");
				}
			}
			output.close();
            input.close();
			client.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
