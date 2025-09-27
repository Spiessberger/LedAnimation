#pragma once

#include "animation.h"

class OscillationAnimation : public Animation
{
public:
  OscillationAnimation(PixelController& controller);

  void nextFrame(int frameCount) override;

private:
  // increase to make cycle animation slower
  int m_phaseShiftModifier = 100;
  // increase to cycle through color bands slower
  int m_cycleSpeedModifier = 5;
  // increase to get a higher bandwidth of colors
  int m_amplitude = 70;
};
