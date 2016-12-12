import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;


public class OurGuests extends JFrame implements ActionListener{
	private static final String JDBC_Driver="com.mysql.jdbc.Driver";
	private static final String DB_USER="jdbc:mysql://localhost/AdityaHotels";
	private static final String USER="root";
	private static final String PWD="aditya";
	private Statement stmt;
	
	private JButton submit,delete,update,showall,count;
	private JTextField guestno,guestname,guestaddress;
	private JLabel no,name,address,list;
	private JTextArea all;
	OurGuests() throws SQLException{
		this.setLayout(null);
		this.setSize(800, 600);
		this.setVisible(true);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		this.setVisible(true);
		this.setTitle("Guest Database");
		
		submit=new JButton("Submit");submit.setBounds(150,300 ,100 , 50);this.add(submit);
		showall=new JButton("Display Guest List");showall.setBounds(370,80,350,30);this.add(showall);
		delete=new JButton("Delete Guest");delete.setBounds(400, 310, 150, 30);this.add(delete);
		update=new JButton("Update Guest");update.setBounds(550,310,150,30);this.add(update);
		count=new JButton("Count Guests using Stored Procedure");
		count.setBounds(370, 50, 350, 30);this.add(count);
		
		no=new JLabel("Guest Number");no.setBounds(40, 150, 150, 30);this.add(no);
		name=new JLabel("Guest Name");name.setBounds(40,200 , 150, 30);this.add(name);
		address=new JLabel("Guest Address");address.setBounds(40, 250, 150, 30);this.add(address);
		list=new JLabel("Our Guests");list.setBounds(500, 130, 100, 20);this.add(list);
		
		guestno=new JTextField();guestno.setBounds(200,150,150,30);this.add(guestno);
		guestname=new JTextField();guestname.setBounds(200,200,150,30);this.add(guestname);
		guestaddress=new JTextField();guestaddress.setBounds(200,250,150,30);this.add(guestaddress);
		
		all=new JTextArea();all.setBounds(400, 150, 300, 150);this.add(all);
		all.setText("Guest No\tGuest Name\tGuest Address");all.setEditable(false);
		all.setBackground(Color.LIGHT_GRAY);
		
		submit.addActionListener(this);
		showall.addActionListener(this);
		delete.addActionListener(this);
		update.addActionListener(this);
		count.addActionListener(this);
		establishConnection();
	}
	
	public void establishConnection() throws SQLException{
		Connection con=null;
		try {
			Class.forName(JDBC_Driver);
			con=DriverManager.getConnection(DB_USER, USER, PWD);
		} 
		catch (Exception e) {
			e.printStackTrace();
		}
		stmt=con.createStatement();
	}
	
	public static void main(String[] args) throws SQLException {
		new OurGuests();
	}

	@Override
	public void actionPerformed(ActionEvent arg0) {
		if(arg0.getSource().equals(showall)){
			String showq="SELECT * FROM GUESTS";
			ResultSet rs;
			try{
				rs = stmt.executeQuery(showq);
				String result="Guest No\tGuest Name\tGuest Address";
				while(rs.next()){
					int g_no=rs.getInt(1);
					String g_name=rs.getString(2);
					String g_add=rs.getString(3);
					result=result+"\n"+g_no+"\t"+g_name+"\t"+g_add;
				}
				all.setText(result);
				
			}
			catch(SQLException e){}
		}
		else if(arg0.getSource().equals(submit)){
			if(!guestno.getText().equals("")&&!guestname.getText().equals("")&&!guestaddress.getText().equals("")){
				try{
				String insertq="INSERT INTO GUESTS VALUES(\""+guestno.getText()+"\"," +
						"\""+guestname.getText()+"\","+
						"\""+guestaddress.getText()+"\")";
				int rows=stmt.executeUpdate(insertq);
				JOptionPane.showMessageDialog(this, rows+" inserted Successfully");
				guestno.setText("");guestname.setText("");guestaddress.setText("");
				showall.doClick();
				}
				catch(SQLException e){}
			}
			else{
				JOptionPane.showMessageDialog(this, "Please fill all fields(no,name,address) to continue insertion.");
			}
		}
		else if(arg0.getSource().equals(delete)){
			try{
				String no=JOptionPane.showInputDialog(this, "Enter guest no to be removed");
				String deleteq="DELETE FROM GUESTS WHERE guest_no=\""+Integer.parseInt(no)+"\"";
				int rows1=stmt.executeUpdate(deleteq);
				JOptionPane.showMessageDialog(this, rows1+" deleted Successfully");
				showall.doClick();
			}
			catch(SQLException e){}
		}
		else if(arg0.getSource().equals(update)){
			try{
				if(!guestno.getText().equals("")&&!guestname.getText().equals("")&&!guestaddress.getText().equals("")){
					String no=JOptionPane.showInputDialog(this, "Enter current guest no to be updated");
					String updateq="UPDATE GUESTS SET guest_no=\""+guestno.getText()+"\","+
							"name=\""+guestname.getText()+"\","+
							"address=\""+guestaddress.getText()+"\""+
							"WHERE guest_no=\""+Integer.parseInt(no)+"\"";
					int rows2=stmt.executeUpdate(updateq);
					JOptionPane.showMessageDialog(this, rows2+" updated Successfully");
					guestno.setText("");guestname.setText("");guestaddress.setText("");
					showall.doClick();
				}
				else{
					JOptionPane.showMessageDialog(this, "Please fill all fields(no,name,address) to continue updation.");
				}
			}
			catch(SQLException e){}
		}
		else if(arg0.getSource().equals(count)){
			try{
				String count="CALL guest_counter()";
				ResultSet rs=stmt.executeQuery(count);
				rs.next();
				int no=rs.getInt(1);
				JOptionPane.showMessageDialog(this, "Currently Database has "+no+" guests information" );
			}
			catch(SQLException e){
				JOptionPane.showMessageDialog(this, "Some error occured" );
			}
		}
		
	}
}
