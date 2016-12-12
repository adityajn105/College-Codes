#include <graphics.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

class ScanLine {
    
    // Global Edge Table
    int x1[10], y1[10], x2[10], y2[20];
    
    // Active Edge List
    int activeEdgeList[10];
    
    // X - Intersects
    int xIntersect[10];
    
    int ymin, ymax;
    
    // Number of points
    int n;
    
public:
    
    ScanLine() {
     
        for(int i = 0; i < 10; i++) {
            x1[i] = x2[i] = y1[i] = y2[i] = 0;
            activeEdgeList[i] = 0;
            xIntersect[i] = 0;
        }   
        
    }
    
    void getDataFromUser() {
         cout << "\nEnter number of points of polygon: ";
        cin >> n;
        cout << "\nEnter vertices: ";
        for(int i = 0; i < n; i++) {
            cout << "\n" << i;
            cout << "\n(X1, Y1): ";
            cin >> x1[i] >> y1[i];
            cout << "\n(X2, Y2): ";
            cin >> x2[i] >> y2[i];
            
            if(y1[i] < y2[i]) {
                std::swap(y1[i], y2[i]);
                std::swap(x1[i], x2[i]);
          }
        } 
        /* n = 4;
        x1[0] = y1[0] = y2[0] = 50;
        x2[0] = 150;
        x1[1] = 150; y1[1] = 50;
        x2[1] = 150; y2[1] = 150;
        x1[2] = 150; y1[2] = 150;
        x2[2] = 50; y2[2] = 150;
        x1[3] = 50; y1[3] = 150;
        x2[3] = 50; y2[3] = 50;
        
        for(int i = 0; i < n; i++) {
            if(y1[i] < y2[i]) {
                std::swap(y1[i], y2[i]);
                std::swap(x1[i], x2[i]);
            }
        } */
 
    }
    
    void fill() {
        
        // Draw Polygon
        
        for(int i = 0; i < n; i++) {
            line(x1[i], y1[i], x2[i], y2[i]);
        }
        
        for(int i = 0; i < n - 1; i++) {
            for(int j = 0; j < n - 1 - i; j++) {
                
                if(y1[j] < y1[j + 1]) {
                    std::swap(y1[j], y1[j + 1]);
                    std::swap(y2[j], y2[j + 1]);
                    std::swap(x1[j], x1[j + 1]);
                    std::swap(x2[j], x2[j + 1]);
                }
                
            }
        }
        
        ymax = y1[0];
        ymin = y2[0];
        
        cout << "y1  y2  x1  x2" << endl;
        for(int i = 0; i < n; i++) {
            cout << y1[i] << " " << y2[i] << " " << x1[i] << " "  << x2[i] << endl;
            
        }
        
            cout << "ymax " << ymax << endl;
            cout << "ymin " << ymin << endl;
        
    while(ymax >= ymin) {    
    
        for(int i = 0; i < 10; i++) {
            xIntersect[i] = 0;
            activeEdgeList[i] = 0;
        } 
        
        for(int i = 0; i < n; i++) {
            
            if(ymax > y2[i] && ymax <= y1[i]) {
                activeEdgeList[i] = 1;
            } else {
              activeEdgeList[i] = 0;
            }
        }
        //cout << "Active EdgeList: " << endl;
        //for(int i = 0; i < n; i++) {
        //    cout << activeEdgeList[i] << endl;
        // }
        

        for(int i = 0; i < n; i++) {
            
            if(activeEdgeList[i]) {
                xIntersect[i] = round(x1[i] - ((x2[i]-x1[i]) / (y2[i]-y1[i])));
            }
        
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(xIntersect[j] < xIntersect[j + 1]) {
                    std::swap(xIntersect[j], xIntersect[j + 1]);        
                } 
            }
        }    
        
        for(int i = 0; i < n; i++) {
        
            cout << "xIntersect: (" << i <<") :" << xIntersect[i] << endl;
        
        }
        delay(100);
        int j = 0;
        for(int i = 0; i < n; i++) {
            
            if(activeEdgeList[i]) {
                line(xIntersect[j], ymax, xIntersect[j + 1], ymax);
                j += 2;
            }
        }
        
        ymax--;
        
        }  
    }
        
};

int main () {
    
    int gd = DETECT, gm;
    
    ScanLine sl;
    sl.getDataFromUser();
    
    initgraph(&gd, &gm, NULL);
    
    sl.fill();
    
    getch();
    closegraph();
    return 0;
}
