#pragma once

#include "animation.h"

class ShiftAnimation : public Animation
{
public:
  ShiftAnimation(PixelController& controller);

  void nextFrame(int frameCount) override;
};
