#include <GL/glut.h>  // GLUT, includes glu.h and gl.h
#include <stdio.h>
 

double xx1, yy1, xx2, yy2;
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
      glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POINTS);
			glVertex2i(xx1, yy1);
		glEnd();
        
		xx1+=xinc;
		yy1+=yinc;
		i++;
		glFlush();

	} while(i<=len);

	
}

void display()
{
    glColor3f(1.0,0.0,1.0); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer
 
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
					
 
}

void init(void)
{
	glClearColor(0.0,0.0,0.0,0.0);
    glColor3f(1.0,0.0,0.0);
    gluOrtho2D(0.0,640.0,0.0,480.0);
}


/* Main function: GLUT runs as a console application starting at main()  */

int main(int argc, char** argv)    //argc...arg count can get number a & argv arg vector can get values of passed arguments 
{
    printf("\nEnter x1, y1, x2, y2: ");
	scanf("%lf %lf %lf %lf", &xx1, &yy1, &xx2, &yy2);

	glutInit(&argc, argv);                     // Initialize GLUT
    glutCreateWindow("OpenGL BASICS ");        // Create a window with the given title
    glutInitWindowSize(640,480);//t the window's initial width & height
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);//tion the window's initial top-left corner
    init();  
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop();           // Enter the infinitely event-processing loop
    return 0;

}




