#include <pixel_animations/oscillationanimation.h>
#include <pixel_animations/color.h>

#include <cmath>


OscillationAnimation::OscillationAnimation(PixelController& controller)
  : Animation(controller)
{
}

void OscillationAnimation::nextFrame(int frameCount)
{
  const int maxHue = 360;
  const double periodFactor = M_PI * 2 / pixelCount();
  const double phaseShift = M_PI * 2 * frameCount / 100;

  const int minValue = (frameCount / 10) % maxHue;
  const int amplitude = 60;

  for (int i = 0; i < pixelCount(); i++)
  {
    const double pixelOffset = periodFactor * i;
    int hue = std::cos(phaseShift + pixelOffset) * amplitude / 2 +
              amplitude / 2 + minValue;

    setPixel(i, hsvHueToRGB(hue));
  }
}
