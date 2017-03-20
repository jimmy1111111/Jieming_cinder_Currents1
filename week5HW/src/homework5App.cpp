#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Timeline.h"
using namespace ci;
using namespace ci::app;
using namespace std;

class homework5App : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    ci::Anim<ci::vec2>      myround1,myround2,myround3,myround4,myround5,myround6,myround7;
    ci::Anim<float>         myfactor = 1.f;
    ci::Anim<int>         a ,b;
    
};

void homework5App::setup()
{
    myround1 = ci::app::getWindowCenter()+vec2(1*20,1*20);
    myround2 = myround1.value()+vec2(1*20,1*20);
    myround3 = myround2.value()+vec2(1*20,1*20);
    
     myround4 = myround1.value()-vec2(1*20,1*20);
        myround5 = myround4.value()-vec2(1*20,1*20);
        myround6 = myround5.value()-vec2(1*20,1*20);
    myround7 = myround6.value()-vec2(1*20,20);
    a=1;
    b=1;
}

void homework5App::mouseDown( MouseEvent event )
{

    a=-a;
    timeline().apply(&myround1,ci::app::getWindowCenter()+vec2(-1*a*20,1*20),0.4f,ci::EaseInCubic());
    timeline().apply(&myround2,ci::app::getWindowCenter()+vec2(-1*a*40,1*40),0.3f,ci::EaseOutSine());
    timeline().apply(&myround3,ci::app::getWindowCenter()+vec2(-1*a*60,1*60),0.5f,ci::EaseOutBack());
    timeline().apply(&myround5,ci::app::getWindowCenter()-vec2(-1*a*20,1*20),0.4f,ci::EaseInCubic());
    timeline().apply(&myround6,ci::app::getWindowCenter()-vec2(-1*a*40,1*40),0.3f,ci::EaseOutSine());
        timeline().apply(&myround7,ci::app::getWindowCenter()-vec2(-1*a*60,1*60),0.5f,ci::EaseOutBack());
   

}

void homework5App::update()
{

}

void homework5App::draw()
{
    gl::clear(Color(0,0,0));
    
        gl::color(Color(0,1,0.5));
    gl::drawSolidCircle(myround4, 10*myfactor);
         gl::color(Color(1,0,0.5));
    gl::drawSolidCircle(myround5, 10*myfactor);
        gl::color(Color(0.5,0,1));
    gl::drawSolidCircle(myround6, 10*myfactor);
      gl::color(Color(0,1,0.5));
      gl::drawSolidCircle(myround7, 10*myfactor);
 gl::color(Color(1,0,0.5));
        gl::drawSolidCircle(myround1, 10*myfactor);
     gl::color(Color(0,1,0.5));
        gl::drawSolidCircle(myround2, 10*myfactor);
     gl::color(Color(1,0,0.5));
        gl::drawSolidCircle(myround3, 10*myfactor);
    
    
    
    
    
    
//    for(int i=0;i<4;i+=1){
//        myround2 = myround1.value()+vec2(a*20,b*-i*20);
//        gl::color(Color(0,1,0.5));
//        gl::drawSolidCircle(myround2, 10*myfactor);}
    
//    for(int i=0;i<4;i+=1){
//        myround2 = myround1.value()+vec2(i*20,-i*20);
//        gl::color(Color(0,1,0.5));
//        gl::drawSolidCircle(myround2, 10*myfactor);}
//    
//    for(int i=0;i<4;i+=1){
//        myround2 = myround1.value()+vec2(-i*20,i*20);
//         gl::color(Color(0,1,0.5));
//        gl::drawSolidCircle(myround2, 10*myfactor);}
    
}

CINDER_APP( homework5App, RendererGl )
