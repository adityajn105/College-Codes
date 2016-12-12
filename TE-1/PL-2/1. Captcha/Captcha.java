
import java.awt.Color;
import java.awt.Font;
import java.awt.Image;
import java.awt.Label;
import java.awt.TextField;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.FocusEvent;
import java.awt.event.FocusListener;
import java.awt.image.ImageObserver;
import java.awt.image.ImageProducer;
import java.awt.Graphics;

import javax.imageio.spi.ImageInputStreamSpi;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPasswordField;


public class Captcha extends JFrame implements ActionListener{
	
	String captcha;
	private static int attempt;
	private static TextField input;
	private static JButton check,refresh;
	private Label result;
	private static JLabel label1;
	private static JLabel label2;
	private static JLabel label3;
	private static JLabel label4;
	private static JLabel label5;
	private static JLabel label6;
	private static JLabel un;
	private static TextField username;
	private static Label pass;
	private static JPasswordField password;
	private Font f[]={new Font("LMSansDemiCond10", Font.ITALIC , 20),
			new Font("URW Chancery L",Font.BOLD + Font.ITALIC,21),
			new Font("Century Schoolbook L",Font.BOLD,19),
			new Font("Purisa",Font.PLAIN,18),
			new Font("URW Gothic L",Font.BOLD,17)};
	private Color colors[]={Color.BLACK,Color.BLUE,Color.RED,Color.MAGENTA,Color.YELLOW,Color.PINK};
	private static int failattempts;
	public Captcha() {
		label1= new JLabel();label1.setBackground(Color.GREEN);label1.setBounds(40, 120, 20, 40);label1.setOpaque(true);
		label2= new JLabel();label2.setBackground(Color.GREEN);label2.setBounds(60, 120, 20, 40);label2.setOpaque(true);
		label3= new JLabel();label3.setBackground(Color.GREEN);label3.setBounds(80, 120, 20, 40);label3.setOpaque(true);
		label4= new JLabel();label4.setBackground(Color.GREEN);label4.setBounds(100, 120, 20,40);label4.setOpaque(true);
		label5= new JLabel();label5.setBackground(Color.GREEN);label5.setBounds(120, 120, 20, 40);label5.setOpaque(true);
		label6= new JLabel();label6.setBackground(Color.GREEN);label6.setBounds(140, 120, 20, 40);label6.setOpaque(true);
		refresh=new JButton(new ImageIcon("refresh.jpeg"));refresh.setBounds(170,120 ,40 ,40 );
		refresh.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {giveNewCaptcha();}
		});
		this.setLayout(null);
		this.setSize(250, 400);
		this.setVisible(true);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		un=new JLabel("UserName");un.setBounds(20, 20, 70, 40);un.setFont(new Font("Ariel",Font.BOLD,11));
		username=new TextField();username.setBounds(130, 20, 100, 30);
		
		pass=new Label("Password");pass.setBounds(20,60,70,40);pass.setFont(new Font("Ariel",Font.BOLD,11));
		password=new JPasswordField();password.setBounds(130,60,100,30);
		
		input=new TextField();
		input.setText("Enter Captcha");
		input.setBounds(40, 180, 120, 30);
		input.addFocusListener(new FocusListener() {	
			@Override
			public void focusLost(FocusEvent arg0) {
				if(input.getText().isEmpty()){
					input.setText("Enter Captcha");
				}	
			}
			@Override
			public void focusGained(FocusEvent e) {input.setText("");	}
		});
		
		check=new JButton("Submit");check.setBounds(40, 220, 120, 40);
		result=new Label();result.setBounds(40,280, 120, 20);
		
		this.add(un);
		this.add(username);
		this.add(pass);
		this.add(password);
		this.add(label1);this.add(label2);this.add(label3);this.add(label4);this.add(label5);this.add(label6);
		this.add(input);
		this.add(check);
		this.add(result);
		this.add(refresh);
		check.addActionListener(this);
	}
	public void giveNewCaptcha(){
		String rand="QWERTYUIOPASDFGHJKLZXCVBNMM";
		captcha="";
		//label1
		int ch = (int) Math.round(Math.random());
		if(ch==0){
			char s=rand.charAt(((int)(Math.random()*100))%26);
			captcha=captcha+s;
			label1.setText(Character.toString(s));
		}
		else{
			int i=(int)(Math.random()*10);
			captcha=captcha+i;
			label1.setText(Integer.toString(i));
		}
		label1.setFont(f[(int)((Math.random()*100)%5)]);
		label1.setForeground(colors[(int)((Math.random()*100)%5)]);
		//label 2
		ch = (int) Math.round(Math.random());
		if(ch==0){
			char s=rand.charAt(((int)(Math.random()*100))%26);
			captcha=captcha+s;
			label2.setText(Character.toString(s));
		}
		else{
			int i=(int)(Math.random()*10);
			captcha=captcha+i;
			label2.setText(Integer.toString(i));
		}
		label2.setFont(f[(int)((Math.random()*100)%5)]);
		label2.setForeground(colors[(int)((Math.random()*100)%5)]);
		//label 3
		ch = (int) Math.round(Math.random());
		if(ch==0){
			char s=rand.charAt(((int)(Math.random()*100))%26);
			captcha=captcha+s;
			label3.setText(Character.toString(s));
		}
		else{
			int i=(int)(Math.random()*10);
			captcha=captcha+i;
			label3.setText(Integer.toString(i));
		}
		label3.setFont(f[(int)((Math.random()*100)%5)]);
		label3.setForeground(colors[(int)((Math.random()*100)%5)]);
		//label 4
		ch = (int) Math.round(Math.random());
		if(ch==0){
			char s=rand.charAt(((int)(Math.random()*100))%26);
			captcha=captcha+s;
			label4.setText(Character.toString(s));
		}
		else{
			int i=(int)(Math.random()*10);
			captcha=captcha+i;
			label4.setText(Integer.toString(i));
		}
		label4.setFont(f[(int)((Math.random()*100)%5)]);
		label4.setForeground(colors[(int)((Math.random()*100)%5)]);
		//label 5
		ch = (int) Math.round(Math.random());
		if(ch==0){
			char s=rand.charAt(((int)(Math.random()*100))%26);
			captcha=captcha+s;
			label5.setText(Character.toString(s));
		}
		else{
			int i=(int)(Math.random()*10);
			captcha=captcha+i;
			label5.setText(Integer.toString(i));
		}
		label5.setFont(f[(int)((Math.random()*100)%5)]);
		label5.setForeground(colors[(int)((Math.random()*100)%5)]);
		//label 6
		ch = (int) Math.round(Math.random());
		if(ch==0){
			char s=rand.charAt(((int)(Math.random()*100))%26);
			captcha=captcha+s;
			label6.setText(Character.toString(s));
		}
		else{
			int i=(int)(Math.random()*10);
			captcha=captcha+i;
			label6.setText(Integer.toString(i));
		}
		label6.setFont(f[(int)((Math.random()*100)%5)]);
		label6.setForeground(colors[(int)((Math.random()*100)%5)]);
	}
	
	public static void main(String[] args) {
		Captcha form=new Captcha();
		form.giveNewCaptcha();
		form.play();
	}
	
	public void paint(Graphics g){
		g.drawLine(40, 120, 160, 160);
		g.drawLine(40,130,160,140);
		g.drawLine(40,150,130,120);
	}
	public void play(){
		repaint();
	}


	@Override
	public void actionPerformed(ActionEvent e) {
		if(e.getSource().equals(check)){
				if(captcha.equals(input.getText())){
					result.setForeground(Color.GREEN);
					result.setText("Form Successfulluy submitted");
					JOptionPane.showMessageDialog(this,username.getText()+
							" you have Registered Successfully","Registration Succeessfull",0,new ImageIcon("success.jpeg"));
					
					this.dispose();
				}
				else{
					if(failattempts<2){
						result.setForeground(Color.RED);
						result.setText("ReEnter Capatcha");
						giveNewCaptcha();
						failattempts+=1;
						
					}
					else{
						result.setForeground(Color.RED);
						result.setText("All attempts Completed");
						JOptionPane.showMessageDialog(this, "Your all attemps are Over.\nFill form again and try again.",
								"Registration Unsuccessfull",0,new ImageIcon("failure.png"));
						this.dispose();
						}
				}
		}
			
	}
}
	