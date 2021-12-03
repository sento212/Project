<?php

namespace App\Controllers;

class Pages extends BaseController
{
    public function index()
    {
        return view('home');
    }
    public function create()
    {
        echo view('layout/header');
        return view('mahasiswa/create');
        echo view('layout/footer');
    }
}
