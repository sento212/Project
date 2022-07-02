package DAO;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

public class AdminDAO {

    public Admin readOne(String ID) {
        Admin admin = null;
        try {
            Connection con = Koneksi.getConnection();
            Statement st = con.createStatement();
            ResultSet rs = st.executeQuery("SELECT * FROM admin WHERE ID = '"+ID+"'");
            while (rs.next()) {
                admin = new Admin();
                admin.setID(rs.getString("ID"));
                admin.setpassword(rs.getString("password"));
                admin.setalamat(rs.getString("alamat"));
                admin.setno_telp(rs.getString("no_tlp"));
            }
            rs.close();
        } catch (Exception ex) {
            System.err.println("read one error: "+ex.getMessage());
        }
        return admin;
    }
    public List<Admin> readAlltoList() {
        List<Admin> list = new ArrayList<Admin>();
        try {
            Connection conn = Koneksi.getConnection();
            Statement st = conn.createStatement();
            ResultSet rs = st.executeQuery("SELECT * FROM admin");
            while (rs.next()) {
                Admin admin = new Admin();
                admin = new Admin();
                admin.setID(rs.getString("ID"));
                admin.setpassword(rs.getString("password"));
                admin.setalamat(rs.getString("alamat"));
                admin.setno_telp(rs.getString("no_tlp"));
                list.add(admin);
            }
            rs.close();
        } catch (Exception ex) {
            list.add(new Admin("0", "0", ex.getMessage()));
            System.err.println("read all error: "+ex.getMessage());
        }
        return list;
    }
    public int insertOne(String ID, String password, String no_telp, String alamat) {
        try {
            Connection con = Koneksi.getConnection();
            Statement st = con.createStatement();
            String sql = "INSERT INTO admin (ID,password,no_tlp,alamat) VALUES ("
                    + "'" + ID + "','"
                    + password + "','"
                    + no_telp + "','"
                    + alamat +"')";
            int i = st.executeUpdate(sql);
            st.close();
            return i;
        } catch (SQLException ex) {
            System.err.println("insert error: "+ex.getMessage());
            return 0;
        }
    }
    public int deleteOne(String ID) {
        try {
            Connection con = Koneksi.getConnection();
            String sql = "delete from admin where ID=?";
            PreparedStatement ps = con.prepareStatement(sql);
            ps.setString(1,ID);
            int i= ps.executeUpdate(); 
            ps.close();
            return i;
        } catch (SQLException ex) {
            System.err.println("delete error: "+ex.getMessage());
            return 0;
        }
    }

}
