<?php
require_once "koneksi.php";
   if(function_exists($_GET['function'])) {
         $_GET['function']();
      }   


   function insert_pesan()
      {
 global $koneksi;
date_default_timezone_set('Asia/Jakarta');
$waktu = date('Y-m-d H:i:s');
$status = 0;
$tipe = "text"; 
$id = $_GET['user_id'];
$isi = $_GET['ketik'];
$penerima = $_GET['lawan'];
$pengirim = $id;


	   $result = mysqli_query($koneksi,"INSERT INTO chat (chat_pengirim,chat_penerima,chat_isi,chat_waktu,chat_status,chat_tipe) values('$pengirim','$penerima','$isi','$waktu','$status','$tipe')");
        if($result)
               {
                  $response=array(
                     'status' => 1,
                     'message' =>'Insert Success'
                  );
               }
               else
               {
                  $response=array(
                     'status' => 0,
                     'message' =>'Insert Failed.'
                  );

			   }
         header('Content-Type: text/xml');
  echo("<?xml version='1.0'?>");
	   
	   echo"<result>";
	   echo"<response>".$response."</response>";
	   echo"</result>";
      }

   function tampilkan_pesan()
   {
      global $koneksi;
	date_default_timezone_set('Asia/Jakarta');
	$id_saya = $_GET['user_id'];
	$id_user = $_GET['id'];
	$result = mysqli_query($koneksi,"SELECT * FROM chat WHERE (chat_pengirim='$id_saya' AND chat_penerima='$id_user') or (chat_pengirim='$id_user' AND chat_penerima='$id_saya')");
      while($row = mysqli_fetch_object($result))
      {
         $data[] = $row;
      }            
      if($data)
      {
      $response = array(
                     'data' => $data
                  );               
      }else {
         $response=array(
                     'status' => 0,
                     'message' =>'No Data Found'
                  );
      }
mysqli_query($koneksi,"UPDATE chat SET chat_status='1' WHERE chat_pengirim='$id_user' AND chat_penerima='$id_saya'");
	   
	   
      header('Content-Type: application/json');
      echo json_encode($response);
   }


   function check()
   {
	   global $koneksi;
$email = mysqli_real_escape_string($koneksi,$_POST['email']);
	   
$cek = mysqli_query($koneksi,"SELECT * FROM user WHERE user_email='$email'");
          
      if(mysqli_num_rows($cek) > 0)
      {
      $response = array(
		  				'status' => 1
                  );               
      }else {
         $response=array(
	
                     'status' => 0,
                     'message' =>'No Data Found'
                  );
      }
	   
      header('Content-Type: application/json');
      echo json_encode($response);
   }

   function daftar()
   {
global $koneksi;
$nama = mysqli_real_escape_string($koneksi,$_POST['nama']);
$email = mysqli_real_escape_string($koneksi,$_POST['email']);
$password = md5($_POST['password']);
$sql = mysqli_query($koneksi,"INSERT INTO user (user_email,user_nama,user_password,user_foto,user_status) VALUES ('$email','$nama','$password','','online')");            
  if($sql)
               {
                  $response=array(
                     'status' => 1,
                     'message' =>'Insert Success'
                  );
               }
               else
               {
                  $response=array(
                     'status' => 0,
                     'message' =>'Insert Failed.'
                  );

			   }
      header('Content-Type: application/json');
      echo json_encode($response);
   }

function login()
   {
	   global $koneksi;

$password = md5($_POST['password']);
$email = mysqli_real_escape_string($koneksi,$_POST['email']);
$sql = mysqli_query($koneksi, "SELECT * FROM user WHERE user_email='$email' AND user_password='$password'"); 
while($row = mysqli_fetch_object($sql))
      {
         $data[] = $row;
      }            
      if(mysqli_num_rows($sql) > 0)
      {
      $response = array(
		  				'data' => $data,
		  				'status' => 1
                  );   
      }else {
         $response=array(
	
                     'status' => 0,
                     'message' =>'No Data Found'
                  );
      }
	   
      header('Content-Type: application/json');
      echo json_encode($response);
   }

function lawan()
   {

	   global $koneksi;
	$id_saya = $_GET['user_id'];
$id_user = $_GET['id'];
	
$result = mysqli_query($koneksi,"SELECT * FROM user WHERE user_id='$id_user'");
while($row = mysqli_fetch_object($result))
      {
         $data[] = $row;
      }            
      if($data)
      {
      $response = array(
                     'data' => $data
                  );               
      }else {
         $response=array(
                     'status' => 0,
                     'message' =>'No Data Found'
                  );
      }
	   
      header('Content-Type: application/json');
      echo json_encode($response);
   }

function show_user()
   {

	   global $koneksi;
	$id_saya = $_GET['user_id'];
	
$result = mysqli_query($koneksi,"select * from user where user_id!='$id_saya'");
while($t = mysqli_fetch_array($result)){
$data[] = $t;

	
		      if($data)
      {
      $response = array(
                     'data' => $data,
		  'status' => mysqli_num_rows($result)
                  );               
      }else {
         $response=array(
                     'status' => 0,
                     'message' =>'No Data Found'
                  );
      }
	

}   
      header('Content-Type: application/json');
      echo json_encode($response);
}

 ?>