#pragma once

#include "animationinterface.h"
#include "pixelcontroller.h"

class Animation : public AnimationInterface
{
public:
  Animation(PixelController& controller);

protected:
  int pixelCount();
  void fill(uint32_t color, int first = 0, int count = 0);
  void setPixel(int index, uint32_t color);

private:
  PixelController& m_controller;
};
