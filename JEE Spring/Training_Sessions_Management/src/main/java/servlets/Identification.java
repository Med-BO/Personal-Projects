package servlets;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import DAO.FormationDAO;

/**
 * Servlet implementation class Identification
 */
@WebServlet("/Identification")
public class Identification extends HttpServlet {
	private static final long serialVersionUID = 1L;
        
    /**
     * @see HttpServlet#HttpServlet()
     */
    public Identification() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		String num = request.getParameter("num");
		String code = request.getParameter("code");
		
		HttpSession session = request.getSession();
		int x = 0;
		session.setAttribute("affichage", x);
		
		String rightCode = FormationDAO.select_code_by_num(num);
		if(rightCode.equals(code)) {
			request.getServletContext().getRequestDispatcher("/listeParticipants.jsp?action=get&num="+num).forward(request, response);
		}
		else {
			x = 1;
			session.setAttribute("affichage", x);
			request.getServletContext().getRequestDispatcher("/ChoixFormation.jsp").forward(request, response);
		}
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
