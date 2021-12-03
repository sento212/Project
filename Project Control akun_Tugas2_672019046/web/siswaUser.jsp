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
            <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
        <link rel="stylesheet" type="text/css" href="css/bootstrap.min.css">
	<link rel="stylesheet" type="text/css" href="css1.css">
		<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
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
    <center>  <h1><br>Welcome ${user.nama} Dari ${user.asal} Fakultas ${user.fakultas} <br> Selamat Datang Di UKSW</h1></center>

        <h4><br> Data Mahasiswa Tahun Ini yang mungkin bisa menjadi teman anda</h4>

     <br>
        <%
            try {
                DAO.SiswaDAO dao = new DAO.SiswaDAO();
                List<Siswa> list =  dao.readAlltoList();%>

              <table class="table">
             <thead class="thead-dark">
                 <tr>
     
      <th scope="col">Nama</th>
      <th scope="col">Fakultas</th>
    </tr>
  </thead>
   <tbody>
               
               <% for (Siswa u : list) {
                
                    String nama = u.getNama();
                     String fakultas = u.getFakultas();
%>
                      
                       <tr>
                   
              
                        <td> <%out.print(nama);%></td>
                           <td> <%out.print(fakultas);%></td>
               
                      </tr>
               <% }%>
  </tbody>
</table>
<form action='index.jsp' method='post'>
<input type='hidden' name='action' value='move'/>
<button type="submit"  class="btn btn-danger">Log Out</button></form>
        <%    } catch (Exception e){
                e.printStackTrace(new java.io.PrintWriter(out));
            } 
        %>
    </body>
</html>