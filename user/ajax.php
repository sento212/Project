<script type="text/javascript">


	$(document).ready(function(){


		//tampilkan list teman dengan mengirim id ke tampilan list teman dan tampilan chat teman
		$("body").on("click",".teman-list",function(){
			var id_user = $(this).attr('id');
			var data = "&id="+id_user;
			$.ajax({
				type: 'POST',
				url: "ajax_chat_tampil.php",
				data: data,
				success: function(html) {
					$(".pesan").html(html);
					$(".avatar-lawan").attr("id",id_user);
					var x = $(".pesan").height()+221000000000;
					$(".pesan").scrollTop(x);
					$("#balas-ketik").val("");
					$(".kotak-kiri-mobile").removeClass("d-block");
				}
			});

			$.ajax({
				type: 'POST',
				url: "ajax_lawan_tampil.php",
				data: data,
				success: function(html2) {
					$(".lawan").html(html2);
					$(".balas").removeClass('d-none')
				}
			});

		});

		// klik tombol kirim
		$("body").on("click",".balas-kirim",function(){
			var ketik = $("#balas-ketik").val();
			if(ketik.length > 0){
				var lawan = $(".avatar-lawan").attr('id');
				var data = "ketik="+ketik+"&lawan="+lawan;
				$.ajax({
					type: 'POST',
					url: "ajax_balas_kirim.php",
					data: data,
					success: function(html) {
						$("#balas-ketik").val("");
						$(".pesan").append(html);
						var x = $(".pesan").height()+221000;
						$(".pesan").scrollTop(x);
					}
				});
			}

		});


		
		// set interval berjalan setiap detik
	
	
			// reload chat dengan 
			var x = $(".avatar-lawan").attr("id");
			if(x != 0){
				var lawan = $(".avatar-lawan").attr('id');
				var data = "&id="+lawan;
				$.ajax({
					type: 'POST',
					url: "ajax_chat_tampil.php",
					data: data,
					success: function(html) {
						var isi = $(".pesan").html();
						if(isi != html){
							// var x = $(".pesan").height()+221000;
							// $(".pesan").scrollTop(x);
							$(".pesan").html(html);

						}
					}
				});
			}
		
		setInterval(function(){ 

			// update list teman 
			var xx = "";
			var data2 = "&id="+xx;
				$.ajax({
					type: 'POST',
					url: "ajax_teman_tampil.php",
					data: data2,
					success: function(html2) {
						$(".teman").html(html2);
					}
				});
		





		}, 500);

	});
</script>