#pragma once

#include <pixel_animations/pixelcontroller.h>

class Adafruit_NeoPixel;

class NeoPixelController : public PixelController
{
public:
  NeoPixelController(Adafruit_NeoPixel& neoPixel);

  void setPixel(int index, uint32_t color) override;

private:
  Adafruit_NeoPixel& m_neoPixel;
};
