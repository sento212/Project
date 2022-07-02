<?php 
session_start();
date_default_timezone_set('Asia/Jakarta');
$id_saya = $_SESSION['user_id'];
$ketik = $_POST['ketik'];
$penerima = $_POST['lawan'];
$pengirim = $id_saya;
$isi = $ketik;
$waktu = date('Y-m-d H:i:s');


$url = "http://localhost/wa/web_service.php?function=insert_pesan&user_id=".$pengirim."&ketik=".$isi."&lawan=".$penerima;

$xml = simplexml_load_file($url); 

?>
<div class="row">
	<div class="col-12">
		<div class="media pesan-item mb-2 pesan-saya">							
			<div class="media-body">
				<?php echo $isi ?>
				<div class="pesan-waktu"><small><?php echo date('H:i',strtotime($waktu)); ?></small></div>
			</div>
		</div>
	</div>
</div>