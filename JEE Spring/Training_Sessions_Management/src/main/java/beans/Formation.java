package beans;

public class Formation {
	
	private String num;
	private String codeAcces;
	private String nom;
	private float prix;
	
	public Formation(String n, String c, String no, float p) {
		super();
		this.num = n;
		this.codeAcces = c;
		this.nom = no;
		this.prix = p;
	}
	
	public String getNum() {
		return num;
	}
	public void setNum(String num) {
		this.num = num;
	}
	public String getCodeAcces() {
		return codeAcces;
	}
	public void setCodeAcces(String codeAcces) {
		this.codeAcces = codeAcces;
	}
	public String getNom() {
		return nom;
	}
	public void setNom(String nom) {
		this.nom = nom;
	}
	public float getPrix() {
		return prix;
	}
	public void setPrix(float prix) {
		this.prix = prix;
	}
	
	
}
