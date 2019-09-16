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
    void SetScale(bool scalar); //if scalar true, increase, else decrease
    void SetOrbitSpeed(bool scalar); //if scalar true, increase, else decrease
    void SetSpinSpeed(bool scalar); //if scalar true, increase, else decrease

    bool pausedOrbit; //determines if the orbit is paused
    bool pausedSpin; //determines if the spin is paused
    bool reversedOrbit; //determines if the orbit is reversed
    bool reversedSpin; //determines if the spin is reversed

  private:
    glm::mat4 model;
    std::vector<Vertex> Vertices;
    std::vector<unsigned int> Indices;
    GLuint VB;
    GLuint IB;

    float angleOrbit; //the angle of the orbit
    float angleSelf; //the anlgle of the self rotation

    bool isMoon; //determines if the object is a moon

    float scaleMult; //the multiplier of the object's scale
    float maxScale; //the maximum multiplier that the object can scale to
    float minScale; //the minimum multiplier that the object can scale to

    float orbitSpeedMult; //the multiplier of the object's orbit speed
    float spinSpeedMult; //the multiplier of the object's spin speed
    float maxSpeed; //the maximum multiplier of the object's speed
    float minSpeed; //the minimum multiplier of the object's speed
};

#endif /* OBJECT_H */
