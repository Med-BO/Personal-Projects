<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
    <%@page import="DAO.EtudiantDAO" %>
    <%@page import="java.util.*" %>
    <%@page import="beans.Etudiant" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Insert title here</title>
</head>
<% 
	String ageS = request.getParameter("age");
	int age = Integer.parseInt(ageS);
	ArrayList<Etudiant> le = new ArrayList<Etudiant>();
	le = EtudiantDAO.filtrer(age);
%>
<body>
	<table>
		<tr>
			<th>ID</th>
			<th>Nom</th>
			<th>Nombre d'abscences</th>
		</tr>
		<%for(int i=0;i<le.size();i++){ %>
		<tr>
			<td><%= le.get(i).getId() %></td>
			<td><%= le.get(i).getName() %></td>
			<td><%= le.get(i).getNb_abs() %></td>
		</tr>
		<%} %>
	</table>
	<a href="Index.html">Retour vers l'accueil</a>
	</body>
</html>