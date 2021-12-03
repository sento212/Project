<%@page import="DAO.Admin"%>
<%@page import="java.sql.SQLException"%>
<%@page import="java.sql.DriverManager"%>
<%@page import="java.sql.Connection"%>
<%@page import="java.util.List"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
        <link rel="stylesheet" type="text/css" href="css/bootstrap.min.css">
	<link rel="stylesheet" type="text/css" href="css1.css">
		<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
		<script src="https://code.jquery.com/jquery-3.5.1.min.js"></script>
<script src="js/bootstrap.bundle.min.js"></script>
                <link rel="stylesheet" href="https://code.jquery.com/ui/1.12.1/themes/base/jquery-ui.css">
        <script src="https://code.jquery.com/jquery-1.12.4.js"></script>
        <script src="https://code.jquery.com/ui/1.12.1/jquery-ui.js"></script>
        <script>
            $(function () {
                $("#datepicker").datepicker();
            });
        </script>
        <style>
  
 td {

  text-align:center;
        
}
  
 th {

  text-align:center;
        
}
</style>
    </head>
    <body>
        <h1>Data Admin</h1>
       <br>
        <%
            try {
                 DAO.AdminDAO dao = new DAO.AdminDAO();
                List<Admin> list =  dao.readAlltoList();%>
<form action='from_Admin.jsp' method='post'>
<input type='hidden' name='action' value='insert'/>
<button type="submit" class="btn btn-dark">Tambah Data</button></form><br>
              <table class="table">
             <thead class="thead-dark">
                 <tr>
      <th scope="col">ID</th>
      <th scope="col">Password</th>
      <th scope="col">No telepon</th>
      <th scope="col">Alamat</th>
      <th scope="col">Edit</th>
    </tr>
  </thead>
   <tbody>
               
               <% for (Admin u : list) {
                    String ID = u.getID();
                    String password = u.getpassword();
                    String no_tlp = u.getno_telp();
                     String alamat = u.getalamat();%>
                      
                       <tr>
                   
                        <td> <%out.print(ID);%></td>
                        <td> <%out.print(password);%></td>
                           <td> <%out.print(no_tlp);%></td>
                           <td> <%out.print(alamat);%></td>

               
                      
<td nowrap>             

 <% out.print("<form action='AdminService' method='post'>"
+"<input type='hidden' name='ID' value='"+ID+"'/>"
+"<input type='hidden' name='action' value='delete'/>"); %>
<button type="submit"  class="btn btn-danger"style="width: 70px">Hapus</button></form>
               </td></tr>
               <% }%>
  </tbody>
</table>
<form action='Root.jsp' method='post'>
<input type='hidden' name='action' value='move'/>
<button type="submit"  class="btn btn-danger">Log Out</button></form>
        <%    } catch (Exception e){
                e.printStackTrace(new java.io.PrintWriter(out));
            } 
        %>
    </body>
</html>