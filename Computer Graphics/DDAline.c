// Still Working on the code
#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<stdlib.h>
#include<stdio.h>
float x1,x2,y1,y2;
 
void display()
{
	float dy,dx,x,y,m,steps,xin,yin;
	int i;
	dx=x2-x1;
	dy=y2-y1;	
	m = dy/dx; 	
	
	x = x1;
	y = y1;

	glBegin(GL_POINTS);
	glVertex2i(x1,y1);
	glEnd();

	if (m<1)
	{
		steps = dx;
		xin = dx/steps;
		yin = dy/steps;
		for(i = 1;i<=steps;i++)
		{
			x = x + xin;
			y = y + yin;
			if( y > (abs(y) + 0.5))
			{
				y = abs(y)+1;
			}
			else
			{
				y = abs(y);
			}
		
			glBegin(GL_POINTS);
			glVertex2i(x,y);
			glEnd();
		} 
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
	glutCreateWindow ("DDA line Algo");
	glClearColor(255,255,255,1);
	gluOrtho2D(-100,100,-100,100);
	glutDisplayFunc(display);
	glutMainLoop();
 
	return 0;
}
