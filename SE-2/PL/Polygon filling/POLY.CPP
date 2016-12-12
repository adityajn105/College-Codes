
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
void floodfill(int x,int y,int oc,int ic)
{
	int color=getpixel(x,y);
	if(color==oc)
	{
	putpixel(x,y,ic);
	floodfill(x+1,y,oc,ic);
	floodfill(x-1,y,oc,ic);
	floodfill(x,y+1,oc,ic);
	floodfill(x,y-1,oc,ic);
	}
}
int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int n,s1,s2,bc,ic,oc;
   initgraph(&gdriver, &gmode, "");
   /* our polygon array */
   cout<<"Enter no of verices in polygon ";cin>>n;
   int poly[50];
   for(int i=0;i<2*n;i+=2)
   {
   cout<<"Input cordinates: ";cin>>poly[i]>>poly[i+1];
   }
   poly[2*n]=poly[0];
   poly[2*n+1]=poly[1];
   cout<<"Give boundary color ";cin>>bc;
   setcolor(bc);

   drawpoly(2*n+2,poly);
   cout<<"Enter seed points :";cin>>s1>>s2;
   oc=getpixel(s1,s2);

   cout<<"Give inside color: ";cin>>ic;
   int ch;
   cout<<"1.Boundary Fill"<<endl<<"2.Flood Fill"<<endl;
   cin>>ch;
   if(ch==1){
	boundaryfill(s1,s2,ic,bc);
   }
   else{
	floodfill(s1,s2,oc,ic);
   }
   /* initialize graphics and local variables */




   /* draw the polygon */


   /* clean up */
   getch();
   closegraph();
   return 0;
}
