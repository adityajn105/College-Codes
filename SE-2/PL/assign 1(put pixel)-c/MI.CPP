#include <graphics.h>
#include <stdlib.h>
#include <iostream.h>
#include <conio.h>
#include <dos.h>
class pixel
{ int x1,y1,col1;

  public:
  void printmit();
  void setpixel();
  void accept();
};
void pixel::setpixel()
{
  putpixel(x1,y1,col1);
}
void pixel::accept()
{
  cout<<"input coordinates";cin>>x1>>y1;
  cout<<"input color";cin>>col1;
}
void pixel::printmit()
{
int i,j;
for(j=200;j>100;j--)
   {putpixel(50,j,rand()%15);
   delay(10);
   }
   for(i=50,j=100;i<100,j<150;i++,j++)
   {putpixel(i,j,rand()%15);delay(10);}
   for(i=100,j=150;i<150,j>100;i++,j--)
   {delay(10);putpixel(i,j,rand()%15);}
   for(j=100;j<200;j++)
   {putpixel(150,j,rand()%15);delay(10);}

   for(i=200;i<300;i++)
   {putpixel(i,100,rand()%15);delay(10);}
   for(j=100;j<200;j++)
   {putpixel(250,j,rand()%15);delay(10);}
   for(i=200;i<300;i++)
   {putpixel(i,200,rand()%15);delay(10);}

   for(i=350;i<450;i++)
   {putpixel(i,100,rand()%15);delay(10);}
   for(j=100;j<200;j++)
   {putpixel(400,j,rand()%15);delay(10);}
}

int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int x, y,color;
   int i,j; pixel p;
   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "");

   p.accept();
   p.setpixel();
   p.printmit();
   getch();
   closegraph();
   return 0;
}
