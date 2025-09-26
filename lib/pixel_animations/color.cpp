#include <pixel_animations/color.h>

uint32_t hsvHueToRGB(int hue)
{
  hue = hue % 360;
  if (hue < 0)
  {
    hue += 360;
  }

  int sector = hue / 60;
  int offset = hue % 60;

  const uint8_t primary = 255;
  const uint8_t secondary = (offset * 255) / 60;
  const uint8_t tertiary = 255 - secondary;

  uint8_t r = 0;
  uint8_t g = 0;
  uint8_t b = 0;

  switch (sector)
  {
  case 0: // Red to Yellow
    r = primary;
    g = secondary;
    break;
  case 1: // Yellow to Green
    r = tertiary;
    g = primary;
    break;
  case 2: // Green to Cyan
    g = primary;
    b = secondary;
    break;
  case 3: // Cyan to Blue
    g = tertiary;
    b = primary;
    break;
  case 4: // Blue to Magenta
    r = secondary;
    b = primary;
    break;
  case 5: // Magenta to Red
  default:
    r = primary;
    b = tertiary;
    break;
  }

  return (r << 16) | (g << 8) | b;
}
