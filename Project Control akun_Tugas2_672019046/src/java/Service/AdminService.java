package Service;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
public class AdminService extends HttpServlet {

    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        String ID = request.getParameter("ID");
        String password = request.getParameter("password");
        String no_telp = request.getParameter("no_telp");
        String alamat = request.getParameter("alamat");
        String resp="";
         if (request.getParameter("action").equals("insert")){
            int r = new DAO.AdminDAO().insertOne(ID, password, no_telp, alamat);
            resp=(r>0)?"Berhasil Tambah Data":"Gagal Tambah Data";
        }
        else if (request.getParameter("action").equals("delete")){
            int r = new DAO.AdminDAO().deleteOne(ID);
            resp=(r>0)?"Berhasil Hapus Data":"Gagal Hapus Data";
        }        
        response.sendRedirect("Admin.jsp?res="+resp);
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