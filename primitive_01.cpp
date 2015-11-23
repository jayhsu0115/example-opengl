/*
 * Draw a triangle and a quad.
 */
#include <GL/glut.h>

void init(void) {
	glShadeModel(GL_SMOOTH); // smooth shading
	glClearColor(1.0, 1.0, 1.0, 0.0); // white, alpha 0
}

void triangle(void) {
	glLoadIdentity(); // reset the model-view matrix
	glTranslatef(0.0, 0.0, -4.0); //
	glBegin(GL_TRIANGLES);
	glColor4f(1.0, 0.0, 0.0, 0.0);
	glVertex3f(0.1, 0.9, 0.0);
	glColor4f(0.0, 1.0, 0.0, 0.0);
	glVertex3f(0.1, 0.1, 0.0);
	glColor4f(0.0, 0.0, 1.0, 0.0);
	glVertex3f(0.7, 0.5, 0.0);
	glEnd();
}

void quad(void) {
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -4.0);

	glBegin(GL_QUADS);
	glColor4f(1.0, 0.0, 0.0, 0.0);     // Red
	glVertex3f(0.8, 0.1, 0.0);
	glVertex3f(0.8, 0.9, 0.0);
	glVertex3f(1.6, 0.9, 0.0);
	glVertex3f(1.6, 0.1, 0.0);
	glEnd();
}

void reshape(int w, int h) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0, w / (GLfloat) h, 3.0, 90.0);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, w, h);  //Use the whole window for rendering
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	quad();
	triangle();
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("Draw Triangles");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();

	return EXIT_SUCCESS;
}
