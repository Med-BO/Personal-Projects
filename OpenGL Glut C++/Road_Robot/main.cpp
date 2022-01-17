#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include <GL/freeglut.h>

void display();
void reshape(int, int);
void tSpecial(int key, int x, int y);
void tClavier(unsigned char key, int x, int y);
void sMouse(int button, int state, int x, int y);

double door_width = 2.9;
double xhoriz = 0;
double yverti = -2.7;
double red = 0;
double green = 0;
double blue = 1;

double lr = 1, lg = 0, lr2 = 1, lg2 = 0;

double ll = 0, rl = 0, indicator = 0;

double v1 = 0, v2 = 1, v3=0;

double text_z = -6;

double ct1 = 1;
double ct2 = 1;

double vv1 = 0, vv2 = 0, vv3 = 0, vv4 = 20, vv5 = 1, vv6 = 0;

//ekleb el 3 : vv2 =7


int main(int argc, char **argv)
{
    //Initializing the glut library
    glutInit(&argc,argv);
    //Initializing the display mode
    glutInitDisplayMode(GLUT_RGB);
    //Initial position of the window on the screen in pixels
    glutInitWindowPosition(200,100);
    //Width and height of the window in pixels
    glutInitWindowSize(500,500);
    //create the windows
    glutCreateWindow("Window title");
    //display callback
    glutDisplayFunc(display);
    //callback to set the viewport and projection for when the windows is resized
    //arrow keys function
    glutSpecialFunc(tSpecial);
    //kzyboard function
    glutKeyboardFunc(tClavier) ;
    //mouse function
    glutMouseFunc ( sMouse);

    glutReshapeFunc(reshape);
    //create a loop so that the program keeps running until the loop breaks
    glutMainLoop();
}

