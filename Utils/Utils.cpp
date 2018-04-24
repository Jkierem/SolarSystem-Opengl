#include "Utils.h"

Vector::Vector(){}
Vector::Vector( float x , float y , float z ){
  this->x = x;
  this->y = y;
  this->z = z;
}

void Utils::translate( Vector t ){
  glTranslatef( t.x , t.y , t.z );
}

void Utils::rotate( Vector r ){
  glRotatef( r.x , 1 , 0 , 0 );
  glRotatef( r.y , 0 , 1 , 0 );
  glRotatef( r.z , 0 , 0 , 1 );
}

void Utils::scale( Vector s ){
  glScalef( s.x , s.y , s.z );
}

void setCamera( Vector eye , Vector center , Vector up ){
  glMatrixMode( GL_MODELVIEW );
  glLoadIdentity();
  gluLookAt( eye.x , eye.y , eye.z ,
             center.x, center.y , center.z ,
             up.x , up.y , up.z );
}

//util utils funks
std::vector<Vector> Utils::getEllipsePoints( float rx , float ry ){
  std::vector<Vector> v;
  return v;
}
std::vector<Vector> Utils::getCirclePoints( float radius ){
  std::vector<Vector> v;
  return v;
}

//simplest of figures (orbits)
void Utils::drawEllipse(){}
void Utils::drawCicrcle(){}

//simple figures
void Utils::drawPyramid(){
  glBegin(GL_QUADS);
    glVertex3f(-1,0,1);
    glVertex3f(1,0,1);
    glVertex3f(1,0,-1);
    glVertex3f(-1,0,-1);
  glEnd();
  glBegin(GL_TRIANGLES);
    glVertex3f(-1,0,1);
    glVertex3f(1,0,1);
    glVertex3f(0,1,0);

    glVertex3f(1,0,1);
    glVertex3f(1,0,-1);
    glVertex3f(0,1,0);

    glVertex3f(1,0,-1);
    glVertex3f(-1,0,-1);
    glVertex3f(0,1,0);

    glVertex3f(-1,0,-1);
    glVertex3f(-1,0,1);
    glVertex3f(0,1,0);
  glEnd();
}
void Utils::drawTrianglePyramid(){}
void Utils::drawPrism(){}
void Utils::drawCube(){}
void Utils::drawTraingularPrism(){}

//complex figures
void Utils::drawSpinningTop(){}
void Utils::drawCross(){}
void Utils::drawOctahedron(){}
void Utils::drawDreidelish(){}
void Utils::drawTrafficCone(){}
void Utils::drawHouse(){}
void Utils::drawStar(){}
