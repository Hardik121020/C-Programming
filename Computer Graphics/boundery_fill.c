#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

 
void circle(int x, int y , int radius)
{
	int x1,y1,i;
	float theta;
	glPointSize(5.0);
	for(i=0;i<360;i++)
	{
		theta = (i*3.14)/180;
		x1 = (int)( x + (radius*cos(theta)) );
		y1 = (int)( y + (radius*sin(theta)) );
		glBegin(GL_POINTS);
		glVertex2f(x1,y1);
		glEnd();
	}	
	glFlush();
}

// 4 Connected

void boundery_fill4(int x, int y, float *fill_color, float *boundary)
{
	float current_color[3];
	glReadPixels(x,y,1,1,GL_RGB,GL_FLOAT,current_color);
	if( (current_color[0] != boundary[0]) || (current_color[1] != boundary[1]) || (current_color[2] != boundary[2] ) && ((current_color[0] != fill_color[0]) || (current_color[1] != fill_color[1]) || (current_color[2] != fill_color[2])))
	{
		glColor3f(fill_color[0],fill_color[1],fill_color[2]);
		glBegin(GL_POINTS);
		glVertex2f(x,y);
		glEnd();
		boundery_fill4(x+1 , y , fill_color , boundary);
		boundery_fill4(x-1 , y , fill_color , boundary);
		boundery_fill4(x , y+1 , fill_color , boundary);
		boundery_fill4(x , y-1 , fill_color , boundary);
	}
}

void display()
{
	int x1 = 0, y1 = 0, radius = 40;
	circle(x1 , y1 , radius);
	float boundery_Color[] = {1,1,0};                             
        float fill_Color[] = {1,0,1}; 
	boundery_fill4(x1 , y1 , fill_Color , boundery_Color);
	glFlush();
}
 
int main(int argc, char** argv) 
{
	 
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500,500);
	glutInitWindowPosition (100,100);
	glutCreateWindow ("Circle Algorithm(using Polar Equations)");
	glClearColor(255,255,255,1);
	gluOrtho2D(-100,100,-100,100);
	glutDisplayFunc(display);
	glutMainLoop();
 	return 0;
}
