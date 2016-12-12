#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int x, ymax;
   int i;
   int poly[10];
   int poly2[10];int poly3[10];
   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "");

   /* read result of initialization */
   errorcode = graphresult();
   /* an error occurred */
   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }
   setcolor(getmaxcolor());
   printf("%d %d",getmaxx(),getmaxy());
  // xmax =639;/* getmaxx();*/
  // ymax =479;/* getmaxy();*/
  for(i=0;i<3;i++){
  for(x=getmaxx();x>70-getmaxx();x--){

  poly[2]=x;poly[3]=180;
  poly[4]=x+30;poly[5]=70;
  poly[0]=x;poly[1]=300;
  poly[6]=x+430;poly[7]=70;
  poly[8]=x+430;poly[9]=300;
   /* draw a diagonal line */
 poly2[0]=x+25;poly2[1]=100;poly2[2]=x+75;poly2[3]=100;poly2[4]=x+75;poly2[5]=160;
 poly2[6]=x+25;poly2[7]=160;poly2[8]=x+25;poly2[9]=100;
  /* line(xmax/3,2*ymax/3,2*xmax/3,2*ymax/3);

   line(xmax/3,2*ymax/3,xmax/2,ymax/3);
   line(xmax/2,ymax/3,2*xmax/3,2*ymax/3);*/
  poly3[0]=x+90;poly3[1]=100;poly3[2]=x+150;poly3[3]=100;poly3[4]=x+150;
  poly3[5]=250;poly3[6]=x+90;poly3[7]=250;poly3[8]=x+90;poly3[9]=100;
line(x+90,300,x+280,300);
  line(x,300,x+20,300);
  line(x+410,300,x+430,300);
   arc(x+55,300,0,180,35);
  drawpoly(5,poly);
  drawpoly(5,poly3);
  drawpoly(5,poly2);
  circle(x+55,300,30);
  circle(375+x,300,30);
  circle(315+x,300,30);
  arc(315+x,300,30,180,35);
  arc(375+x,300,0,150,35);
 moveto(180+x,100);
 outtext("Volvo");clearviewport();  }}

   /* clean up */
   getch();
   closegraph();
   return 0;
}

