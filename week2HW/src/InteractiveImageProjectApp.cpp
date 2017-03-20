
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
using namespace ci;
using namespace ci::app;
using namespace std;

class ImageUsageApp : public App {
public:
    void setup() override;
    void mouseDown( MouseEvent event ) override;
    void update() override;
    void draw() override;
    void twirl(Surface8u *surface, Area area, float maxAngle);
    // useful function to place a texture, scale is preset so you dont have to fill in this arg everytime
    Rectf getRectf(glm::vec2 startingPoint, glm::vec2 size, glm::vec2 scale = glm::vec2(1.f, 1.f));
    
    gl::TextureRef      mTexture;
    
    ci::Surface8u       mSurface;
    ci::Surface8u       mSurfaceBW;
    ci::Surface8u       mSurfaceTwirl;
    
    gl::TextureRef      mTexFromSurface;
    gl::TextureRef      mTexBWFromSurface;
    gl::TextureRef      mTexTwirlFromSurface;
    gl::TextureRef      mTexClouds;
    
    float               mWidth;
    float               mHeight;

};

void ImageUsageApp::setup()
{
    mWidth = 400.f;
    mHeight = 300.f;
    
    ci::app::setWindowSize(glm::vec2(1000.f, 800.f));
    
    try {
    
        mTexture = gl::Texture::create( loadImage( loadAsset( "dragon.jpg" ) ) );
        
        mSurface = loadImage(ci::app::loadAsset("dragon.jpg"));
        mSurfaceBW = mSurface.clone();
        mSurfaceTwirl = mSurface.clone();
        
        mTexClouds = gl::Texture::create( loadImage( loadAsset( "dragon.jpg" ) ) );
        
    } catch (exception& e) {
       
        ci::app::console() << e.what() << std::endl;
    }
    

    
}


Rectf ImageUsageApp::getRectf(glm::vec2 startingPoint, glm::vec2 size, glm::vec2 scale)
{
    return Rectf(startingPoint.x, startingPoint.y, (size.x + startingPoint.x) * scale.x, (size.y + startingPoint.y) * scale.y);
}

void ImageUsageApp::mouseDown( MouseEvent event )
{
    ci::Surface::Iter iter = mSurface.getIter(mSurface.getBounds());
    while(iter.line()){
        while(iter.pixel()){
            iter.r() = 255.f - iter.r();
            iter.g() = 255.f - iter.g();
            iter.b() = 255.f - iter.b();
        }
    }
    
}

void ImageUsageApp::update()
{
    
}

void ImageUsageApp::draw()

{
         gl::clear( Color( 0, 0, 0 ) );
      gl::color( 1,1,1 );
 
    mTexFromSurface = gl::Texture::create(mSurface);
    gl::draw(mTexFromSurface, getRectf(glm::vec2(mWidth, mHeight), glm::vec2(mWidth, mHeight)));
    gl::color( 0.f,0.f,1.f );
    ci::gl::drawString("Mouse down to change color",vec2(10.f,50.f));
    
    
}

CINDER_APP( ImageUsageApp, RendererGl )
