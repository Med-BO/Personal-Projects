package servlets;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


import DAO.FormationDAO;

/**
 * Servlet implementation class ajout
 */
@WebServlet("/ajout")
public class ajout extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public ajout() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */ 
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		String matricule = request.getParameter("matricule");
		String nom = request.getParameter("nom");
		String statut = request.getParameter("statut");
		String num = request.getParameter("num");
		
		FormationDAO.ajouter_participant(matricule, nom, statut);
		
		FormationDAO.ajouter_participation(num, matricule);
		
		request.getServletContext().getRequestDispatcher("/listeParticipants.jsp?method=get&id="+num).forward(request, response);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
