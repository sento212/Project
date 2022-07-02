<html>
<head>
	<link rel="stylesheet" type="text/css" href="css/bootstrap.min.css">
	<link rel="stylesheet" type="text/css" href="css1.css">
	<title>Input Data ke Database dengan PHP dan MySQL</title>
		<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
		<script src="https://code.jquery.com/jquery-3.5.1.min.js"></script>
<script src="js/bootstrap.bundle.min.js"></script>
</head>
<body>
	<h1>tesss</h1>
	<form action="action_input.php" method="POST" enctype="multipart/form-data">
		<table border="0" align="center" cellpadding="0" cellspacing="0" class="table1">
		<tr>
			<td colspan="3" height=50px><font size="4" color="blue" ><b style="padding-left: 80px ;" ><strong>INPUT DATA Mahasiswa</strong></b></font></td>
		</tr>
		<tr>
			<td width="11" height="40">&nbsp;</td>
			<td width="291">NIM</td>
			<td width="226"><input type="text" name="NIM" size="28" maxlength="9" onkeypress="return onlyNumberKey(event)"></td>
		</tr>
		<tr>
			<td height="40">&nbsp;</td>
			<td width="291">Nama Lengkap</td>
			<td><input type="text" name="Nama_Lengkap" size="28"></td>
		</tr>
		<tr>
			<td height="40">&nbsp;</td>
			<td width="291">Kota Asal</td>
			<td><input type="text" name="Kota_Asal" size="28"></td>
		</tr>
		<tr>
			<td height="40">&nbsp;</td>
			<td width="291">Tanggal Lahir</td>
			<td><input type="date" name="Tanggal_Lahir" size="28"></td>
		</tr>
<tr>
			<td height="40">&nbsp;</td>
			<td width="291">Nama Orang Tua</td>
			<td><input type="text" name="Nama_Orang_Tua" size="28"></td>
		</tr>
<tr>
			<td height="40">&nbsp;</td>
			<td width="291">Alamat Orang Tua</td>
			<td><input type="text" name="Alamat_Orang_Tua" size="28"></td>
		</tr>
			<tr>
			<td height="40">&nbsp;</td>
			<td width="291">Kode Pos</td>
			<td><input type="text" name="Kode_Pos" size="28" maxlength="5" onkeypress="return onlyNumberKey(event)"></td>
		</tr>
			<tr>
			<td height="40">&nbsp;</td>
			<td width="291">No Telpon</td>
			<td><input type="text" name="Telpon" size="28" maxlength="12" onkeypress="return onlyNumberKey(event)"></td>
		</tr>
				<tr>
			<td height="40">&nbsp;</td>
			<td>Status</td>
			<td>  
	<select name="Status" id="Status">
    <option value="Tama">Tama</option>
    <option value="Wreda">Wreda</option>
  </select>
			</td>
		</tr>
<tr>
			<td height="20"></td>
			<td>&nbsp;&nbsp;</td>
			<td><a href="view_data.php" style="padding-left: 70%" >View Data</a></td>
		</tr>
		<tr>
			<td height="60">&nbsp;</td>
			<td>&nbsp;</td>
			<td><button type="submit" class="btn btn-success">Input</button>&nbsp;&nbsp;&nbsp;
			<button type="reset" class="btn btn-warning">Reset</button>
			
		</tr>
		</table>
	</form>
	
</body>
<script>
    function onlyNumberKey(evt) {
          
        var ASCIICode = (evt.which) ? evt.which : evt.keyCode
        if (ASCIICode > 31 && (ASCIICode < 48 || ASCIICode > 57))
            return false;
        return true;
    }
</script>
</html>