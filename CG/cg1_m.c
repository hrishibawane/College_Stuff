#include <GL/glut.h>  // GLUT, includes glu.h and gl.h
#include <stdio.h>
 
double xx1, yy1, xx2, yy2;
int first=0;
void plot(double xx1, double yy1, double xx2, double yy2)
{
	
	double dx = abs(xx2-xx1);
	double dy = abs(yy2-yy1);
	double len = (dy>=dx) ? dy : dx;
	double xinc = (xx2-xx1)/len;
	double yinc = (yy2-yy1)/len;
	int i=0;
	do
	{
      	glColor3f(0.0, 0.0, 1.0);
		glBegin(GL_POINTS);
			glVertex2i(xx1, yy1);
		glEnd();
        
		xx1+=xinc;
        yy1+=yinc;
		i++;
		
		glFlush();

	} while(i<=len);

	glFlush();
}

void mouse(int button, int state, int x, int y)
{
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		switch(first)
		{
			case 0: xx1=x-640;
					yy1=y-480;
					first=1;
					break;
			case 1: xx2=x-640;
					yy2=y-480;
					
					glColor3f(1.0,0.0,1.0);
					glClear(GL_COLOR_BUFFER_BIT); 
					plot(xx1, yy1, xx1, yy2);
					plot(xx1, yy2, xx2, yy2);
					plot(xx2, yy2, xx2, yy1);
					plot(xx2, yy1, xx1, yy1);

					plot(xx1, (yy1+yy2)/2, (xx1+xx2)/2, yy2);
					plot((xx1+xx2)/2, yy2, xx2, (yy1+yy2)/2);
					plot(xx2, (yy1+yy2)/2, (xx1+xx2)/2, yy1);
					plot((xx1+xx2)/2, yy1, xx1, (yy1+yy2)/2);

					plot((3*xx1+xx2)/4, (yy1+3*yy2)/4, (xx1+3*xx2)/4, (yy1+3*yy2)/4);
					plot((xx1+3*xx2)/4, (yy1+3*yy2)/4, (xx1+3*xx2)/4, (3*yy1+yy2)/4);
					plot((xx1+3*xx2)/4, (3*yy1+yy2)/4, (3*xx1+xx2)/4, (3*yy1+yy2)/4);
					plot((3*xx1+xx2)/4, (3*yy1+yy2)/4, (3*xx1+xx2)/4, (yy1+3*yy2)/4);
					
					glFlush();
					first=0;
					break;
					
		}
	}
}

void init(void)
{
	glClearColor(0.0,0.0,0.0,0.0);
    glColor3f(1.0,0.0,0.0);
    gluOrtho2D(-640.0,640.0,-480.0,480.0);
}



int main(int argc, char** argv)    
{

	glutInit(&argc, argv);                     
    glutCreateWindow("OpenGL BASICS ");        
    glutInitWindowSize(640,480);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
	glutMouseFunc(mouse);
    init();  
    glutMainLoop();          
    return 0;

}
