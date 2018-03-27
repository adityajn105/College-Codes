<%@ page import="java.io.*, java.net.*" %>
<HTML>
   <BODY>
	 <%       
	 try
        {      
            Socket s=new Socket("localhost",8776);  
	    DataOutputStream dout=new DataOutputStream(s.getOutputStream());  
	    DataInputStream inSocket = new DataInputStream(s.getInputStream());
	    String str1 = request.getParameter("number1");
	    dout.writeUTF(str1);  
	    dout.flush(); 
	    int n = Integer.parseInt(str1);
	    for(int i=0;i<=n-1;i++)
	    {
	    	String name="num"+i;
	    	str1 = request.getParameter(name);
	    	dout.writeUTF(str1);  
	    	dout.flush(); 
	    }
            dout.flush(); 
	    String strr;
	    
	    try
	    {
		    while(inSocket.available() == 0)
		    {
		    	out.println("Original array:");
		    	strr=(String)inSocket.readUTF();
		    	out.print(strr);
		    	%>
		    	<br><br>
		    	<%
		    	out.println("Sorted array:");
		    	strr=(String)inSocket.readUTF();
		    	out.print(strr);
			inSocket.close();    
		    }
            }
            catch(Exception e){}
            dout.close();  
            s.close();  
    	}
    	catch(ConnectException e)
    	{%>
    		Please connect to the Server...
    	<%	
    	}  
        %>
   </BODY>
</HTML>
