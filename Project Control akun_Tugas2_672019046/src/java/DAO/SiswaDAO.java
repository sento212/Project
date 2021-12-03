package DAO;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

public class SiswaDAO {

    public Siswa readOne(String NIM) {
        Siswa siswa = null;
        try {
            Connection con = Koneksi.getConnection();
            Statement st = con.createStatement();
            ResultSet rs = st.executeQuery("SELECT * FROM siswa WHERE NIM = '"+NIM+"'");
            while (rs.next()) {
                siswa = new Siswa();
                siswa.setNIM(rs.getString("NIM"));
                siswa.setNama(rs.getString("Nama"));
                siswa.setTanggal_Lahir(rs.getString("Tanggal_Lahir"));
                siswa.setFakultas(rs.getString("Fakultas"));
                siswa.setAsal(rs.getString("Asal"));
                siswa.setpassword(rs.getString("password"));
            }
            rs.close();
        } catch (Exception ex) {
            System.err.println("read one error: "+ex.getMessage());
        }
        return siswa;
    }
    public List<Siswa> readAlltoList() {
        List<Siswa> list = new ArrayList<Siswa>();
        try {
            Connection conn = Koneksi.getConnection();
            Statement st = conn.createStatement();
            ResultSet rs = st.executeQuery("SELECT * FROM siswa");
            while (rs.next()) {
                Siswa siswa = new Siswa();
                siswa.setNIM(rs.getString("NIM"));
                siswa.setNama(rs.getString("Nama"));
                siswa.setTanggal_Lahir(rs.getString("Tanggal_Lahir"));
                siswa.setFakultas(rs.getString("Fakultas"));
                siswa.setAsal(rs.getString("Asal"));
                siswa.setpassword(rs.getString("password"));
                list.add(siswa);
            }
            rs.close();
        } catch (Exception ex) {
            list.add(new Siswa("0", "0", ex.getMessage()));
            System.err.println("read all error: "+ex.getMessage());
        }
        return list;
    }
    public int insertOne(String nim, String nama, String tanggal_lahir, String fakultas, String asal, String password) {
        try {
            Connection con = Koneksi.getConnection();
            Statement st = con.createStatement();
            String sql = "INSERT INTO siswa (NIM,Nama,Tanggal_Lahir,Fakultas,Asal,password) VALUES ("
                    + "'" + nim + "','"
                    + nama + "','"
                    + tanggal_lahir + "','"
                    + fakultas + "','"
                    + asal +  "','"
                    + password +"')";
            int i = st.executeUpdate(sql);
            st.close();
            return i;
        } catch (SQLException ex) {
            System.err.println("insert error: "+ex.getMessage());
            return 0;
        }
    }
    public int deleteOne(String nim) {
        try {
            Connection con = Koneksi.getConnection();
            String sql = "delete from siswa where NIM=?";
            PreparedStatement ps = con.prepareStatement(sql);
            ps.setString(1,nim);
            int i= ps.executeUpdate(); 
            ps.close();
            return i;
        } catch (SQLException ex) {
            System.err.println("delete error: "+ex.getMessage());
            return 0;
        }
    }
    public int updateOne(String nim, String nama, String tanggal_lahir, String fakultas, String asal) {
        try {
            Connection con = Koneksi.getConnection();
            String sql = "update siswa set Nama=?, Tanggal_Lahir=?, Fakultas=?, Asal=? where NIM=?";
            PreparedStatement ps = con.prepareStatement(sql);
            ps.setString(1,nama);
            ps.setString(2,tanggal_lahir);
            ps.setString(3,fakultas);
            ps.setString(4,asal);
            ps.setString(5,nim);
            int i= ps.executeUpdate(); 
            ps.close();
            return i;
        } catch (SQLException ex) {
            System.err.println("update error: "+ex.getMessage());
            return 0;
        }
    }
}
