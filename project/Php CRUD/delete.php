<?php
    include "koneksi.php";
	$NIM		    = $_GET['NIM'];
    $ambilData = mysqli_query($conn, "DELETE FROM mahasiswa WHERE NIM='$NIM'");
if ($ambilData) {
	//Jika Sukses
	?>
		<script language="JavaScript">
			alert('Data Buku Berhasil DIHAPUS!');
			document.location='view_data.php';
		</script>

	<?php
	}
	else {
	//Jika Gagal
	echo "Data Buku Gagal DIHAPUS, Silahkan diulangi!";
	}
	//Tutup koneksi engine MySQL
	mysql_close($conn);
?>
 