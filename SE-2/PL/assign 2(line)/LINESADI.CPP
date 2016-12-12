
#include <graphics.h>
#include <stdlib.h>
#include <iostream.h>
#include <conio.h>
#include <math.h>

class Line
{
int x1,y1,x2,y2;
public:
int col;
void getdata();
void bline(int);
void bline();
void bdotted();
void bthick();
void bdashdot();
void bdotted(int);
void bdashdot(int);
void bthick(int);
int round(float);
};

void Line::getdata()
{
   cout<<"Enter start points";cin>>x1>>y1;
   cout<<"Enter end points";cin>>x2>>y2;
   cout<<"Enter color";cin>>col;
}

void Line::bline(int c)
{
	int dx=x2-x1,dy=y2-y1;
	float x,y;
	float xinc,yinc;int steps,i;
	if(abs(dx)>abs(dy))
	{steps=abs(dx);}
	else
	{steps=abs(dy);}
	xinc=float(dx)/float(steps);
	yinc=float(dy)/float(steps);
	putpixel(round(x1),round(y1),c);
	x=x1;y=y1;
	for(i=0;i<steps;i++)
	{
	x+=xinc;
	y+=yinc;
	putpixel(round(x),round(y),c);

	}
}

void Line::bdotted(int c)
{
int dx=x2-x1;
int dy=y2-y1;float x,y;
float xinc,yinc;int steps,i;
if(abs(dx)>abs(dy))
	{steps=abs(dx);}
else
	{steps=abs(dy);}
xinc=float(dx)/float(steps);
yinc=float(dy)/float(steps);
putpixel(round(x1),round(y1),c);
x=x1;y=y1;
for(i=0;i<steps;i+=2)
	{
	x+=2*xinc;
	y+=2*yinc;
	putpixel(round(x),round(y),c);

	}
}
void Line::bdashdot(int c)
{
int dx=x2-x1;
int dy=y2-y1;float x,y;
float xinc,yinc;int steps,i;

if(abs(dx)>abs(dy))
	{steps=abs(dx);}
else
	{steps=abs(dy);}
xinc=float(dx)/float(steps);
yinc=float(dy)/float(steps);
putpixel(round(x1),round(y1),c);
x=x1;y=y1;
for(i=0;i<steps;i++)
{
	x+=xinc;
	y+=yinc;
	if(i%15<5||i%15==9)
	{
	putpixel(round(x),round(y),c);
	}

}
}
void Line::bthick(int c)
{
int dx=x2-x1;int i=1,thk;
int dy=y2-y1;float x,y;
cout<<"Enter thickness";cin>>thk;
float xinc,yinc;int steps;
float wx=( (thk-1)*(sqrt((dx*dx)+(dy*dy))) )/abs(2*dx);
float wy=( (thk-1)*(sqrt((dx*dx)+(dy*dy))) )/abs(2*dy);
if(abs(dx)>abs(dy))
	{steps=abs(dx);}
else
	{steps=abs(dy);}
xinc=float(dx)/float(steps);
yinc=float(dy)/float(steps);
putpixel(round(x1),round(y1),c);
x=x1;y=y1;

while(i<=steps)
	{
		if (dy<=dx)
		{
			for(int j=y-wy; j<y+wy; j++)
			{
				putpixel(round(x),j,col);
			}
		}
		else if(dy>dx)
		{
			for(int k=x-wx; k<x+wx; k++)
			{
				putpixel(k,round(y),col);
			}
		}
		x=x+xinc;
		y=y+yinc;
		i=i+1;
		//delay(20);
	}
}

int Line::round(float z)
{
	float temp=int(z);
	temp+=0.5;

	if(temp>=z)
	{
		return(int(z));
	}
	else
	{
		return(int(z)+1);
	}

}

void Line::bline()
{
	int dx,dy,pk1,count;
	int x,y;
	x=x1;y=y1;

	dx=x2-x1;dy=



	y2-y1;
	putpixel(x,y,col);
	pk1=2*dy-dx;
	count=dx;
	for(int i=0;i<count;i++)
	{
		if(pk1<0)
		{
			x=x+1;
			putpixel(x,y,col);
			pk1=pk1+2*dy;
		}
		else
		{
			x=x+1;
			y=y+1;
			putpixel(x,y,col);
			pk1=pk1+2*dy-2*dx;
		}
	}
}
void Line::bdotted()
{
	int dx,dy,pk1,count;
	int x,y;
	x=x1;y=y1;

	dx=x2-x1;dy=y2-y1;
	putpixel(x,y,col);
	pk1=2*dy-dx;
	count=dx;
	for(int i=0;i<count;i+=2)
	{
		if(pk1<0)
		{
			x+=2;
			putpixel(x,y,col);
			pk1=pk1+2*dy;
		}
		else
		{
			x+=2;
			y+=1;
			putpixel(x,y,col);
			pk1=pk1+2*dy-2*dx;
		}
	}
}
void Line::bdashdot()
{
	int dx,dy,pk1,count;
	int x,y;
	x=x1;y=y1;

	dx=x2-x1;dy=y2-y1;
	putpixel(x,y,col);
	pk1=2*dy-dx;
	count=dx;int k;
	for(int i=0;i<count;i+=1)
	{

		if(pk1<0)
		{
			x+=1;
				k=i%15;
				if(k<5||k==10){
				putpixel(x,y,col);}
			pk1=pk1+2*dy;
		}
		else
		{
			x+=1;
			y+=1;
				k=i%15;
				if(k<5||k==10){
				putpixel(x,y,col);}
			pk1=pk1+2*dy-2*dx;
		}
	    }

}

int main(void)
{

   int gdriver = DETECT, gmode, errorcode;
   Line l;
   int ch;char con;
   initgraph(&gdriver, &gmode, "");
   cout<<"Max resolution is "<<getmaxx()<<","<<getmaxy()<<"\n";
   l.getdata();
   cout<<"Menu\n"<<"Brehesnem\n1.Simple Line\n2.Dotted line\n3.Dash Dot line\n4.Thick line\n";
   cout<<"DDALine\n5.Simple Line\n6.Dotted line\n7.Dash Dot line\n8.Thick line\n";
   cin>>ch;
   int c=l.col;
   switch (ch)
   {
     case 1:{l.bline();break;}
     case 2:{l.bdotted();break;}
     case 3:{l.bdashdot();break;}
    // case 4:{l.bthick();break;}
     case 5:{l.bline(c);break;}
     case 6:{l.bdotted(c);break;}
     case 7:{l.bdashdot(c);break;}
     case 8:{l.bthick(c);break;}

   }

   getch();
   closegraph();
   return 0;
}
