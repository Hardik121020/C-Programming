#include<stdio.h>
#include<math.h>
#include<GL/glut.h>

double rotate_x = 0;
double rotate_y = 0;

void display()
{
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    	glEnable(GL_DEPTH_TEST);

	glRotatef(rotate_x,1.0,1.0,1.0);
	glRotatef(rotate_y,1.0,1.0,1.0);

	glBegin(GL_POLYGON);
	// Front
	glColor3f(1, 0.2, 0.2);     
	glVertex3f(0.5, -0.5 , -0.5);     
	glVertex3f(0.5,  0.5, -0.5);      
       	glVertex3f(-0.5,  0.5, -0.5);     
  	glVertex3f( -0.5, -0.5, -0.5 );  
	glEnd();

	//BACK
  	glBegin(GL_POLYGON);
  	glColor3f(0.188, 0.047, 0.905);
  	glVertex3f(0.5, -0.5, 0.5);
  	glVertex3f(0.5,  0.5, 0.5);
  	glVertex3f(-0.5,  0.5, 0.5);
  	glVertex3f(-0.5, -0.5, 0.5);
  	glEnd();
 
  	//RIGHT
  	glBegin(GL_POLYGON);
  	glColor3f(0.949, 0.894, 0.223);
  	glVertex3f( 0.5, -0.5, -0.5 );
  	glVertex3f( 0.5,  0.5, -0.5 );
  	glVertex3f( 0.5,  0.5,  0.5 );
  	glVertex3f( 0.5, -0.5,  0.5 );
  	glEnd();
 
  	//LEFT
  	glBegin(GL_POLYGON);
  	glColor3f(1, 0.674, 0.196);
  	glVertex3f(-0.5, -0.5,  0.5);
  	glVertex3f( -0.5,  0.5,  0.5 );
  	glVertex3f( -0.5,  0.5, -0.5 );
  	glVertex3f( -0.5, -0.5, -0.5 );
  	glEnd();
 
  	//TOP
  	glBegin(GL_POLYGON);
  	glColor3f(0.282, 1, 0.305);
  	glVertex3f(0.5,0.5,0.5);
  	glVertex3f(0.5,0.5,-0.5);
  	glVertex3f(-0.5,0.5,-0.5);
  	glVertex3f( -0.5,  0.5,  0.5 );
  	glEnd();
 
  	//BOTTOM
  	glBegin(GL_POLYGON);
  	glColor3f(1.0,1.0,1.0);
  	glVertex3f(  0.5, -0.5, -0.5 );
  	glVertex3f(  0.5, -0.5,  0.5 );
  	glVertex3f( -0.5, -0.5,  0.5 );
  	glVertex3f( -0.5, -0.5, -0.5 );
  	glEnd();
	glFlush();
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y )
{
	if(key == 'w')
	{
		rotate_x = rotate_x + 2;
	}
	else if(key == 's')
	{
		rotate_x = rotate_x - 2;
	}
	else if(key == 'a')
	{
		rotate_y = rotate_y + 2;
	}
	else if(key == 'd')
	{
		rotate_y = rotate_y - 2;
	}
	glutPostRedisplay();
}


	
int main(int argc, char** argv) 
{	
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500,500);
	glutInitWindowPosition (100,100);
	glutCreateWindow ("CUBE");
	glClearColor(0,0,0,1);
	//gluOrtho2D(0,10,0,10);
	glutKeyboardFunc(keyboard);	
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
