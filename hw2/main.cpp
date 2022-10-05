/*******************************************************
 * Homework 2: OpenGL                                  *
 *-----------------------------------------------------*
 * First, you should fill in problem1(), problem2(),   *
 * and problem3() as instructed in the written part of *
 * the problem set.  Then, express your creativity     *
 * with problem4()!                                    *
 *                                                     *
 * Note: you will only need to add/modify code where   *
 * it says "TODO".                                     *
 *                                                     *
 * The left mouse button rotates, the right mouse      *
 * button zooms, and the keyboard controls which       *
 * problem to display.                                 *
 *                                                     *
 * For Linux/OS X:                                     *
 * To compile your program, just type "make" at the    *
 * command line.  Typing "make clean" will remove all  *
 * computer-generated files.  Run by typing "./hw2"    *
 *                                                     *
 * For Visual Studio:                                  *
 * You can create a project with this main.cpp and     *
 * build and run the executable as you normally would. *
 *******************************************************/

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>

#include "./freeglut-3.2.1/include/GL/freeglut.h"

using namespace std;

bool leftDown = false, rightDown = false;
int lastPos[2];
float cameraPos[4] = {0,1,4,1};
int windowWidth = 640, windowHeight = 480;
double yRot = 0;
int curProblem = 1; // TODO: change this number to try different examples

float specular[] = { 1.0, 1.0, 1.0, 1.0 };
float shininess[] = { 50.0 };

void problem1() {
   // TODO: Your code here!
  for(int x=0;x<=360;x=x+36){
    glPushMatrix();
      glRotatef(-x, 0,0,1);
      glTranslatef(0, 1.5, 0);
      glutSolidTeapot(0.2);
      //glTranslatef(0, -1.5, 0);
    glPopMatrix();
  }

  
}

void problem2() {
  // TODO: Your code here!
  //draw the base
  for(float y=0;y<0.3;y=y+0.1){
    for(float x=-1.5;x<=1.5;x=x+0.1){
      glPushMatrix();
        glTranslatef(x, y, 0);
        glutSolidCube(0.1);
      glPopMatrix();
    }  
  }
  //draw the top part
  float y=0.3;
  for(float a=1.5;a>=(-1.5);a=a-0.2){
    y=y+0.1;
    for(float x=-1.5;x<=a;x=x+0.1){
      glPushMatrix();
        glScalef(1, 0.5, 1);
        glTranslatef(x, y, 0);
        glutSolidCube(0.1);
      glPopMatrix();
    }
  }
}

void problem3() {
    // TODO: Your code here!
  float x_start=-1.9;
  for(float y=1.2;y>=-1.8;y=y-0.6){
    x_start=x_start+0.3;
    for(float x=x_start;x<=-x_start;x=x+0.6){
      glPushMatrix();
        glTranslatef(x, y, 0);
        glutSolidTeapot(0.2);
      glPopMatrix();
    }
    
  }
}

void problem4() {
    // TODO: Your code here!

   //1st block
  glPushMatrix(); 
    glTranslatef(0, -1, 0);
    glScalef(2.5, 1, 2.5);
    glutSolidCube(2);
  glPopMatrix();
  //2nd block cones facing up
  for(float y=0;y<=360;y=y+90){
    glPushMatrix();
      glRotatef(y,0,1,0);//rotate arounf y 90degree everytime to make the surrounding
      glTranslatef(0, 0, 2);//allocate the position
      glRotatef(90,-1,0,0);//rotate around itself regarding x axis to make the cone point up
      glutSolidCone(0.2, 1, 20,20);
    glPopMatrix();
  }
  //2nd block facing down 
  for(float y=45;y<=360;y=y+90){
    glPushMatrix();
      glRotatef(y,0,1,0);//rotate arounf y 90degree everytime to make the surrounding
      glTranslatef(0, 1, 2);//allocate the position
      glRotatef(90,1,0,0);//rotate around itself regarding x axis to make the cone point down
      glutSolidCone(0.2, 1, 20,20);
    glPopMatrix();
  }

 

    //2nd block sphere 
    for(int degree=0;degree<=360;degree+=45){
      glPushMatrix(); 
        glRotatef(degree,0,1,0);
        glTranslatef(0, 1.3, 2);
        //glRotatef(degree,0,1,0);
        glutSolidSphere(0.3, 20, 20);
      glPopMatrix();
    }

  //3rd block
  glPushMatrix(); 
    glTranslatef(0, 2.1, 0);//0.6+1+0.5
    glScalef(4.5, 1, 4.5);
    glutSolidCube(1);
  glPopMatrix();

  //4th block
  glPushMatrix(); 
    glTranslatef(0, 3, 1.5);//0.6+1+0.5+1
    //glRotatef(degree,0,1,0);
    glRotatef(-20, 0, 0, 1);
    glutSolidTetrahedron();
  glPopMatrix();

  glPushMatrix(); 
    glTranslatef(0, 3, -1.5);//0.6+1+0.5+1
    //glRotatef(degree,0,1,0);
    glRotatef(-20, 0, 0, 1);
    glutSolidTetrahedron();
  glPopMatrix();

  //5th block
  glPushMatrix(); 
    glTranslatef(0, 4.8, 0);
    glRotatef(90,1,0,0);
    glutSolidTorus(0.8, 1.5, 20, 20);
  glPopMatrix();
  
  //6th block
  for(int degree=0;degree<=360;degree+=90){
    glPushMatrix(); 
      glRotatef(degree, 0, 1, 0);
      glTranslatef(0, 5.9, 1.5);
      glutSolidTeapot(0.5);
    glPopMatrix();
  }
}

void display() {
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glDisable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glBegin(GL_LINES);
		glColor3f(1,0,0); glVertex3f(0,0,0); glVertex3f(1,0,0); // x axis
		glColor3f(0,1,0); glVertex3f(0,0,0); glVertex3f(0,1,0); // y axis
		glColor3f(0,0,1); glVertex3f(0,0,0); glVertex3f(0,0,1); // z axis
	glEnd(/*GL_LINES*/);

	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glEnable(GL_LIGHT0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0,0,windowWidth,windowHeight);

	float ratio = (float)windowWidth / (float)windowHeight;
	gluPerspective(50, ratio, 1, 1000);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(cameraPos[0], cameraPos[1], cameraPos[2], 0, 0, 0, 0, 1, 0);

	glLightfv(GL_LIGHT0, GL_POSITION, cameraPos);

	glRotatef(yRot,0,1,0);

	if (curProblem == 1) problem1();
	if (curProblem == 2) problem2();
	if (curProblem == 3) problem3();
	if (curProblem == 4) problem4();

	glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) leftDown = (state == GLUT_DOWN);
	else if (button == GLUT_RIGHT_BUTTON) rightDown = (state == GLUT_DOWN);

	lastPos[0] = x;
	lastPos[1] = y;
}

void mouseMoved(int x, int y) {
	if (leftDown) yRot += (x - lastPos[0])*.1;
	if (rightDown) {
		for (int i = 0; i < 3; i++)
			cameraPos[i] *= pow(1.1,(y-lastPos[1])*.1);
	}


	lastPos[0] = x;
	lastPos[1] = y;
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	curProblem = key-'0';
    if (key == 'q' || key == 'Q' || key == 27){
        exit(0);
    }
	glutPostRedisplay();
}

void reshape(int width, int height) {
	windowWidth = width;
	windowHeight = height;
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow("HW2");

	glutDisplayFunc(display);
	glutMotionFunc(mouseMoved);
	glutMouseFunc(mouse);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);

	glutMainLoop();

	return 0;
}
