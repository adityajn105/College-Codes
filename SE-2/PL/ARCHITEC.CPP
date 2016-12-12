#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int mem[10],alu[10],pcu[10];

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
   //mem
   rectangle(120,70,200,270);
   outtextxy(140,160,"MEMORY");
   rectangle(200,100,270,130);
   rectangle(200,200,270,230);
   line(200,130,205,125); //arrow1
   line(200,130,205,135); //arrow1
   line(200,230,205,225);//arrow2
   line(200,230,205,235);//arrow2
   line(270,100,265,95);//arrow3
   line(270,100,265,105);//arrow3
   line(270,200,265,195);//arrow4
   line(270,200,265,205);//arrow4
   //alu
   rectangle(270,50,370,150);
   outtextxy(310,60,"ALU");
   rectangle(280,80,310,140);
   rectangle(280,90,310,130);
   rectangle(280,100,310,120);
   line(280,110,310,110);
   rectangle(325,110,360,140);
   outtextxy(335,120,"AC");
   //pcu
  rectangle(310,150,330,180); //joinaluandpcu
  line(310,150,305,155);//arrow5
  line(310,150,315,155);//arrow5
  line(330,180,325,175);//arrow6
  line(330,180,335,175);//arrow6
  rectangle(270,180,370,280); //pcu
   outtextxy(310,265,"PCU");
  rectangle(280,190,315,220); //ir
  outtextxy(290,200,"IR");
  rectangle(325,190,360,220);//PC
  outtextxy(335,200,"PC");

 // line()
  /* clean up */
   getch();
   closegraph();
   return 0;
}
