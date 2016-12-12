
import java.awt.Image;
import java.awt.Toolkit;
import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;

import javax.swing.*;

import com.mongodb.DB;
import com.mongodb.MongoClient;
import com.mongodb.gridfs.GridFS;
import com.mongodb.gridfs.GridFSDBFile;
import com.mongodb.gridfs.GridFSInputFile;


public class GridFs extends JFrame{
	GridFs(){
		this.setLayout(null);
		this.setSize(400, 400);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
	}
	
	public static void main(String s[]) throws IOException{
		GridFs gf=new GridFs();
		MongoClient mongo = new MongoClient("localhost", 27017);
		DB db = mongo.getDB("imagedb");
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		boolean cont=true;
		while(cont){
			System.out.println("1.Save Image\n2.Get Image\n3.Exit");
			int ch=Integer.parseInt(br.readLine());
			switch(ch) {
                case 1:
                    System.out.println("Enter file name");String img=br.readLine();
                    File f = new File(img);
                    GridFS gphoto = new GridFS(db);
                    GridFSInputFile gfsFile = gphoto.createFile(f);
                    gfsFile.setFilename(img);
                    gfsFile.save();
                    break;
                case 2:
                    System.out.println("Enter file name to show");String shimg=br.readLine();
                    GridFS gfsPhoto = new GridFS(db);
                    GridFSDBFile imageForOutput = gfsPhoto.findOne(shimg);
                    File tmpfile = File.createTempFile("tmp", "png");
                    imageForOutput.writeTo(tmpfile);
                    //Image obtainedimg = Toolkit.getDefaultToolkit().getImage(tmpfile.getAbsolutePath());
                    JLabel jLabel = new JLabel(new ImageIcon(tmpfile.getPath()));
                    jLabel.setBounds(0, 0, 400, 400);
                    gf.add(jLabel);
                    gf.setVisible(true);
                    break;
                case 3:
                    cont = false;
                    break;
			}

		}
		
	}

}
