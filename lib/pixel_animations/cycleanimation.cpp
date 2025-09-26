#include <pixel_animations/cycleanimation.h>

#include <pixel_animations/color.h>

CycleAnimation::CycleAnimation(PixelController& controller)
  : Animation(controller)
{
}

void CycleAnimation::nextFrame(int frameCount)
{
  const int hue = frameCount % 360;

  fill(hsvHueToRGB(hue));
}
