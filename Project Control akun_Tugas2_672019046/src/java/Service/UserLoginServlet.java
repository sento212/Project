package Service;

import DAO.LoginDAO;
import DAO.Siswa;
import java.io.*;
import java.sql.SQLException;
 
import javax.servlet.*;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;
 
@WebServlet("/UserLogin")
public class UserLoginServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;
 
    public UserLoginServlet() {
        super();
    }
    
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        String NIM = request.getParameter("NIM");
        String password = request.getParameter("password");
         
        LoginDAO userDao = new LoginDAO();
         
        try {
            Siswa user = userDao.checkLoginSiswa(NIM, password);
            String destPage = "index.jsp";
             
            if (user != null) {
                HttpSession session = request.getSession();
                session.setAttribute("user", user);
                destPage = "siswaUser.jsp";
            } else {
                String message = "Invalid NIM/password";
                request.setAttribute("message", message);
            }
             
            RequestDispatcher dispatcher = request.getRequestDispatcher(destPage);
            dispatcher.forward(request, response);
             
        } catch (SQLException | ClassNotFoundException ex) {
            throw new ServletException(ex);
        }
    }
}
