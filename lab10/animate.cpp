// Will Fritz
// 12/2/2016
//
// Creates a target traveling in a cricular motion, The user will then try 
// to shoot within the target


#include "gfx.h"
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <ctime>
#include <cstdio>

using namespace std;

void target(float);

int main(){
    int x = 600, y = 600; // size of graphics window
    float hard = 50.0, medium = 70.0, easy = 80.0;
    char c;
    
    gfx_open(x, y, "Target Practice");
    gfx_color(255,255,255);
    gfx_text(1, 10, "Type e for easy, m for medium, h for hard");
    
    // selection of difficulty
    while(true){
        c = gfx_wait();
        if (c == 'e')
            target(easy);
        else if (c == 'm')
            target(medium);
        else if (c == 'h')
            target(hard);
    }
    
}

void target(float a){
    float outerR = a, R2 = a/2, R3 = a/4; // diff rings of target
    float xposi = 250.0, yposi = 250.0; //arbitrary starting pos for target
    float theta = 0.0; // will be used to edit pos of target
    float dtheta = 0.01; // change of angle
    float xpos, ypos;  // pos of center of circle
    char buff[20]; // will be used to store score of user
    char c, scoreChar, scoreText[15];
    float mouseX, mouseY; // so comparison can be made
    int score = 0;
 
    while(c != 'q'){
        usleep(5000);
        gfx_clear();
        
        // change pos of target
        theta += dtheta;
        xpos = xposi + 200.0*cos(theta);
        ypos = yposi + 200.0*sin(theta);
        
        // make circles
        gfx_color(255,255,255);
        gfx_circle(xpos, ypos, outerR);
        gfx_circle(xpos, ypos, R2);
        gfx_circle(xpos, ypos, R3);
        
        if (c == 1){
            mouseX = gfx_xpos();
            mouseY = gfx_ypos();
                if((mouseX < (xpos+outerR) && mouseX > (xpos+R2)&& 
                    mouseY < (ypos+outerR)&& mouseY > (ypos+R2))||
                   (mouseX > (xpos-outerR) && mouseX < (xpos-R2)&&
                    mouseY > (ypos-outerR)&& mouseY < (ypos-R2)))
                    score += 1;
                if((mouseX < (xpos+R2) && mouseX > (xpos+R3)&&
                    mouseY < (ypos+R2)&& mouseY > (ypos+R3))||
                   (mouseX > (xpos-R2) && mouseX < (xpos-R3)&&
                    mouseY > (ypos-R2)&& mouseY < (ypos-R3)))
                    score += 2;
                if(mouseX < (xpos+R3) && mouseX > (xpos-R3) &&
                   mouseY < (ypos+R3) && mouseY > (ypos-R3))
                    score += 3;
        }
        c = 'w';
        
        sprintf(scoreText, "%d", score);
        gfx_text(1, 10, "Score");
        gfx_text(1, 30, scoreText);
        gfx_text(1, 50, "Press q to quit"); 
        
        if(gfx_event_waiting())
            c = gfx_wait();
        
        gfx_flush();
    }
}

        
    
    
