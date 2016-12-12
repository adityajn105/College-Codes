
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
