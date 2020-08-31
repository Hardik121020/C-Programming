#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<math.h>

void display()
{	
	glClear(GL_COLOR_BUFFER_BIT);

	//Sky
	glColor3f(0,0,1);	
	glBegin(GL_QUADS);
    	glVertex2f(-1,0.2);
    	glVertex2f(1,0.2);
	glVertex2f(1,1);
	glVertex2f(-1,1);
	glEnd();

	//Ground

	glColor3f(0,1,0);	
	glBegin(GL_QUADS);
    	glVertex2f(-1,0.2);
    	glVertex2f(1,0.2);
	glVertex2f(1,-1);
	glVertex2f(-1,-1);
	glEnd();
	
	//Mountains
	glColor3f(1,1,1);	
	glBegin(GL_TRIANGLES);
    	glVertex2f(-1,0.2);
    	glVertex2f(-0.75,1);
	glVertex2f(-0.5,0.2);
	glEnd();

	glColor3f(1,1,1);	
	glBegin(GL_TRIANGLES);
    	glVertex2f(-0.5,0.2);
    	glVertex2f(-0.25,1);
	glVertex2f(0,0.2);
	glEnd();

	glColor3f(1,1,1);	
	glBegin(GL_TRIANGLES);
    	glVertex2f(1,0.2);
    	glVertex2f(0.75,1);
	glVertex2f(0.5,0.2);
	glEnd();

	glColor3f(1,1,1);	
	glBegin(GL_TRIANGLES);
    	glVertex2f(0.5,0.2);
    	glVertex2f(0.25,1);
	glVertex2f(0,0.2);
	glEnd();

	//River

	glColor3f(0,0,1);	
	glBegin(GL_TRIANGLES);
    	glVertex2f(-0.8,-1);
    	glVertex2f(0,0.2);
	glVertex2f(-0.2,-1);
	glEnd();

	//House

	//Roof
	glColor3f(1,1,1);	
	glBegin(GL_TRIANGLES);
    	glVertex2f(0.1,-0.4);
    	glVertex2f(0.3,-0.2);
	glVertex2f(0.5,-0.4);
	glEnd();
	
	glColor3f(1,1,0);	
	glBegin(GL_QUADS);
    	glVertex2f(0.3,-0.2);
    	glVertex2f(0.7,-0.2);
	glVertex2f(0.9,-0.4);
	glVertex2f(0.5,-0.4);
	glEnd();

	//walls
	
	glColor3f(1,0,0);	
	glBegin(GL_QUADS);
    	glVertex2f(0.1,-0.4);
    	glVertex2f(0.5,-0.4);
	glVertex2f(0.5,-0.8);
	glVertex2f(0.1,-0.8);
	glEnd();
	
	glColor3f(1,0,0);	
	glBegin(GL_QUADS);
    	glVertex2f(0.5,-0.4);
    	glVertex2f(0.9,-0.4);
	glVertex2f(0.9,-0.8);
	glVertex2f(0.5,-0.8);
	glEnd();

	//Door
	
	glColor3f(1,0,1);	
	glBegin(GL_QUADS);
    	glVertex2f(0.2,-0.5);
    	glVertex2f(0.2,-0.8);
	glVertex2f(0.4,-0.8);
	glVertex2f(0.4,-0.5);
	glEnd();

	//Window

	glColor3f(1,0,1);	
	glBegin(GL_QUADS);
    	glVertex2f(0.6,-0.5);
    	glVertex2f(0.6,-0.7);
	glVertex2f(0.8,-0.7);
	glVertex2f(0.8,-0.5);
	glEnd();

	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(0.7,-0.5);
	glVertex2f(0.7,-0.7);
	glEnd();

	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(0.6,-0.6);
	glVertex2f(0.8,-0.6);
	glEnd();
	
	//OutLining
	//Roof
	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(0.1,-0.4);
	glVertex2f(0.3,-0.2);
	glEnd();

	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(0.3,-0.2);
	glVertex2f(0.5,-0.4);
	glEnd();

	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(0.1,-0.4);
	glVertex2f(0.5,-0.4);
	glEnd();

	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(0.3,-0.2);
	glVertex2f(0.7,-0.2);
	glEnd();

	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(0.7,-0.2);
	glVertex2f(0.9,-0.4);
	glEnd();

	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(0.9,-0.4);
	glVertex2f(0.5,-0.4);
	glEnd();
	
	//Walls
		
	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(0.5,-0.4);
	glVertex2f(0.5,-0.8);
	glEnd();
	
	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(0.1,-0.4);
	glVertex2f(0.1,-0.8);
	glEnd();

	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(0.1,-0.8);
	glVertex2f(0.5,-0.8);
	glEnd();

	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(0.5,-0.8);
	glVertex2f(0.9,-0.8);

	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(0.9,-0.4);
	glVertex2f(0.9,-0.8);
	glEnd();
	
	//Door
	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(0.2,-0.5);
	glVertex2f(0.2,-0.8);
	glEnd();

	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(0.2,-0.8);
	glVertex2f(0.4,-0.8);
	glEnd();

	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(0.4,-0.8);
	glVertex2f(0.4,-0.5);
	glEnd();
	
	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(0.4,-0.5);
	glVertex2f(0.2,-0.5);
	glEnd();

	//Window 

	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(0.6,-0.5);
	glVertex2f(0.6,-0.7);
	glEnd();

	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(0.6,-0.7);
	glVertex2f(0.8,-0.7);
	glEnd();

	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(0.8,-0.7);
	glVertex2f(0.8,-0.5);
	glEnd();

	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(0.8,-0.5);
	glVertex2f(0.6,-0.5);
	glEnd();
		
	glFlush();
}

