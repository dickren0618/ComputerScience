package dataBase;

public class CD extends Item{
	private String artist;
	private int numofTacks;
	
	public CD(String title,int playingtimes, String comment,String artist,int numofTacks) {
		super(title, playingtimes,comment);
		this.artist=artist;
		this.numofTacks=numofTacks;
	}
	public void print() {
		System.out.print("CD:");
		super.print();
		System.out.println("artist is "+artist);
	}

}
