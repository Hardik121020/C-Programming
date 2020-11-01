#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
 
void flood_fill4(int x, int y, int* fill_color, int* flood_fill)
{
	float current_color[3];
	glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,current_color);
	if( (current_color[0] == fill_color[0]) || (current_color[1] == fill_color[1]) || (current_color[2] == fill_color[2]) )
	{
		glColor3f(flood_fill[0] , flood_fill[1] , flood_fill[2]);
		glBegin(GL_POINTS);
		glVertex2i(x,y);
		glEnd();
		glFlush(); 
		flood_fill4(x+1 , y , fill_color , flood_fill);
		flood_fill4(x-1 , y , fill_color , flood_fill);
		flood_fill4(x , y+1 , fill_color , flood_fill);
		flood_fill4(x , y-1 , fill_color , flood_fill);
	}
}

void mouse(int btn, int state, int x, int y)
{                        
    if(btn==GLUT_LEFT_BUTTON)                                        
    {
        if(state==GLUT_UP)                                         
        {
            int fCol[3] = {1,0,0};                             
            int color[3] = {0,1,1}; 
	    int xi=101;
	    int yi=101;                           
           
            flood_fill4(xi,yi,color,fCol);
        }
    }
}

void display()
{
	glLineWidth(3);
	glPointSize(2);                              
    	glClear(GL_COLOR_BUFFER_BIT);
    	//glColor3f(1,1,0);                                
    	//glBegin(GL_POLYGON);
	glBegin(GL_LINE_LOOP);
        glColor3f(1,0,0);
         glVertex2i(100,100);
        glVertex2i(100,300);
        glVertex2i(300,300);
        glVertex2i(300,100);
    	glEnd();


    	glFlush();                                 
}
 
int main(int argc, char** argv) 
{
	 
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (600,480);
	glutInitWindowPosition (200,200);
	glutCreateWindow ("Flood Fill Algorithm");
	glClearColor(1.0,1.0,1.0,0.0);
    	glMatrixMode(GL_PROJECTION);
    	gluOrtho2D(0,600,0,480);
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMainLoop();
 	return 0;
}
