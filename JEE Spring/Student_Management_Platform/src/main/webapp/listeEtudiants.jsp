<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<%@ page import="DAO.EtudiantDAO" %>
<%@ page import="java.util.ArrayList" %>
<%@ page import="beans.Etudiant" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Insert title here</title>
</head>
<%ArrayList<Etudiant> le = EtudiantDAO.selectAll(); %>
<body>
<table>
<tr>
	<th>ID</th>
	<th>Nom</th>
	<th>Age</th>
	<th>Nombre d'abscences</th>
	<th>Supprimer</th>
	<th>Ajouter une abscense</th>
	<th>Enlever une abscense</th>
</tr>
<%for(int i=0; i<le.size();i++){ %>
<tr>
	<td><%= le.get(i).getId() %></td>
	<td><%= le.get(i).getName() %></td>
	<td><%= le.get(i).getAge() %></td>
	<td><%= le.get(i).getNb_abs() %></td>
	<td><a href="SuppressionEtudiant?action=get&id=<%=le.get(i).getId()%>">supprimer</a></td>
	<td><a href="AjoutAbs?action=get&id=<%=le.get(i).getId()%>">+</a></td>
	<td><a href="EnleveAbs?action=get&id=<%=le.get(i).getId()%>">-</a></td>
</tr>
<%} %>
</table>
<a href="Index.html">Ajouter un autre étudiant</a>
<form action="Filtre.jsp" method="get">
	<label for="age">Filtrer par age : </label>
	<input type="number" size="2" name="age" id="age">
</form>
</body>
</html>