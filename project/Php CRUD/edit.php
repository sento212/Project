<?php
    include "koneksi.php";
    $NIM = $_GET['NIM'];
    $ambilData = mysqli_query($conn, "SELECT * FROM mahasiswa WHERE NIM='$NIM'");
    $data=mysqli_fetch_array($ambilData);
?>
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
	<form method="POST" enctype="multipart/form-data">
		
		<table width="39%"  border="0" align="center" cellpadding="0" cellspacing="0" class="table1">
		<tr>
			<td width="4" height="40">&nbsp;</td>
			<td>&nbsp;</td>
			<td width="335"><font size="4" color="blue" ><b style="padding-left: 35px"><strong>EDIT DATA MAHASISWA</strong></b></font></td>
		</tr>
	
			
		<tr>
			<td height="40">&nbsp;</td>
			<td width="71">NIM</td>
			<td><?php echo $data['NIM']?></td>
		<tr>
			<td height="40">&nbsp;</td>
			<td>Nama Lengkap</td>
			<td><input type="text" name="nama_lengkap" size="30"  value="<?php echo $data['nama_lengkap']?>"></td>
		</tr>
		<tr>
			<td height="40">&nbsp;</td>
			<td>Kota Asal</td>
			<td><input type="text" name="Kota_Asal" size="30"  value="<?php echo $data['Kota_Asal']?>"></td>
		</tr>
		<tr>
			<td height="40">&nbsp;</td>
			<td>Tanggal Lahir</td>
			<td><input type="date" name="Tanggal_Lahir" size="28"></td>
		</tr>
		<tr>
			<td height="40">&nbsp;</td>
			<td>Nama Orang Tua</td>
			<td><input type="text" name="Nama_Orang_Tua" size="30"  value="<?php echo $data['Nama_Orang_Tua']?>"></td>
		</tr>

		<tr>
			<td height="40">&nbsp;</td>
			<td>Alamat Orang Tua</td>
			<td><input type="text" name="Alamat_Orang_Tua" size="30"  value="<?php echo $data['Alamat_Orang_Tua']?>"></td>
		</tr>
		<tr>
			<td height="40">&nbsp;</td>
			<td>Kode Pos</td>
			<td><input type="text" name="Kode_Pos" size="30" maxlength="5" onkeypress="return onlyNumberKey(event)" value="<?php echo $data['Kode_Pos']?>"></td>
		</tr>
		<tr>
			<td height="40">&nbsp;</td>
			<td>Telepon</td>
			<td><input type="text" name="Telpon" size="30" maxlength="12" onkeypress="return onlyNumberKey(event)" value="<?php echo $data['Telpon']?>"></td>
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
			<td height="60">&nbsp;</td>
			<td>&nbsp;&nbsp;</td>
			<td><button type="submit" name="simpan" class="btn btn-success" style="width: 80px">Update</button>&nbsp;&nbsp;&nbsp;
				<a href="view_data.php" class="btn btn-danger" role="button" style="width: 80px">Batal</a>

			</td>
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

<?php
        if(isset($_POST['simpan']))
        {

	$Nama		= $_POST['nama_lengkap'];
	$Kota		= $_POST['Kota_Asal'];
	$Tanggal		= $_POST['Tanggal_Lahir'];
	$NamaOrtu	= $_POST['Nama_Orang_Tua'];
	$AlamatOrtu	= $_POST['Alamat_Orang_Tua'];
	$KodePos		= $_POST['Kode_Pos'];
	$NoTelp		= $_POST['Telpon'];
	$Status		= $_POST['Status'];
	

            mysqli_query($conn, "UPDATE mahasiswa 
            SET NIM='$NIM', nama_lengkap='$Nama', Kota_Asal='$Kota', Tanggal_Lahir='$Tanggal', Nama_Orang_Tua='$NamaOrtu', Alamat_Orang_Tua='$AlamatOrtu', Kode_Pos='$KodePos', Telpon='$NoTelp', Status='$Status'
            WHERE NIM='$NIM'") or die(mysqli_error($conn));

            echo "<div align='center'><h5> Silahkan Tunggu... </h5></div>";
            echo "<meta http-equiv='refresh' content='1;url=http://localhost/tugas5/view_data.php'>";
        }

?>