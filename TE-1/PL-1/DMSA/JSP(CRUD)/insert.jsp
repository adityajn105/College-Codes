<%@ page import="java.sql.*" %>
<%@ page import="javax.sql.*" %>
<%--
  Created by IntelliJ IDEA.
  User: aditya
  Date: 14/9/16
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Insert Guest Info</title>
    <style>
        #button{
            background-color:#648BBF;border:1px solid #648BBF;padding:10px;width: 30%;
            margin-top:5px;font-weight:bold;font-size:25px;font-family:sawasdee;
            -webkit-border-radius:10px;-moz-border-radius:10px;border-radius:10px;
        }
        body{
            background-color: darkgray;
        }
        #button:hover{
            border:1px solid #356DB7;margin-right:5px;font-style:italic;font-weight:bold;
            background:-webkit-linear-gradient(225deg,#356DB7,#648BBF);/*background:#356DB7;*/
            background:-moz-linear-gradient(225deg,#356DB7,#648BBF);
            cursor:pointer;font-family:laksaman;border-radius:10px;
            box-shadow:rgba(110,110,110,.5) 5px -5px 3px;
            text-shadow:rgb(110,110,110) 2px -2px 2px;
            transition: transform 1s;
            transform:rotate(-5deg) scale(1.1) translate(0px,-10px);
        }
        a{
            text-decoration: none;
        }
    </style>
</head>
<body>
<p align="center" style="font:bold 30px Comic Sans MS;position:relative;top:20px;color:#D04040;">INDEX</p>
<h3 align="center"><a href="insert.jsp"><div id="button">Insert Guest Info</div></a></h3>
<h3 align="center"><a href="delete.jsp"><div id="button">Delete Guest Info</div></a></h3>
<h3 align="center"><a href="update.jsp"><div id="button">Update Guest Info</div></a></h3>
<h3 align="center"><a href="showall.jsp"><div id="button">Show All Guest Info</div></a></h3>
<hr>
<h4 align="center" style="font:bold 30px Comic Sans MS;
        position:relative;color:#D04040;margin: 0px;padding: 0px;">INSERT GUEST INFO</h4>
<hr>
<%
    final String JDBC_Driver="com.mysql.jdbc.Driver";
    final String DB_USER="jdbc:mysql://localhost/AdityaHotels";
    final String USER="root";
    final String PWD="aditya";
    Connection con=null;
    PreparedStatement preparedStatement = null;
    Statement stmt=null;
    try {
        Class.forName("com.mysql.jdbc.Driver");
        con= DriverManager.getConnection(DB_USER, USER, PWD);
        stmt=con.createStatement();
    String no=request.getParameter("no");
    String name=request.getParameter("name");
    String address=request.getParameter("address");
    if( no!=null && name!=null && address!=null ) {
            String queryInsert = "INSERT INTO GUESTS values (?, ?, ?);";
            preparedStatement = con.prepareStatement(queryInsert);
            preparedStatement.setInt(1, Integer.parseInt(no));
            preparedStatement.setString(2, name);
            preparedStatement.setString(3, address);
            int rows = preparedStatement.executeUpdate();
            out.print("<center>"+rows + " Rows Inserted</center>");
    }
    else{
        if(no!=null || name!=null || address!=null){
            %>
                <h4 align="center" style="color: #D04040">Please fill all Information correctly...</h4>
            <%
        }
%>
<center>
    <form action="insert.jsp" method="post">
    <Label for="no">Guest No.  :</Label>
    <input type="number" name="no" id="no" value="<%out.print(no);%>">
    <br />
    <Label for="name">Guest Name  :</Label>
    <input type="text" name="name" id="name" width="30px" value="<%out.print(name);%>">
    <br />
    <Label for="address" >Guest address  :</Label><br>
    <textarea type="text" name="address" id="address" cols="50" value="<%out.print(address);%>"></textarea>
    <br />
    <input type="submit" value="Submit"/>
    </form>
</center>
<%
        }
    }
    catch (Exception e) {
        out.print("<center>"+e.toString()+"</center><br>");
    }
%>
</body>
</html>
