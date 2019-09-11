#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include "graphics_headers.h"

class Object
{
  public:
    Object(bool moon);
    ~Object();
    void Update(unsigned int dt, glm::mat4 orbitOrigin);
    void Render();

    glm::mat4 GetModel();
    bool pausedOrbit;
    bool pausedSpin;
    bool reversedOrbit;
    bool reversedSpin;
    bool isMoon;

  private:
    glm::mat4 model;
    std::vector<Vertex> Vertices;
    std::vector<unsigned int> Indices;
    GLuint VB;
    GLuint IB;

    float angleOrbit; //the angle of the orbit
    float angleSelf; //the anlgle of the self rotation
};

#endif /* OBJECT_H */
