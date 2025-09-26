#pragma once

#include <cstdint>

class PixelController
{
public:
  PixelController() = default;

  int pixelCount() const;
  void setPixelCount(int newNumPixels);

  void fill(uint32_t color, int first = 0, int count = 0);

  virtual void setPixel(int index, uint32_t color) = 0;

private:
  int m_pixelCount = 0;
};
