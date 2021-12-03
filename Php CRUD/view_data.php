<html>
<head>
	<title>View Data Buku</title>
</head>
<body bgcolor=" #EFEFEF">
	<br><font size="6" ><center><strong><a>DATA Mahasiswa</a></strong></center><font><br>
	<table width="100%" border="0" align="center" cellpadding="0" cellspacing="0">
			<tr>
			<td height="36"><a href="index.php" >Return</a></td>
			<td>&nbsp;</td>
		</tr>
		<tr bgcolor="#FFA600" height="40">
			<th width="11%">NIM</th>&nbsp;
			<th width="11%">Nama Lengkap</th>&nbsp;
			<th width="11%">Kota Asal</th>&nbsp;
			<th width="11%">Tanggal Lahir</th>&nbsp;   
			<th width="11%">Nama Orang Tua</th>&nbsp; 
			<th width="11%">Alamat Orang Tua</th>&nbsp;   
			<th width="11%">Kode Pos</th>&nbsp; 
			<th width="11%">Nomor Telepon</th>
			<th width="11%">Status</th>
			<th width="11%">Aksi</th>
			<th width="11%">&nbsp;</th>
			&nbsp;   
		</tr>
		
	<?php
		include "koneksi.php";
		//view data mahasiswa di dalam database
		$Lihat="SELECT * FROM Mahasiswa ORDER BY NIM";
		$Tampil = mysqli_query($conn,$Lihat);
		$nomer=0;
		while (	$hasil = mysqli_fetch_array ($Tampil)) {
	$NIM		= stripslashes ($hasil['NIM']);
	$Nama		= stripslashes ($hasil['nama_lengkap']);
	$Kota		= stripslashes ($hasil['Kota_Asal']);
	$Tanggal	= date('Y-m-d',strtotime(stripslashes($hasil['Tanggal_Lahir'])));
	$NamaOrtu   = stripslashes ($hasil['Nama_Orang_Tua']);
	$AlamatOrtu	= stripslashes ($hasil['Alamat_Orang_Tua']);
	$KodePos	= stripslashes ($hasil['Kode_Pos']);
	$NoTelp		= stripslashes ($hasil['Telpon']);
	$Status 	= stripslashes ($hasil['Status']);
			{
		$nomer++;
	
	?>
		<tr bgcolor="#DFE6EF">
			<td>&nbsp;</td>
			<td>&nbsp;</td>
			<td>&nbsp;</td> 
			<td>&nbsp;</td>
			<td>&nbsp;</td>
			<td>&nbsp;</td>
			<td>&nbsp;</td>
			<td>&nbsp;</td>
			<td>&nbsp;</td>
			<td>&nbsp;</td>
			<td>&nbsp;</td>
		</tr>
		<tr align="center" height="40">
			<td><?=$NIM?><div align="center"></div></td>
			<td><?=$Nama?><div align="center"></div></td>
			<td><?=$Kota?><div align="center"></div></td>
			<td><?=$Tanggal?><div align="center"></div></td>
			<td><?=$NamaOrtu?><div align="center"></div></td>
			<td><?=$AlamatOrtu?><div align="center"></div></td>
			<td><?=$KodePos?><div align="center"></div></td>
			<td><?=$NoTelp?><div align="center"></div></td>
			<td><?=$Status?><div align="center"></div></td>
			<td><a href="edit.php?NIM=<?=$NIM?>">Edit</a><div align="center"></div></td>
			<td><a href="hapus.php?NIM=<?=$NIM?>">Hapus</a><div align="center"></div></td>
			<td>&nbsp;</td>

			<td>&nbsp;</td>
		</tr>
		<tr bgcolor="#DFE6EF">
			<td>&nbsp;</td>
			<td>&nbsp;</td>
			<td>&nbsp;</td> 
			<td>&nbsp;</td>
			<td>&nbsp;</td>
			<td>&nbsp;</td>
			<td>&nbsp;</td>
			<td>&nbsp;</td>
			<td>&nbsp;</td>
			<td>&nbsp;</td>
			<td>&nbsp;</td>
			
		</tr>
		<tr>

	<?php  
			}

		}
	//Tutup koneksi engine MySQL
		mysqli_close($conn);
	?>
	</table>
	

</body>
</html>