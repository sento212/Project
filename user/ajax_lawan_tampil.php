<?php 
include '../koneksi.php';
session_start();
date_default_timezone_set('Asia/Jakarta');
$id_saya = $_SESSION['user_id'];
$id_user = $_POST['id'];
// menampilkan nama user di kolom atas chat

$url = "http://localhost/wa/web_service.php?function=lawan&user_id=".$id_saya."&id=".$id_user;

	$context = stream_context_create(array(
    'http' => array('ignore_errors' => true),
));
	
	$json = file_get_contents($url, false, $context);
	$json_data = json_decode($json);
	 foreach($json_data->data as $count)
	 {
?>
<div class="avatar-lawan" id="<?php echo $count->user_id; ?>>

	<span class="ml-2 mt-5"><?php echo $count->user_nama; }?></span>

</div>


