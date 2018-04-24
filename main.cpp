#include <GL/glut.h>
#include <GL/freeglut.h>
#include <GL/gl.h>

#include "./Utils/Utils.h"

void Timer( int i ){
  glutPostRedisplay();
  glutTimerFunc( 1000, Timer, 0);
}

void init(){
  glClearColor(0.0, 0.0, 0.0, 1.0); // Set background (clear) color to black
  glEnable( GL_DEPTH_TEST );
  glutTimerFunc(0, Timer, 0);
}

void display(){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  glColor3f(1,0,0);
  Utils::rotate(Vector(0,0,90));
  Utils::translate(Vector(0,0,-10));
  Utils::scale(Vector(1,2,1));
  Utils::drawPyramid();
  glutSwapBuffers();
}

void reshape( int width , int height ){
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0f, (GLfloat)width/(GLfloat)height, 1.0f, 6000.0f);
  glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char *argv[]) {

  //Initial display and window config
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(600,600);
  glutCreateWindow("Sistema Solar!");

  init();

  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();

  return 0;
}
