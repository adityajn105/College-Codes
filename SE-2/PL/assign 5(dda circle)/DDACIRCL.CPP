#include<graphics.h>
#include<iostream.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<dos.h>
class ddacircle
{
 int rad,x0,y0,col;
 public:
 ddacircle();
 void drawcircle();
 float epsilon();
}

ddacircle::ddacircle()
{
cout<<"Input radius: ";cin>>rad;
cout<<"Input center: ";cin>>x0>>y0;
cout<<"Input Color: ";cin>>col;

}
void ddacircle::drawcircle()
{  float x,y;
   float startx=rad*cos(0);float starty=rad*sin(0);
   float x1=startx;float y1=starty;
   float e=epsilon();
   do
   {
   x=x1+e*y1;
   y=y1-e*x;
   putpixel(x+x0,y+y0,col);
   x1=x;y1=y;
   }while(y1-starty<e||startx-x1>e);
}

float ddacircle::epsilon()
{
	int n=0,val;float e;
	do
	{
	val=pow(2,n);
	n++;
	}
	while(val<rad);

	e=1/pow(2,n-1);
	return e;
}
int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int xmax, ymax;
   initgraph(&gdriver, &gmode, "");
   ddacircle d;
   d.drawcircle();


   /* clean up */
   getch();
   closegraph();
   return 0;
}