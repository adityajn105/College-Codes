#include <iostream>
#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>

using namespace std;

void setpixel(float a,float b,int c)
{
	if(a>0 && b>0)
		putpixel(a,b,c);
}

class dda
{
	int x1,y1,x2,y2,dx,dy,length;
	float x,y,xinc,yinc;
	public:
	dda()
	{
	  x=y=x1=y1=x2=y2=length=0;
	  xinc=yinc=0;
	}
	void getdata();	
	void calc();
	void line();
	void dotline();
	void dashline();
	void thickline();
	void thickline(int);
};


void dda::getdata()
{
	cout<<"Enter the co-ordinate x1 : ";
	cin>>x1;
	cout<<"Enter the co-ordinate y1 : ";
	cin>>y1;
	cout<<"Enter the co-ordinate x2 : ";
	cin>>x2;
	cout<<"Enter the co-ordinate y2 : ";
	cin>>y2;
	
}
void dda::calc()
{
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	
	if(dx>=dy)
	{
		length=dx;
	}
	else
	{
		length=dy;
	}
	xinc=float(x2-x1)/length;
	yinc=float(y2-y1)/length;
	
	x=x1+0.5;
	y=y1+0.5;

}
void dda::line()
{
	  
	int i=1;
	
	while(i<=length)
	{
		setpixel(x,y,YELLOW);
		x=x+xinc;
		y=y+yinc;
		i=i+1;
		delay(20);
	}

        
}

void dda::dotline()
{
	  
	int i=1,count=0;
	
	while(i<=length)
	{
		if(count%3==0)
			setpixel(x,y,CYAN);
		x=x+xinc;
		y=y+yinc;
		i=i+1;
		count++;
		delay(20);
	}

        
}

void dda::dashline()
{
	  
	int i=1,count=0;
	
	while(i<=length)
	{
		if(count%6<3)
			setpixel(x,y,WHITE);
		x=x+xinc;
		y=y+yinc;
		i=i+1;
		count++;
		delay(20);
	}

        
}

void dda::thickline()
{  
	int i=1, j, k, thickness=3;
	float wx, wy;

	wx=( (thickness-1)*(sqrt(dx*dx+dy*dy)) )/abs(2*dx);
   	wy=( (thickness-1)*(sqrt(dx*dx+dy*dy)) )/abs(2*dy);	

	while(i<=length)
	{
		if (dy<=dx)
		{
			for(j=y-wy; j<y+wy; j++)
			{
				setpixel(x,j,RED);
			}
		}
		else if(dy>dx)
		{
			for(k=x-wx; k<x+wx; k++)
			{
				setpixel(k,y,RED);
			}
		}
		x=x+xinc;
		y=y+yinc;
		i=i+1;
		delay(20);
	}     
}

void dda::thickline(int thickness)
{
	  
	int i=1, j, k;
	float wx, wy;
	
	wx=( (thickness-1)*(sqrt(dx*dx+dy*dy)) )/abs(2*dx);
   	wy=( (thickness-1)*(sqrt(dx*dx+dy*dy)) )/abs(2*dy);

	while(i<=length)
	{
		if (dy<=dx)
		{
			for(j=y-wy; j<y+wy; j++)
			{
				setpixel(x,j,BLUE);
			}
		}
		else if(dy>dx)
		{
			for(k=x-wx; k<x+wx; k++)
			{
				setpixel(k,y,BLUE);
			}
		}
		x=x+xinc;
		y=y+yinc;
		i=i+1;
		delay(20);
	}        
}


//*********Bresenham**********//


class bresenham
{
	int x, y, x0, y0, x1, y1, dx, dy, s1, s2, error;
	bool interchange;
public:
	bresenham()
	{
		x=y=x0=y0=x1=y1=dx=dy = 0;	
	}

	void accept();
	void contline();
	void dotline();
	void thickline();
	void thickline(int);
	void dashline();
	int sign(int x);
};	

int bresenham :: sign(int x)
{
	if (x>0)
		return 1;
	else if(x==0)
		return 0;
	else
		return (-1);
}