void display()
{
    //clearing the canvas from any left drawings to a black background
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //changing background color. The arguments are RGB values between 0 and 1, the fourth argument is 0
    //glClearColor(1,0,0,0);
    //Reset the matrix
    glLoadIdentity();
    //declaring a quadratic object (for the cylinder)
    GLUquadricObj *quadratic;
    quadratic = gluNewQuadric();
    gluLookAt(vv1,vv2,vv3,0,0,vv4,0,vv5,vv6);
    //menu
    glColor3d(1,1,0);
    glPushMatrix();
        glTranslated(0,2,20);
        glScaled(16,10,1);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslated(7.5,3.5,20);
    glRasterPos2f(0, 0);
    glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (unsigned char*)"              START THE GAME\n                         > P <\n\n                          Quit\n                         >F1<");
    glPopMatrix();
    //drawing
    //Road + ground
    //road
    glPushMatrix();
    glColor3d(0.3,0.3,0.3);
        glTranslated(0,0,-5.4);
        glScaled(2.7,6.5,0.3);
        glutSolidCube(1);
    glPopMatrix();
    //grass ground
    glColor3d(0,1,0);
    glPushMatrix();
        glTranslated(2.2,0,-5.4);
        glScaled(1.65,6.5,0.3);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslated(-2.2,0,-5.4);
        glScaled(1.65,6.5,0.3);
        glutSolidCube(1);
    glPopMatrix();
    //road stripes
    glColor3d(1,1,1);
    glLineWidth(5);
    glBegin(GL_LINES);
        glVertex3d(0,-3,-5.4);
        glVertex3d(0,-2.6,-5.4);
        glVertex3d(0,-2.4,-5.4);
        glVertex3d(0,-2,-5.4);
        glVertex3d(0,-1.8,-5.4);
        glVertex3d(0,-1.4,-5.4);
        glVertex3d(0,-1.2,-5.4);
        glVertex3d(0,-0.8,-5.4);
        glVertex3d(0,-0.6,-5.4);
        glVertex3d(0,-0.2,-5.4);
        glVertex3d(0,0,-5.4);
        glVertex3d(0,0.4,-5.4);
        glVertex3d(0,0.6,-5.4);
        glVertex3d(0,1,-5.4);
        glVertex3d(0,1.2,-5.4);
        glVertex3d(0,1.6,-5.4);
        glVertex3d(0,1.8,-5.4);
        glVertex3d(0,2.2,-5.4);
        glVertex3d(0,2.4,-5.4);
        glVertex3d(0,2.8,-5.4);
    glEnd();
    //end of 3D cube road
    //road siege
    glColor3ub(138, 138, 92);
    glPushMatrix();
        glTranslated(1.3,0,-5.7);
        glScaled(0.1,5.5,0.1);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslated(-1.3,0,-5.7);
        glScaled(0.1,5.5,0.1);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslated(1.3,0,-5.7);
        glScaled(1,1,1);
        glRotated(0,1,0,0);
        gluCylinder(quadratic, 0.08f, 0.08f, 0.5, 32, 32);
    glPopMatrix();
    glPushMatrix();
        glTranslated(-1.3,0,-5.7);
        glScaled(1,1,1);
        glRotated(0,1,0,0);
        gluCylinder(quadratic, 0.08f, 0.08f, 0.5, 32, 32);
    glPopMatrix();
    glPushMatrix();
        glTranslated(1.3,1.5,-5.7);
        glScaled(1,1,1);
        glRotated(0,1,0,0);
        gluCylinder(quadratic, 0.08f, 0.08f, 0.5, 32, 32);
    glPopMatrix();
    glPushMatrix();
        glTranslated(-1.3,1.5,-5.7);
        glScaled(1,1,1);
        glRotated(0,1,0,0);
        gluCylinder(quadratic, 0.08f, 0.08f, 0.5, 32, 32);
    glPopMatrix();
    glPushMatrix();
        glTranslated(1.3,-1.5,-5.7);
        glScaled(1,1,1);
        glRotated(0,1,0,0);
        gluCylinder(quadratic, 0.08f, 0.08f, 0.5, 32, 32);
    glPopMatrix();
    glPushMatrix();
        glTranslated(-1.3,-1.5,-5.7);
        glScaled(1,1,1);
        glRotated(0,1,0,0);
        gluCylinder(quadratic, 0.08f, 0.08f, 0.5, 32, 32);
    glPopMatrix();
    //tree 1
    glColor3ub(135,62,35);
    glPushMatrix();
        glTranslated(2.5,-2.5,-6);
        glScaled(1,1,1);
        glRotated(0,1,0,0);
        gluCylinder(quadratic, 0.1f, 0.1f, 0.5, 32, 32);
    glPopMatrix();
    glColor3ub(88,135,35);
    glPushMatrix();
        glTranslated(2.5,-2.5,-6);
        glScaled(0.4,0.3,0.4);
        glRotated(180,1,0,0);
        glutWireCone(1,2,16,16);
    glPopMatrix();
    //tree 2
    glColor3ub(135,62,35);
    glPushMatrix();
        glTranslated(-2.5,0,-6);
        glScaled(1,1,1);
        glRotated(0,1,0,0);
        gluCylinder(quadratic, 0.1f, 0.1f, 0.5, 32, 32);
    glPopMatrix();
    glColor3ub(88,135,35);
    glPushMatrix();
        glTranslated(-2.5,0,-6);
        glScaled(0.4,0.3,0.4);
        glRotated(180,1,0,0);
        glutWireCone(1,2,16,16);
    glPopMatrix();
    //tree 3 sphere
    glColor3ub(135,62,35);
    glPushMatrix();
        glTranslated(2.5,2.5,-6);
        glScaled(1,1,1);
        glRotated(0,1,0,0);
        gluCylinder(quadratic, 0.1f, 0.1f, 0.5, 32, 32);
    glPopMatrix();
    glColor3ub(88,135,35);
    glPushMatrix();
        glTranslated(2.5,2.5,-6);
        glScaled(0.35,0.35,0.35);
        glRotated(0,1,0,0);
        glutSolidSphere(1,32,32);
    glPopMatrix();
    //tree dodecahedron
    glColor3ub(135,62,35);
     glPushMatrix();
        glTranslated(2.45,0,-6);
        glScaled(1,1,1);
        glRotated(0,1,0,0);
        gluCylinder(quadratic, 0.1f, 0.1f, 0.5, 32, 32);
    glPopMatrix();
    glColor3ub(88,135,35);
    glPushMatrix();
        glTranslated(2.3,-0.2,-6);
        glScaled(0.2,0.2,0.2);
        glRotated(90,1,0,0);
        glutSolidDodecahedron();
    glPopMatrix();
    glPushMatrix();
        glTranslated(2.3,-0.2,-6);
        glScaled(0.2,0.2,0.2);
        glRotated(90,1,0,0);
        glutSolidDodecahedron();
    glPopMatrix();
    glPushMatrix();
        glTranslated(2.45,0.1,-6);
        glScaled(0.2,0.2,0.2);
        glRotated(90,1,0,0);
        glutSolidDodecahedron();
    glPopMatrix();
    //sign
    glColor3ub(135,62,35);
     glPushMatrix();
        glTranslated(-2,-2,-6);
        glScaled(1,1,1);
        glRotated(0,1,0,0);
        gluCylinder(quadratic, 0.07f, 0.07f, 0.8, 32, 32);
    glPopMatrix();
    glPushMatrix();
        glTranslated(-2,-2.1,-6);
        glScaled(1,1,1);
        glRotated(0,1,0,0);
        glRotated(90,0,1,0);
        gluCylinder(quadratic, 0.02f, 0.02f, 0.4, 32, 32);
    glPopMatrix();
    glColor3d(1,1,1);
    glPushMatrix();
        glTranslated(-1.8,-2.13,-5.87);
        glScaled(0.3,0.02,0.3);
        glRotated(90,1,0,0);
        glutSolidCube(1);
    glPopMatrix();
    //finish line
    glColor3ub(102, 102, 153);
    glPushMatrix();
        glTranslated(-1.3,3.3,-5.8);
        glScaled(0.2,0.2,0.7);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslated(1.3,3.3,-5.8);
        glScaled(0.2,0.2,0.7);
        glutSolidCube(1);
    glPopMatrix();
    glColor3ub(51, 51, 77);
    glPushMatrix();
        glTranslated(-1.2,3.3,-6);
        glScaled(0.2,0.1,0.1);
        glRotated(90,0,1,0);
        glutSolidCone(1,2,32,32);
    glPopMatrix();
    glPushMatrix();
        glTranslated(1.2,3.3,-6);
        glScaled(0.2,0.1,0.1);
        glRotated(-90,0,1,0);
        glutSolidCone(1,2,32,32);
    glPopMatrix();
    glColor3d(lr,lg,0);
    glPushMatrix();
        glTranslated(-0.8,3.3,-6);
        glScaled(1,1,1);
        glRotated(90,0,1,0);
        gluCylinder(quadratic, 0.02f, 0.02f, 1.6, 32, 32);
    glPopMatrix();
    //start line
    glColor3ub(102, 102, 153);
    glPushMatrix();
        glTranslated(-1.3,-3.3,-5.8);
        glScaled(0.2,0.2,0.7);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslated(1.3,-3.3,-5.8);
        glScaled(0.2,0.2,0.7);
        glutSolidCube(1);
    glPopMatrix();
    glColor3ub(51, 51, 77);
    glPushMatrix();
        glTranslated(-1.2,-3.3,-6);
        glScaled(0.2,0.1,0.1);
        glRotated(90,0,1,0);
        glutSolidCone(1,2,32,32);
    glPopMatrix();
    glPushMatrix();
        glTranslated(1.2,-3.3,-6);
        glScaled(0.2,0.1,0.1);
        glRotated(-90,0,1,0);
        glutSolidCone(1,2,32,32);
    glPopMatrix();
    glColor3d(lr2,lg2,0);
    glPushMatrix();
        glTranslated(-0.8,-3.3,-6);
        glScaled(1,1,1);
        glRotated(90,0,1,0);
        gluCylinder(quadratic, 0.02f, 0.02f, 1.6, 32, 32);
    glPopMatrix();
    //obstacle 1 - spikes
    glColor3d(1,0,0);
    glPushMatrix();
        glTranslated(-0.9,-1.8,-5.2);
        glScaled(0.1,0.1,0.25);
        glRotated(180,1,0,0);
        glutSolidCone(1,2,32,32);
    glPopMatrix();
    glPushMatrix();
        glTranslated(-0.7,-1.8,-5.2);
        glScaled(0.1,0.1,0.25);
        glRotated(180,1,0,0);
        glutSolidCone(1,2,32,32);
    glPopMatrix();
    glPushMatrix();
        glTranslated(-0.5,-1.8,-5.2);
        glScaled(0.1,0.1,0.25);
        glRotated(180,1,0,0);
        glutSolidCone(1,2,32,32);
    glPopMatrix();
    //obstacle 2
    glColor3d(1,0,0);
    glPushMatrix();
        glTranslated(1.1,0,-5.5);
        glScaled(0.1,0.1,0.5);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslated(0.1,0,-5.5);
        glScaled(0.1,0.1,0.5);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslated(0.6,0,-5.7);
        glScaled(0.9,0.1,0.1);
        glutSolidCube(1);
    glPopMatrix();
    //obstacle 3
    glColor3d(1,0,0);
    glPushMatrix();
        glTranslated(-0.6,2,-5.5);
        glScaled(0.4,0.4,0.4);
        glutSolidSphere(1,32,32);
    glPopMatrix();
    glPushMatrix();
        glTranslated(-0.45,2,-5.8);
        glScaled(0.2,0.2,0.2);
        glutSolidSphere(1,32,32);
    glPopMatrix();
    glColor3d(0.5,0,0);
    glPushMatrix();
        glTranslated(-0.45,2,-6.1);
        glScaled(1,1,1);
        glRotated(45,-1,0,1);
        gluCylinder(quadratic, 0.02f, 0.02f, 0.2, 32, 32);
    glPopMatrix();


    //character
    //character
    glPushMatrix();
        glScaled(0.2,0.2,0.2);
        glTranslated(xhoriz,yverti-13,-37);
        gluLookAt(0,8,-6,0,9,-6,0,1,-20);
    glPushMatrix();
    glColor3d(0,0,0);
    glPushMatrix();
        glTranslated(0,2.6,-6);
        glRotated(90,1,0,0);
        gluCylinder(quadratic, 0.1f, 0.1f, 0.2, 32, 32);
    glPopMatrix();
    glColor3d(red, green, blue);
    glPushMatrix();
        glTranslated(0,2.7,-6);
        glScaled(0.15,0.15,0.15);
        glutSolidSphere(1,32,32);
    glPopMatrix();
    //head
    glPushMatrix();
    glTranslated(0,-0.2,0);
    //eyes
    glColor3d(red,green,blue);
    glPushMatrix();
        glTranslated(0.2,2,-5.55);
        glScaled(0.15,0.15,0.15);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslated(-0.2,2,-5.55);
        glScaled(0.15,0.15,0.15);
        glutSolidCube(1);
    glPopMatrix();
    //eyelids
    glColor3f(1,1,1);
    glPushMatrix();
        glTranslated(0.2,2,-5.55);
        glScaled(0.05,0.05,0.05);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslated(-0.2,2,-5.55);
        glScaled(0.05,0.05,0.05);
        glutSolidCube(1);
    glPopMatrix();
    //mouth
    glColor3d(0,0,0);
    glPushMatrix();
        glTranslated(0,1.75,-5.6);
        glScaled(0.5,0.2,0.25);
        glRotated(110,1,0,0);
        glutSolidCube(1);
    glPopMatrix();
    //teeth
    glColor3d(1,1,1);
    glPushMatrix();
        glTranslated(-0.15,1.8,-5.6);
        glScaled(0.1,0.03,0.25);
        glRotated(160,1,0,0);
        glutSolidCube(1);
    glPopMatrix();
    glColor3d(ct1,ct1,ct1);
    glPushMatrix();
        glTranslated(0,1.8,-5.6);
        glScaled(0.1,0.03,0.25);
        glRotated(140,1,0,0);
        glutSolidCube(1);
    glPopMatrix();
    glColor3d(1,1,1);
    glPushMatrix();
        glTranslated(0.15,1.8,-5.6);
        glScaled(0.1,0.03,0.25);
        glRotated(160,1,0,0);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslated(-0.15,1.7,-5.6);
        glScaled(0.1,0.03,0.25);
        glRotated(160,1,0,0);
        glutSolidCube(1);
    glPopMatrix();
    glColor3d(ct2,ct2,ct2);
    glPushMatrix();
        glTranslated(0,1.7,-5.6);
        glScaled(0.1,0.03,0.25);
        glRotated(140,1,0,0);
        glutSolidCube(1);
    glPopMatrix();
    glColor3d(1,1,1);
    glPushMatrix();
        glTranslated(0.15,1.7,-5.6);
        glScaled(0.1,0.03,0.25);
        glRotated(160,1,0,0);
        glutSolidCube(1);
    glPopMatrix();
    glPopMatrix();
     //face
    glColor3ub(25, 25, 77);
    glPushMatrix();
        glTranslated(0,2,-6);
        glScaled(0.5,0.6,0.5);
        glutSolidSphere(1,32,32);
    glPopMatrix();//end of head
    //body
    glColor3ub(25, 25, 77);
    glPushMatrix();
        glTranslated(0,1,-6);
        glScaled(1,1,1);
        glRotatef(90,1,0,0);
        glutSolidCone(1,2,32,32);
    glPopMatrix();
    //arm connectors
    glColor3d(red,green,blue);
    glPushMatrix();
        glTranslated(1,0.7,-6);
        glScaled(0.25,0.25,0.25);
        glRotatef(55,1,1,0);
        glutSolidTorus(0.4,1,32,32);
    glPopMatrix();
    glPushMatrix();
        glTranslated(-1,0.7,-6);
        glScaled(0.25,0.25,0.25);
        glRotatef(-55,-1,1,0);
        glutSolidTorus(0.4,1,32,32);
    glPopMatrix();
    //arms_before_elbow
    glColor3d(0,0,0);
    glPushMatrix();
        glTranslated(1,0.7,-6);
        glRotatef(65,0,1,0);
        glRotatef(65,1,0,0);
        gluCylinder(quadratic, 0.1f, 0.1f, 0.5, 32, 32);
    glPopMatrix();
    glPushMatrix();
        glTranslated(-1,0.7,-6);
        glRotatef(-65,0,1,0);
        glRotatef(-65,-1,0,0);
        gluCylinder(quadratic, 0.1f, 0.1f, 0.5, 32, 32);
    glPopMatrix();
    //arms_after_elbow
    glColor3d(0,0,0);
    glPushMatrix();
        glTranslated(1.25,0.05+ll,-6);
        glRotatef(90,0,1,0);
        glRotatef(90,1,0,0);
        gluCylinder(quadratic, 0.1f, 0.1f, 0.5, 32, 32);
    glPopMatrix();
    glPushMatrix();
        glTranslated(-1.25,0.05+rl,-6);
        glRotatef(-90,0,1,0);
        glRotatef(-90,-1,0,0);
        gluCylinder(quadratic, 0.1f, 0.1f, 0.5, 32, 32);
    glPopMatrix();
    //elbows
    glColor3d(red,green,blue);
    glPushMatrix();
        glTranslated(1.25,0.15,-6);
        glScaled(0.15,0.15,0.15);
        glutSolidSphere(1,32,32);
    glPopMatrix();
    glPushMatrix();
        glTranslated(-1.25,0.15,-6);
        glScaled(0.15,0.15,0.15);
        glutSolidSphere(1,32,32);
    glPopMatrix();
    //arms
    glColor3d(red,green,blue);
    glPushMatrix();
        glTranslated(1.25,-0.5+ll,-6);
        glScaled(0.15,0.15,0.15);
        glutSolidSphere(1,32,32);
    glPopMatrix();
    glPushMatrix();
        glTranslated(-1.25,-0.5+rl,-6);
        glScaled(0.15,0.15,0.15);
        glutSolidSphere(1,32,32);
    glPopMatrix();
    //leg connectors
    glColor3d(red,green,blue);
    glPushMatrix();
        glTranslated(0.4,-0.7,-6);
        glScaled(0.25,-0.25,0.25);
        glRotatef(45,0,1,0);
        glRotatef(-28,1,0,0);
        glutSolidTorus(0.4,1,32,32);
    glPopMatrix();
    glPushMatrix();
        glTranslated(-0.4,-0.7,-6);
        glScaled(0.25,-0.25,0.25);
        glRotatef(-45,0,1,0);
        glRotatef(-28,1,0,0);
        glutSolidTorus(0.4,1,32,32);
    glPopMatrix();
    //legs_before_knees
    glColor3d(0,0,0);
    glPushMatrix();
        glTranslated(0.4,-0.7,-6);
        glRotatef(65,0,1,0);
        glRotatef(65,1,0,0);
        gluCylinder(quadratic, 0.1f, 0.1f, 0.8, 32, 32);
    glPopMatrix();
    glPushMatrix();
        glTranslated(-0.4,-0.7,-6);
        glRotatef(-65,0,1,0);
        glRotatef(-65,-1,0,0);
        gluCylinder(quadratic, 0.1f, 0.1f, 0.8, 32, 32);
    glPopMatrix();
    //legs_after_knees
    glPushMatrix();
        glTranslated(0.75,-1.7+rl,-6);
        glRotatef(90,0,1,0);
        glRotatef(90,1,0,0);
        gluCylinder(quadratic, 0.1f, 0.1f, 0.7, 32, 32);
    glPopMatrix();
    glPushMatrix();
        glTranslated(-0.75,-1.7+ll,-6);
        glRotatef(-90,0,1,0);
        glRotatef(-90,-1,0,0);
        gluCylinder(quadratic, 0.1f, 0.1f, 0.7, 32, 32);
    glPopMatrix();
    //knees
    glColor3d(red,green,blue);
    glPushMatrix();
        glTranslated(0.75,-1.55,-6);
        glScaled(0.15,0.15,0.15);
        glutSolidSphere(1,32,32);
    glPopMatrix();
    glPushMatrix();
        glTranslated(-0.75,-1.55,-6);
        glScaled(0.15,0.15,0.15);
        glutSolidSphere(1,32,32);
    glPopMatrix();
    //feet
    glColor3ub(25, 25, 77);
    glPushMatrix();
        glTranslated(-0.8,-2.5+ll,-6);
        glScaled(0.3,0.2,0.7);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslated(0.8,-2.5+rl,-6);
        glScaled(0.3,0.2,0.7);
        glutSolidCube(1);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    //drawing ends

    //text
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslated(8,17,text_z);
    glRasterPos2f(0, 0);
    glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (unsigned char*)"    Arrow keys : Move the robot\n    r, g, b : Change robot color\n    u, n, d, l : Change camera");
    glPopMatrix();
    //Rendering the canvas on the screen
    glFlush();
}

