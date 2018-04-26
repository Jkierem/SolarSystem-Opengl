#ifndef __UTILS__H__
#define __UTILS__H__

#include <GL/glut.h>
#include <GL/freeglut.h>
#include <GL/gl.h>

#include <vector>
#include <cmath>

struct Vector{
  float x;
  float y;
  float z;
  Vector();
  Vector( float x , float y , float z );
};

namespace Utils {

  //transformaciones
  void translate( Vector t );
  void rotate( Vector r );
  void scale( Vector s );
  void setCamera( Vector eye , Vector center , Vector up );
  void setColor( Vector color );

  //util utils funks
  std::vector<Vector> getEllipsePoints( float rx , float ry , float segs=720);
  std::vector<Vector> getCirclePoints( float radius , float segs=720 );

  //simplest of figures (orbits)
  void drawCircle();

  //simple figures
  void drawPyramid( Vector colors[5] );
  void drawTrianglePyramid( Vector colors[4] );
  void drawPrism( Vector colors[6] );
  void drawCube( Vector colors[6] ); //planet with triangle prism moon
  void drawTriangularPrism( Vector colors[5] ); //moon of cube

  //complex figures
  void drawSpinningTop( Vector colors[6] ); //sun
  void drawCross( Vector colors[6] ); //planet with no moons
  void drawOctahedron(); //planet with house and star moon
  void drawDreidelish(); //planet with traffic cone moon
  void drawMocho( Vector colors[4]);
  void drawTrafficCone(); //moon of dreidel
  void drawHouse(  Vector colors[6] ); //moon of octahedron
  void drawStar( Vector colors[6] ); //moon of octahedron

} /* Utils */

#endif
