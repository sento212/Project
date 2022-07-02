<?php 
session_start();
session_destroy();
//lempar ke tampilan login
header("location:../index.php?alert=logout");
?>