<?php
require "vendor/autoload.php";
use \Firebase\JWT\JWT;

include "koneksi.php";

$response = array("error" => FALSE);

$password = $_POST['password'];
$email = mysqli_real_escape_string($koneksi,$_POST['email']);

$url = "http://localhost/wa/web_service.php?function=login";

$context = stream_context_create(array(
    'http' => array('ignore_errors' => true),
));



$ch = curl_init();

$data = array(
'email' => $email,
'password' => $password
);

curl_setopt($ch, CURLOPT_URL, $url);
curl_setopt($ch, CURLOPT_POST, true);
curl_setopt($ch, CURLOPT_POSTFIELDS, $data);
curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);

$resp = curl_exec($ch);

if($e = curl_error($ch))
{
	echo($e);
}
else{
	$json_data = json_decode($resp);
echo $json_data->data[0]->user_password;
$id = $json_data->data[0]->user_id;
$ps = $json_data->data[0]->user_password;

if($json_data->status == 1) {
	
	session_start();
	$response["error"] = FALSE;
	$_SESSION['user_id'] = $id; 
	$_SESSION['user_status'] = 'login'; 
	
	$id = $id;
    $password2 = $ps;
	 if($password2 == $password2)
    {
        $secret_key = "rahasia";
        $issuedat_claim = time(); // issued at
        $expire_claim = $issuedat_claim + 10; // expire time in seconds

		 $payload = [
 			"user_id" => $id,
            "exp" => $expire_claim
];

    $jwt = JWT::encode($payload, $secret_key,'HS256');
		 
		 setcookie("X-PZN-SESSION",$jwt);
	
header("Location:user/index.php");
	return;
	 }
}else{
	$response["error"] = TRUE;
	header("location:index.php?alert=gagal");

}
}




?>