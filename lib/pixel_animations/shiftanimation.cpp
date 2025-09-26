#include <pixel_animations/shiftanimation.h>

#include <pixel_animations/color.h>

ShiftAnimation::ShiftAnimation(PixelController& controller)
  : Animation(controller)
{
}

void ShiftAnimation::nextFrame(int frameCount)
{
  const int maxHue = 360;
  for (int i = 0; i < pixelCount(); i++)
  {
    int hue = (maxHue * i / pixelCount() + frameCount) % maxHue;
    setPixel(i, hsvHueToRGB(hue));
  }
}