void reshape(int width, int height)
{
    const float ar = (float)width / (float)height;
    //specifying the viewport, the area on which the drawings will be displayed
    //first two arguments are x and y of origin point and the rest arguments are the width and height from that point
    glViewport(0, 0, width, height);
    //background color
    glClearColor(1,1,1,1);
    //switch to the projection matrix
    glMatrixMode(GL_PROJECTION);
    //reset the projection matrix
    glLoadIdentity();
    //set up the projection mode to 3D
/*left, right
Specify the coordinates for the left and right vertical clipping planes.

bottom, top
Specify the coordinates for the bottom and top horizontal clipping planes.

nearVal, farVal
Specify the distances to the near and far depth clipping planes. Both distances must be positive.*/
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 50.0);
    //switch back to the default matrix to draw
    glMatrixMode(GL_MODELVIEW);
}

void tSpecial(int key, int x, int y)
{
switch (key) {

case GLUT_KEY_UP : // case GLUT_KEY_F1 :

if (yverti >23){lr = 0;lg = 1;}

if (yverti > -4){lr2 = 0; lg2 = 1;}

if (indicator==0){ll = 0.4; rl = 0; indicator = 1;}
else {rl = 0.4; ll = 0; indicator = 0;}

if ((yverti>1.5) && (yverti<3) && (xhoriz<-1)){
    yverti -= 0.5;
}
else if ((yverti>10) && (yverti<11.5) && (xhoriz>-1)){
    yverti -= 0.5;
}
else if ((yverti>18) && (yverti<19.5) && (xhoriz<0)){
    yverti -= 0.5;
}
else{
    yverti += 0.5;
}
 break;

case GLUT_KEY_DOWN : // case GLUT_KEY_F2 :

if (indicator==0){ll = 0.4; rl = 0; indicator = 1;}
else {rl = 0.4; ll = 0; indicator = 0;}

if ((yverti>1.5) && (yverti<5.5) && (xhoriz<-1)){
    yverti += 0.5;
}
else if ((yverti>10) && (yverti<14) && (xhoriz>-1)){
    yverti += 0.5;
}
else if ((yverti>18) && (yverti<22.5) && (xhoriz<0)){
    yverti += 0.5;
}
else{
    yverti -= 0.5;
}

break;

case GLUT_KEY_LEFT : // case GLUT_KEY_F1 :

if(xhoriz>=5.5){
    xhoriz -= 0;
}
else{
    xhoriz += 0.5;
}
 break;

case GLUT_KEY_RIGHT : // case GLUT_KEY_F2 :

if(xhoriz<=-5.5){
    xhoriz -= 0;
}
else{
    xhoriz -= 0.5;
}
 break;

 case GLUT_KEY_F1 : glutExit();break;
}
glutPostRedisplay();
}

