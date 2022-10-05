#include <cstdlib>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

using   namespace   std;

// ----------------------------------------------------------------------
//  CS 218 -> Assignment #10
//  Circles Program.
//  Provided main...

//  Uses openGL (which must be installed).
//  openGL installation:
//  sudo apt-get update
//  sudo apt-get upgrade
//  sudo apt-get install libgl1-mesa-dev
//  sudo apt-get install freeglut3 freeglut3-dev
//  sudo apt-get install binutils-gold

//  Compilation:
//  g++ -g -c circles.cpp -lglut -lGLU -lGL -lm


// ----------------------------------------------------------------------
//  External functions (in seperate file).

extern "C" void drawCircles();
extern "C" int getParams(int, char* [], int *, int *, int *);


// ----------------------------------------------------------------------
//  Global variables
//  Must be accessible for openGL display routine, drawCircles().

int drawSpeed;          // draw speed
int drawColor;          // draw color
int backColor;          // background color


// ----------------------------------------------------------------------
//  Key handler function.
//  Terminates for 'x', 'q', or ESC key.
//  Ignores all other characters.

void    keyHandler(unsigned char key, int x, int y)
{
    if (key == 'x' || key == 'q' || key == 27) {
        glutLeaveMainLoop();
        exit(0);
    }
}

// ----------------------------------------------------------------------
//  Main routine.

int main(int argc, char* argv[])
{
    int height = 500;
    int width = 500;
    bool    stat;
    float   redBK, greenBK, blueBK;

    double  left = -1.25;
    double  right = 1.25;
    double  bottom = -1.25;
    double  top = 1.25;

    stat = getParams(argc, argv, &drawSpeed, &drawColor, &backColor);

    // Debug call for display function
    //drawCircles();

    blueBK = backColor & 0xff;
    backColor = backColor >> 8;
    greenBK = backColor & 0xff;
    backColor = backColor >> 8;
    redBK = backColor & 0xff;

    if (stat) {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
        glutInitWindowSize(width, height);
        glutInitWindowPosition(50, 50);
        glutCreateWindow("CS 218 Assignment #10 - Circles Program");

        glClearColor(redBK, greenBK, blueBK, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(left, right, bottom, top, 0.0, 1.0);
    
        glutKeyboardFunc(keyHandler);
        glutDisplayFunc(drawCircles);

        glutMainLoop();
    }

    return 0;
}


