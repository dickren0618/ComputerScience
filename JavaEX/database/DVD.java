package dataBase;

public class DVD extends Item{

	private String director;
	
	public DVD(String title, int playingtimes, String comment,String director)
	{
		super(title,playingtimes,comment);
		this.director=director;
		
	}
	public void print() {
		System.out.print("DVD:");
		super.print();
		System.out.println("director is "+director);
	}
	
}