void tClavier(unsigned char key, int x, int y)
{
    switch (key){
    case 'r' :case 'R': red = 1; green = 0; blue = 0; glutPostRedisplay();break;
    case 'g' :case 'G': red = 0; green = 1; blue = 0; glutPostRedisplay();break;
    case 'b' :case 'B': red = 0; green = 0; blue = 1; glutPostRedisplay();break;
    case 's' :case 'S': ct1 = 0; ct2 = 1 ;glutPostRedisplay();break;
    case 't' :case 'T': ct2 = 0; ct1 = 1 ;glutPostRedisplay();break;
    case 'i' :case 'I': ct1 = 1; ct2 = 1; glutPostRedisplay();break;

    case 'p' :case 'P':case 'u':case 'U': vv1 = 0;vv2 = -7; vv3 = -10; vv4 = -6; vv5 = 1;vv6 = -20; text_z = -6; glutPostRedisplay();break;
    case 'n': case 'N': vv1 = 8;vv2 = 0; vv3 = -6; vv4 = -6; vv5 = 0;vv6 = -100; glutPostRedisplay();break;
    case 'd':case 'D': vv1 = 0;vv2 = -8; vv3 = -6; vv4 = -6; vv5 = 1;vv6 = -20; text_z = 100; glutPostRedisplay();break;
    case 'l' :case 'L': vv1 = 0; vv2 = 0; vv3 = -13; vv4 = 6; vv5 = 1; vv6 = -20; glutPostRedisplay();break;

    glutPostRedisplay();
}
}

void sMouse(int button, int state, int x, int y){
switch (button) {

    case GLUT_LEFT_BUTTON : if (state == GLUT_DOWN) { vv1 += 0.5; }
    break;

    case GLUT_RIGHT_BUTTON : if (state == GLUT_DOWN){ vv1 -= 0.5; }
    break;

}

glutPostRedisplay();
}
