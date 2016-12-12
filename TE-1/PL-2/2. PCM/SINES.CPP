#include <graphics.h>
#include <bitset>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include<math.h>
#include <vector>
#define pi 3.14
using namespace std;

int main(void)
{


   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;

   int x,y,y1;
   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "");
   int amp;double F;
   int xmax=getmaxx(), ymax=getmaxy();
   int xh=xmax/2,yh=ymax/2;

   cout<<"Enter Amplitude  :";cin>>amp;
   cout<<"Enter Fundamental frequency  :";cin>>F;
   
   line(xh,0,xh,ymax);		//draw vertical screen partition
   line(0,ymax/4,xmax,ymax/4);	//draw horizontal partition for input wave
   
   int i,j;
   for(i=xh;i<xmax;i++){	//draw input wave	
       y=ymax/4+amp*sin(2*pi*F*(i-xh));
       putpixel(i,y,5);
   }
   outtextxy(xmax/4,ymax/4-20,"Input Wave");	

   int ch;
   double Fs=0;
   
   cout<<"Enter Sampling frequency   :";
   cin>>Fs;			//accepting sampling freq
   double fn=F/Fs;		
   cout<<"Enter the number of levels :";
   int level;cin>>level;	//no of levels
 
   double D=2*(double)amp/(double)level;	//D=delta (size of each level)	
   int l;
   
   outtextxy(xmax/4,3*ymax/4-20,"Output Wave");
   line(0,3*ymax/4,xmax,3*ymax/4);//draw horizontal partition for sampled wave
   
   
   vector<double> pam; 	//PAM values		
   vector<int> lev;	//lev contain level in which sample point lies
   vector<double> mid;	//mid contain nearest mid value of all sampled points
   vector<double> error;	///error contain difference b/w mid-value & y coordinate
   
   int currl;double currm;
   double ycord;
   for(i=xh;i<xmax;i+=16){
   	ycord=amp*sin(2*3.14*fn*(i-xh));
	y=3*ymax/4+ycord;
	pam.push_back(-1*ycord);
	
	currl=-1*round(ycord/D);
	
	mid.push_back(currm=(currl*D)+D/2);
	
	lev.push_back(round((currm/D)+0.1));
	
	error.push_back((-1*ycord)-currm);
	
	line(i,y,i,3*ymax/4);	
   }
    
   //Normalized PAM Values
   cout<<"Normalized PAM Values \n";
   vector<double>::iterator p=pam.begin();   
   while(p!=pam.end()){
   	cout<<*p<<"  ";
   	p++;
   }
   
   cout<<endl;
   //Normalized Quantized Values
   cout<<"Normalized Qunatized Values \n";
   vector<double>::iterator m=mid.begin();
   while(m!=mid.end()){
   	cout<<*m<<"  ";
   	m++;
   }
   
   cout<<endl;
   cout<<"Quantization Code:  ";
   vector<int>::iterator c=lev.begin();
   while(c!=lev.end()){
   	switch(*c){	
		case -3: cout<<"0"<<"  ";break;
		case -2: cout<<"1"<<"  ";break;
		case -1: cout<<"2"<<"  ";break;
		case 0: cout<<"3"<<"  ";break;
		case 1: cout<<"4"<<"  ";break;
		case 2: cout<<"5"<<"  ";break; 		
	   	case 3: cout<<"6"<<"  ";break;
	   	case 4: cout<<"7"<<"  "; break;
	   	case 5: cout<<"7"<<"  ";break;
	   	default: cout<<*c<<"--";break;
   	}
   	c++;
   }
   
   
   cout<<endl;
   cout<<"Encoded Words:  ";
    vector<int>::iterator v=lev.begin();
   while(v!=lev.end()){
   	switch(*v){	
		case -3: cout<<"000";break;
		case -2: cout<<"001";break;
		case -1: cout<<"010";break;
		case 0: cout<<"011";break;
		case 1: cout<<"100";break;
		case 2: cout<<"101";break;
		case 3: cout<<"110";break; 		
	   	case 4: cout<<"111";break;
	   	case 5: cout<<"111";break;
   	}
   	v++;
   }

   getch();
   closegraph();
   return 0;
}


