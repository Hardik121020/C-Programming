#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<stdlib.h>
#include<stdio.h>
float x_1,x_2,y_1,y_2;
 
void display()
{
	float dy,dx,x,y,m,steps,xin,yin;
	int i;
	dx=x_2-x_1;
	dy=y_2-y_1;	
	m = dy/dx; 	
	
	x = x_1;
	y = y_1;

	glBegin(GL_POINTS);
	glVertex2f(x,y);
	glEnd();

	//When calculated slope is less than 1 
	if (m<1)
	{
		steps = dx;
		xin = dx/steps;
		yin = dy/steps;
		for(i = 1;i<=steps;i++)
		{
			y = y + yin;
			x = x + xin;
			glBegin(GL_POINTS);
			if( y > (abs(y) + 0.5))
			{
				glVertex2f(x,abs(y)+1);
			}
			else
			{
				glVertex2f(x,abs(y));
			}
			glEnd();
		}
	}

	//When calculated slope is greater than 1
	else if (m>1)
	{
		steps = dy;
		xin = dx/steps;
		yin = dy/steps;
		for(i = 1;i<=steps;i++)
		{
			y = y + yin;
			x = x + xin;
			glBegin(GL_POINTS);
			if( y > (abs(y) + 0.5))
			{
				glVertex2f(x,abs(y)+1);
			}
			else
			{
				glVertex2f(x,abs(y));
			}
			glEnd();
		}
	}

	//When calculated slope is equal to 1
	else if (m == 1)
 	{
		steps = dy; // or steps = dx
		xin = dx/steps;
		yin = dy/steps;
		for(i = 1;i<=steps;i++)
		{
			y = y + yin;
			x = x + xin;
			glBegin(GL_POINTS);
			if( y > (abs(y) + 0.5))
			{
				glVertex2f(x,abs(y)+1);
			}
			else
			{
				glVertex2f(x,abs(y));
			}
			glEnd();
		}
		glFlush();
	}
}
 
int main(int argc, char** argv) 
{
	printf("Enter the value of x1 : ");
	scanf("%f",&x_1);
	printf("Enter the value of y1 : ");
	scanf("%f",&y_1);
	printf("Enter the value of x2 : ");
	scanf("%f",&x_2);
	printf("Enter the value of y2 : ");
	scanf("%f",&y_2);
	 
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
