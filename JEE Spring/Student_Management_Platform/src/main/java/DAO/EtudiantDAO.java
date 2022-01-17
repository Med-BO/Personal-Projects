package DAO;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import beans.Etudiant;


public class EtudiantDAO {
	private static final String INSERT = "insert into Etudiant (name, age) values (?, ?);";
	private static final String ADDABS = "update Etudiant set nb_abs = nb_abs + 1 where id = ?;";
	private static final String DELABS = "update Etudiant set nb_abs = nb_abs - 1 where id = ?;";
	private static final String SELECTALL = "select * from Etudiant;";
	private static final String DELETE = "delete from Etudiant where id = ?;";
	private static final String FILTER = "select * from Etudiant where age = ?;";
	
	public EtudiantDAO() {}
	static ConnexionJDBC cnx = new ConnexionJDBC();
	
	public static void Insert_Etudiant(String name, int age) {
		try {
			java.sql.Connection connection = cnx.getConnection();
			java.sql.PreparedStatement preparedStatement = connection.prepareStatement(INSERT);
			preparedStatement.setString(1, name);
			preparedStatement.setInt(2, age);
			preparedStatement.executeUpdate();
		}catch(SQLException e) {
			//error treatment
		}
	}
	
	public static void Add_Abs(int id) {
		try {
			java.sql.Connection connection = cnx.getConnection();
			java.sql.PreparedStatement preparedStatement = connection.prepareStatement(ADDABS);
			preparedStatement.setInt(1, id);
			preparedStatement.executeUpdate();
		}catch(SQLException e) {
			//error treatment
		}
	}
	
	public static void Del_Abs(int id) {
		try {
			java.sql.Connection connection = cnx.getConnection();
			java.sql.PreparedStatement preparedStatement = connection.prepareStatement(DELABS);
			preparedStatement.setInt(1, id);
			preparedStatement.executeUpdate();
		}catch(SQLException e) {
			//error treatment
		}
	}
	
	public static ArrayList<Etudiant> selectAll() {
		ArrayList<Etudiant> le = new ArrayList<Etudiant>();
		try {
			java.sql.Connection connection = cnx.getConnection();
			java.sql.PreparedStatement preparedStatement = connection.prepareStatement(SELECTALL);
			ResultSet rs = preparedStatement.executeQuery();
			while(rs.next()) {
				String name = rs.getString("name");
				int id = rs.getInt("id");
				int age = rs.getInt("age");
				int nb_abs = rs.getInt("nb_abs");
				le.add(new Etudiant(id,name,age,nb_abs));
			}
		}catch(SQLException e) {
			//error treatment
		}
		return le;
	}
	
	public static void suppEtudiant(int id) {
		try {
			java.sql.Connection connection = cnx.getConnection();
			java.sql.PreparedStatement preparedStatement = connection.prepareStatement(DELETE);
			preparedStatement.setInt(1, id);
			preparedStatement.executeUpdate();
		}catch(SQLException e) {
			//error treatment
		}
	}
	
	public static ArrayList<Etudiant> filtrer(int a){
		ArrayList<Etudiant> le = new ArrayList<Etudiant>();
		try {
			java.sql.Connection connection = cnx.getConnection();
			java.sql.PreparedStatement preparedStatement = connection.prepareStatement(FILTER);
			preparedStatement.setInt(1, a);
			ResultSet rs = preparedStatement.executeQuery();
			while(rs.next()) {
				String name = rs.getString("name");
				int id = rs.getInt("id");
				int age = rs.getInt("age");
				int nb_abs = rs.getInt("nb_abs");
				le.add(new Etudiant(id,name,age,nb_abs));
			}
		}catch(SQLException e) {
			//error handling
		}
		return le;
	}
}
