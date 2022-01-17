package DAO;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class ConnexionJDBC {

	protected Connection getConnection() {
        Connection connection = null;
        try {
            Class.forName("org.sqlite.JDBC");
            //connection = DriverManager.getConnection("sqlite:jdbc:C:\\Users\\Mohamed\\Desktop\\Etudiants.db");
            connection = DriverManager.getConnection("jdbc:sqlite:/C:/Users/Mohamed/Desktop/Formations.db");
        } catch (SQLException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        } catch (ClassNotFoundException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        } 
        return connection;
    }
}
