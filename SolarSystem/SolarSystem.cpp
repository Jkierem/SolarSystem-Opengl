#include "SolarSystem.h"

SolarSystem::SolarSystem (){}

SolarSystem::SolarSystem ( int rotation , Vector axis ){
  this->rotation = rotation;
  this->axis = axis;
}

SolarSystem::~SolarSystem (){}

void SolarSystem::addMoon( SolarSystem *s , Vector rotation , Orbit orbit , Vector color ){
  Satellite sat;
  sat.solar = s;
  sat.orbitRotation = rotation;
  sat.orbit = orbit;
  sat.pos = 0;
  sat.orbitColor = color;
  this->moons.push_back( sat );
}

void SolarSystem::update(){
  glPushMatrix();
    Utils::rotate( this->rotation , this->axis );
    this->draw();
    for( Satellite& sat : this->moons ){
      Utils::rotate( sat.orbitRotation );
      Utils::drawPoints( sat.orbit , sat.orbitColor );
      Utils::translate( sat.orbit[sat.pos] );
      sat.solar->update();
      sat.pos++;
      sat.pos = sat.pos % sat.orbit.size();
    }
  glPopMatrix();
}
