<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class Mahasiswa extends Model
{
    //use HasFactory;
    protected $table      = 'mahasiswa';
    protected $primaryKey = 'NIM';
    protected $allowedFields = ['NIM', 'nama_lengkap', 'Kota_Asal', 'Tanggal_Lahir', 'Nama_Orang_Tua', 'Alamat_Orang_Tua', 'Kode_Pos', 'Telpon', 'Status'];
    public $timestamps = false;
}
