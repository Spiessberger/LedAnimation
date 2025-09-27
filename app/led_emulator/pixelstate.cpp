#include "pixelstate.h"

void PixelState::setPixel(int index, uint32_t color)
{
  if (index >= 0 && index < m_pixelColors.size())
  {
    m_pixelColors[index] = QColor::fromRgb(color);
  }
}

void PixelState::show()
{
  emit pixelColorsChanged();
}

const std::vector<QColor>& PixelState::pixelColors() const
{
  return m_pixelColors;
}

void PixelState::resizePixelColors()
{
  m_pixelColors.resize(pixelCount());
}
