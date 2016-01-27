//
//  Particle.cpp
//  wk6_attractorRepulsor
//
//  Created by TheAlkimist on 10/5/13.
//
//

#include "Particle.h"
#include "ofMain.h"

Particle::Particle(){
    setInitCondition(ofGetWindowWidth()/2, ofGetWindowHeight()/2, ofGetWindowHeight()/2, 0, 0, 0);
    damping = 0.1;
    size = 10;
    r = ofRandom(160,240);
    g = ofRandom(0,80);
    b = ofRandom(0,40);
}

void Particle::resetForce(){
    force.set(0, 0, 0);
}

void Particle::setForce(float fx, float fy, float fz){
    force.set(fx, fy, fz);
}

void Particle::addDamping(){
    force.x = force.x - vel.x * damping;
    force.y = force.y - vel.y * damping;
    force.z = force.z - vel.z * damping;
}

void Particle::setInitCondition(float px, float py, float pz, float vx, float vy, float vz){
    pos.set(px, py, pz);
    vel.set(vx, vy, vz);
}

void Particle::update(){
    vel += force;
    pos += vel;

    if (pos.y > ofGetWindowHeight())
        pos.y = 0;
}

void Particle::draw(float time){
    ofSetColor(r, g, b);

    ofPushMatrix();

    ofTranslate(pos);
    ofRotate(time, 1, 0, 0);
    ofCircle(0, 0, 0, size);
//    ofRotate(time + 180.0, 1, 0, 0);
//    ofCircle(0, 0, 0, size);

    //ofCircle(pos.x, pos.y, pos.z, size);
    //ofDrawBox(pos.x, pos.y, pos.z, size);

    ofPopMatrix();
}
