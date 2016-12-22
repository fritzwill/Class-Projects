// Will Fritz
// 12/2/2016
//
// A ball that bounces around the screen


#include "gfx.h"
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <ctime>


int main(){
    int x = 400, y = 400, r = 25, dx = 1, dy = 1, deltat = 4;
    int xi = 200, yi = 200; // initial location oc circle
    float xpos, ypos;
    double vx, vy; //velocties of x and y
    char c;

    srand(time(NULL)); // seed random num generator
    
    vx = rand()%10;
    vy = rand()%15;
    gfx_open(x, y, "Bouncing Ball");
    
    gfx_color(255,255,255);
    gfx_circle(xi, yi,r);
    
    // makes floats 
    xpos = xi;
    ypos = yi;

    while(true){
        usleep(5000);
        gfx_clear();
        xpos += dx*vx;
        ypos += dy*vy;
        
        // creates boarder restrictions
        if (xpos - r < 0 || xpos + r > 400)
            dx *= (-1);
        if(ypos - r < 0 || ypos + r > 400)
            dy *= (-1);
        if(xpos - r < 0)
            xpos = r;
        if(xpos + r > 400)
            xpos = 400 - r;
        if(ypos - r < 0)
            ypos = r;
        if(ypos + r > 400)
            ypos = 400 - r;
        
        // puts circle where click is
        if(c == 1){
            xpos = gfx_xpos();
            ypos = gfx_ypos();
            vx = rand()%15;
            vy = rand()%10;
            c = ' ';
        }
         
        gfx_circle(xpos, ypos, r); //creates circle after every loop
    
        if(gfx_event_waiting())
            c = gfx_wait();   
        
        if(c == 'q')
            break;
    }

}
