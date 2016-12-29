import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.HashMap;

/**
 * Created by aditya on 29/12/16.
 */
public class Master {
    public static void main(String args[]) throws IOException{
        ServerSocket master = new ServerSocket(7956);
        HashMap<String,String> servermap=new HashMap<>();
        System.out.println("Master server started");
        while(true){
            Socket socket=master.accept();
            PrintStream output = new PrintStream(socket.getOutputStream());
            BufferedReader input=new BufferedReader(new InputStreamReader(socket.getInputStream()));
            if(input.readLine().equals("AVAIL")){
                System.out.println("Registering a Server @"+socket.getInetAddress().toString().substring(1));
                servermap.put(socket.getInetAddress().toString().substring(1),"AVAIL");
                output.println("true");
                output.close();
                input.close();
                socket.close();
            }
            else{
                boolean done=false;
                System.out.println("Getting Request from Client @"+socket.getInetAddress().toString().substring(1));
                for(String server:servermap.keySet()){
                    if(servermap.get(server).equals("AVAIL")){
                        output.println(server);
                        System.out.println("Assigning server@"+server+" to client@"+socket.getInetAddress().toString().substring(1));
                        if(input.readLine().equals("OK")) {
                            servermap.put(server,"NOTAVAIL");
                            done=true;
                            break;
                        }
                    }
                }
                if(!done) output.println("NOTAVAIL");
                output.close();
                input.close();
                socket.close();
            }
        }


    }
}
