<%@page import="java.sql.SQLException"%>
<%@page import="java.sql.DriverManager"%>
<%@page import="java.sql.Connection"%>
<%@page import="java.util.List"%>
<%@page import="DAO.Siswa"%>
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
        <h1>Data Siswa</h1>
       <br>
        <%
            try {
                DAO.SiswaDAO dao = new DAO.SiswaDAO();
                List<Siswa> list =  dao.readAlltoList();%>
<form action='from_siswa.jsp' method='post'>
<input type='hidden' name='action' value='insert'/>
<button type="submit" class="btn btn-dark">Tambah Data</button></form><br>
              <table class="table">
             <thead class="thead-dark">
                 <tr>
      <th scope="col">NIM</th>
      <th scope="col">Nama</th>
      <th scope="col">Tanggal Lahir</th>
      <th scope="col">Fakultas</th>
      <th scope="col">Asal</th>
      <th scope="col">Edit</th>
    </tr>
  </thead>
   <tbody>
               
               <% for (Siswa u : list) {
                    String nim = u.getNIM();
                    String nama = u.getNama();
                    String tanggal_lahir = u.getTanggal_Lahir();
                     String fakultas = u.getFakultas();
                      String asal = u.getAsal();
                      String password = u.getpassword();%>
                      
                       <tr>
                   
                        <td> <%out.print(nim);%></td>
                        <td> <%out.print(nama);%></td>
                           <td> <%out.print(tanggal_lahir);%></td>
                           <td> <%out.print(fakultas);%></td>
                           <td> <%out.print(asal);%></td>
               
                      
<td nowrap>             
<% out.print("<form action='from_siswa.jsp' method='post'>"
+"<input type='hidden' name='action' value='edit'/>"
+"<input type='hidden' name='NIM' value='"+nim+"'/>");%>
<button type="submit" class="btn btn-success" style="width: 70px">Ubah</button></form>
 <% out.print("<form action='SiswaService' method='post'>"
+"<input type='hidden' name='NIM' value='"+nim+"'/>"
+"<input type='hidden' name='action' value='delete'/>"); %>
<button type="submit"  class="btn btn-danger"style="width: 70px">Hapus</button></form>
               </td></tr>
               <% }%>
  </tbody>
</table>
<form action='AdminLogin.jsp' method='post'>
<input type='hidden' name='action' value='move'/>
<button type="submit"  class="btn btn-danger">Log Out</button></form>
        <%    } catch (Exception e){
                e.printStackTrace(new java.io.PrintWriter(out));
            } 
        %>
    </body>
</html>