void bresenham :: accept()
{
	cout<<"\nEnter coordinate Xo : ";
	cin>>x0;
	
	cout<<"\nEnter coordinate Yo : ";
	cin>>y0;
	
	cout<<"\nEnter coordinate X1 : ";
	cin>>x1;
	
	cout<<"\nEnter coordinate Y1 : ";
	cin>>y1;
}

void bresenham :: contline()
{
	  
	int ax, ay, temp;
	x=x0;
	y=y0;
	
	dx = x1-x0;
	dy = y1-y0;
	
	s1=sign(dx);
	s2=sign(dy);
	
	ax=abs(dx);
	ay=abs(dy);
	
	if(ay>ax)
	{
		temp=ax;
		ax=ay;
		ay=temp;
		
		interchange=1;
	}
	else
		interchange =0;
		
	error=2*ay-ax;
	
	for(int i=0;i<ax;i++)
	{
		setpixel(x,y,YELLOW);
		while(error>0)
		{	
			if(interchange==1)
				x=x+s1;
			else
				y=y+s2;
				
			error=error-2*ax;		
		}
		
		
		
		if (interchange==1)
			y=y+s2;
		else
			x=x+s1;
			
		error=error+2*ay;
		
		delay(20);
	}	
	
}

void bresenham :: dotline()
{
	  
	int ax, ay, temp;
	x=x0;
	y=y0;
	
	dx = x1-x0;
	dy = y1-y0;
	
	s1=sign(dx);
	s2=sign(dy);
	
	ax=abs(dx);
	ay=abs(dy);
	
	if(ay>ax)
	{
		temp=ax;
		ax=ay;
		ay=temp;
		
		interchange=1;
	}
	else
		interchange =0;
		
	error=2*ay-ax;
	
	for(int i=0;i<ax;i++)
	{
		if(i%3==0)
			setpixel(x,y,RED);
		while(error>0)
		{	
			if(interchange==1)
				x=x+s1;
			else
				y=y+s2;
				
			error=error-2*ax;		
		}
		
		
		
		if (interchange==1)
			y=y+s2;
		else
			x=x+s1;
			
		error=error+2*ay;
		
		delay(20);
	}	
	
}

void bresenham :: dashline()
{
	  
	int ax, ay, temp;
	
	x=x0;
	y=y0;
	
	dx = x1-x0;
	dy = y1-y0;
	
	s1=sign(dx);
	s2=sign(dy);
	
	ax=abs(dx);
	ay=abs(dy);
	
	if(ay>ax)
	{
		temp=ax;
		ax=ay;
		ay=temp;
		
		interchange=1;
	}
	else
		interchange =0;
		
	error=2*ay-ax;
	
	for(int i=0;i<ax;i++)
	{
		if(i%4!=0)
			setpixel(x,y,WHITE);
		while(error>0)
		{	
			if(interchange==1)
				x=x+s1;
			else
				y=y+s2;
				
			error=error-2*ax;		
		}
		
		
		
		if (interchange==1)
			y=y+s2;
		else
			x=x+s1;
			
		error=error+2*ay;
		
		delay(20);
	}	
	
}

void bresenham :: thickline()
{
	  
	int ax, ay, temp, thickness=3 , j, k;
	
	float wx, wy;
	
	wx=( (thickness-1)*(sqrt(dx*dx+dy*dy)) )/abs(2*dx);
   	wy=( (thickness-1)*(sqrt(dx*dx+dy*dy)) )/abs(2*dy);
	
	
	x=x0;
	y=y0;
	
	dx = x1-x0;
	dy = y1-y0;
	
	s1=sign(dx);
	s2=sign(dy);
	
	ax=abs(dx);
	ay=abs(dy);
	
	if(ay>ax)
	{
		temp=ax;
		ax=ay;
		ay=temp;
		
		interchange=1;
	}
	else
		interchange =0;
		
	error=2*ay-ax;
	
	for(int i=0;i<ax;i++)
	{
		for(int j=0;j<thickness;j++)
		{
			if (dy<=dx)
			{
				for(j=y-wy; j<y+wy; j++)
				{
				setpixel(x,j,CYAN);
				}
			}
			else if(dy>dx)
			{
				for(k=x-wx; k<x+wx; k++)
				{
				setpixel(k,y,CYAN);
				}
			}
		}
		while(error>0)
		{	
			if(interchange==1)
				x=x+s1;
			else
				y=y+s2;
				
			error=error-2*ax;		
		}
		
		
		
		if (interchange==1)
			y=y+s2;
		else
			x=x+s1;
			
		error=error+2*ay;
		
		delay(20);
	}	
	
}

