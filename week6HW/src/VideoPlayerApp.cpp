#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "MoviePlayer.hpp"
#include "icon.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

class VideoPlayerApp : public App {
public:
    void setup() override;
    void mouseDown( MouseEvent event ) override;
    void update() override;
    void draw() override;
    icon                micon;
    ci::vec2        cursorPos;
    MoviePlayerRef     mPlayer;
    ci::fs::path       mFilePath;
   
};

void VideoPlayerApp::setup()
{
    ci::app::setWindowSize(900, 700);
        mPlayer = MoviePlayer::creat();
        mFilePath = getOpenFilePath();
    if (! mFilePath.empty()) {
        mPlayer->loadVideo(mFilePath);
    }
        mPlayer->setWindow(ci::vec2(100.f, 80.f), 640, 480);
    
    
    
    micon.setup(ci::vec2(100.f, 560.f), ci::vec2(640, 40));
    micon.isPlaying = false;
    cursorPos = ci::vec2(205, 577);
}

void VideoPlayerApp::mouseDown( MouseEvent event )
{
    
    
    if (micon.inPlayButton(ci::vec2(event.getPos())))
    {
    if (mPlayer->isPlaying) {
    mPlayer->stopMovie();
    micon.isPlaying = true;
        }else{
    mPlayer->playMovie();
    micon.isPlaying = false;
        }
        
    }
    if (micon.inOpenFileButton(event.getPos())) {
    mFilePath = getOpenFilePath();
    if (! mFilePath.empty()) {
    mPlayer->loadVideo(mFilePath);
        }
    }
    
    if(micon.inSeekBar(ci::vec2(event.getPos())))
    {
float pos = event.getX() - 205;
    mPlayer->setVideoTimeTo(pos/520 * mPlayer->getDuration());
    }
    
    
}

void VideoPlayerApp::update()
{
    mPlayer->update();
    micon.update(mPlayer->getCurrentTime());
}

void VideoPlayerApp::draw()
{
    gl::clear( Color(  0.1, 0.1, 0.1 ) );
    mPlayer->draw();
    micon.draw();
}

CINDER_APP( VideoPlayerApp, RendererGl )
