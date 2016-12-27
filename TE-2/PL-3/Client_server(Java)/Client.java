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
			server=new Socket(args[0],7956);
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			boolean more=true;
			out=new PrintStream(server.getOutputStream());
			in=new BufferedReader(new InputStreamReader(server.getInputStream()));
			out.println(more);
			while(more){
				System.out.print("Menu>>>\n 1. Addition\n 2. Subtraction\n 3. Multiplication\n 4. Division\n Your Choice :");
				out.println(Integer.parseInt(br.readLine()));
				System.out.print("Inputs (seperate by ,) to send to "+server.getInetAddress().toString()+" :");
				msg=br.readLine();
				out.println(msg);
				int res=Integer.parseInt(in.readLine());
				System.out.println("Result Recieved : "+res);
				System.out.print("Calculate More?(y or n) ");
				String ch=br.readLine();
				more = ch.equals("y");
				out.println(more);
			}
			out.close();
			in.close();
			br.close();
		}
		catch(IOException ie){}
		}
}