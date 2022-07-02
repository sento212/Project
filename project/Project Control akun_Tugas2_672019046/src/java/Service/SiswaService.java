package Service;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
public class SiswaService extends HttpServlet {

    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        String nim = request.getParameter("NIM");
        String nama = request.getParameter("nama");
        String tanggal_lahir = request.getParameter("tanggal_lahir");
        String fakultas = request.getParameter("fakultas");
        String asal = request.getParameter("asal");
        String password = request.getParameter("password");
        String resp="";
        if (request.getParameter("action").equals("insert")){
            int r = new DAO.SiswaDAO().insertOne(nim, nama, tanggal_lahir, fakultas, asal, password);
            resp=(r>0)?"Berhasil Tambah Data":"Gagal Tambah Data";
        }
        else if (request.getParameter("action").equals("update")){
            int r = new DAO.SiswaDAO().updateOne(nim, nama, tanggal_lahir, fakultas, asal);
            resp=(r>0)?"Berhasil Ubah Data":"Gagal Ubah Data";
        }
        else if (request.getParameter("action").equals("delete")){
            int r = new DAO.SiswaDAO().deleteOne(nim);
            resp=(r>0)?"Berhasil Hapus Data":"Gagal Hapus Data";
        }        
        response.sendRedirect("siswa.jsp?res="+resp);
    }

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }
}