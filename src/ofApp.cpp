#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(0,0,0);
    ofEnableAlphaBlending();

    width = ofGetWindowWidth();
    height = ofGetWindowHeight();

    for (int i = 0; i < 100; i++){
        Particle myParticle;
        myParticle.setInitCondition(ofRandom(0, width), ofRandom(0, height), ofRandom(-height / 2, height / 2), 0, 0, 0);
        myParticle.damping = ofRandom(0.2,0.3);
        particles.push_back(myParticle);
    }

    pointLight.enable();
    pointLight2.enable();
    pointLight3.enable();
    pointLight4.enable();
    pointLight.setPosition(0, 1000, 1000);
    pointLight2.setPosition(0, -1000, 1000);
    pointLight3.setPosition(0, 1000, -1000);
    pointLight4.setPosition(0, -1000, -1000);
}

//--------------------------------------------------------------
void ofApp::update(){

    time = ofGetElapsedTimef();

    for (int i = 0; i < particles.size(); i++){

        float fx = 0.2 - 0.4 * ofNoise(time * 1.0 + i * 104.3 + 14.6);
        //float fy = 0.1;
        float fy = 0.2 * ofNoise(time * 1.0 + i * 53.3 + 35.2);
        float fz = 0.2 - 0.4 * ofNoise(time * 1.0 + i * 104.3 + 14.6);

        //float fx = 0.2 - 0.4 * ofNoise(particles[i].pos.x / width, particles[i].pos.y /height, time * 2.0 + i * 104.3 + 14.6);
        //float fy = 0.2 * ofNoise(particles[i].pos.x / width, particles[i].pos.y /height, time * 2.0 + i * 53.3 + 35.2);

        //float fx = 0.2 - 0.4 * ofNoise(particles[i].pos.x / width, particles[i].pos.y /height, time);
        //float fy = 0.2 * ofNoise(particles[i].pos.x / width, particles[i].pos.y /height, time);

        particles[i].setForce(fx, fy, fz);
        //particles[i].addAttraction(mouseX, mouseY, 1000, 0.05);
        //particles[i].addRepulsion(mouseX, mouseY, 30, 35);
        particles[i].addDamping();
        particles[i].update();

    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofEnableDepthTest();
    ofEnableLighting();
    pointLight.enable();
    pointLight2.enable();
    pointLight3.enable();
    pointLight4.enable();

    for (int i = 0; i < particles.size(); i++){

        //ofRotate(360.0 * ofNoise(i * 53.3 + 35.2), 1, 0, 0);
        particles[i].draw(360.0 * ofNoise(time * 1.0 + i * 104.3 + 14.6));
    }

    ofDisableLighting();
    ofDisableDepthTest();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
