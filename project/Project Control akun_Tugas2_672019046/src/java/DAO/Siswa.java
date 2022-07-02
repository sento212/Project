package DAO;

public class Siswa{
    private String NIM;
    private String Nama;
    private String Tanggal_Lahir;
    private String Fakultas;
    private String Asal;
    private String password;


    public Siswa() { }

    public Siswa(String NIM, String Nama, String Tanggal_Lahir ,String Fakultas,String Asal, String password) {
        this.NIM = NIM;
        this.Nama = Nama;
        this.Tanggal_Lahir = Tanggal_Lahir;
        this.Fakultas = Fakultas;
        this.Asal = Asal;
        this.password = password;
    }

    Siswa(String string, String string0, String message) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    public String getNIM() {
        return NIM;
    }

    public void setNIM(String NIM) {
        this.NIM = NIM;
    }

     public String getNama() {
        return Nama;
    }

    public void setNama(String Nama) {
        this.Nama = Nama;
    }
    
     public String getTanggal_Lahir() {
        return Tanggal_Lahir;
    }

    public void setTanggal_Lahir(String Tanggal_Lahir) {
        this.Tanggal_Lahir = Tanggal_Lahir;
    }
    
    public String getFakultas() {
        return Fakultas;
    }

    public void setFakultas(String Fakultas) {
        this.Fakultas = Fakultas;
    }

    public String getAsal() {
        return Asal;
       
    }

    public void setAsal(String Asal) {
        this.Asal = Asal;
    }

        public String getpassword() {
        return password;
       
    }

    public void setpassword(String password) {
        this.password = password;
    }



}
