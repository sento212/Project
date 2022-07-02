<?php 
include '../koneksi.php';
session_start();
date_default_timezone_set('Asia/Jakarta');
$id_saya = $_SESSION['user_id'];

$url = "http://localhost/wa/web_service.php?function=show_user&user_id=".$id_saya;

	$context = stream_context_create(array(
    'http' => array('ignore_errors' => true),
));
	
	$json = file_get_contents($url, false, $context);
	$json_data = json_decode($json);
	 foreach($json_data->data as $count)
	 {
	?>
	<div class="row teman-list" id="<?php 
	echo $count->user_id; ?>">
		<div class="col-3 col-sm-3 col-xs-3 teman-avatar">
			<div class="avatar-icon">

					<img class="avatar-icon-<?php echo $count->user_status; ?>" src="../gambar/default/user.png">

			</div>
		</div>
		<div class="col-9 col-sm-9 col-xs-9 teman-main">

			<!-- menampilkan nama pada user yang terdaftar -->
			<?php 
			if($json_data->status >= 0){
				?>


				<div class="row">

					<div class="col-sm-9 col-xs-8 teman-data">
						<span class="nama-meta font-weight-bold"><?php echo $count->user_nama ?></span>
					</div>
					<div class="col-sm-3 col-xs-4 pull-right teman-time">

						<span class="time-meta pull-right">
							<?php 


							?>
							<br>

						</span>
					</div>

				</div>

				<?php 
			
	 }
	 
			?>

		</div>
	</div>	
	<?php 
}
?>
