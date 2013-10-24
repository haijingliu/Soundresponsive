#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
#include "star.h"


#define  NUM 10

class testApp : public ofSimpleApp{

	public:

		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased (int key);

		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
        void mouseReleased();

        //-------sound input-----------------//
        //void dragEvent(ofDragInfo dragInfo);
        //void gotMessage(ofMessage msg);
    
        //ofSoundPlayer  synth;
        //ofSoundPlayer  vocals;
    
        //float 			synthPosition;
    
        //---------sound responsive-------------//
        
        //void dragEvent(ofDragInfo dragInfo);
        //void gotMessage(ofMessage msg);
        
        void audioIn(float * input, int bufferSize, int nChannels);
        
        vector <float> left;
        vector <float> right;
        vector <float> volHistory;
        
        int 	bufferCounter;
        int 	drawCounter;
        
        float smoothedVol;
        float scaledVol;
        
        ofSoundStream soundStream;
        
        float time[50];
        float size[10];
        

  
    
    //---------vector class stars-------------//
    

        vector<star> myStars;
    
    
};

#endif

