#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<stdlib.h>
#include<stdio.h>

int x_c,y_c,r;
 
void plotpoint(int xc,int yc,int x,int y)
{
	glPointSize(5.0);
	glBegin(GL_POINTS);
	glVertex2f(x+xc,y+yc);
	glVertex2f(x+xc,-(y+yc));
	glVertex2f(-(x+xc),-(y+yc));
	glVertex2f(-(x+xc),y+yc);
	glVertex2f(y+yc,x+xc);
	glVertex2f(y+yc,-(x+xc));
	glVertex2f(-(y+yc),-(x+xc));
	glVertex2f(-(y+yc),(x+xc));
	glEnd();

}

void display()
{
	int x,y,d,k;
	x = 0;
	y = r;
	d = 3-2*r;
	plotpoint(x_c,y_c,x,y);
	
	for(k=x;k<=y;k++)
	{
		if(d<=0)
		{
			d = d + 4*k + 6;
		}
		else
		{
			d = d + 4*k - 4*y + 10;
			y = y -1;
		}
		plotpoint(x_c,y_c,k,y);
	}
	
	glFlush();	
}
 
int main(int argc, char** argv) 
{

	printf("Enter the value of x cordinate of circle : ");
	scanf("%d",&x_c);
	printf("Enter the value of x cordinate of circle : ");
	scanf("%d",&y_c);
	printf("Enter the radius of circle : ");
	scanf("%d",&r);
	 
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500,500);
	glutInitWindowPosition (100,100);
	glutCreateWindow ("Bresenham Circle Algorithm");
	glClearColor(255,255,255,1);
	gluOrtho2D(-100,100,-100,100);
	glutDisplayFunc(display);
	glutMainLoop();
 
	//return 0;
}
