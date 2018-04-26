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

void Utils::setCamera( Vector eye , Vector center , Vector up ){
  glMatrixMode( GL_MODELVIEW );
  glLoadIdentity();
  gluLookAt( eye.x , eye.y , eye.z ,
             center.x, center.y , center.z ,
             up.x , up.y , up.z );
}

void Utils::setColor( Vector color ){
  glColor3f( color.x , color.y , color.z );
}

//util utils funks
std::vector<Vector> Utils::getEllipsePoints( float rx , float ry , float segs ){
  std::vector<Vector> v;
  for( float angle = 0.0f; angle <= (2.0f*M_PI); angle += (2.f*M_PI/segs)){
    float x = cos(angle)*rx;
    float y = sin(angle)*ry;
    Vector p(x,y,0);
    v.push_back(p);
  }
  return v;
}

std::vector<Vector> Utils::getCirclePoints( float radius , float segs ){
  return Utils::getEllipsePoints(radius,radius,segs);
}

//simplest of figures (orbits)
void Utils::drawCircle(){
  std::vector<Vector> v = Utils::getEllipsePoints(1,1);
  glBegin( GL_POINTS );
  for( int i = 0 ; i < v.size() ; i++ ){
    Vector p = v[i];
    glVertex3f(p.x,p.y,p.z);
  }
  glEnd();
}

//simple figures
void Utils::drawPyramid( Vector colors[5] ){
  glBegin(GL_QUADS);
    setColor( colors[0] );
    glVertex3f(-1,0,1);
    glVertex3f(1,0,1);
    glVertex3f(1,0,-1);
    glVertex3f(-1,0,-1);
  glEnd();
  glBegin(GL_TRIANGLES);
    setColor( colors[1] );
    glVertex3f(-1,0,1);
    glVertex3f(1,0,1);
    glVertex3f(0,1,0);

    setColor( colors[2] );
    glVertex3f(1,0,1);
    glVertex3f(1,0,-1);
    glVertex3f(0,1,0);

    setColor( colors[3] );
    glVertex3f(1,0,-1);
    glVertex3f(-1,0,-1);
    glVertex3f(0,1,0);

    setColor( colors[4] );
    glVertex3f(-1,0,-1);
    glVertex3f(-1,0,1);
    glVertex3f(0,1,0);
  glEnd();
}

void Utils::drawTrianglePyramid( Vector colors[4] ){
  float root2 = sqrt(2);
  glBegin(GL_TRIANGLES);
    setColor( colors[0] );
    glVertex3f(0,0,1);
    glVertex3f(-root2,0,-root2);
    glVertex3f(root2,0,-root2);

    setColor( colors[1] );
    glVertex3f(0,0,1);
    glVertex3f(-root2,0,-root2);
    glVertex3f(0,root2,0);

    setColor( colors[2] );
    glVertex3f(-root2,0,-root2);
    glVertex3f(root2,0,-root2);
    glVertex3f(0,root2,0);

    setColor( colors[3] );
    glVertex3f(root2,0,-root2);
    glVertex3f(0,0,1);
    glVertex3f(0,root2,0);

  glEnd();
}

void Utils::drawPrism( Vector colors[6] ){
  glBegin(GL_QUADS);

    setColor( colors[0] );
    glVertex3f(-2,1,-1);
    glVertex3f(-2,1,1);
    glVertex3f(-2,-1,1);
    glVertex3f(-2,-1,-1);

    setColor( colors[1] );
    glVertex3f(2,1,-1);
    glVertex3f(2,1,1);
    glVertex3f(2,-1,1);
    glVertex3f(2,-1,-1);

    setColor( colors[2] );
    glVertex3f(-2,1,1);
    glVertex3f(-2,-1,1);
    glVertex3f(2,-1,1);
    glVertex3f(2,1,1);

    setColor( colors[3] );
    glVertex3f(-2,1,-1);
    glVertex3f(-2,-1,-1);
    glVertex3f(2,-1,-1);
    glVertex3f(2,1,-1);

    setColor( colors[4] );
    glVertex3f(2,1,1);
    glVertex3f(2,1,-1);
    glVertex3f(-2,1,-1);
    glVertex3f(-2,1,1);

    setColor( colors[5] );
    glVertex3f(2,-1,1);
    glVertex3f(2,-1,-1);
    glVertex3f(-2,-1,-1);
    glVertex3f(-2,-1,1);

  glEnd();
}

