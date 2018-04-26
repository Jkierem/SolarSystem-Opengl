#include <GL/glut.h>
#include <GL/freeglut.h>
#include <GL/gl.h>

#include "./Utils/Utils.h"

using namespace Utils;

typedef std::vector<Vector> Orbit;
float timeout = 1000/60;

float angles[5] = {0,0,0,0,0};
float ratios[5] = {1,2,1,4,5};
float sunScale = 1;
float scaleRatio = 0.01;

int positions[4] = {0,0,0,0};
float posRatio[4] = {1,5,1,1};
int posMod[4] = {720,720,720,1440};

int moonPositions[4] = {0,0,0,0};
int moonRatios[4] = {8,4,2,1};

float moonAngles[4] = {0,0,0,0};
float angleRatio[4] = {1,3,0.5,2};


Vector defaultColors[6] = { Vector(1,0,0) , Vector(0,1,0) ,
  Vector(0,0,1) , Vector(1,1,0) , Vector(1,0,1) , Vector(0,1,1) };

void Timer( int i ){
  glutPostRedisplay();
  glutTimerFunc( timeout , Timer, 0);
}

void init(){
  glClearColor(0.0, 0.0, 0.0, 1.0); // Set background (clear) color to black
  glEnable( GL_DEPTH_TEST );
  glutTimerFunc(0, Timer, 0);
}

void draw(){
  translate(Vector(0,0,-1000));
  glPushMatrix();
    rotate(0,angles[0],0);
    scale(Vector(15,15,15));
    scale(Vector(sunScale,sunScale,sunScale));
    drawSpinningTop( defaultColors );
  glPopMatrix();
  Orbit o = getEllipsePoints(500,250);
  Orbit m;
  glPushMatrix();
    rotate(45,0,45);
    drawPoints(o,Vector(1,0,0));
    translate(o[positions[0]]);
    glPushMatrix();
      rotate(0,angles[1],0);
      scale(Vector(25,25,25));
      drawCube(defaultColors);
    glPopMatrix();
    m = getCirclePoints(100);
    rotate(20,0,0);
    drawPoints(m,Vector(0,1,0));
    translate(m[moonPositions[0]]);
    glPushMatrix();
      rotate(0,moonAngles[0],0);
      scale(Vector(5,5,5));
      drawTriangularPrism(defaultColors);
    glPopMatrix();
  glPopMatrix();

  o = getCirclePoints(200);
  glPushMatrix();
    rotate(0,0,90);
    drawPoints(o,Vector(1,1,0));
    translate(o[positions[1]]);
    rotate(0,angles[2],0);
    scale(Vector(5,5,5));
    drawCross(defaultColors);
  glPopMatrix();

  o = getEllipsePoints(300,500);
  glPushMatrix();
    rotate(30,60,0);
    drawPoints(o,Vector(1,0,1));
    translate(o[positions[2]]);
    glPushMatrix();
      rotate(0,angles[3],0);
      scale(Vector(20,20,20));
      drawDreidelish(defaultColors);
    glPopMatrix();
    m = getEllipsePoints(60,120);
    rotate(0,90,0);
    drawPoints(m,Vector(0,0,1));
    translate(m[moonPositions[1]]);
    glPushMatrix();
      rotate(0,moonAngles[1],0);
      scale(Vector(10,10,10));
      drawTrafficCone();
    glPopMatrix();
  glPopMatrix();

  o = getCirclePoints(280,1440);
  glPushMatrix();
    rotate(80,0,0);
    drawPoints(o,Vector(1,0.8,0.8));
    translate(o[positions[3]]);
    glPushMatrix();
      rotate(angles[4],0,90);
      scale(Vector(20,40,20));
      drawOctahedron(defaultColors);
    glPopMatrix();
    m = getEllipsePoints(60,120);
    glPushMatrix();
      rotate(0,90,0);
      drawPoints(m,Vector(0,0,1));
      translate(m[moonPositions[2]]);
      glPushMatrix();
        rotate(0,moonAngles[2],0);
        scale(Vector(10,10,10));
        drawHouse(defaultColors);
      glPopMatrix();
    glPopMatrix();
    m = getEllipsePoints(60,120);

    glPushMatrix();
      rotate(0,0,90);
      drawPoints(m,Vector(0.6,0.4,0.6));
      translate(m[moonPositions[3]]);
      glPushMatrix();
        rotate(0,moonAngles[3],0);
        scale(Vector(10,10,10));
        drawStar(defaultColors);
      glPopMatrix();
    glPopMatrix();
  glPopMatrix();

}

void update(){
  for (int i = 0; i < 5; i++) {
    angles[i] += ratios[i];
  }
  for (int i = 0; i < 4; i++) {
    moonAngles[i] += angleRatio[i];
  }

  for (int i = 0; i < 4; i++) {
    positions[i] += posRatio[i];
    positions[i] = positions[i] % posMod[i];
  }
  for (int i = 0; i < 4; i++) {
    moonPositions[i] += moonRatios[i];
    moonPositions[i] = moonPositions[i] % 720;
  }

  sunScale += scaleRatio;
  if( sunScale >= 5 || sunScale <= 1 ){
    scaleRatio *= -1;
  }

}

void display(){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  draw();
  update();
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
