#include <pixel_animations/slicedpixelcontroller.h>

SlicedPixelController::SlicedPixelController(PixelController& pixelController)
  : m_pixelController(pixelController)
{
}

void SlicedPixelController::setPixel(int index, uint32_t color)
{
  m_pixelController.setPixel(index + m_offset, color);
}

int SlicedPixelController::offset() const
{
  return m_offset;
}

void SlicedPixelController::setOffset(int newOffset)
{
  m_offset = newOffset;
}
