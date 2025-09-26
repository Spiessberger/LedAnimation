#include <pixel_animations/animation.h>

Animation::Animation(PixelController& controller) : m_controller(controller)
{
}

int Animation::pixelCount()
{
  return m_controller.pixelCount();
}

void Animation::fill(uint32_t color, int first, int count)
{
  m_controller.fill(color, first, count);
}

void Animation::setPixel(int index, uint32_t color)
{
  m_controller.setPixel(index, color);
}
