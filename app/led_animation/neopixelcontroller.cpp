#include "neopixelcontroller.h"

#include <Adafruit_NeoPixel.h>

NeoPixelController::NeoPixelController(Adafruit_NeoPixel& neoPixel)
  : m_neoPixel(neoPixel)
{
}

void NeoPixelController::setPixel(int index, uint32_t color)
{
  m_neoPixel.setPixelColor(index, color);
}