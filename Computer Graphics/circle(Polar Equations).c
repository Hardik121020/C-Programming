#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int x_c,y_c,r;
 
void display()
{
	int x,y,i;
	float theta;
	glPointSize(5.0);
	for(i=0;i<360;i++)
	{
		theta = (i*3.14)/180;
		x = (int)( x_c + (r*cos(theta)) );
		y = (int)( y_c + (r*sin(theta)) );
		glBegin(GL_POINTS);
		glVertex2f(x,y);
		glEnd();
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
	glutCreateWindow ("Circle Algorithm(using Polar Equations)");
	glClearColor(255,255,255,1);
	gluOrtho2D(-100,100,-100,100);
	glutDisplayFunc(display);
	glutMainLoop();
 	return 0;
}
