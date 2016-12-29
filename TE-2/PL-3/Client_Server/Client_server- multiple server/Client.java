import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.Socket;
public class Client {
	public static void main(String[] args) {
		String msg;
		Socket server;
		PrintStream out;
		BufferedReader in;
		if(args.length==0){
			System.err.println("Please pass master address");
		}
		try{
            Socket master=new Socket(args[0],7956);
            BufferedReader input = new BufferedReader(new InputStreamReader(master.getInputStream()));
            PrintStream output = new PrintStream(master.getOutputStream());
            output.println("GETAVAIL");
            String cadd=input.readLine();
            if(cadd.equals("NOTAVAIL")){
                System.out.println("Currently No Server is Available. Please try after sometime.");
            }
            else {
                output.println("OK");
                System.out.println("Trying to connect to server@" + cadd);
                server = new Socket(cadd, 7955);
                new CReciever(server).start();
                new CSender(server).start();
            }
		}
		catch(IOException ie){}
	}
}

class CReciever extends Thread{
	Socket client;
	BufferedReader input;
	PrintStream output;
	public CReciever(Socket c) {
		this.client=c;
	}
	public void run(){
		try {
			input = new BufferedReader(new InputStreamReader(client.getInputStream()));
			output = new PrintStream(client.getOutputStream());
			while(true) {
				String s=input.readLine();
				if(s.subSequence(0, 3).equals("ACK")){
					System.out.println(s);
				}
				else{
					System.out.println(client.getInetAddress().toString().substring(1)+" >>>"+ s);
				}
				if(s==null) break;
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
class CSender extends Thread{
	Socket client;
	BufferedReader input;
	PrintStream output;
	public CSender(Socket c) {
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