<%@ page import="java.io.*, java.net.*" %>
<HTML>
    <BODY>
    <center>Number of elements:
    <form action="sort.jsp">
    <input name="number1" type="text" 
      value='<%=request.getParameter("number1")%>' /></center>
    <%       
	 
            String str1 = request.getParameter("number1");
            int n = Integer.parseInt(str1);
    %>
           
            <center>Enter the elements:</center>
    <%
            for(int i=0;i<=n-1;i++)
            {
            	String str="num"+i;
     %>
            	<center><input type="text" name='<%=str%>' /></center>
            	
            	
    <%
            }
	
    %>
    <center><input type="submit" name="sub" id="sub" value="OK"/></center>
    </BODY>
</HTML>
