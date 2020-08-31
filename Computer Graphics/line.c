#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<stdlib.h>
#include<stdio.h>
float x1,x2,y1,y2;
 
void display()
{
	float dy,dx,x,y,k,m,c=50;
	dx=x2-x1;
	dy=y2-y1;	
	m = dy/dx; 	
	
	y = y1;

	for (k=x1 ;k<=x2;k++)
	{
		y = m*k + c;	
		
		if( y > (abs(y) + 0.5))
		{
			y = abs(y)+1;
		}
		else
		{
			y = abs(y);
		}
		
		glBegin(GL_POINTS);
		glVertex2i(k,y);
		glEnd();
	}
 
	glFlush();
}
 
int main(int argc, char** argv) 
{
	printf("Enter the value of x1 : ");
	scanf("%f",&x1);
	printf("Enter the value of y1 : ");
	scanf("%f",&y1);
	printf("Enter the value of x2 : ");
	scanf("%f",&x2);
	printf("Enter the value of y2 : ");
	scanf("%f",&y2);
	 
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500,500);
	glutInitWindowPosition (100,100);
	glutCreateWindow ("Y = mx + c line");
	glClearColor(255,255,255,1);
	gluOrtho2D(-100,100,-100,100);
	glutDisplayFunc(display);
	glutMainLoop();
 
	return 0;
}
