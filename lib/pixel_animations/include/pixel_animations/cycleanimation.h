#pragma once

#include "animation.h"

class CycleAnimation : public Animation
{
public:
  CycleAnimation(PixelController& controller);

  void nextFrame(int frameCount) override;
};
