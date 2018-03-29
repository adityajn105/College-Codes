package mypackage;

import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JButton;
import javax.swing.JTextField;

import org.opennebula.client.Client;
import org.opennebula.client.ClientConfigurationException;
import org.opennebula.client.host.Host;
import org.opennebula.client.vm.VirtualMachinePool;
import javax.swing.JPasswordField;

public class dashboard {

	private JFrame frame;
	private JTextField uname;
	String password;
	Client mycloud;
	private JPasswordField passwd;
	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					dashboard window = new dashboard();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public dashboard() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.setBounds(100, 100, 450, 300);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
		frame.getContentPane().setLayout(null);
		
		JLabel lblUsername = new JLabel("Username");
		lblUsername.setBounds(55, 46, 137, 35);
		frame.getContentPane().add(lblUsername);
		
		JLabel lblPassword = new JLabel("Password");
		lblPassword.setBounds(55, 93, 89, 15);
		frame.getContentPane().add(lblPassword);
		
		JButton Login = new JButton("Login");
		Login.setBounds(133, 156, 117, 25);
		frame.getContentPane().add(Login);
		
		uname = new JTextField();
		uname.setText("student");
		uname.setBounds(181, 54, 114, 19);
		frame.getContentPane().add(uname);
		uname.setColumns(10);
		
		passwd = new JPasswordField();
		passwd.setText("student");
		passwd.setBounds(181, 93, 114, 19);
		frame.getContentPane().add(passwd);
		
		Login.addActionListener(new ActionListener() {
			
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				if (uname.getText().equalsIgnoreCase("") || passwd.getText().equalsIgnoreCase("")){
					JOptionPane.showMessageDialog(frame, "Username or Password fields are empty", "Data Field Empty",JOptionPane.ERROR_MESSAGE);

					return;
				}
				password = uname.getText() + ":" + passwd.getText();
				
				try {
					mycloud = new Client(password, "http://localhost:2633/RPC2");
					if (mycloud.get_version().getMessage()!=null){
						JOptionPane.showMessageDialog(frame, "Login Success", "Message",JOptionPane.INFORMATION_MESSAGE);
						frame.dispose();
						new Home(mycloud);
					}else{
						JOptionPane.showMessageDialog(frame, "Login Failure", "Failure",JOptionPane.ERROR_MESSAGE);
					}
				} catch (ClientConfigurationException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
				
				
			}
		});
	}
}
