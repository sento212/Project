  <%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>

<html>
<head>
<meta charset="utf-8">
<title>Login User</title>
<link href="//maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css" rel="stylesheet" id="bootstrap-css">
<script src="//maxcdn.bootstrapcdn.com/bootstrap/4.0.0/js/bootstrap.min.js"></script>
<script src="//cdnjs.cloudflare.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>
<link rel="stylesheet" type="text/css" href="css.css">
</head>
<body>
            
            <div class="wrapper fadeInDown">
  <div id="formContent">

    <div class="fadeIn first">
    </div>
      <br>
  <h1>Admin Login</h1>

     <form action="login" method="post">
      <input type="text" id="login" class="fadeIn second" name="ID" placeholder="ID">
      <input type="text" id="password" class="fadeIn third" name="password" placeholder="password">
      <input type="submit" class="fadeIn fourth" value="Log In">
    <br>${message}
    </form>

    <div id="formFooter">
      <a class="underlineHover" href="index.jsp">Login As User</a>
      <a class="underlineHover" href="Root.jsp">Login As Root</a>
        
    </div>

  </div>
</div>
</body>
</html>

