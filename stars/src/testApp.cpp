#include "testApp.h"
#include "ofMain.h"


//--------------------------------------------------------------
void testApp::setup(){

	
	/*ofSetVerticalSync(true);
    
    
    synth.loadSound("sounds/synth.wav");
	vocals.loadSound("sounds/Violet.mp3");
	synth.setVolume(0.75f);
	vocals.setVolume(0.5f);
	//font.loadFont("Sudbury_Basin_3D.ttf", 32);
	synth.setMultiPlay(false);
	vocals.setMultiPlay(true);*/
	
	
	ofBackground(30,30,30);
    for(int i=0; i<=300; i++) {
        star stars;
        myStars.push_back(stars);
    }
}

//--------------------------------------------------------------
void testApp::update(){
    
	//xPos = xPos + ofRandom(-1,1);
    
    for (int i = 0; i < NUM; i++){
        time[i]= ofRandom(20);
    }
    
    // 0 output channels,
    // 2 input channels
    // 44100 samples per second
    // 256 samples per buffer
    // 4 num buffers (latency)
    
    
    //--------------------------- Sound Input
    //if you want to set a different device id
    //soundStream.setDeviceID(0); //bear in mind the device id corresponds to all audio devices, including  input-only and output-only devices.
    
    soundStream.listDevices();
    int bufferSize = 256;
    left.assign(bufferSize, 0.0);
    volHistory.assign(400, 0.0);
    bufferCounter	= 0;
    drawCounter		= 0;
    smoothedVol     = 0.0;
    scaledVol		= 0.0;
    
    soundStream.setup(this, 0, 2, 44100, bufferSize, 4);


}



//--------------------------------------------------------------
void testApp::draw(){
    
    for(int i=0; i<= myStars.size(); i++){
        myStars[i].draw();
        }
    

}

//--------------------------------------------------------------
void testApp::audioIn(float * input, int bufferSize, int nChannels){
    
    
	float curVol = 0.0;
	int numCounted = 0;
	for (int i = 0; i < bufferSize; i++){
    left[i]		= input[i*2]*0.5;
    curVol += left[i] * left[i];
    numCounted+=2;
	}
	
	curVol /= (float)numCounted;
	curVol = sqrt( curVol );
	smoothedVol *= 0.93;
	smoothedVol += 0.07 * curVol;
	bufferCounter++;
    
    
}

//--------------------------------------------------------------
void testApp::keyPressed (int key){
    
    
    
	
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
