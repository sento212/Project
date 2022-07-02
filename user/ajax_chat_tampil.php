<div class="row">

	<?php 
	include '../koneksi.php';
	session_start();
	date_default_timezone_set('Asia/Jakarta');
	$id_saya = $_SESSION['user_id'];
	$id_user = $_POST['id'];
	if($id_saya == null && $id_user ==null or $id_saya == $id_saya && $id_user ==$id_user )
	{
	$idsesion = $id_saya;
	$id_user1 = $id_user;

		
	}
		?>

	<?php 
	
	$url = "http://localhost/wa/web_service.php?function=tampilkan_pesan&user_id=".$idsesion."&id=".$id_user1;

	$context = stream_context_create(array(
    'http' => array('ignore_errors' => true),
));
	
	$json = file_get_contents($url, false, $context);
	$json_data = json_decode($json);


?>

	<?php 
	
	 foreach($json_data->data as $count)
	 {
		 if(is_null($count))
		 {
			 continue;
		 }
	?>
		<div class="col-12">
			<div class="media pesan-item mb-2 <?php if($count->chat_pengirim == $id_saya){echo "pesan-saya";}else{echo "pesan-teman";} ?>">							
				<div class="media-body">
					<?php 
					if($count->chat_tipe == "gambar"){
						 echo $count->chat_isi;

					}elseif($count->chat_tipe == "file"){
						?>
						<div class="pesan-file">
							<a target="_blank" href="../gambar/file/<?php echo $count->chat_isi;?>"><?php echo $count->chat_isi; ?></a>
						</div>
						<?php
					}else{

						echo $count->chat_isi;
					}

					?>
					<div class="pesan-waktu">

						<small>
							<?php echo(date('H:i',strtotime($count->chat_waktu))); ?>

							<?php 
							// cek apakah yanng chat adalah saya, jika iya tampilkan status checklist
							if($count->chat_pengirim == $id_saya){
								// cek apakah status chat sudah dibaca, jika iya tampilkan check warna biru
								if($count->chat_status == 1){
									?>
									<span class="text-primary"><i class="fa fa-check"></i></span>
									<?php 
								}else{
									?>
									<span class=""><i class="fa fa-check"></i></span>
									<?php
								}
							}
							?>

						</small>
					</div>
				</div>
			</div>
		</div>

		<?php 

	}

	

	?>
</div>