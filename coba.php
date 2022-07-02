<?php 

$url = "http://localhost/wa/web_service.php?function=login";

$ch = curl_init();

$data = array(
'email' => 'hamma@gmail.com',
'password' => 'hamma'
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
	$decode = json_decode($resp);
print_r($decode);
}



?>