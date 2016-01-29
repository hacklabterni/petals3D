//
//  Particle.h
//  wk6_attractorRepulsor
//
//  Created by TheAlkimist on 10/5/13.
//
//

#include "ofMain.h"

class Particle{
public:

    Particle();     // particle constructor
    virtual ~Particle(){};

    ofVec3f pos;    // vector position
    ofVec3f rot;    // vector rotation
    ofVec3f vel;    // vector velocity
    ofVec3f force;    // vector force

    void resetForce();
    void setForce(float fx, float fy, float fz);
    void setRotation(float rx, float ry, float rz);
    void addDamping();                      // damping
    void setInitCondition(float px, float py, float pz, float vx, float vy, float vz);  // starting force
    void update();
    void draw(ofMesh quad, ofImage imgtex);

    float damping;
    float size;
    float rotZ0;

    int r, g, b;

    ofColor color;

};
