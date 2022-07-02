/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Service;
import DAO.LoginDAO;
import DAO.Root;
import java.io.*;
import java.sql.SQLException;
 
import javax.servlet.*;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;
 
@WebServlet("/root")
public class RootLoginServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;
 
    public RootLoginServlet() {
        super();
    }
 
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        String Username = request.getParameter("Username");
        String password = request.getParameter("password");
         
        LoginDAO userDao = new LoginDAO();
         
        try {
            Root user = userDao.checkLoginRoot(Username, password);
            String destPage = "Root.jsp";
             
            if (user != null) {
                HttpSession session = request.getSession();
                session.setAttribute("user", user);
                destPage = "Admin.jsp";
            } else {
                String message = "Invalid username/password";
                request.setAttribute("message", message);
            }
             
            RequestDispatcher dispatcher = request.getRequestDispatcher(destPage);
            dispatcher.forward(request, response);
             
        } catch (SQLException | ClassNotFoundException ex) {
            throw new ServletException(ex);
        }
    }
}