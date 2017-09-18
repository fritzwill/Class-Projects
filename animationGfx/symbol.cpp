// Will Fritz
// 12/2/2016
//
// creates symbols given differnt key strokes


#include "gfx.h"
#include <cmath>

void polygon(float, float, float, float);

int main(){
    float x = 400.0, y = 400.0, r = 25.0; 
    float xpos, ypos, af; // r is radius of shape. af is used for input
    char c;

    gfx_open(x, y, "Symbols");
    
    while(true){
        c = gfx_wait();
        xpos = gfx_xpos();
        ypos = gfx_ypos();

        // displays blue square with left click
        if (c == 1){
            gfx_color(0, 0, 255);
            gfx_line(xpos + r, ypos + r, xpos - r, ypos + r);
            gfx_line(xpos - r, ypos + r, xpos - r, ypos - r);
            gfx_line(xpos - r, ypos - r, xpos + r, ypos - r);
            gfx_line(xpos + r, ypos - r, xpos + r, ypos + r);
        }
        
        // displays green traingle with press of t
        else if (c == 't'){
            gfx_color(0, 255, 0);
            gfx_line(xpos, ypos + r, xpos - r, ypos - r);
            gfx_line(xpos - r, ypos - r, xpos + r, ypos - r);
            gfx_line(xpos + r, ypos - r, xpos, ypos + r);
        }
        
        // displays a white circle with press of c
        else if (c == 'c'){
            gfx_color(255, 255, 255);
            gfx_circle(xpos, ypos, r);
        }
        
        else if (c == 'q')
            break;

        // displays purple polygon
        else{ 
            af = (c - '0');
            if (af <= 9.0 && af >= 3){
                gfx_color(255, 0, 255);
                polygon(af, xpos, ypos, r);
            }
        }
                 
    }

    return 0;
}

// function of polygon of a sides
void polygon(float a, float x, float y, float r){
    float x2, y2, theta = 0;
    float x1 = x + r;
    float y1 = y;
    for(float i; i <= a; i++){ 
        x2 = x + r*cos(theta);
        y2 = y + r*sin(theta);
        gfx_line(x1, y1, x2, y2);
        x1 = x2;
        y1 = y2;
        theta += (2*3.14159) / a;
    }
}









