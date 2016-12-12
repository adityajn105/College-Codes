import java.awt.*;
import java.applet.*;
import java.util.*;

public class line extends Applet {
	int x1,y1,x2,y2,ch;
	
	public void thick(Graphics g,int x1,int x2,int y1,int y2)
	{

		g.drawOval(x1, y1, 5, 5);
		int dx=x2-x1;
		int dy=y2-y1;
		int p1=2*dy-2*dx;
		int p0=2*dy-dx;
		int i=0;
		p1=p0;
		while(i<dx)
		{
			if(p1<0)
			{
				g.drawOval(x1+1, y1, 5, 5);
				p1=p0+2*dy;
				x1++;
			}
			else
			{
				g.drawOval(x1+1, y1+1, 5, 5);
				p1=p0+2*dy-2*dx;
				x1++;
				y1++;
			}
			p0=p1;
			i++;
		}
		
		
		
	}
	
	public void simple(Graphics g,int x1,int x2,int y1,int y2)
	{
		g.drawOval(x1, y1, 1, 1);
		int dx=x2-x1;
		int dy=y2-y1;
		int p1=2*dy-2*dx;
		int p0=2*dy-dx;
		int i=0;
		p1=p0;
		while(i<dx)
		{
			if(p1<0)
			{
				g.drawOval(x1+1, y1, 1, 1);
				p1=p0+2*dy;
				x1++;
			}
			else
			{
				g.drawOval(x1+1, y1+1, 1, 1);
				p1=p0+2*dy-2*dx;
				x1++;
				y1++;
			}
			p0=p1;
			i++;
		}
		
		
		
	}
		
	
	public void dashed(Graphics g,int x1,int x2,int y1,int y2)
	{
		g.drawOval(x1, y1, 1, 1);
		int dx=x2-x1;
		int dy=y2-y1;
		int p1=2*dy-2*dx;
		int p0=2*dy-dx;
		int i=0;
		p1=p0;
		while(i<dx)
		{
			if(p1<0)
			{
				if(x1%4!=0)
				{
				g.drawOval(x1+1, y1, 1, 1);
				p1=p0+2*dy;
				x1++;
				}
				else
				{
					x1++;	
				}
			}
			else
			{
				if(x1%4!=0)
				{
				g.drawOval(x1+1, y1+1, 1, 1);
				p1=p0+2*dy-2*dx;
				x1++;
				y1++;
				}
				else
				{
					x1++;
					y1++;
				}
			}
			p0=p1;
			i++;
		}
		
	}
	
	public void dotted(Graphics g,int x1,int x2,int y1,int y2)
	{

		g.drawOval(x1, y1, 1, 1);
		int dx=x2-x1;
		int dy=y2-y1;
		int p1=2*dy-2*dx;
		int p0=2*dy-dx;
		int i=0;
		p1=p0;
		while(i<dx)
		{
			if(p1<0)
			{
				if(x1%3==0)
				{
				g.drawOval(x1+1, y1, 1, 1);
				p1=p0+2*dy;
				x1++;
				}
				else
				{
					x1++;	
				}
			}
			else
			{
				if(x1%3==0)
				{
				g.drawOval(x1+1, y1+1, 1, 1);
				p1=p0+2*dy-2*dx;
				x1++;
				y1++;
				}
				else
				{
					x1++;
					y1++;
				}
			}
			p0=p1;
			i++;
		}
		
	}
	
	
	public void paint(Graphics g)
	{

		g.drawOval(1, 1, 1, 1);
		switch(ch)
		{
		case 1:
		{
			simple(g,x1,x2,y1,y2);
			break;
		}
		case 2:
		{
			thick(g,x1,x2,y1,y2);
			break;
		}
		case 3:
		{
			dashed(g,x1,x2,y1,y2);
			break;
		}
		case 4:
		{
			dotted(g,x1,x2,y1,y2);
			break;
		}
		
		
	}

	}
	
	public void init()
	{
		System.out.println("Enter the co-ordinates(x1,y1) (x2,y2) :");
		Scanner s=new Scanner(System.in);
		x1=s.nextInt();
		y1=s.nextInt();
		x2=s.nextInt();
		y2=s.nextInt();
		System.out.println("Enter your choice\n1.Simple\n2.Thick\n3.Dashed\n4.Dotted");
		ch=s.nextInt();
		
	}

}
