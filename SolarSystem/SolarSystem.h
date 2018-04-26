#ifndef __SOLARSYSTEM__H__
#define __SOLARSYSTEM__H__

#include <GL/glut.h>
#include <GL/freeglut.h>
#include <GL/gl.h>

#include <vector>
#include "../Utils/Utils.h"

typedef std::vector<Vector> Orbit;

class SolarSystem;

struct Satellite{
  Orbit orbit;
  int pos;
  Vector orbitRotation;
  Vector orbitColor;
  SolarSystem *solar;
};

class SolarSystem {
protected:
  std::vector<Satellite> moons;
  int rotation;
  Vector axis;

public:
  SolarSystem ();
  SolarSystem ( int rotation , Vector axis );
  virtual ~SolarSystem ();
  void addMoon( SolarSystem *s , Vector rotation , Orbit orbit , Vector color );
  virtual void draw() =0;
  void update();
};

typedef SolarSystem Solar;

#endif
