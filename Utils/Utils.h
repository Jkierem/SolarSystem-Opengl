#ifndef __UTILS__H__
#define __UTILS__H__

#include <GL/glut.h>
#include <GL/freeglut.h>
#include <GL/gl.h>

#include <vector>

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

  //util utils funks
  std::vector<Vector> getEllipsePoints( float rx , float ry );
  std::vector<Vector> getCirclePoints( float radius );

  //simplest of figures (orbits)
  void drawEllipse();
  void drawCicrcle();

  //simple figures
  void drawPyramid();
  void drawTrianglePyramid();
  void drawPrism();
  void drawCube(); //planet with triangle prism moon
  void drawTraingularPrism(); //moon of cube

  //complex figures
  void drawSpinningTop(); //sun
  void drawCross(); //planet with no moons
  void drawOctahedron(); //planet with house and star moon
  void drawDreidelish(); //planet with traffic cone moon
  void drawTrafficCone(); //moon of dreidel
  void drawHouse(); //moon of octahedron
  void drawStar(); //moon of octahedron

} /* Utils */

#endif
