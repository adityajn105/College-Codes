<%--
  Created by IntelliJ IDEA.
  User: aditya
  Date: 30/8/16
  Time: 12:06 AM
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
  <head>
    <title>Welcome</title>
    <style>
      #button{
        background-color:#648BBF;
        border:1px solid #648BBF;
        padding:10px;
        width: 30%;
        margin-top:5px;
        font-weight:bold;
        font-size:25px;
        -webkit-border-radius:10px;-moz-border-radius:10px;border-radius:10px;
        font-family:sawasdee;
      }
      body{
        background-color: darkgray;
      }
      #button:hover{
        border:1px solid #356DB7;
        background:-webkit-linear-gradient(225deg,#356DB7,#648BBF);/*background:#356DB7;*/
        background:-moz-linear-gradient(225deg,#356DB7,#648BBF);
        margin-right:5px;
        font-style:italic;
        font-weight:bold;
        cursor:pointer;
        font-family:laksaman;
       border-radius:10px;
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
  <h3 align="center"><a href="inner.jsp"><div id="button">All Rooms(Inner Join)</div></a></h3>
  <h3 align="center"><a href="left.jsp"><div id="button">Bookings done by Guests(Left Join)</div></a></h3>
  <h3 align="center"><a href="right.jsp"><div id="button">Guests and their Bookings(Right Join)</div></a></h3>
  <hr>
  </body>

  </body>
</html>
