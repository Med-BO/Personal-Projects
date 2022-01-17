package beans;

public class Participant {
	
	private String matricule;
	private String nom;
	private String statut;
	
	public Participant(String m, String n, String s) {
		super();
		this.matricule = m;
		this.nom= n;
		this.statut = s;
	}
	
	public String getMatricule() {
		return matricule;
	}
	public void setMatricule(String matricule) {
		this.matricule = matricule;
	}
	public String getNom() {
		return nom;
	}
	public void setNom(String nom) {
		this.nom = nom;
	}
	public String getStatut() {
		return statut;
	}
	public void setStatut(String statut) {
		this.statut = statut;
	}
	
	
}
