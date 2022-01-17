package beans;

public class Etudiant {
	private int id;
	private String name;
	private int age;
	private int nb_abs;
	
	public Etudiant(int id, String name, int age, int nb_abs)
	{
		super();
		this.id = id;
		this.name = name;
		this.age = age;
		this.nb_abs = nb_abs;
	}
	
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getAge() {
		return age;
	}
	public void setAge(int age) {
		this.age = age;
	}
	public int getNb_abs() {
		return nb_abs;
	}
	public void setNb_abs(int nb_abs) {
		this.nb_abs = nb_abs;
	}
}
