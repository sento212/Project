<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<link rel="stylesheet" type="text/css" href="../assets/css/bootstrap.css">
	<link rel="stylesheet" type="text/css" href="../assets/css/sapateman.css">
	<link href="https://stackpath.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css" rel="stylesheet" integrity="sha384-wvfXpqpZZVQGK6TAh5PVlGOfQNHSoD2xbE+QkPxCAFlNEevoEH3Sl0sibVcOQVnN" crossorigin="anonymous">

	<script type="text/javascript" src="../assets/js/jquery.js"></script>
	<script type="text/javascript" src="../assets/js/popper.js"></script>
	<script type="text/javascript" src="../assets/js/bootstrap.js"></script>

	<title>Meet Up</title>

</head>
<body>
	<?php 
	

require "../vendor/autoload.php";
use \Firebase\JWT\JWT;

	if($_COOKIE['X-PZN-SESSION']){
		$secret_key = "rahasia";
		$jwt = $_COOKIE['X-PZN-SESSION'];
	}
	


 try {
	 
session_start();
	$token=(json_decode(base64_decode(str_replace('_', '/', str_replace('-','+',explode('.', $jwt)[1])))));
	$now = new DateTimeImmutable();
	 if ($token->user_id !== $_SESSION['user_id'] ||
    $token->exp < $now->getTimestamp())
{
    header('Session habis silahkan keluar');
    exit;
}
	 
	 
	date_default_timezone_set('Asia/Jakarta');
	include "../koneksi.php";
	if($_SESSION['user_status'] != "login"){
		session_destroy();
		header("location:../index.php?alert=login-dulu");
	}
	$id_user = $_SESSION['user_id'];
	$s = mysqli_query($koneksi,"select * from user where user_id='$id_user'");
	$saya = mysqli_fetch_assoc($s);
	

    }catch (Exception $e){
    echo json_encode(array(
        "message" => "Access denied.",
        "error" => $e->getMessage()
    ));
 }
	
	?>
	<div class="container-fluid p-0">
		
		<div class="row kotak">

			<div class="col-12 col-md-3 kotak-kiri d-none d-sm-none d-md-block">

				<div class="kotak-kiri-sidebar">

					<nav class="navbar navbar-expand-lg navbar-light bg-light">



						<div class="dropdown ml-auto">
							<div class="dropdown-toggle" id="dropdownMenuButton2" data-toggle="dropdown" aria-haspopup="tre" aria-expanded="flse">
								<i class="fa fa-cog"></i>
							</div>
							<div class="dropdown-menu dropdown-menu-right" aria-labelledby="dropdownMenuButton2">

								<a class="dropdown-item" href="logout.php">Keluar</a>
							</div>
						</div>

					</nav>




					<div class="teman"></div>
				</div>

			</div>


			<div class="col-md-9 col-12 conversation">

				<nav class="navbar navbar-expand-lg navbar-light bg-light" style="min-height: 70px">

					<div class="dropdown">
						<div class="lawan" href="#">

						</div>

					</div>

					<div class="dropdown float-right ml-4 d-block d-md-none">
						<button class="btn btn-secondary float-right tombol-tampil-user-mobile"><i class="fa fa-users"></i></button>
					</div>

				</nav>


				<div class="pesan" id="conversation">



				</div>

				<div class="row balas py-2 d-none">
					<div class="col-sm-2 col-2">
						<div class="upload-btn-main">

						</div>
					</div>

					<div class="col-sm-8 col-6">
						<textarea class="form-control" id="balas-ketik" placeholder="Ketik pesan .."></textarea>
					</div>

					<div class="col-sm-2 col-4">

						<button class="btn btn-primary p-2 balas-kirim"><i class="fa fa-send"></i></button>
					</div>

				</div>


			</div>

		</div>

	</div>


	<?php include 'ajax.php'; ?>

</body>
</html>