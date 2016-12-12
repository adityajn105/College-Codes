#include <iostream.h>
#include <stdlib.h>
#include <graphics.h>
#include <string.h>
#include <dos.h>
#include <conio.h>
#include <stdio.h>
class CPU {

public:
 void drawCPU();
 void setAXValue(int);
 void setBXValue(int);
 void clearAX();
};

void CPU::setAXValue(int x) {
  settextjustify(0, 0);
  char s[10];
  sprintf(s, "AX = %d",  x);
  outtextxy(260, 90, s);
  settextjustify(1, 1);
}

void CPU::setBXValue(int x) {
  char s[10];
  sprintf(s, "BX = %d", x);
  settextjustify(0, 0);
  outtextxy(260, 120, s);
  settextjustify(1, 1);
}

void CPU::clearAX() {
 settextjustify(0, 0);
 outtextxy(260, 90, "AX =  ");
 settextjustify(1, 1);
}

void CPU::drawCPU() {
 settextjustify(1, 1);
 /* Memory */
 rectangle(50, 50, 200, 350);
 outtextxy(125, 100, "Memory");

 /* ALU */
 rectangle(250, 50, 450, 200);
 outtextxy(350, 75, "ALU");

 /* Registers */
 rectangle(255, 75, 315, 195);
 line(255, 105, 315, 105);
 line(255, 135, 315, 135);
 line(255, 165, 315, 165);
 settextjustify(0, 0);
 outtextxy(260, 90, "AX");
 outtextxy(260, 120, "BX");
 outtextxy(260, 150, "CX");
 outtextxy(260, 180, "DX");
 settextjustify(1, 1);

 /* Adder */
 rectangle(330, 90, 430, 190);
 outtextxy(380, 130, "Adder");
 outtextxy(380, 150, "Shifter");

 /* PCU */
 rectangle(250, 250, 450, 350);
 outtextxy(350, 320, "PCU");

 /* CS and IP */
 rectangle(280, 260, 340, 290);
 outtextxy(310, 275, "CS");
 rectangle(350, 260, 410, 290);
 outtextxy(380, 275, "IP");

 /* Buses */
 line(200, 125, 250, 125);
 outtextxy(203, 126, "<");
 outtextxy(247, 126, ">");
 line(200, 300, 250, 300);
 outtextxy(203, 301, "<");
 outtextxy(247, 301, ">");
 line(350, 200, 350, 250);
 outtextxy(350, 205, "/\\");
 outtextxy(350, 245, "\\/");

 /* Buttons */

 rectangle(500, 50, 600, 100);
 outtextxy(550, 75, "1:MOV AX,BX");
 rectangle(500, 150, 600, 200);
 outtextxy(550, 175, "2:ADD AX,BX");

}


int main() {

 int gd = DETECT, gmode;
 initgraph(&gd, &gmode, NULL);
 CPU c;
 c.drawCPU();
 int x;
 cout << "Enter your choice (1 or 2): ";
 cin >> x;
 switch(x) {
  case 1:
	int a1;
	cout << "Enter BX: ";
	cin >> a1;
	c.setBXValue(a1);
	delay(500);
	cout << "After Mov instruction";
	c.setAXValue(a1);
	break;
  case 2:
	int a, b;
	cout << "Enter  AX: ";
	cin >> a;
	cout << "\nEnter BX: ";
	cin >> b;
	c.setBXValue(b);
	c.setAXValue(a);
	delay(1000);
	cleardevice();
	c.drawCPU();
	cout << "After add instruction : ";
	c.setBXValue(b);
	c.setAXValue(a + b);
	break;
 }

 getch();
 closegraph();

 return 0;
}
