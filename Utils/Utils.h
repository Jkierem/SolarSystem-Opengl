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
  void rotate( float x , float y , float z );
  void rotate( float angle , Vector axis );
  void scale( Vector s );
  void setCamera( Vector eye , Vector center , Vector up );
  void setColor( Vector color );
  void drawPoints( std::vector<Vector> points, Vector color );

  //util utils funks
  std::vector<Vector> getEllipsePoints( float rx , float ry , float segs=720);
  std::vector<Vector> getCirclePoints( float radius , float segs=720 );

  //simplest of figures (orbits)
  void drawCircle( Vector color );

  //simple figures
  void drawPyramid( Vector colors[3] , bool closed=true);
  void drawTrianglePyramid( Vector colors[4] , bool closed=true);
  void drawPrism( Vector colors[6] );
  void drawCube( Vector colors[6] ); //planet with triangle prism moon
  void drawTriangularPrism( Vector colors[5] ); //moon of cube

  //complex figures
  void drawSpinningTop( Vector colors[6] ); //sun
  void drawCross( Vector colors[6] ); //planet with no moons
  void drawOctahedron(Vector colors[2]); //planet with house and star moon
  void drawDreidelish( Vector colors[3] ); //planet with traffic cone moon
  void drawMocho( Vector colors[4]);
  void drawTrafficCone(); //moon of dreidel
  void drawHouse(  Vector colors[6] ); //moon of octahedron
  void drawStar( Vector colors[6] ); //moon of octahedron

} /* Utils */

#endif
