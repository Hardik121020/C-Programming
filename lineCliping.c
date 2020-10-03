#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

int x_1,y_1,x_2,y_2;
const int x_max = 10; 
const int y_max = 8; 
const int x_min = 4; 
const int y_min = 4; 

#define INSIDE 0
#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8

int code(double x, double y)
{
	int code = INSIDE;
	if(x < x_max)
	{
		code |= LEFT;
	}
	else
	{
		code |= RIGHT;
	}
	if(y < y_max)
	{
		code |= BOTTOM;
	}
	else
	{
		code |= TOP;
	}

	return code;
}

void lineCliping(double x1, double y1, double x2, double y2)
{
	int code1,code2;
	code1 = code(x1,y1);
	code2 = code(x2,y2);
	
	bool accept = false;

	while(true)
	{
		if((code1 == 0) & (code2 == 0))
		{
			accept = true;
			break;
		}
		else if (code1 & code2)
		{
			break;
		}
		else
		{
			int code_out;
			double x,y;
			if(code1 !=0)
			{
				code_out = code1;
			}
			else
			{
				code_out = code2;
			}
	
			if (code_out & TOP) 
			{ 
                		x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1); 
                		y = y_max; 
            		} 
            		else if (code_out & BOTTOM) 
			{ 	
                		x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1); 
                		y = y_min; 
            		} 
            		else if (code_out & RIGHT) 
			{ 	 
                		y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1); 
                		x = x_max; 
            		} 
            		else if (code_out & LEFT) 
			{  
                		y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1); 
                		x = x_min; 
            		} 
   
            		if (code_out == code1) 
			{ 
                		x1 = x; 
                		y1 = y; 
                		code1 = code(x1, y1); 
            		} 
            		else 
			{ 
                		x2 = x; 
                		y2 = y; 
                		code2 = code(x2, y2); 
            		} 
		}
	}

	if (accept)
	{
		glColor3f(1,1,0);
  		glBegin(GL_LINES);
		glVertex2f(x1,y1);
		glVertex2f(x2,y2);
		glEnd();
	}
}


void display()  
{  
	glClear(GL_COLOR_BUFFER_BIT);

	/*glColor3f(1,1,1);	
	glBegin(GL_QUADS);
    	glVertex2f(x_min,y_min);
    	glVertex2f(x_max,y_min);
	glVertex2f(x_max,y_max);
	glVertex2f(x_min,y_max);
	glEnd();*/

	//glColor3f(1,0,1);
  	//glBegin(GL_LINES);
	lineCliping(x_1,y_1,x_2,y_2);
	
	glFlush();
	
}

int main(int argc, char** argv) 
{	
	printf("Enter the value of x1 : ");
	scanf("%d",&x_1);
	printf("Enter the value of y1 : ");
	scanf("%d",&y_1);
	printf("Enter the value of x2 : ");
	scanf("%d",&x_2);
	printf("Enter the value of y2 : ");
	scanf("%d",&y_2);

	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500,500);
	glutInitWindowPosition (100,100);
	glutCreateWindow ("Line Clipping");
	glClearColor(0,0,0,1);
	gluOrtho2D(0,10,0,10);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
