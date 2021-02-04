package dataBase;
public class Item {
	private String title;
	private int playingtimes;
	private boolean gotit;
	private String comment;
	public Item(String title, int playingtimes, String comment)
	{
		this.title = title;
		this.playingtimes = playingtimes;
		this.comment = comment;
	}
	public void print() {
		System.out.print("title is "+title+" and ");	
	}
}
