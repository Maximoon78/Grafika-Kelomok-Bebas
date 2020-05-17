#include <GLFW/glfw3.h>

#include <iostream>
#include <stdlib.h>
#include <GL\freeglut.h>
#include <glm.hpp>
#include <vec2.hpp>
#include <vec3.hpp>
#include <vec4.hpp>
#include <mat4x4.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtc\type_ptr.hpp>


float lx = 0.0f, lz = -1.0f;
float x = 0.0f, z = 5.0f;
float red = 1.0f, blue = 1.0f, green = 1.0f;
float angle = 0.0f;



void init(void) {
	GLfloat mat_specular[] = { 1.0,1.0,1.0,1.0 };
	GLfloat mat_shininess[] = { 50.0 };
	GLfloat light_position[] = { 1.0,1.0,1.0,1.0 };
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}

void changeSize(int w, int h)
{

	if (h == 0)
		h = 1;
	float ratio = w * 1.0 / h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, w, h);
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}
void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION); glLoadIdentity();
	if (w <= h) glOrtho(-1.5, 1.5, -1.5 * (GLfloat)h / (GLfloat)w, 1.5 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
	else glOrtho(-1.5 * (GLfloat)w / (GLfloat)h, 1.5 * (GLfloat)w / (GLfloat)h, -1.5, 1.5, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW); glLoadIdentity();

}
void renderScene(void)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(x, 1.0f, z,
		x + lx, 1.0f, z + lz,
		0.0f, 1.0f, 0.0f);

	//badan depan
	glClearColor(255.0f, 255.0f, 255.0f, 0.0f);
	glColor3f(255.0, 255.75, .35);
	glBegin(GL_POLYGON);
	glVertex3f(0.2, 0.1, 0.0);
	glVertex3f(0.9, 0.1, 0.0);
	glVertex3f(0.9, 0.575, 0.0);
	glVertex3f(0.2, 0.575, 0.0);
	glEnd();

	//badan belakang
	glColor3f(.5, .75, .35);
	glBegin(GL_POLYGON);
	glVertex3f(0.2, 0.1, 0.5);
	glVertex3f(0.9, 0.1, 0.5);
	glVertex3f(0.9, 0.575, 0.5);
	glVertex3f(0.2, 0.575, 0.5);
	glEnd();

	//badan kiri
	glColor3f(.75, 0.75, .25);
	glBegin(GL_POLYGON);
	glVertex3f(0.2, 0.1, 0.5);
	glVertex3f(0.2, 0.1, 0.0);
	glVertex3f(0.2, 0.575, 0.0);
	glVertex3f(0.2, 0.575, 0.5);
	glEnd();

	//badan kanan
	glColor3f(.75, 0.75, .25);
	glBegin(GL_POLYGON);
	glVertex3f(0.9, 0.1, 0.5);
	glVertex3f(0.9, 0.1, 0.0);
	glVertex3f(0.9, 0.575, 0.0);
	glVertex3f(0.9, 0.575, 0.5);
	glEnd();

	//atap kiri
	glColor3f(.5, 0.5, .25);
	glBegin(GL_TRIANGLES);
	glVertex3f(0.9, 0.575, 0.0);
	glVertex3f(0.9, 0.575, 0.5);
	glVertex3f(0.9, 0.8, 0.25);
	glEnd();

	//atap kanan
	glColor3f(.5, 0.5, .25);
	glBegin(GL_TRIANGLES);
	glVertex3f(0.2, 0.575, 0.0);
	glVertex3f(0.2, 0.575, 0.5);
	glVertex3f(0.2, 0.8, 0.25);
	glEnd();

	//atap depan
	glColor3f(.60, 0.35, .2);
	glBegin(GL_POLYGON);
	glVertex3f(0.2, 0.575, 0.0);
	glVertex3f(0.9, 0.575, 0.0);
	glVertex3f(0.9, 0.8, 0.25);
	glVertex3f(0.2, 0.8, 0.25);
	glEnd();

	//atap belaakang
	glColor3f(.50, 0.35, .2);
	glBegin(GL_POLYGON);
	glVertex3f(0.2, 0.575, 0.5);
	glVertex3f(0.9, 0.575, 0.5);
	glVertex3f(0.9, 0.8, 0.25);
	glVertex3f(0.2, 0.8, 0.25);
	glEnd();

	//pintu
	glColor3f(.15, 0.2, .3);
	glBegin(GL_POLYGON);
	glVertex3f(0.47, 0.105, 0.0);
	glVertex3f(0.65, 0.105, 0.0);
	glVertex3f(0.65, 0.46, 0.0);
	glVertex3f(0.47, 0.46, 0.0);
	glEnd();

	//jendela 1
	glColor3f(.3, 0.2, .1);
	glBegin(GL_POLYGON);
	glVertex3f(0.72, 0.25, 0.0);
	glVertex3f(0.83, 0.25, 0.0);
	glVertex3f(0.83, 0.4, 0.0);
	glVertex3f(0.72, 0.4, 0.0);
	glEnd();

	//jendela 2
	glColor3f(.3, 0.2, .1);
	glBegin(GL_POLYGON);
	glVertex3f(0.27, 0.25, 0.0);
	glVertex3f(0.38, 0.25, 0.0);
	glVertex3f(0.38, 0.4, 0.0);
	glVertex3f(0.27, 0.4, 0.0);
	glEnd();

	glutSwapBuffers();
}

void processNormalKeys(unsigned char key, int x, int y)
{

	if (key == 27)
		exit(0);
}

void processSpecialKeys(int key, int xx, int yy)
{

	float fraction = 0.1f;

	switch (key) {
	case GLUT_KEY_LEFT:
		angle -= 0.06f;
		lx = sin(angle);
		lz = -cos(angle);
		break;
	case GLUT_KEY_RIGHT:
		angle += 0.06f;
		lx = sin(angle);
		lz = -cos(angle);
		break;
	case GLUT_KEY_UP:
		x += lx * fraction;
		z += lz * fraction;
		break;
	case GLUT_KEY_DOWN:
		x -= lx * fraction;
		z -= lz * fraction;
		break;
	}
}

int main(int argc, char** argv)
{

	

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1000, 800);
	glutCreateWindow("Tugas Grafika");

	
	glutDisplayFunc(renderScene);
	glutReshapeFunc(reshape);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);

	
	glEnable(GL_DEPTH_TEST);

	
	glutMainLoop();

	return 1;
}