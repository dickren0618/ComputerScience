package dataBase;

import java.util.ArrayList;
import java.util.Scanner;

public class DataBase {
    private ArrayList<Item> item = new ArrayList<Item>();
    public void add(Item it)
    {
    	item.add(it);
    }
    public void list()
    {
    	for(Item it:item)
    	{
    		it.print();
    	}
    }
	public static void main(String[] args) {
		DataBase db=new DataBase();
		CD cd=new CD("MAMA",60, "good","Ren",4);
		db.add(cd);
		db.list();
		Scanner in=new Scanner(System.in);
		while(true)
		{
			String title;int playingtimes;String comment;String director;String artist;int numofTacks;
			System.out.println("Chose what do you wanna put?");
			String key=in.next();
			if(key.equals("CD"))
			{
				System.out.println("please input title,playingtimes,comment,artist and numofTacks");
				title=in.next();
				playingtimes=in.nextInt();
				comment=in.next();
				artist=in.next();
				numofTacks=in.nextInt();
				CD ab=new CD(title,playingtimes,comment,artist,numofTacks);
				db.add(ab);
			}
			else if(key.equals("DVD"))
			{
				System.out.println("please input title,playingtimes,comment,director");
				title=in.next();
				playingtimes=in.nextInt();
				comment=in.next();
				director=in.next();
				DVD bb=new DVD(title,playingtimes,comment,director);
				db.add(bb);
			}
			db.list();
			key=null;
		}
	}

}
