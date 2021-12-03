<?php

namespace App\Models;

use CodeIgniter\Model;

class MahasiswaModel extends Model
{
    protected $table      = 'mahasiswa';
    protected $primaryKey = 'NIM';
    protected $allowedFields = ['NIM', 'nama_lengkap', 'Kota_Asal', 'Tanggal_Lahir', 'Nama_Orang_Tua', 'Alamat_Orang_Tua', 'Kode_Pos', 'Telpon', 'Status'];
}
