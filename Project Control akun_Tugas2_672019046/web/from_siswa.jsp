<%@page import="DAO.Siswa"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
         <link rel="stylesheet" href="https://code.jquery.com/ui/1.12.1/themes/base/jquery-ui.css">
        <script src="https://code.jquery.com/jquery-1.12.4.js"></script>
        <script src="https://code.jquery.com/ui/1.12.1/jquery-ui.js"></script>

        <script>
            $(function () {
                $("#datepicker").datepicker();
            });
            </script>
    </head>
    <body>
        <h1>Olah Data Siswa</h1>
        <% Siswa u = null;
            if (request.getParameter("action").toString().equalsIgnoreCase("edit")) {
            String id = request.getParameter("NIM");
            u = new DAO.SiswaDAO().readOne(id);        
        %>
            <form method="post" action="SiswaService">
            <input type="hidden" name="action" value="update"/><br/>
        <% } else if (request.getParameter("action").toString().equalsIgnoreCase("insert")) { %>
            <form method="post" action="SiswaService">
            <input type="hidden" name="action" value="insert" /><br/>
        <% } %>
        <%
            if (u==null) 
                out.write("NIM <br> <input  name='NIM' type='text'/><br/>");
            else {
                out.write("NIM <br> "+ u.getNIM() + "<br/>");
                out.write("<input name='NIM' type='hidden' value='"+u.getNIM()+"'/>");
            }
        %>
            Nama <br> <input type="text"  name="nama" <% if (u!=null) out.write("value='"+u.getNama()+"'"); %>/><br/>
            Tanggal Lahir <br> <input type="text" name="tanggal_lahir" id="datepicker" <% if (u!=null) out.write("value='"+u.getTanggal_Lahir()+"'"); %>/><br/>
            Fakultas <br> <input type="text" name="fakultas" <% if (u!=null) out.write("value='"+u.getFakultas()+"'"); %>><br/>
            Asal <br> <input type="text" name="asal" <% if (u!=null) out.write("value='"+u.getAsal()+"'"); %>><br/>
                  <%
            if (u==null) 
                out.write("Password <br> <input name='password' type='text'/><br/>");
            else {
               
            }
        %>
        <br>
  <button type="submit" class="btn btn-primary">Simpan</button></form>
            
            
            
        </form>
    </body>
    <script>
</script>
</html>

