#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetVerticalSync(true);
    ofSetFrameRate(30);
    ofBackground(0,0,0);

    ofEnableNormalizedTexCoords();

    width = ofGetWindowWidth();
    height = ofGetWindowHeight();

    for (int i = 0; i < 120; i++){
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

    imgtex.loadImage("petal.png");
    imgtex.setImageType(OF_IMAGE_COLOR_ALPHA);
    imgtex.reloadTexture();

    // first triangle
    quad.addVertex(ofVec3f(0, 0, 0));
    quad.addVertex(ofVec3f(1, 0, 0));
    quad.addVertex(ofVec3f(1, 1, 0));
    // second triangle
    quad.addVertex(ofVec3f(1, 1, 0));
    quad.addVertex(ofVec3f(0, 1, 0));
    quad.addVertex(ofVec3f(0, 0, 0));
    // first triangle
    quad.addTexCoord(ofVec2f(0, 0));
    quad.addTexCoord(ofVec2f(1, 0));
    quad.addTexCoord(ofVec2f(1, 1));
    // second triangle
    quad.addTexCoord(ofVec2f(1, 1));
    quad.addTexCoord(ofVec2f(0, 1));
    quad.addTexCoord(ofVec2f(0, 0));

}

//--------------------------------------------------------------
void ofApp::update(){

    time = ofGetElapsedTimef();

    for (int i = 0; i < particles.size(); i++){

        float fx = 4.2 - 8.0 * ofNoise(time * 1.0 + i * 104.3 + 14.6);
        //float fy = 0.2;
        float fy = 0.2 + 0.2 * ofNoise(time * 1.0 + i * 53.3 + 35.2);
        float fz = 4.0 - 8.0 * ofNoise(time * 1.0 + i * 104.3 + 14.6);

        //float fx = 0.2 - 0.4 * ofNoise(particles[i].pos.x / width, particles[i].pos.y /height, time * 1.0 + i * 104.3 + 14.6);
        //float fy = 0.2 * ofNoise(particles[i].pos.x / width, particles[i].pos.y /height, time * 1.0 + i * 53.3 + 35.2);

        //float fx = 0.2 - 0.4 * ofNoise(particles[i].pos.x / width, particles[i].pos.y /height, time);
        //float fy = 0.2 * ofNoise(particles[i].pos.x / width, particles[i].pos.y /height, time);

        particles[i].setForce(fx, fy, fz);

        float rx = 90.0 - 180.0 * ofNoise(time * 1.0 + i * 104.3 + 14.6);
        float ry = 0.0;
        float rz = 90.0 - 180.0 * ofNoise(time * 1.0 + i * 53.3 + 35.2);

        //float rx = 360.0 * ofNoise(time * 1.0 + i * 104.3 + 14.6);
        //float ry = 0.0;
        //float rz = 0.0;

        particles[i].setRotation(rx, ry, rz);

        particles[i].addDamping();
        particles[i].update();

    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofEnableAlphaBlending();
    //ofEnableDepthTest();

    glEnable(GL_ALPHA);
    glEnable(GL_DEPTH_TEST);
    glAlphaFunc(GL_GREATER, 0.5);
    glEnable(GL_ALPHA_TEST);

    ofEnableLighting();
    pointLight.enable();
    pointLight2.enable();
    pointLight3.enable();
    pointLight4.enable();

    for (int i = 0; i < particles.size(); i++){
        particles[i].draw(quad, imgtex);
    }

    glDisable(GL_DEPTH_TEST);
    glDisable(GL_ALPHA);

    ofDisableLighting();

    //ofDisableDepthTest();
    ofDisableAlphaBlending();

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
