

#include "icon.hpp"


icon::icon()
{
    iconPos = ci::vec2(100, 600);
    iconSize = ci::vec2(650, 40);
}

void icon::setup(ci::vec2 startpoint, ci::vec2 iconSize)
{
    try {
        
       
        
        playButtonTexture = ci::gl::Texture::create(loadImage(ci::app::loadAsset("play.jpg")));
        stopButtonTexture = ci::gl::Texture::create(loadImage(ci::app::loadAsset("stop.jpg")));
        openFileTexture = ci::gl::Texture::create(loadImage(ci::app::loadAsset("openvideo.png")));
    } catch (std::exception &e) {
        
    }
    
    
    mPlayButtonSize = mOpenFileSize = ci::vec2(iconSize.y);
    
    isPlaying = true;
    
}



void icon::update(float time)
{
    currentTime = time;
}

void icon::draw()
{
    
    {gl::ScopedColor newColor2(0.5, 0.5, 0.5, 0.5);
        ci::gl::drawSolidRect(Rectf(100, 560, 740, 600));
    }
    
    
    
if (playButtonTexture && isPlaying) {
        gl::draw(playButtonTexture, Rectf(155, 560, 155+mPlayButtonSize.x, 560+mPlayButtonSize.y));
    }
if (stopButtonTexture && !isPlaying) {
        gl::draw(stopButtonTexture, Rectf(155, 560, 155+mPlayButtonSize.x, 560+mPlayButtonSize.y));
    }
    
if (openFileTexture) {
        gl::draw(openFileTexture, Rectf(110, 560, 110+mPlayButtonSize.x, 560+mPlayButtonSize.y));
    }
    
    gl::drawSolidRect(Rectf(205,575, 725, 582));
    //draw seekbar
    {
        gl::ScopedColor newColor1( 0.5, 0.5, 0.1);
        gl::drawSolidRect(Rectf(205, 580, currentTime+205, 577));
    }
}

bool icon::inPlayButton(ci::vec2 mousePos)
{
    if(mousePos.x <= 195 && mousePos.x >= 155 && mousePos.y <= 600 && mousePos.y >= 560)
        return true;
    else
        return false;
}

bool icon::inOpenFileButton(ci::vec2 mousePos)
{
    if(mousePos.x <= 150 && mousePos.x >= 110 && mousePos.y <= 600 && mousePos.y >= 560)
        return true;
    else
        return false;
}

bool icon::inSeekBar(ci::vec2 mousePos)
{
    if (mousePos.x <= 725 && mousePos.x >= 205 & mousePos.y <=580 && mousePos.y >=577)
    {
        return true;
    }
    else
        return false;
}