void Keyboard(unsigned char key, int x, int y )
{
    	if(key == 'a')
	{
		//River
		glColor3f(0.596, 0.086, 0.890);	
		glBegin(GL_QUADS);
	    	glVertex2f(0.2,-0.5);
	    	glVertex2f(0.2,-0.8);
		glVertex2f(0.4,-0.8);
		glVertex2f(0.4,-0.5);
		glEnd();
		glFlush();
	}

	else if(key == 'b')
	{
		//Roof
		glColor3f(1, 0.921, 0.019);	
		glBegin(GL_TRIANGLES);
	    	glVertex2f(0.1,-0.4);
	    	glVertex2f(0.3,-0.2);
		glVertex2f(0.5,-0.4);
		glEnd();
		glFlush();
	}
	else if(key == 'c')
	{
		glColor3f(0.968, 0.031, 0.443);	
		glBegin(GL_QUADS);
    		glVertex2f(0.3,-0.2);
    		glVertex2f(0.7,-0.2);
		glVertex2f(0.9,-0.4);
		glVertex2f(0.5,-0.4);
		glEnd();
		glFlush();
	}
	
}

void mouse(int button,int state,int x,int y)
{
	switch(button)
	{
	case GLUT_LEFT_BUTTON:
		if(state==GLUT_DOWN)
		{
			glColor3f(0.443, 0.349, 0.054);	
			glBegin(GL_TRIANGLES);
		    	glVertex2f(-0.5,0.2);
		    	glVertex2f(-0.25,1);
			glVertex2f(0,0.2);
			glEnd();

			glColor3f(0.443, 0.349, 0.054);	
			glBegin(GL_TRIANGLES);
		    	glVertex2f(0.5,0.2);
		    	glVertex2f(0.25,1);
			glVertex2f(0,0.2);
			glEnd();
			glFlush();

		}
		break;
	case GLUT_RIGHT_BUTTON:
		if(state==GLUT_DOWN)
		{
			glColor3f(0.415, 0.360, 0.184);	
			glBegin(GL_TRIANGLES);
		    	glVertex2f(-1,0.2);
		    	glVertex2f(-0.75,1);
			glVertex2f(-0.5,0.2);
			glEnd();
			

			glColor3f(0.415, 0.360, 0.184);	
			glBegin(GL_TRIANGLES);
		    	glVertex2f(1,0.2);
		    	glVertex2f(0.75,1);
			glVertex2f(0.5,0.2);
			glEnd();
			glFlush();
		}
		break;
	default:
		break;
	}
}


int main(int argc,char **argv)
{

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

	glutInitWindowSize(500,500);
	glutInitWindowPosition(200,200);

	glutCreateWindow("Senery");
	glClearColor(255,255,255,1);
	glutDisplayFunc(display);
	glutKeyboardFunc(Keyboard);
	glutMouseFunc(mouse);
	glutMainLoop();
}


//gcc s.c -o s -lGL -lGLU -lglut
