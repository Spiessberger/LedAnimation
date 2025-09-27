#pragma once

#include <QColor>
#include <QObject>
#include <pixel_animations/pixelcontroller.h>

class PixelState : public QObject, public PixelController
{
  Q_OBJECT
public:
  PixelState() = default;

  const std::vector<QColor>& pixelColors() const;
  void resizePixelColors();

  void setPixel(int index, uint32_t color) override;
  void show();

signals:
  void pixelColorsChanged();

private:
  std::vector<QColor> m_pixelColors;
};
