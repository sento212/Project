/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Service;
import DAO.Admin;
import DAO.LoginDAO;
import java.io.*;
import java.sql.SQLException;
 
import javax.servlet.*;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;
 
@WebServlet("/login")
public class AdminLoginServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;
 
    public AdminLoginServlet() {
        super();
    }
 
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        String ID = request.getParameter("ID");
        String password = request.getParameter("password");
         
        LoginDAO userDao = new LoginDAO();
         
        try {
            Admin user = userDao.checkLogin(ID, password);
            String destPage = "AdminLogin.jsp";
             
            if (user != null) {
                HttpSession session = request.getSession();
                session.setAttribute("user", user);
                destPage = "siswa.jsp";
            } else {
                String message = "Invalid ID/password";
                request.setAttribute("message", message);
            }
             
            RequestDispatcher dispatcher = request.getRequestDispatcher(destPage);
            dispatcher.forward(request, response);
             
        } catch (SQLException | ClassNotFoundException ex) {
            throw new ServletException(ex);
        }
    }
}