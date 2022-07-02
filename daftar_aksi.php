<?php
include("koneksi.php");

$nama = mysqli_real_escape_string($koneksi,$_POST['nama']);
$email = mysqli_real_escape_string($koneksi,$_POST['email']);
$password = ($_POST['password']);

$url = "http://localhost/wa/web_service.php?function=check";

$data2 = array(
'email' => $email
);

$ch = curl_init();
curl_setopt($ch, CURLOPT_URL, $url);
curl_setopt($ch, CURLOPT_POST, true);
curl_setopt($ch, CURLOPT_POSTFIELDS, $data2);
curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);


	$context = stream_context_create(array(
    'http' => array('ignore_errors' => true),
));

$resp = curl_exec($ch);

if($e = curl_error($ch))
{
	echo($e);
}
else{
	$json_data = json_decode($resp);
	if($json_data ->status > 0){
	header("Location:daftar.php?alert=duplikat");
}else{
	// daftar user
	$url2 = "http://localhost/wa/web_service.php?function=daftar";
	
	
	$ch = curl_init();

$data = array(
	'nama' => $nama,
'email' => $email,
'password' => $password
);

curl_setopt($ch, CURLOPT_URL, $url2);
curl_setopt($ch, CURLOPT_POST, true);
curl_setopt($ch, CURLOPT_POSTFIELDS, $data);
curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);

$resp = curl_exec($ch);


}




	

header("Location:index.php?alert=registered");
}

?>