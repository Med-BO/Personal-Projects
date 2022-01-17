package DAO;
import java.util.*;
import beans.Participant;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class FormationDAO {
	
	private static final String SELECTNUM = "select num from Formation;";
	private static final String SELECTCODEBYNUM = "select codeAcces from Formation where num = ?;";
	private static final String SELECTPARTICIPANTS = "select P.* from Participant as \"P\", Participation as \"Pion\" where Pion.numF = ? AND Pion.matP = P.matricule;";
	private static final String INSERT1 = "insert into Participant values (?,?,?);";
	private static final String INSERT2 = "insert into Participation (numF, matP) values (?,?);";
	
	static ConnexionJDBC cnx = new ConnexionJDBC();
	
	public static ArrayList<String> select_num(){
		ArrayList<String> ln = new ArrayList<String>();
		try {
			Connection connection = cnx.getConnection();
			PreparedStatement preparedStatement = connection.prepareStatement(SELECTNUM);
			ResultSet rs = preparedStatement.executeQuery();
			while(rs.next()) {
				String num = rs.getString("num");
				ln.add(num);
			}
		}catch(SQLException e) {
			//error handling
		}
		return ln;
	}
	
	public static String select_code_by_num(String num) {
		String code  = new String();
		try {
			Connection connection = cnx.getConnection();
			PreparedStatement preparedStatement = connection.prepareStatement(SELECTCODEBYNUM);
			preparedStatement.setString(1, num);
			ResultSet rs = preparedStatement.executeQuery();
			code = rs.getString("codeAcces");
		}catch(SQLException e) {
			//error handling
		}
		return code;
	}
	
	public static ArrayList<Participant> select_participants_by_formation(String num){
		ArrayList<Participant> lp = new ArrayList<Participant>();
		try {
			Connection connection = cnx.getConnection();
			PreparedStatement preparedStatement = connection.prepareStatement(SELECTPARTICIPANTS);
			preparedStatement.setString(1, num);
			ResultSet rs = preparedStatement.executeQuery();
			while(rs.next()) {
				String matricule = rs.getString("matricule");
				String nom = rs.getString("nom");
				String statut = rs.getString("statut");
				lp.add(new Participant(matricule,nom,statut));
			}
		}catch(SQLException e) {
			//error handling
		}
		return lp;
	}
	
	public static void ajouter_participant(String m, String n, String s){
		try {
			Connection connection = cnx.getConnection();
			PreparedStatement preparedStatement = connection.prepareStatement(INSERT1);
			preparedStatement.setString(1, m);
			preparedStatement.setString(2, n);
			preparedStatement.setString(3, s);
			preparedStatement.executeUpdate();
		}catch(SQLException e) {
			//error handling
		}
	}
	
	public static void ajouter_participation(String n, String m){
		try {
			Connection connection = cnx.getConnection();
			PreparedStatement preparedStatement = connection.prepareStatement(INSERT2);
			preparedStatement.setString(1, n);
			preparedStatement.setString(2, m);
			preparedStatement.executeUpdate();
		}catch(SQLException e) {
			//error handling
		}
	}
	
}
