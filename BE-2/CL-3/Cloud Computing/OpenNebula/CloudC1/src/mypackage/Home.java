package mypackage;

import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.regex.Pattern;

import javax.swing.JFrame;
import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JScrollPane;

import org.opennebula.client.Client;
import org.opennebula.client.OneResponse;
import org.opennebula.client.Pool;
import org.opennebula.client.host.Host;
import org.opennebula.client.template.Template;
import org.opennebula.client.template.TemplatePool;
import org.opennebula.client.vm.VirtualMachine;
import org.opennebula.client.vm.VirtualMachinePool;
import javax.swing.JList;

import java.awt.BorderLayout;
import java.awt.Color;
import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;
import javax.swing.border.BevelBorder;
import javax.swing.border.EtchedBorder;
import javax.swing.JTextField;
import javax.swing.ListSelectionModel;

public class Home {

	private JFrame frame;
	Client mycloud;
	private JTable vmtable;
	private String columns[] = new String[]{"ID","Name", "Status"};
	DefaultTableModel dtm;
	DefaultListModel tpm;
	ArrayList<Template> tlist;
	JScrollPane sp;
	private JTextField input_ram;
	/**
	 * Launch the application.
	 * @wbp.parser.entryPoint
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Home window = new Home();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 * @wbp.parser.entryPoint
	 */
	public Home(){
		initialize();
	}
	/**
	 * @wbp.parser.entryPoint
	 */
	public Home(Client c) {
		mycloud = c;
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 * @wbp.parser.entryPoint
	 */
	private void initialize() {
		frame = new JFrame();
		frame.setBounds(100, 100, 500, 350);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
		frame.getContentPane().setLayout(null);
		
		JButton btnLogout = new JButton("Logout");
		btnLogout.setBounds(29, 263, 117, 25);
		frame.getContentPane().add(btnLogout);
		
		JLabel lblRunningVms = new JLabel("Virtual Machines");
		lblRunningVms.setBounds(29, 17, 139, 15);
		frame.getContentPane().add(lblRunningVms);
		
		vmtable = new JTable();
		dtm = new DefaultTableModel(0, 0);
		sp=new JScrollPane(vmtable);    
		sp.setBounds(15, 50, 225, 127);
		vmtable.setFillsViewportHeight(true);
		dtm.setColumnIdentifiers(columns);
		vmtable.setModel(dtm);
		frame.getContentPane().add(sp, BorderLayout.CENTER);
		
		JButton btnRefresh = new JButton("Refresh");
		btnRefresh.setBounds(29, 210, 117, 25);
		frame.getContentPane().add(btnRefresh);
		
		JLabel lblAllocateRequest = new JLabel("Allocate / Request");
		lblAllocateRequest.setBounds(308, 12, 152, 15);
		frame.getContentPane().add(lblAllocateRequest);
		
		JLabel lblRam = new JLabel("RAM");
		lblRam.setBounds(284, 51, 70, 15);
		frame.getContentPane().add(lblRam);
		
		input_ram = new JTextField();
		input_ram.setBounds(346, 50, 114, 19);
		frame.getContentPane().add(input_ram);
		input_ram.setColumns(10);
		
		JLabel lblTemplates = new JLabel("Templates");
		lblTemplates.setBounds(332, 88, 74, 15);
		frame.getContentPane().add(lblTemplates);
		
		JList list = new JList();
		JScrollPane slp = new JScrollPane(list);
		slp.setBounds(284, 115, 183, 153);
		frame.getContentPane().add(slp);
		
		JButton btnDeploy = new JButton("Deploy");
		btnDeploy.setBounds(308, 280, 117, 25);
		frame.getContentPane().add(btnDeploy);
		
		VirtualMachinePool vmp = new VirtualMachinePool(mycloud);
		TemplatePool tp = new TemplatePool(mycloud);
		
		tlist = new ArrayList<>();
		tpm = new DefaultListModel<>();
		list.setSelectionMode(ListSelectionModel.SINGLE_INTERVAL_SELECTION);
		loadtmp(tp, tpm, tlist);
		list.setModel(tpm);
		
		Host h = new Host(0, mycloud);
		
		loadvms(vmp, dtm);
		btnLogout.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				JOptionPane.showMessageDialog(frame, "Logout Success", "You have been logged out",JOptionPane.INFORMATION_MESSAGE);
				frame.dispose();
				new dashboard();
			}
		});
		
		btnRefresh.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				loadvms(vmp, dtm);
				loadtmp(tp, tpm, tlist);
			}
		});
		
		btnDeploy.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				if (list.getSelectedIndex()!=-1){
					if (input_ram.getText().isEmpty()){
						JOptionPane.showMessageDialog(frame, "Please enter the amount of RAM to allocate","Empty Field",JOptionPane.ERROR_MESSAGE);
						return;
					}
					String hstmsg = h.info().getMessage();
					String a[] = hstmsg.split("<FREE_MEM>");
					String a2[] = a[1].split("</FREE_MEM>");
					Float freemem = Float.parseFloat(a2[0]) / 1000;
					String ram = input_ram.getText().toString();
					if (freemem<Float.parseFloat(ram)){
						JOptionPane.showMessageDialog(frame, "Insufficent Memory (RAM) Error","Select Template Error",JOptionPane.ERROR_MESSAGE);
						return;
					}
					Template t = tlist.get(list.getSelectedIndex());
					String vmTemplate ="NAME     = "+t.getName()+" CPU = 1    MEMORY = "+ram+"\n"
									+ "OS=[ARCH=\"x86_64\",BOOT=\"cdrom,hd\"]\n";
					OneResponse rc = VirtualMachine.allocate(mycloud, vmTemplate);
					if(rc.isError()){
						System.out.println(rc.getErrorMessage());
						return;
					}
					JOptionPane.showMessageDialog(frame, "VM successfully created and deployed", "Success in Deployment",JOptionPane.INFORMATION_MESSAGE);	
				}else{
					JOptionPane.showMessageDialog(frame, "Please select a template", "Select Template Error",JOptionPane.ERROR_MESSAGE);
				}
			}
		});
		
	}
	
	private void loadvms(VirtualMachinePool vmp, DefaultTableModel dtm){
		vmp.infoAll();
		
		//Delete all existing rows
		for(int i=dtm.getRowCount() - 1; i>=0; i--){
			dtm.removeRow(i);
		}
		
		//Load all rows
		Iterator<VirtualMachine> i = vmp.iterator();
		while(i.hasNext()){
			VirtualMachine v = i.next();
			dtm.addRow(new Object[]{ v.getId(), v.getName(), v.lcmStateStr()});
		}
		
	}
	private void loadtmp(TemplatePool tp, DefaultListModel tpm, ArrayList<Template> tlist){
		tp.infoAll();
		
		//Delete all existing rows
		tlist.clear();
		for(int i=tpm.getSize() - 1; i>=0; i--){
			tpm.remove(i);
		}
		
		for (Template t : tp){
			tpm.addElement(t.getName());
			tlist.add(t);
		}
		
	}
}
