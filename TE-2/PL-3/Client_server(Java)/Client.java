
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
		
		try{
			server=new Socket("localhost",7956);
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			boolean more=true;
			out=new PrintStream(server.getOutputStream());
			in=new BufferedReader(new InputStreamReader(server.getInputStream()));
            out.println(more);
            while(more){
				System.out.print("Data to send to "+server.getInetAddress().toString()+" :");
				msg=br.readLine();
				out.println(msg);

				String ack=in.readLine();
				System.out.println(ack);
				System.out.print("Send more Data?(y or n)  ");
				String ch=br.readLine();
				more = ch.equals("y");
                out.println(more);
			}
			out.close();
			in.close();
			br.close();

		}catch(IOException ie){}
	}
	
}
