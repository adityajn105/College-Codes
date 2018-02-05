package mypackage;

import java.awt.EventQueue;
import java.awt.GridLayout;

import javax.swing.JComponent;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTabbedPane;

import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

import java.awt.BorderLayout;

public class VMinfos {

	JFrame frame;
	private JTabbedPane tabbedPane;

	/**
	 * Create the application.
	 */
	public VMinfos() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.setBounds(100, 100, 450, 300);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		
		tabbedPane = new JTabbedPane(JTabbedPane.TOP);
		tabbedPane.setBounds(0, 0, 438, 288);
		
	}
	
	public void putVmInfo(NodeList nList){
		JPanel jp[] = new JPanel[nList.getLength()]; 
		for (int temp = 0; temp < nList.getLength(); temp++) {
            Node nNode = nList.item(temp);
            Element eElement = (Element) nNode;
            jp[temp] = new JPanel();
            jp[temp].setLayout(new GridLayout(4,1));
            jp[temp].add(new JLabel("ID :"+eElement.getElementsByTagName("ID").item(0).getTextContent()));
            jp[temp].add(new JLabel("UNAME :"+eElement.getElementsByTagName("UNAME").item(0).getTextContent()));
            jp[temp].add(new JLabel("NAME :"+eElement.getElementsByTagName("NAME").item(0).getTextContent()));
            jp[temp].add(new JLabel("STATE :"+eElement.getElementsByTagName("STATE").item(0).getTextContent()));
            
            tabbedPane.addTab("VM ID : "+eElement.getElementsByTagName("ID").item(0).getTextContent(), jp[temp]);
            frame.getContentPane().add(tabbedPane);
        }
	}
	
}
