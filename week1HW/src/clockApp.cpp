#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"


using namespace ci;
using namespace ci::app;
using namespace std;


class clockApp : public App {
public:
    void setup() override;
    void mouseDown( MouseEvent event ) override;
    void update() override;
    void draw() override;
    time_t oldtime;
    struct tm * newtime;
    char a[300];
    
  
    
};

void clockApp::setup()
{
    ci::app::setWindowSize(100.f, 100.f);
  
    
}

void  clockApp::mouseDown( MouseEvent event )
{
}

void  clockApp::update()
{
}

void  clockApp::draw()
{
    gl::clear( Color( 0.f, 0.5f, 0.5f ) );
    oldtime = std::time(NULL);
    newtime = std::localtime(&oldtime);
    strftime(a, 100, "%I :%M :%S", newtime);
    gl::drawString( a, ci::vec2( 10.f, 50.f ),Color::white());
}

CINDER_APP(  clockApp, RendererGl )
