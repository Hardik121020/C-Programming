#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/freeglut.h>
#include<stdio.h>
#include<float.h>
struct P 
{
	int x,y;
}p[20],p1[20];

int n;
int xmin,ymin,xmax,ymax;
int i,j;
float m;

void clipl()
{
    	i = 0; j = 0;
    	for(i=0;i<n;i++)
    	{
        	if(p[(i+1)%n].x - p[i].x != 0)
        	{
        	    	m = (p[(i+1)%n].y - p[i].y)*(1.0/(p[(i+1)%n].x-p[i].x));
        	}
        	else
        	{
        		m = FLT_MAX;            
        	}
        	if(p[i].x<xmin && p[(i+1)%n].x>=xmin) //OUT to IN
        	{   
            		p1[j].x = xmin;
            		p1[j].y = p[i].y+m*(xmin-p[i].x);
            		j++;
            		p1[j].x = p[(i+1)%n].x;
            		p1[j].y = p[(i+1)%n].y;
            		j++;
        	}
        	if(p[i].x>=xmin && p[(i+1)%n].x>=xmin)//IN to IN
        	{
            		p1[j].x = p[(i+1)%n].x;
            		p1[j].y = p[(i+1)%n].y;
            		j++;          
        	}
        	if(p[i].x>=xmin && p[(i+1)%n].x<xmin) //IN to OUT
        	{   
            		p1[j].x = xmin;
            		p1[j].y = p[i].y+m*(xmin-p[i].x);
            	j++;
        	}
    	}
    
    	for(i=0;i<j;i++)
    	{
        	p[i].x = p1[i].x;
        	p[i].y = p1[i].y;
        	p1[i].x = p1[i].y = 0;
    	}
    	if(j<n)
    	{
        	for(;i<n;i++)
        	{
            		p[i].x = p[i].y = 0;
        	}  
    	}  
   	n=j;
   
}

void clipr()
{
	i = 0; j = 0;
    	for(i=0;i<n;i++)
    	{

            	if(p[(i+1)%n].x - p[i].x != 0)
            	{
                	m = (p[(i+1)%n].y - p[i].y)*(1.0/(p[(i+1)%n].x-p[i].x));
                
            	}
            	else
            	{
                	m = FLT_MAX;
            	}

        	if(p[i].x>xmax && p[(i+1)%n].x<=xmax) //OUT to IN
        	{   
            		p1[j].x = xmax;
            		p1[j].y = p[i].y+m*(xmax-p[i].x);
            		j++;
            		p1[j].x = p[(i+1)%n].x;
            		p1[j].y = p[(i+1)%n].y;
            		j++;
        	}

        	if(p[i].x<=xmax && p[(i+1)%n].x<=xmax)//IN to IN
        	{
            		p1[j].x = p[(i+1)%n].x;
            		p1[j].y = p[(i+1)%n].y;
            		j++;          
        	}

        	if(p[i].x<=xmax && p[(i+1)%n].x>xmax) //IN to OUT
        	{   
        	    	p1[j].x = xmax;
            		p1[j].y = p[i].y+m*(xmax-p[i].x);
            		j++;
        	}
    	}
    
    	for(i=0;i<j;i++)
    	{
    		p[i].x = p1[i].x;
        	p[i].y = p1[i].y;
        	p1[i].x = p1[i].y = 0;

    	}
    	if(j<n)
    	{
    	    	for(;i<n;i++)
        	{
            		p[i].x = p[i].y = 0;
        	}  
    	}  
   	n=j;
}


void clipt()
{
    	i = 0; j = 0;
    	for(i=0;i<n;i++)
    	{
        	if(p[(i+1)%n].x - p[i].x != 0)
        	{
            		m = (p[(i+1)%n].y - p[i].y)*(1.0/(p[(i+1)%n].x-p[i].x));  
        	}
        	else
            	{
                	m = FLT_MAX;
            	}
        	if(p[i].y>ymax && p[(i+1)%n].y<=ymax) //OUT to IN
        	{   
            		p1[j].x = p[i].x +((ymax-p[i].y)/m);
            		p1[j].y = ymax;
            		j++;
            		p1[j].x = p[(i+1)%n].x;
            		p1[j].y = p[(i+1)%n].y;
            		j++;
        	}
        	if(p[i].y<=ymax && p[(i+1)%n].y<=ymax)//IN to IN
        	{
            		p1[j].x = p[(i+1)%n].x;
            		p1[j].y = p[(i+1)%n].y;
            		j++;          
        	}
        	if(p[i].y<=ymax && p[(i+1)%n].y>ymax) //IN to OUT
        	{   
            		p1[j].x = p[i].x +((ymax-p[i].y)/m);
            		p1[j].y = ymax;
            		j++;
        	}
    	}
    	for(i=0;i<j;i++)
    	{
        	p[i].x = p1[i].x;
        	p[i].y = p1[i].y;
        	p1[i].x = p1[i].y = 0;

    	}
    	if(j<n)
    	{
        	for(;i<n;i++)
        	{
            		p[i].x = p[i].y = 0;
        	}  
    	}  
   	n=j;
}

