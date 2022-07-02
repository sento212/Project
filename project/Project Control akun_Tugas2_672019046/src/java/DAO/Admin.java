package DAO;

public class Admin {
    private String ID;
    private String password;
    private String no_telp;
    private String alamat;


    public Admin() { }

    public Admin(String ID, String password ,String alamat,String no_telp) {
        this.ID = ID;
        this.password = password;
        this.alamat = alamat;
        this.no_telp = no_telp;
    }

    Admin(String string, String string0, String message) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }



     public String getID() {
        return ID;
    }

    public void setID(String ID) {
        this.ID = ID;
    }
    
     public String getpassword() {
        return password;
    }

    public void setpassword(String password) {
        this.password = password;
    }
    
    public String getalamat() {
        return alamat;
    }

    public void setalamat(String alamat) {
        this.alamat = alamat;
    }

    public String getno_telp() {
        return no_telp;
       
    }

    public void setno_telp(String no_telp) {
        this.no_telp = no_telp;
    }
}
