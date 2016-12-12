import java.io.BufferedReader;
import java.io.InputStreamReader;
//import java.lang.*=to include all classes
public class LoginUser
{
	public static void main(String args[])
	{
	int count=0;
	try
	{
		String line;
		Process p1=Runtime.getRuntime().exec("who");
		BufferedReader input=new BufferedReader(new InputStreamReader(p1.getInputStream()));
		line=input.readLine();
		while(line!=null)
		{
			System.out.println(line);
			count++;
			line=input.readLine();
		}
		System.out.println("no of users are"+count);
		input.close();
		 
		p1=Runtime.getRuntime().exec("ps");
		input=new BufferedReader(new InputStreamReader(p1.getInputStream()));
		
		while((line=input.readLine())!=null)
		{
			System.out.println(line);
		}
		input.close();
	}
	catch(Exception e)
	{
		e.printStackTrace();
	}
	}
}		
	
