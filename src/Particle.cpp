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
    size = 40;
    rotZ0 = ofRandom(360.0);
    r = ofRandom(160,240);
    g = ofRandom(160,240);
    b = ofRandom(160,240);

}

void Particle::resetForce(){
    force.set(0, 0, 0);
}

void Particle::setForce(float fx, float fy, float fz){
    force.set(fx, fy, fz);
}

void Particle::setRotation(float rx, float ry, float rz){
    rot.set(rx, ry, rz);
}

void Particle::addDamping(){
    force.x = force.x - vel.x * damping;
    force.y = force.y - vel.y * damping;
    force.z = force.z - vel.z * damping;
}

void Particle::setInitCondition(float px, float py, float pz, float vx, float vy, float vz){
    pos.set(px, py, pz);
    vel.set(vx, vy, vz);
    rot.set(0, 0, 0);
}

void Particle::update(){
    vel += force;
    pos += vel;

    if (pos.y > ofGetWindowHeight())
        pos.y = 0;
    if (pos.x > ofGetWindowWidth())
        pos.x = 0;
}

void Particle::draw(ofMesh quad, ofImage imgtex){

    ofSetColor(r, g, b);
    //ofSetColor(255);

    ofPushMatrix();

    ofTranslate(pos);

    ofRotateZ(rot.z);
    ofRotateY(rot.y);
    ofRotateX(45.0 + rot.x);
    ofRotateZ(rotZ0);

    ofTranslate(-size/2, -size/2, 0);
    ofScale(size, size, 0);

    imgtex.getTextureReference().bind();
    quad.draw();
    imgtex.getTextureReference().unbind();

    ofPopMatrix();
}
