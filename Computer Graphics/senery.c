#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<math.h>

void display()
{	
	glClear(GL_COLOR_BUFFER_BIT);


	//Sky
	//glColor3f(0,136,250);
	glColor3f(23,12,157);	
	glBegin(GL_QUADS);
    	glVertex2f(-1,0.2);
    	glVertex2f(1,0.2);
	glVertex2f(1,1);
	glVertex2f(-1,1);
	glEnd();
	
	//Mountains
	glColor3f(95,45,63);	
	glBegin(GL_TRIANGLES);
    	glVertex2f(-1,0.2);
    	glVertex2f(-0.75,1);
	glVertex2f(-0.5,0.2);
	glEnd();

	glColor3f(95,45,63);	
	glBegin(GL_TRIANGLES);
    	glVertex2f(-0.5,0.2);
    	glVertex2f(-0.25,1);
	glVertex2f(0,0.2);
	glEnd();

	glColor3f(95,45,63);	
	glBegin(GL_TRIANGLES);
    	glVertex2f(1,0.2);
    	glVertex2f(0.75,1);
	glVertex2f(0.5,0.2);
	glEnd();

	glColor3f(95,45,63);	
	glBegin(GL_TRIANGLES);
    	glVertex2f(0.5,0.2);
    	glVertex2f(0.25,1);
	glVertex2f(0,0.2);
	glEnd();

	//River

	glColor3f(0,136,250);	
	glBegin(GL_TRIANGLES);
    	glVertex2f(-0.8,-1);
    	glVertex2f(-0.75,1);
	glVertex2f(-0.5,0.2);
	glEnd();

	glColor3f(0,0,0);
	glBegin(GL_LINES);
    	glVertex2f(0,0.2);
    	glVertex2f(-0.8,-1);
	glEnd();

	glColor3f(0,0,0);
	glBegin(GL_LINES);
    	glVertex2f(0,0.2);
    	glVertex2f(-0.2,-1);
	glEnd();
	
	
	
	glFlush();
}



int main(int argc,char **argv)
{

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

	glutInitWindowSize(500,500);
	glutInitWindowPosition(200,200);

	glutCreateWindow("POLYGONS");
	glClearColor(255,255,255,1);
	glutDisplayFunc(display);
	glutMainLoop();
}
