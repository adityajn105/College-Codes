import java.io.BufferedReader;
import java.io.InputStreamReader;
//import java.lang.*;
public class ProcessPriority{
  public static void main(String args[]){
 	String str, str1;
 	Process p;
 	try{
  		p= Runtime.getRuntime().exec("ps -lf");
  		BufferedReader brq;
  		BufferedReader br =new BufferedReader(new InputStreamReader(p.getInputStream()));
  		while((str = br.readLine())!=null) 
     			System.out.println(" " +str);
  		p.waitFor();
  		System.out.println("exit :"+p.exitValue());
  		System.out.println("Changing the priority of the processes with Renice with default value \n");
		System.out.println("Press any key to continue ...");
  		brq= new BufferedReader(new InputStreamReader(System.in));
		str1= brq.readLine();
		p= Runtime.getRuntime().exec("renice -n 10 -u student");
		p=Runtime.getRuntime().exec("clear");
		System.out.println("\n\n Dispalying the renewed Priority now \n");
		p= Runtime.getRuntime().exec("ps -lf");
		br =new BufferedReader(new InputStreamReader(p.getInputStream()));
		while((str = br.readLine())!=null) 
		     System.out.println(" " +str);
		p.waitFor();
		System.out.println("exit :"+p.exitValue());
		p.destroy();
	}
	catch(Exception e){}
  }
}
