<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
    <%@ page import="java.util.*" %>
    <%@ page import="beans.Participant" %>
    <%@ page import="DAO.FormationDAO" %>
<% 
	String num = request.getParameter("num");
	ArrayList<Participant> lp = new ArrayList<Participant>();
	lp = FormationDAO.select_participants_by_formation(num);
%> 
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Insert title here</title>
</head>
<body>
<h1>Liste des participants</h1>
<table>
	<tr>
		<th>Matricule</th>
		<th>Nom</th>
		<th>Statut</th>
	</tr>
	<% for(int i=0;i<lp.size();i++){ %>
	<tr>
		<td><%= lp.get(i).getMatricule() %></td>
		<td><%= lp.get(i).getNom() %></td>
		<td><%= lp.get(i).getStatut() %></td>
	</tr>
	<% } %>
</table>
<a href="AjoutParticipant.html">Ajouter un participant</a>
</body>
</html>