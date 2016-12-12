import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.lang.String;
//import java.lang.*
public class PhysicalDevices{		
	public static void main(String args[]){	 
		String s,p,q;
		int count=0;
		Process p1;	//p1 is instance of class Process
		try
		{
			System.out.println("\nI-No of instances");
			System.out.println("\nII-User name");
			System.out.println("\nIII-Terminal name");
			System.out.println("\nIV-major no");
			System.out.println("\nV-minor no.");
			System.out.println("\nI II  III     IV    V    device name\n");
			p1=Runtime.getRuntime().exec("ls -l /dev");	
			
			BufferedReader brq=new BufferedReader(new InputStreamReader(p1.getInputStream()));
			//bufferreader is a class and brq is its object
			//getInputStream() reads info from p1 in byte form and pass to InputStreamReader() class
			//InputStreamReader() converts bytes to chars and pass to bufferreader brq
			while((s=brq.readLine())!=null)
			{
				try{
				p=s.substring(12,34);	//s is class of string...substring is method to cut columns
				count=s.length();
				q=s.substring(48,count);
				System.out.println(p+""+q);
				}
				catch(Exception e1){}
			}
			p1.waitFor();
			System.out.println("exit :"+p1.exitValue());
			p1.destroy();
		}
		catch(Exception e){}	
	}	 
}		 	

