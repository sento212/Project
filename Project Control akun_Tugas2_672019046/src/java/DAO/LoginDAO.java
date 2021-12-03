package DAO;
import java.sql.*;
 
public class LoginDAO {

 
    public Admin checkLogin(String ID, String password) throws SQLException,
            ClassNotFoundException {
        Connection con = Koneksi.getConnection();
        String sql = "SELECT * FROM admin WHERE ID = ? and password = ?";
        PreparedStatement statement = con.prepareStatement(sql);
        statement.setString(1, ID);
        statement.setString(2, password);
 
        ResultSet result = statement.executeQuery();
 
        Admin user = null;
 
        if (result.next()) {
            user = new Admin();
            user.setID(ID);
        }
 
       
 
        return user;
    }
    
        public Siswa checkLoginSiswa(String NIM, String password) throws SQLException,
            ClassNotFoundException {
        Connection con = Koneksi.getConnection();
        String sql = "SELECT * FROM siswa WHERE NIM = ? and password = ?";
        PreparedStatement statement = con.prepareStatement(sql);
        statement.setString(1, NIM);
        statement.setString(2, password);
        ResultSet rs = statement.executeQuery();
 
       Siswa siswa = null;
 
           if (rs.next()) {
            siswa = new Siswa();
                siswa.setNama(rs.getString("Nama"));
                siswa.setTanggal_Lahir(rs.getString("Tanggal_Lahir"));
                siswa.setFakultas(rs.getString("Fakultas"));
                siswa.setAsal(rs.getString("asal"));
                siswa.setpassword(rs.getString("password"));
            siswa.setNIM(NIM);
        }
       
        return siswa;
    }
        
            public Root checkLoginRoot(String Username, String password) throws SQLException,
            ClassNotFoundException {
        Connection con = Koneksi.getConnection();
        String sql = "SELECT * FROM root WHERE Username = ? and password = ?";
        PreparedStatement statement = con.prepareStatement(sql);
        statement.setString(1, Username);
        statement.setString(2, password);
 
        ResultSet result = statement.executeQuery();
 
        Root root = null;
 
        if (result.next()) {
            root = new Root();
            root.setusername(Username);
        }
 
       
 
        return root;
}
}