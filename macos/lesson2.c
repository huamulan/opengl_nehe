//
// This code was created by Jeff Molofee '99
//
// If you've found this code useful, please let me know.
//
// Visit me at www.demonews.com/hosted/nehe
//
/**************************************************************/
// This code was ported to MacOS by Tony Parker.
//  I'd also appreciate it if you could drop me a line if you found
//  this code useful. 
// 
//  Tony Parker - asp@usc.edu
// 
// Have a nice day.

#include <stdio.h>			// Header File For Standard Input / Output
#include <stdarg.h>			// Header File For Variable Argument Routines
#include <string.h>			// Header File For String Management
#include <stdlib.h>
#include <GL/gl.h>				// Header File For The OpenGL32 Library
#include <GL/glu.h>			// Header File For The GLu32 Library
#include <GL/glut.h>			// Header File For The GLUT Library
#include <math.h>

// Constants -----------------------------------------------------------------

#define kWindowWidth	400
#define kWindowHeight	300

// Function Prototypes -------------------------------------------------------

GLvoid InitGL(GLvoid);
GLvoid DrawGLScene(GLvoid);
GLvoid ReSizeGLScene(int Width, int Height);

// Main ----------------------------------------------------------------------

int main(int argc, char** argv)
{
	
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (kWindowWidth, kWindowHeight); 
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);
	
	InitGL();
 
    glutDisplayFunc(DrawGLScene); 
    glutReshapeFunc(ReSizeGLScene); 

    glutMainLoop();
    
    return 0;
}

// Init ----------------------------------------------------------------------

GLvoid InitGL(GLvoid)
{

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);		// This Will Clear The Background Color To Black
	glClearDepth(1.0);							// Enables Clearing Of The Depth Buffer
	glDepthFunc(GL_LESS);						// The Type Of Depth Test To Do
	glEnable(GL_DEPTH_TEST);					// Enables Depth Testing
	glShadeModel(GL_SMOOTH);					// Enables Smooth Color Shading

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();							// Reset The Projection Matrix

	gluPerspective(45.0f,(GLfloat)kWindowWidth/(GLfloat)kWindowHeight,0.1f,100.0f);	// Calculate The Aspect Ratio Of The Window

	glMatrixMode(GL_MODELVIEW);

}

// DrawGLScene ---------------------------------------------------------------

GLvoid DrawGLScene(GLvoid)
{    
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// Clear The Screen And The Depth Buffer
	glLoadIdentity();										// Reset The View

	glTranslatef(-1.5f,0.0f,-6.0f);

	glBegin(GL_POLYGON);
		glVertex3f( 0.0f, 1.0f, 0.0f);
		glVertex3f(-1.0f,-1.0f, 0.0f);
		glVertex3f( 1.0f,-1.0f, 0.0f);
	glEnd();

	glTranslatef(3.0f,0.0f,0.0f);

	glBegin(GL_QUADS);
		glVertex3f(-1.0f, 1.0f, 0.0f);
		glVertex3f( 1.0f, 1.0f, 0.0f);
		glVertex3f( 1.0f,-1.0f, 0.0f);
		glVertex3f(-1.0f,-1.0f, 0.0f);
	glEnd();
	
    glFlush();
}

// ReSizeGLScene ------------------------------------------------------------

GLvoid ReSizeGLScene(int Width, int Height)
{
    glViewport (0, 0, (GLsizei) Width, (GLsizei) Height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0, (GLfloat) Width / (GLfloat) Height, 0.1, 100.0);
   
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

