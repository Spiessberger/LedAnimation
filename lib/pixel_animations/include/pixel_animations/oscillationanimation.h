#pragma once

#include "animation.h"

class OscillationAnimation : public Animation
{
public:
  OscillationAnimation(PixelController& controller);

  void nextFrame(int frameCount) override;
};
