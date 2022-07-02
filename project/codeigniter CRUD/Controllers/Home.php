<?php

namespace App\Controllers;

class Home extends BaseController
{
    public function index()
    {
        echo view('layout/header');
        return view('mahasiswa/index');
        echo view('layout/footer');
    }
}
