<div class="container">
    <div class="row">
        <div class="col-8">
            <h2 class="my-3">Form Input Data Mahasiswa</h2>
            <form action="/mahasiswa/save" method="post">
                <?= csrf_field(); ?>
                <div class="row mb-3">
                    <label for="NIM" class="col-sm-2 col-form-label">NIM</label>
                    <div class="col-sm-7">
                        <input type="text" class="form-control" id="NIM" name="NIM" maxlength="9" onkeypress="return onlyNumberKey(event)" autofocus>
                    </div>
                </div>
                <div class="row mb-3">
                    <label for="nama_lengkap" class="col-sm-2 col-form-label">Nama Lengkap</label>
                    <div class="col-sm-7">
                        <input type="text" class="form-control" id="nama_lengkap" name="nama_lengkap">
                    </div>
                </div>
                <div class="row mb-3">
                    <label for="Kota_Asal" class="col-sm-2 col-form-label">Kota Asal</label>
                    <div class="col-sm-7">
                        <input type="text" class="form-control" id="Kota_Asal" name="Kota_Asal">
                    </div>
                </div>

                <div class="row mb-3">
                    <label for="Tanggal_Lahir" class="col-sm-2 col-form-label">Tanggal Lahir</label>
                    <div class="col-sm-7">
                        <input type="date" class="form-control" id="Tanggal_Lahir" name="Tanggal_Lahir">
                    </div>
                </div>

                <div class="row mb-3">
                    <label for="Nama_Orang_Tua" class="col-sm-2 col-form-label">Nama Orang Tua</label>
                    <div class="col-sm-7">
                        <input type="text" class="form-control" id="Nama_Orang_Tua" name="Nama_Orang_Tua">
                    </div>
                </div>
                <div class="row mb-3">
                    <label for="Alamat_Orang_Tua" class="col-sm-2 col-form-label">Alamat Orang Tua</label>
                    <div class="col-sm-7">
                        <input type="text" class="form-control" id="Alamat_Orang_Tua" name="Alamat_Orang_Tua">
                    </div>
                </div>
                <div class="row mb-3">
                    <label for="Kode_Pos" class="col-sm-2 col-form-label">Kode Pos</label>
                    <div class="col-sm-7">
                        <input type="text" class="form-control" id="Kode_Pos" name="Kode_Pos" maxlength="5" onkeypress="return onlyNumberKey(event)">
                    </div>
                </div>
                <div class="row mb-3">
                    <label for="Telpon" class="col-sm-2 col-form-label">Nomor Telepon</label>
                    <div class="col-sm-7">
                        <input type="text" class="form-control" id="Telpon" name="Telpon" maxlength="12" onkeypress="return onlyNumberKey(event)">
                    </div>
                </div>
                <div class="row mb-3">
                    <label for="Status" class="col-sm-2 col-form-label">Status</label>
                    <div class="form-group col-md-4">
                        <select id="Status" name="Status" class="form-control">
                            <option selected value="Tama">Tama</option>
                            <option value="Wreda">Wreda</option>
                        </select>
                    </div>
                </div>
                <button type="submit" class="btn btn-primary">Update</button>
            </form>

        </div>
    </div>
</div>