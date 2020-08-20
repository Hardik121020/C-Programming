#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>

void display()
{	
	glClear(GL_COLOR_BUFFER_BIT);	
	
	//Line strips
	
	glColor3f(0,1,1);
	glBegin(GL_LINES);
    	glVertex2f(0.1,0.2);
    	glVertex2f(0.1,0.6);
	glEnd();

	glColor3f(0,1,1);
	glBegin(GL_LINES);
    	glVertex2f(0.2,0.2);
    	glVertex2f(0.2,0.6);
	glEnd();

	glColor3f(0,1,1);
	glBegin(GL_LINES);
    	glVertex2f(0.3,0.2);
    	glVertex2f(0.3,0.6);
	glEnd();

	glColor3f(0,1,1);
	glBegin(GL_LINES);
    	glVertex2f(0.4,0.2);
    	glVertex2f(0.4,0.6);
	glEnd();

	glRasterPos2f(0.1,0.1);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18,"LINE STRIP");
	glFlush();

	//TRIANGLE

	glColor3f(0,1,1);	
	glBegin(GL_TRIANGLES);
    	glVertex2f(-0.1,0.2);
    	glVertex2f(-0.3,0.4);
	glVertex2f(-0.5,0.2);
	glEnd();

	glRasterPos2f(-0.5,0.1);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18,"TRIANGLE");
	glFlush();
	
	//Square

	glColor3f(0,1,1);	
	glBegin(GL_QUADS);
    	glVertex2f(-0.6,0.2);
    	glVertex2f(-0.6,0.5);
	glVertex2f(-0.9,0.5);
	glVertex2f(-0.9,0.2);
	glEnd();

	glRasterPos2f(-0.9,0.1);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18,"SQUARE");
	glFlush();

	//PENTAGON
	glColor3f(0,1,1);	
	glBegin(GL_POLYGON);
    	glVertex2f(-0.1,-0.3);
    	glVertex2f(-0.1,-0.5);
	glVertex2f(-0.3,-0.6);
	glVertex2f(-0.5,-0.5);
	glVertex2f(-0.5,-0.3);
	glEnd();

	glRasterPos2f(-0.5,-0.7);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18,"PENTAGON");
	glFlush();

	
	
	glFlush();
}



int main(int argc,char **argv)
{

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

	glutInitWindowSize(500,500);
	glutInitWindowPosition(200,200);

	glutCreateWindow("POLYGONS");
	glClearColor(1,0,0,1);
	glutDisplayFunc(display);
	glutMainLoop();
}
