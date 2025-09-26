#include <pixel_animations/pixelcontroller.h>

#include <algorithm>

int PixelController::pixelCount() const
{
  return m_pixelCount;
}

void PixelController::setPixelCount(int newNumPixels)
{
  m_pixelCount = newNumPixels;
}

void PixelController::fill(uint32_t color, int first, int count)
{
  int last = pixelCount();

  if (count > 0)
  {
    last = std::min(first + count, pixelCount());
  }

  for (int i = first; i < last; i++)
  {
    setPixel(i, color);
  }
}
