<?php
	include "koneksi.php";
	//Kirimkan Variabel
	$NIM		= $_POST['NIM'];
	$Nama		= $_POST['Nama_Lengkap'];
	$Kota		= $_POST['Kota_Asal'];
	$Tanggal	= date('Y-m-d',strtotime($_POST['Tanggal_Lahir']));
	$NamaOrtu   = $_POST['Nama_Orang_Tua'];
	$AlamatOrtu	= $_POST['Alamat_Orang_Tua'];
	$KodePos	= $_POST['Kode_Pos'];
	$NoTelp		= $_POST['Telpon'];
	$Status 	= $_POST['Status'];
	
	//validasi id mahasiswa dalam database
	$cek=mysqli_num_rows (mysqli_query($conn,"SELECT NIM FROM mahasiswa WHERE NIM='$_POST[NIM]'"));
	if ($cek > 0) {
	?>
		<script language="JavaScript">
			alert('Data mahasiswa sudah dipakai !, silahkan diulang kembali');
			document.location='index.php';
		</script>
	<?php
	}
	//input data ke table mahasiswa dalam database akademik
	$input	="INSERT INTO mahasiswa (NIM,nama_lengkap,Kota_Asal,Tanggal_Lahir,Nama_Orang_Tua,Alamat_Orang_Tua,Kode_Pos,Telpon,Status)
			VALUES ('$NIM','$Nama','$Kota','$Tanggal','$NamaOrtu','$AlamatOrtu','$KodePos','$NoTelp','$Status')";
	$query_input =mysqli_query($conn,$input);
		if ($query_input) {
	//Jika Sukses
	?>
		<script language="JavaScript">
			alert('Data Buku Berhasil diinput!');
			document.location='index.php';
		</script>
	<?php
	}
	else {
	//Jika Gagal
	echo "Data Buku Gagal diinput, Silahkan diulangi!";
	}
	//Tutup koneksi engine MySQL
	mysqli_close($conn);
?>