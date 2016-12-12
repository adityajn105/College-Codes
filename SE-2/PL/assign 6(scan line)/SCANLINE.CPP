
#include <graphics.h>
#include <stdlib.h>
#include <iostream.h>
#include <conio.h>
class scanline
{
	int poly[40],n;
	public:
	scanline();
	void fillpolys();
};

scanline::scanline()
{
   cout<<"Enter no of vertices";cin>>n;
   for (int i=1;i<2*n;i+=2)
   {
	cout<<"Enter coordinate of "<<i/2+1<<"th vertex ";cin>>poly[i-1]>>poly[i];
   }
   poly[2*n]=poly[0];poly[2*n+1]=poly[1];
   clearviewport();
   drawpoly(n+1,poly);

}

void scanline::fillpolys()
{
      int edge[21][4];
      cout<<"y1\ty2\tx1\tx2"<<endl;
      for(int i=0;i<2*n;i+=2)
      { int k=i/2;
	edge[k][0]=poly[i+1];edge[k][2]=poly[i];
	edge[k][1]=poly[i+3];edge[k][3]=poly[i+2];
	cout<<edge[k][0]<<"\t"<<edge[k][1]<<"\t"<<edge[k][2]<<"\t"<<edge[k][3]<<endl;
      }

      int temp;
      for(i=0;i<n;i++)  	//sorting columns
      {
	if(edge[i][0]<edge[i][1])
	{
	 temp=edge[i][1];
	 edge[i][1]=edge[i][0];
	 edge[i][0]=temp;
	}

	if(edge[i][2]<edge[i][3])
	{
	temp=edge[i][2];
	edge[i][2]=edge[i][3];
	edge[i][3]=temp;
	}
      }
      cout<<endl<<"y1\ty2\tx1\tx2"<<endl;
      for(i=0;i<n;i++)
      {
	cout<<edge[i][0]<<"\t"<<edge[i][1]<<"\t"<<edge[i][2]<<"\t"<<edge[i][3]<<endl;
      }


      for(i=0;i<n;i++)              //sorting rows
      {
	for(int j=i;j<n-1;j++)
	{
	 if(edge[j][0]<edge[j+1][0])
	   {
	      temp=edge[j+1][0];
	      edge[j+1][0]=edge[j][0];
	      edge[j][0]=temp;

	      temp=edge[j+1][1];
	      edge[j+1][1]=edge[j][1];
	      edge[j][1]=temp;

	      temp=edge[j+1][2];
	      edge[j+1][2]=edge[j][2];
	      edge[j][2]=temp;

	      temp=edge[j+1][3];
	      edge[j+1][3]=edge[j][3];
	      edge[j][3]=temp;
	   }
	}
      }
      cout<<endl<<"y1\ty2\tx1\tx2"<<endl;
      for(i=0;i<n;i++)
      {
	cout<<edge[i][0]<<"\t"<<edge[i][1]<<"\t"<<edge[i][2]<<"\t"<<edge[i][3]<<endl;
      }
      //edge matrix is now sorted
      int y=edge[0][0];






}

int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "");
   scanline l;
   /* clean up */
   l.fillpolys();
   getch();
   closegraph();
   return 0;
}