void Utils::drawCube( Vector colors[6] ){
  glBegin(GL_QUADS);

    setColor( colors[0] );
    glVertex3f(-1,1,-1);
    glVertex3f(-1,1,1);
    glVertex3f(-1,-1,1);
    glVertex3f(-1,-1,-1);

    setColor( colors[1] );
    glVertex3f(1,1,-1);
    glVertex3f(1,1,1);
    glVertex3f(1,-1,1);
    glVertex3f(1,-1,-1);

    setColor( colors[2] );
    glVertex3f(-1,1,1);
    glVertex3f(-1,-1,1);
    glVertex3f(1,-1,1);
    glVertex3f(1,1,1);

    setColor( colors[3] );
    glVertex3f(-1,1,-1);
    glVertex3f(-1,-1,-1);
    glVertex3f(1,-1,-1);
    glVertex3f(1,1,-1);

    setColor( colors[4] );
    glVertex3f(1,1,1);
    glVertex3f(1,1,-1);
    glVertex3f(-1,1,-1);
    glVertex3f(-1,1,1);

    setColor( colors[5] );
    glVertex3f(1,-1,1);
    glVertex3f(1,-1,-1);
    glVertex3f(-1,-1,-1);
    glVertex3f(-1,-1,1);

  glEnd();
}

void Utils::drawTriangularPrism( Vector colors[5] ){
  float root2 = sqrt(2);
  glBegin(GL_TRIANGLES);
    setColor( colors[0] );
    glVertex3f(-2,1,0);
    glVertex3f(-2,-root2,-root2);
    glVertex3f(-2,-root2,root2);

    setColor( colors[1] );
    glVertex3f(2,1,0);
    glVertex3f(2,-root2,-root2);
    glVertex3f(2,-root2,root2);
  glEnd();

  glBegin(GL_QUADS);
    setColor( colors[2] );
    glVertex3f(2,-root2,-root2);
    glVertex3f(2,-root2,root2);
    glVertex3f(-2,-root2,root2);
    glVertex3f(-2,-root2,-root2);

    setColor( colors[3] );
    glVertex3f(2,1,0);
    glVertex3f(2,-root2,-root2);
    glVertex3f(-2,-root2,-root2);
    glVertex3f(-2,1,0);

    setColor( colors[4] );
    glVertex3f(2,1,0);
    glVertex3f(2,-root2,root2);
    glVertex3f(-2,-root2,root2);
    glVertex3f(-2,1,0);

  glEnd();
}

//complex figures
void Utils::drawSpinningTop( Vector colors[6] ){
  float root1 = sqrt(1);
  glBegin(GL_TRIANGLES);
    setColor( colors[0] );
    glVertex3f(0,root1,0);
    glVertex3f(0,0,1);
    glVertex3f(-root1,0,-root1);

    setColor( colors[1] );
    glVertex3f(0,root1,0);
    glVertex3f(0,0,1);
    glVertex3f(root1,0,-root1);

    setColor( colors[2] );
    glVertex3f(0,root1,0);
    glVertex3f(root1,0,-root1);
    glVertex3f(-root1,0,-root1);

    setColor( colors[3] );
    glVertex3f(0,-root1,0);
    glVertex3f(0,0,1);
    glVertex3f(-root1,0,-root1);

    setColor( colors[4] );
    glVertex3f(0,-root1,0);
    glVertex3f(0,0,1);
    glVertex3f(root1,0,-root1);

    setColor( colors[5] );
    glVertex3f(0,-root1,0);
    glVertex3f(root1,0,-root1);
    glVertex3f(-root1,0,-root1);

  glEnd();
}

void Utils::drawCross( Vector colors[6]){
    glBegin(GL_POLYGON);

      setColor( colors [0] );
      glVertex3f(-1,1,1);
      glVertex3f(-1,2,1);
      glVertex3f(1,2,1);
      glVertex3f(1,1,1);
      glVertex3f(2,1,1);
      glVertex3f(2,-1,1);
      glVertex3f(1,-1,1);
      glVertex3f(1,-2,1);
      glVertex3f(-1,-2,1);
      glVertex3f(-1,-1,1);
      glVertex3f(-2,-1,1);
      glVertex3f(-2,1,1);

    glEnd();

    glBegin(GL_POLYGON);

      setColor( colors [1] );
      glVertex3f(-1,1,-1);
      glVertex3f(-1,2,-1);
      glVertex3f(1,2,-1);
      glVertex3f(1,1,-1);
      glVertex3f(2,1,-1);
      glVertex3f(2,-1,-1);
      glVertex3f(1,-1,-1);
      glVertex3f(1,-2,-1);
      glVertex3f(-1,-2,-1);
      glVertex3f(-1,-1,-1);
      glVertex3f(-2,-1,-1);
      glVertex3f(-2,1,-1);

    glEnd();

    glBegin(GL_QUADS);

      setColor( colors[2] );
      glVertex3f(-1,1,1);
      glVertex3f(-1,2,1);
      glVertex3f(-1,2,-1);
      glVertex3f(-1,1,-1);

      setColor( colors[3] );
      glVertex3f(-1,2,1);
      glVertex3f(1,2,1);
      glVertex3f(1,2,-1);
      glVertex3f(-1,2,-1);

      setColor( colors[4] );
      glVertex3f(1,2,1);
      glVertex3f(1,1,1);
      glVertex3f(1,1,-1);
      glVertex3f(1,2,-1);

      setColor( colors[5] );
      glVertex3f(1,1,1);
      glVertex3f(2,1,1);
      glVertex3f(2,1,-1);
      glVertex3f(1,1,-1);

      setColor( colors[2] );
      glVertex3f(2,1,1);
      glVertex3f(2,-1,1);
      glVertex3f(2,-1,-1);
      glVertex3f(2,1,-1);

      setColor( colors[3] );
      glVertex3f(2,-1,1);
      glVertex3f(1,-1,1);
      glVertex3f(1,-1,-1);
      glVertex3f(2,-1,-1);

      setColor( colors[4] );
      glVertex3f(1,-1,1);
      glVertex3f(1,-2,1);
      glVertex3f(1,-2,-1);
      glVertex3f(1,-1,-1);

      setColor( colors[5] );
      glVertex3f(1,-2,1);
      glVertex3f(-1,-2,1);
      glVertex3f(-1,-2,-1);
      glVertex3f(1,-2,-1);

      setColor( colors[2] );
      glVertex3f(-1,-2,1);
      glVertex3f(-1,-1,1);
      glVertex3f(-1,-1,-1);
      glVertex3f(-1,-2,-1);

      setColor( colors[3] );
      glVertex3f(-1,-1,1);
      glVertex3f(-2,-1,1);
      glVertex3f(-2,-1,-1);
      glVertex3f(-1,-1,-1);

      setColor( colors[4] );
      glVertex3f(-2,-1,1);
      glVertex3f(-2,1,1);
      glVertex3f(-2,1,-1);
      glVertex3f(-2,-1,-1);

      setColor( colors[5] );
      glVertex3f(-1,1,1);
      glVertex3f(-2,1,1);
      glVertex3f(-2,1,-1);
      glVertex3f(-1,1,-1);
    glEnd();
}

