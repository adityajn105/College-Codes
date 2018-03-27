import java.lang.*;
import java.io.*;  
import java.net.*;  
public class MyServer1 
{ 

    DataInputStream dis; 
    DataOutputStream diso;
    ServerSocket ss;
    Socket s;
    static int n;
    static int array[];
    static StringBuilder sb;
    static StringBuilder result;
    void establishConnection()
    {
    	try
    	{
    		ss=new ServerSocket(8776);
		s=ss.accept();//establishes connection 
		
		dis=new DataInputStream(s.getInputStream());
         	diso=new DataOutputStream(s.getOutputStream());   
	}
	catch(Exception e)
	{
		System.out.println(e);
	}
    }
    

    void getData()
    {
    	try
	    {  
		String str=(String)dis.readUTF();  		
		n = Integer.parseInt(str);
		array=new int[n];
		for(int i=0;i<n;i++)
		{
			str=(String)dis.readUTF();
			array[i]=Integer.parseInt(str);
		}
		
	    }
	    catch(Exception e)
	    {
	    	System.out.println(e);
	    }  
	    
    }

 
    void sendResult()
    {
    	try
    	{
		diso.writeUTF(sb.toString());
		diso.writeUTF(result.toString());
		diso.flush();
		diso.close();
		ss.close();
	}
	catch(Exception e) 
	{
		System.out.println(e);
	}

    }

    
    public static void main(String[] args)
    {  
	    MyServer1 b = new MyServer1();
	    b.establishConnection();		
	    b.getData();
	    int i;
	  sb = new StringBuilder();
	  
	  for(i = 0; i < array.length; i++)
	  {
		    //System.out.println(array[i]);
		  sb.append(array[i]+" ");
	}
	  System.out.println();
	  
	  odd_even_srt(array,array.length);
	  
	  result = new StringBuilder();
	  for(i = 0; i <array.length; i++)
	  {
	  	  //System.out.println(array[i]);

		 result.append(array[i]+" ");
		}	 
	  System.out.println();
    	 b.sendResult();    
    }  
    
    public static void odd_even_srt(int array[],int n)
	  {
	  for (int i = 0; i < n/2; i++ )
	  {
		  for (int j = 0; j+1 < n; j += 2)
		  {
			  Runnable t1=new mythread(array,j);
			  Thread t2=new Thread(t1);
			  t2.start();
		  }
		  for (int j = 1; j+1 < array.length; j += 2)
		  {
			  Runnable t3=new mythread(array,j);
			  Thread t4=new Thread(t3);
			  t4.start();
		  }
	  }

	  }

} 

class mythread implements Runnable
{
	int j;
	private int[] array;
	public mythread(int arr[],int j)
	{
		this.j=j;
		this.array=arr;
	}
	public void run() 
	{	
		if (array[j] > array[j+1]) 
		  {
		  int T = array[j];
		  array[j] = array[j+1];
		  array[j+1] = T;
		  }
		
	}

}
 
