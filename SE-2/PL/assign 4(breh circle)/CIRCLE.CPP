#include<iostream.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
#include<dos.h>
class lines
{
protected:
	int x1,x2,y1,y2;
public:
	void getdata();
	void line();
};

class circles:public lines
{
	int rad,x0,y0;
  public:
  circles(){};
  void crad()
  {
	rad=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	x0=x1;y0=y1;
  }
	void circle();
};
void lines::getdata()
{
	cout<<"Enter starting points: ";cin>>x1>>y1;
	cout<<"Enter end points:";cin>>x2>>y2;
}

void circles::circle()
{
   int x=0,y=rad,col=15;
   int d=3-2*rad;
   cout<<"Radius is :"<<rad;
   while(x<y)
   {
	putpixel(x0+x,y0+y,col);putpixel(x0+x,y0-y,col);
	putpixel(x0-x,y0+y,col);putpixel(x0-x,y0-y,col);
	putpixel(x0+y,y0+x,col);putpixel(x0+y,y0-x,col);
	putpixel(x0-y,y0+x,col);putpixel(x0-y,y0-x,col);
	if(d<=0)
	{d=d+4*x+6;}
	else
	{d=d+4*(x-y)+10;y=y-1;}
	x=x+1;

	delay(100);
   }

}
int main(void)
{

	int gdriver=DETECT,gmode,errorcode;
	initgraph(&gdriver,&gmode,"");
	circles c;
	c.getdata();
	c.crad();

	c.circle();

	getch();
	closegraph();
	return 0;
}