#pragma once

#include "pixelcontroller.h"

class SlicedPixelController : public PixelController
{
public:
  SlicedPixelController(PixelController& pixelController);

public:
  void setPixel(int index, uint32_t color) override;

  int offset() const;
  void setOffset(int newOffset);

private:
  PixelController& m_pixelController;
  int m_offset = 0;
};
