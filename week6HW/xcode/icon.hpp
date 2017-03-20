
#define icon_hpp

#include <stdio.h>
#include "cinder/gl/Texture.h"
#include "cinder/Surface.h"
#include "cinder/gl/gl.h"


using namespace ci;
using namespace ci::app;
using namespace std;

class icon;

class icon{
public:
    
    icon();
    void        setup(ci::vec2 startpoint, ci::vec2 toolBarSize);
    void        update(float time);
    void        draw();
    bool        inPlayButton(ci::vec2 mousePos);
    bool        inOpenFileButton(ci::vec2 mousePos);
    bool        inSeekBar(ci::vec2 mousePos);
    float       getHandlePos();
    
    bool        isPlaying;
    float       currentTime;
    
private:
    
    ci::vec2            iconPos;
    ci::vec2            iconSize;
    ci::vec2            mPlayButtonSize;
    ci::gl::TextureRef  playButtonTexture;
    ci::gl::TextureRef  stopButtonTexture;
    ci::vec2            mOpenFileSize;
    ci::gl::TextureRef  openFileTexture;
};
    
    
    
