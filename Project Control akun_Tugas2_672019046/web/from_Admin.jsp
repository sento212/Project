<%@page import="DAO.Admin"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>edit</title>
   <link rel="stylesheet" type="text/css" href="css/bootstrap.min.css">
	<link rel="stylesheet" type="text/css" href="css1.css">
<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<script src="https://code.jquery.com/jquery-3.5.1.min.js"></script>
    </head>
    <body>
        <h1>Olah Data Admin</h1>      
            <form method="post" action="AdminService">
            <input type="hidden" name="action" value="insert"/><br/>      
  <div class="form-group">
    <label for="exampleInputPassword1">ID</label>
    <input type="text" class="form-control"  placeholder="ID" name='ID'>
  </div>
  <div class="form-group">
    <label for="exampleInputPassword1">Password</label>
    <input type="password" class="form-control" name="password" placeholder="Password">
  </div>
              <div class="form-group">
    <label for="exampleInputPassword1">No Telepon</label>
    <input type="text" class="form-control" name="no_telp" placeholder="No_Telp">
  </div>
              <div class="form-group">
    <label for="exampleInputPassword1">Alamat</label>
    <input type="text" class="form-control" name="alamat" placeholder="Alamat">
  </div>
  <button type="submit" class="btn btn-primary">Simpan</button></form>
        </form>
    </body>
</html>
