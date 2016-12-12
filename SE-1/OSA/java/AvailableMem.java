import java.io.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;
public class AvailableMem{
    public static void main(String args[]){
	String s,s1,q;
	Process p;
	int count=0;
	System.out.println("\n \n Total memory of the system:"+Runtime.getRuntime().totalMemory());
	System.out.println("\n \n Total Available memory of the system:"+Runtime.getRuntime().freeMemory());
	s1="";
	System.out.println("\n \n Linux System Memory Information \n");
	try{
		//displaying first 5 lines of information for verification
		p=Runtime.getRuntime().exec("cat /proc/meminfo");
		BufferedReader br=new BufferedReader(new InputStreamReader(p.getInputStream()));
		while((s=br.readLine())!=null){
			count++;
			System.out.println(" "+s);
			if(s.subSequence(0,8).equals("MemFree:"))
				s1=s;
		}
		p.waitFor();
		// now displaying extracted output
		System.out.println("\n \n Available memory->:"+s1);
		System.out.println("\n \n exit->:"+p.exitValue());
		System.out.println("\n \n Exiting....");
		p.destroy();

	}
	catch(Exception err){
		err.printStackTrace();
	}
    }
}
