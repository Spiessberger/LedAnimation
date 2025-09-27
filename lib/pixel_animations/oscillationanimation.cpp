#include <cmath>
#include <pixel_animations/color.h>
#include <pixel_animations/oscillationanimation.h>

OscillationAnimation::OscillationAnimation(PixelController& controller)
  : Animation(controller)
{
}

void OscillationAnimation::nextFrame(int frameCount)
{

  const int maxHue = 360;

  // map pixelcount to cos period of 2 pi
  const double periodFactor = M_PI * 2 / pixelCount();
  // shift phase with to get slightliy new color for each frame
  const double phaseShift = M_PI * 2 * frameCount / m_phaseShiftModifier;

  // shift base color with ongoing animation to get different colors within the
  // amplitude
  const int minValue = (frameCount / m_cycleSpeedModifier) % maxHue;

  for (int i = 0; i < pixelCount(); i++)
  {
    const double pixelOffset = periodFactor * i;
    int hue =
        (std::cos(phaseShift + pixelOffset) + 1) * m_amplitude / 2 + minValue;

    setPixel(i, hsvHueToRGB(hue));
  }
}
