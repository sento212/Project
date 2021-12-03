<?php

namespace App\Controllers;

use App\Models\MahasiswaModel;

class Mahasiswa extends BaseController
{
    protected $mahasiswaModel;
    public function __construct()
    {
        $this->mahasiswaModel = new MahasiswaModel();
    }

    public function index()
    {
        $mahasiswaModel = new MahasiswaModel();
        $mahasiswa = $mahasiswaModel->findAll();

        $data = [
            'title' => 'Daftar Mahasiswa',
            'mahasiswa' => $mahasiswa
        ];

        echo view('layout/header');
        return view('mahasiswa/index', $data);
        echo view('layout/footer');
    }

    public function create()
    {
        $data = [
            'title' => 'Form Tambah Data Mahasiswa',
        ];

        echo view('layout/header');
        return view('mahasiswa/create', $data);
        echo view('layout/footer');
    }

    public function save()
    {
        //$slug = url_title($this->request->getVar('nim'), '-', true);
        //dd($this->request->getVar());
        $this->mahasiswaModel->insert([
            //  'slug' => $slug,
            'NIM' => $this->request->getVar('NIM'),
            'nama_lengkap' => $this->request->getVar('nama_lengkap'),
            'Kota_Asal' => $this->request->getVar('Kota_Asal'),
            'Tanggal_Lahir' => $this->request->getVar('Tanggal_Lahir'),
            'Nama_Orang_Tua' => $this->request->getVar('Nama_Orang_Tua'),
            'Alamat_Orang_Tua' => $this->request->getVar('Alamat_Orang_Tua'),
            'Kode_Pos' => $this->request->getVar('Kode_Pos'),
            'Telpon' => $this->request->getVar('Telpon'),
            'Status' => $this->request->getVar('Status')
        ]);

        return redirect()->to('/mahasiswa');
    }

    public function delete($NIM = null)
    {

        $model = new MahasiswaModel();

        $data['NIM'] = $model->where('NIM', $NIM)->delete();

        return redirect()->to(base_url('/mahasiswa'));
    }

    public function edit($NIM = null)
    {

        $model = new MahasiswaModel();

        $data['mhs'] = $model->where('NIM', $NIM)->first();

        echo view('layout/header');
        return view('mahasiswa/update', $data);
        echo view('layout/footer');
    }

    public function update()
    {

        helper(['form', 'url']);

        $model = new MahasiswaModel();

        $NIM = $this->request->getVar('NIM');

        $data = [
            'nama_lengkap' => $this->request->getVar('nama_lengkap'),
            'Kota_Asal' => $this->request->getVar('Kota_Asal'),
            'Tanggal_Lahir' => $this->request->getVar('Tanggal_Lahir'),
            'Nama_Orang_Tua' => $this->request->getVar('Nama_Orang_Tua'),
            'Alamat_Orang_Tua' => $this->request->getVar('Alamat_Orang_Tua'),
            'Kode_Pos' => $this->request->getVar('Kode_Pos'),
            'Telpon' => $this->request->getVar('Telpon'),
            'Status' => $this->request->getVar('Status')
        ];

        $save = $model->update($NIM, $data);

        return redirect()->to(base_url('/mahasiswa'));
    }
}