void bresenham :: thickline(int thickness)
{
	  
	int ax, ay, temp, j, k;
	
	float wx, wy;
	
	wx=( (thickness-1)*(sqrt(dx*dx+dy*dy)) )/abs(2*dx);
   	wy=( (thickness-1)*(sqrt(dx*dx+dy*dy)) )/abs(2*dy);
	
	
	x=x0;
	y=y0;
	
	dx = x1-x0;
	dy = y1-y0;
	
	s1=sign(dx);
	s2=sign(dy);
	
	ax=abs(dx);
	ay=abs(dy);
	
	if(ay>ax)
	{
		temp=ax;
		ax=ay;
		ay=temp;
		
		interchange=1;
	}
	else
		interchange =0;
		
	error=2*ay-ax;
	
	for(int i=0;i<ax;i++)
	{
		for(int j=0;j<thickness;j++)
		{
			if (dy<=dx)
			{
				for(j=y-wy; j<y+wy; j++)
				{
				setpixel(x,j,MAGENTA);
				}
			}
			else if(dy>dx)
			{
				for(k=x-wx; k<x+wx; k++)
				{
				setpixel(k,y,MAGENTA);
				}
			}
		}
		while(error>0)
		{	
			if(interchange==1)
				x=x+s1;
			else
				y=y+s2;
				
			error=error-2*ax;		
		}
		
		
		
		if (interchange==1)
			y=y+s2;
		else
			x=x+s1;
			
		error=error+2*ay;
		delay(20);
	}	
	
}


int main(void)
{
	int choice,opt,thickness;
   	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, NULL);
   
   	dda d;
	bresenham obj;
  	
  	while(1)
  	{
  		cout<<	"\n1->Use Bresenham algorithm"
  			"\n2->Use DDA algorithm"
  			"\n3->Exit  :  ";
  		cin>>opt;
  		
  		if(opt==3)
  			exit(0);
  		
  		cout<<	"\n1.Continuous Line"
  			"\n2.Dotted Line"
  			"\n3.Dashed Line"
  			"\n4.Thick Line"
  			"\nEnter option : ";
  		cin>>choice; 
  		
  		switch(choice)
  		{
  		case 1:
  			if(opt==1)
  			{
  				obj.accept();
  				obj.contline();
  			}
  			else if(opt==2)
  			{
  				d.getdata();
				d.calc();
				d.line();
  			}
			break;
		case 2:
			if(opt==1)
  			{
  				obj.accept();
  				obj.dotline();
  			}
  			else if(opt==2)
  			{
  				d.getdata();
				d.calc();
				d.dotline();
  			}
			break;
		case 3:
			if(opt==1)
  			{
  				obj.accept();
  				obj.dashline();
  			}
  			else if(opt==2)
  			{
  				d.getdata();
				d.calc();
				d.dashline();
  			}
			break;
		case 4:
			if(opt==1)
  			{
  				obj.accept();
  				cout<<"\nEnter thickness (0:Default) : ";
  				cin>>thickness;
  				if(thickness==0)
  					obj.thickline();
  				else
  					obj.thickline(thickness);
  			}
  			else if(opt==2)
  			{
  				d.getdata();
				d.calc();
  				cout<<"\nEnter thickness (0:Default) : ";
  				cin>>thickness;
  				if(thickness==0)
  					d.thickline();
  				else
  					d.thickline(thickness);
  			}
			break;
  		}
	  	
  	}

	getch();
   	
return 0;
}
