#include <graphics.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

class Polygon {
    
    // Global Edge Table
    float x1[10], y1[10], x2[10], y2[20];
    
    // For successive calculations
    float xOld[10];

    // Inverse slope of each edge
    float m[10];

    // Active Edge List
    int activeEdgeList[10];
    
    // X - Intersects
    float xIntersect[10];
    
    int ymin, ymax;
    
    // Number of points
    int n;

    // Color to fill with
    int color;
    
public:
    
    Polygon() {
     
        for(int i = 0; i < 10; i++) {
            x1[i] = x2[i] = y1[i] = y2[i] = 0.0f;
            activeEdgeList[i] = 0;
            xIntersect[i] = 0.0f;
            m[i] = 0.0f;
            xOld[i] = 0.0f;
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
            
            // If y2 is greater than y1, exchange
            if(y1[i] < y2[i]) {
                std::swap(y1[i], y2[i]);
                std::swap(x1[i], x2[i]);
          }
        } 
	
	// Get color from user
	cout << "\nEnter color to fill polygon: ";
	cin >> color;

	// Calculate Inverse Slope
        for(int i = 0; i < n; i++) {

        	if(y2[i] - y1[i] != 0) {
        		float t1 = y2[i] - y1[i];
        		float t2 = x2[i] - x1[i];

        		m[i] = t2 / t1;
        	} 
        	
        }
 	
    }
    
    void draw() {

    	// Draw Polygon
        setcolor(color);
        for(int i = 0; i < n; i++) {
            line(x1[i], y1[i], x2[i], y2[i]);
        }
    }

    void fill() {
        

        // Sort global edge table in descending order of y1
        for(int i = 0; i < n - 1; i++) {
            for(int j = 0; j < n - 1 - i; j++) {
                
                if(y1[j] < y1[j + 1]) {
                    std::swap(y1[j], y1[j + 1]);
                    std::swap(y2[j], y2[j + 1]);
                    std::swap(x1[j], x1[j + 1]);
                    std::swap(x2[j], x2[j + 1]);
                    std::swap(m[j], m[j + 1]);
                }
                
            }
        }
        
        ymax = y1[0];
        ymin = y2[0];

        // Find ymin
        for(int i = 0; i < n; ++i) {
        	
        	if(y2[i] < ymin) {
        		ymin = y2[i];
        	}

        }

        if(y1[n - 1] < ymin) {
        	ymin = y1[n - 1];
        }
        
        cout << "y1  y2  x1  x2" << endl;
        for(int i = 0; i < n; i++) {
            cout << y1[i] << " " << y2[i] << " " << x1[i] << " "  << x2[i] << endl;
            
        }
        
            cout << "ymax " << ymax << endl;
            cout << "ymin " << ymin << endl;
    
        // Initialize xOld to x1
    	for (int i = 0; i < n; ++i) {
    		xOld[i] = x1[i];
		}

    	while(ymax >= ymin) {    
    		
    		// Reset xIntersect and activeEgdeList arrays
        	for(int i = 0; i < 10; i++) {
            	xIntersect[i] = 0;
            	activeEdgeList[i] = 0;
        	} 
        
    	// Create active edge list and count number of active edges
        int count = 0;
        for(int i = 0; i < n; i++) {
            
            if(ymax > y2[i] && ymax <= y1[i]) {
                activeEdgeList[count++] = i; 
            }
        }
        
        // Calculate x intersects        
        int k = 0;
        for(k = 0; k < count; k++) {
        
               int l = activeEdgeList[k];
               float xNew = xOld[l] - m[l];
               xOld[l] = xNew;
               xIntersect[k] = xNew; 
        }
        
        // Sort x intersect array in ascending order
        for(int i = 0; i < count; i++) {
            for(int j = 0; j < count - 1; j++) {
                if(xIntersect[j] > xIntersect[j + 1]) {
                    std::swap(xIntersect[j], xIntersect[j + 1]);
                    std::swap(activeEdgeList[j], activeEdgeList[j + 1]);        
                } 
            }
        }    
        
		cout << "\nActive Edge \t X Intersect\n";
		for(int i = 0; i < n; i++) {
		cout << activeEdgeList[i] << "\t" << xIntersect[i] << endl;
		}
        
        int j = 0;
		
		// Set color and draw the scan lines between x intersects
		setcolor(color);
        for(int i = 0; i < count / 2; i += 1) {

                line(floor(xIntersect[j]), ymax, ceil(xIntersect[j + 1]), ymax);
                j += 2;    
        }
        
        ymax--;
        
        }  
    }
        
};

int main () {
    
    int gd = DETECT, gm;
    
    Polygon p;
    p.getDataFromUser();
    
    initgraph(&gd, &gm, NULL);
    
    p.draw();
    p.fill();
    
    getch();
    closegraph();
    return 0;
}