void clipb()
{
    	i = 0; j = 0;
    	for(i=0;i<n;i++)
    	{
        	if(p[(i+1)%n].x - p[i].x != 0)
        	{
            		m = (p[(i+1)%n].y - p[i].y)*(1.0/(p[(i+1)%n].x-p[i].x));
                
         	}
        	else
            	{
                	m = FLT_MAX;
               
            	}
        	if(p[i].y<ymin && p[(i+1)%n].y>=ymin) //OUT to IN
        	{   
            		p1[j].x = p[i].x +((ymin-p[i].y)/m);
            		p1[j].y = ymin;
            		j++;
            		p1[j].x = p[(i+1)%n].x;
            		p1[j].y = p[(i+1)%n].y;
            		j++;
        	}
        	if(p[i].y>=ymin && p[(i+1)%n].y>=ymin)//IN to IN
        	{
            		p1[j].x = p[(i+1)%n].x;
            		p1[j].y = p[(i+1)%n].y;
            		j++;          
        	}
        	if(p[i].y>=ymin && p[(i+1)%n].y<ymin) //IN to OUT
        	{   
            		p1[j].x = p[i].x +((ymin-p[i].y)/m);
            		p1[j].y = ymin;
            		j++;
        	}
    	}
    	for(i=0;i<j;i++)
    	{
        	p[i].x = p1[i].x;
        	p[i].y = p1[i].y;
        	p1[i].x = p1[i].y = 0;

    	}
    	if(j<n)
    	{
        	for(i=j;i<n;i++)
        	{
            		p[i].x = p[i].y = 0;
        	}  
    	}  
   	n=j;
}

void draw_poly()
{    
    	glColor3f(0.0,0.0,1.0);

	glBegin(GL_LINES);
	glVertex2f(150,290);
	glVertex2f(155,300);
	glEnd();

	glBegin(GL_LINE_STRIP);
	

        for(i = 0;i<n;i++)
        {
            glVertex2f(p[i].x,p[i].y);
        }
    	glEnd();
}

void draw_poly1()
{    
    	glColor3f(0.0,0.0,1.0);
	glBegin(GL_LINE_STRIP);
        for(i = 0;i<n+1;i++)
        {
            glVertex2f(p[i].x,p[i].y);
        }
    	glEnd();
}

void my_keyboard(unsigned char key, int x, int y)
{
    
	if(key)
	{
        	glClear(GL_COLOR_BUFFER_BIT);
        	glColor3f(1.0,0.0,0.0);
        	glBegin(GL_LINE_LOOP);
        	glVertex2f(xmin,ymin);
        	glVertex2f(xmax,ymin);
        	glVertex2f(xmax,ymax);
        	glVertex2f(xmin,ymax);
        	glEnd();
        	clipl();
        	clipt();
        	clipr();
        	clipb();
	       	draw_poly();

    	}
    	glFlush();
}

void display()
{
    
    	glClear(GL_COLOR_BUFFER_BIT);
    	glColor3f(1.0,0.0,0.0);
        glBegin(GL_LINE_LOOP);
        glVertex2f(xmin,ymin);
        glVertex2f(xmax,ymin);
        glVertex2f(xmax,ymax);
        glVertex2f(xmin,ymax);
    	glEnd();
    	draw_poly1();
    	glFlush();
}
void init()
{
    	glClearColor(0.364, 0.913, 0.976, 0.976);
    	gluOrtho2D(0,500,0,500);
}

int main(int argc, char** argv)
{   
    
    	printf("enter the xmin and ymin : ");
    	scanf("%d %d",&xmin,&ymin);
    	printf("enter the xmax and ymax : ");
    	scanf("%d %d",&xmax,&ymax);
    	printf("enter the no. of vertices: ");
    	scanf("%d",&n);
    	for( i = 0; i<n; i++)
    	{
        	printf("enter value of vertex %d: ",i+1);
        	printf("\n enter the value of x co.: ");
        	scanf("%d",&p[i].x);
        	printf(" enter the value of y co.: ");
        	scanf("%d",&p[i].y);
    	}
    	p[i].x = p[0].x;
    	p[i].y = p[0].y;

    	glutInit(&argc,argv);
    	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    	glutInitWindowSize(500,500);
    	glutInitWindowPosition(200,200);
    	glutCreateWindow("Polygon clipping algorithm(Sutherland Hogdman)");
    	init();
    	glutDisplayFunc(display);
    	glutKeyboardFunc(my_keyboard);
    	glutMainLoop();
    	return 0;
}

























