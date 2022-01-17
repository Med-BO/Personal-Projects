<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
   <%@ page import="DAO.FormationDAO" %>
    <%@ page import="java.util.ArrayList" %>
    <%@ page import="javax.servlet.http.HttpSession" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Insert title here</title>
</head>
<%
	ArrayList<String> ln = new ArrayList<String>();
	ln = FormationDAO.select_num();
%>
<body>
<form method="get" action="Identification">
	<label for="num">Numéro de formation : </label>
	<input list="numeros" name="num" id="num">

	<datalist id="numeros">
	<%for(int i =0; i<ln.size();i++){ %>
	  <option value="<%= ln.get(i) %>">
	  <%} %>
	</datalist>
	<label for="code">Code d'acces : </label>
	<input type="text" size="10" id="code" name="code">
	<input type="submit" value="Valider">
</form>
<% 
	if(request.getSession().getAttribute("affichage")!=null){
		int affichage = (int)request.getSession().getAttribute("affichage");
		if(affichage==1){%>
		<h1 style="color:red">Le code saisi est incorrect !</h1>
	<%}
	} %>
</body>
</html>