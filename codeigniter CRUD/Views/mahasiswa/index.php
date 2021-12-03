<body style="background-color: rgb(18, 14, 31)">
    <br>
    <div class="container">
        <div class="row">
            <div class="col">
                <a class="btn btn-light" href="/mahasiswa/create">Input Data</a>
                <table class="table table-dark">
                    <thead>
                        <tr>
                            <th scope="col">No</th>
                            <th scope="col">NIM</th>
                            <th scope="col">Nama Lengkap</th>
                            <th scope="col">Kota Asal</th>
                            <th scope="col">Tanggal lahir</th>
                            <th scope="col">Nama Orang Tua</th>
                            <th scope="col">Alamat Orag Tua</th>
                            <th scope="col">Kode Pos</th>
                            <th scope="col">Telepon</th>
                            <th scope="col">Status</th>
                            <th scope="col">Delete</th>
                            <th scope="col">Update</th>
                        </tr>
                    </thead>
                    <tbody>
                        <?php $i = 1; ?>
                        <?php foreach ($mahasiswa as $mhs) : ?>
                            <tr>
                                <th scope="row"><?= $i++; ?></th>
                                <td><?= $mhs['NIM']; ?></td>
                                <td><?= $mhs['nama_lengkap'] ?></td>
                                <td><?= $mhs['Kota_Asal'] ?></td>
                                <td><?= $mhs['Tanggal_Lahir'] ?></td>
                                <td><?= $mhs['Nama_Orang_Tua'] ?></td>
                                <td><?= $mhs['Alamat_Orang_Tua'] ?></td>
                                <td><?= $mhs['Kode_Pos'] ?></td>
                                <td><?= $mhs['Telpon'] ?></td>
                                <td><?= $mhs['Status'] ?></td>
                                <td> <a href="<?php echo base_url('/mahasiswa/delete/' . $mhs['NIM']); ?>" class="btn btn-danger">Delete</a></td>
                                <td> <a href="<?php echo base_url('/mahasiswa/edit/' . $mhs['NIM']); ?>" class="btn btn-success">Edit</a></td>
                            </tr>
                        <?php endforeach; ?>
                    </tbody>
                </table>
            </div>
        </div>
    </div>