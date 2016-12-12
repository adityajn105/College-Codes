
#include <graphics.h>
#include <stdlib.h>
#include <iostream.h>
#include <conio.h>
void boundaryfill(int x,int y,int ic,int bc)
{
	int color=getpixel(x,y);
	if((color!=bc)&&(color!=ic))
	{
	putpixel(x,y,ic);
	boundaryfill(x+1,y,ic,bc);
	boundaryfill(x-1,y,ic,bc);
	boundaryfill(x,y+1,ic,bc);
	boundaryfill(x,y-1,ic,bc);
	}
}
void floodfill(int x,int y,int bc,int ic)
{
}
int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int n,s1,s2,bc,ic;
   initgraph(&gdriver, &gmode, "");
   /* our polygon array */
   cout<<"enter no of verices in polygon";cin>>n;
   int poly[50];
   for(int i=0;i<2*n+2;i+=2)
   {
   cout<<"Input cordinates";cin>>poly[i]>>poly[i+1];
   }
   cout<<"enter seed points";cin>>s1>>s2;
   cout<<"give boundary color";cin>>bc;
   setcolor(bc);

   drawpoly(2*n+2,poly);
   cout<<"give inside color";cin>>ic;
   boundaryfill(s1,s2,ic,bc);

   /* initialize graphics and local variables */




   /* draw the polygon */


   /* clean up */
   getch();
   closegraph();
   return 0;
}
