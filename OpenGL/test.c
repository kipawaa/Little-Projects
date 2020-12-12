#include<stdio.h>
#include<stdlib.h>

// This silences deprecation warning
#define GL_SILENCE_DEPRECATION

// imports for opengl libraries
#include<OpenGL/gl.h>
#include<OpenGL/glu.h>
#include<GLUT/glut.h>

/**************** MAKE SURE TO COMPILE WITH "-framework GLUT" AND "-framework OpenGL" *************************/

void display() {
	// set everything in the frame buffer to "clear"
	glClear(GL_COLOR_BUFFER_BIT);

	// define a new polygon
	glBegin(GL_POLYGON);
		// set the colour at the first vertex
		glColor3f(1, 0, 0);
		// define the first vertex
		glVertex3f(-0.6, -0.75, 0.5);

		// colour and second vertex
		glColor3f(0, 1, 0);
		glVertex3f(0.6, -0.75, 0);

		// colour and second vertex
		glColor3f(0, 0, 1);
		glVertex3f(0, 0.75, 0);
	// end of polygon definition
	glEnd();

	// flush the command buffer so that this is the next thing to be drawn
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	
	// initialize a single buffered window in RGB mode
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	// position the window
	glutInitWindowPosition(0, 0);

	// window size
	glutInitWindowSize(800, 800);

	// create the window
	glutCreateWindow("Triangle");

	// call the display function whenever glut wants to draw somthing
	glutDisplayFunc(display);

	// start glut. will run until user closes the window
	glutMainLoop();
}