void Utils::drawOctahedron(){}
void Utils::drawDreidelish(){}

void Utils::drawMocho( Vector colors[4] ){
  glBegin(GL_TRIANGLES);
    setColor( colors[0] );
    glVertex3f(0,2,0);
    setColor( colors[1] );
    glVertex3f(0,0,1);
    glVertex3f(1,0,0);

    setColor( colors[2] );
    glVertex3f(0,0,1);
    glVertex3f(1,0,0);
    glVertex3f(1,0,1);
  glEnd();

  glBegin(GL_QUADS);
    glVertex3f(1,0,0);
    glVertex3f(1,0,1);
    glVertex3f(1,-0.25,1);
    glVertex3f(1,-0.25,0);

    glVertex3f(0,0,1);
    glVertex3f(1,0,1);
    glVertex3f(1,-0.25,1);
    glVertex3f(0,-0.25,1);

    setColor(colors[3]);
    glVertex3f(0,-0.25,0);
    glVertex3f(0,-0.25,1);
    glVertex3f(1,-0.25,1);
    glVertex3f(1,-0.25,0);
  glEnd();

}

void Utils::drawTrafficCone(){
  Vector c[4] = { Vector(1,0.75,0),Vector(1,0,0),Vector(1,0,0),Vector(0.8,0.2,0)};
  glPushMatrix();
  for( int i = 0 ; i < 4 ; i++ ){
    drawMocho(c);
    rotate(Vector(0,90,0));
  }
  glPopMatrix();
}

void Utils::drawHouse( Vector colors[6] ){
  glBegin(GL_POLYGON);
    setColor( colors[0] );
    glVertex3f(0,2,1);
    glVertex3f(1,1,1);
    glVertex3f(1,-1,1);
    glVertex3f(-1,-1,1);
    glVertex3f(-1,1,1);
  glEnd();

  glBegin(GL_POLYGON);
    setColor( colors[1] );
    glVertex3f(0,2,-1);
    glVertex3f(1,1,-1);
    glVertex3f(1,-1,-1);
    glVertex3f(-1,-1,-1);
    glVertex3f(-1,1,-1);
  glEnd();

  glBegin(GL_QUADS);
    setColor(colors[2]);
    glVertex3f(0,2,-1);
    setColor(colors[3]);
    glVertex3f(1,1,-1);
    glVertex3f(1,1,1);
    setColor(colors[2]);
    glVertex3f(0,2,1);
    setColor(colors[3]);

    glVertex3f(1,1,-1);
    glVertex3f(1,-1,-1);
    glVertex3f(1,-1,1);
    glVertex3f(1,1,1);

    setColor(colors[2]);
    glVertex3f(0,2,-1);
    setColor(colors[4]);
    glVertex3f(-1,1,-1);
    glVertex3f(-1,1,1);
    setColor(colors[2]);
    glVertex3f(0,2,1);
    setColor(colors[4]);

    glVertex3f(-1,1,-1);
    glVertex3f(-1,-1,-1);
    glVertex3f(-1,-1,1);
    glVertex3f(-1,1,1);

    setColor( colors[5] );
    glVertex3f(-1,-1,-1);
    glVertex3f(1,-1,-1);
    glVertex3f(1,-1,1);
    glVertex3f(-1,-1,1);

  glEnd();

}

void Utils::drawStar( Vector colors[6] ){
  drawCube( colors );
  rotate(Vector(45,0,0));
  drawCube( colors );
}
