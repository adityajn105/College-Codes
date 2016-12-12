import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Scanner;
import org.bson.Document;
import com.mongodb.BasicDBObject;
import com.mongodb.DB;
import com.mongodb.DBCollection;
import com.mongodb.DBCursor;
import com.mongodb.DBObject;
import com.mongodb.MongoClient;
import com.mongodb.client.MongoCollection;

public class Mongo {
	public static void main(String[] args) throws IOException {
		MongoClient client=new MongoClient("localhost",27017);
		System.out.println("Connection established");
		DB db = client.getDB("BlogData");
		System.out.println("Database Found: BlogData");
		DBCollection col = db.getCollection("post");
		System.out.println("Using Collection : post");
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		boolean contin=true;
		while(contin){
			System.out.println("***MENU***\n1.Insert.\n2.Delete.\n3.Update.\n4.Display all.\n5.Exit");
			int ch=Integer.parseInt(br.readLine());
			switch(ch){
			case 1:
				System.out.print("Enter Title");String s=br.readLine();
				System.out.print("Enter description");String d=br.readLine();
				BasicDBObject doc = new BasicDBObject("title",s)
										.append("description",d);
				doc.append("by","Shrikant");
				doc.append("url","shrikant");
				ArrayList<String> al=new ArrayList<String>();
				al.add("tag1");
				al.add("tag2");
				doc.append("tags",al);
				doc.append("likes","100");
				col.insert(doc);
				break;
			case 4: DBCursor cur=col.find();
					for(DBObject co:cur){
					System.out.println(co);
				    }
				    break;
			case 2: System.out.print("Enter Tille");String s2=br.readLine();
					BasicDBObject obj=new BasicDBObject("title",s2);
					col.remove(obj);
					System.out.println("Removed");
					break;
			case 3: System.out.print("Enter title of document");
					String tit=br.readLine();
					System.out.println("Enter new Description");
					String dec=br.readLine();
					BasicDBObject obj2=new BasicDBObject("$set",new BasicDBObject("description",dec));
					col.update(new BasicDBObject("title",tit), obj2);
					break;
					/*DBCursor dbc=col.find(obj1);
					DBObject obj3=dbc.next();
					obj3.put("description",dec);
					col.update(obj1, obj3);
					System.out.println("updated");*/
			case 5: contin=false;
					break;
			}
		}	}
}
