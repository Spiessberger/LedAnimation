#pragma once

#include "pixelstate.h"

#include <QObject>
#include <QQmlEngine>
#include <QTimer>
#include <pixel_animations/animationinterface.h>
#include <pixel_animations/slicedpixelcontroller.h>

class QmlAnimationEngine : public QObject
{
  Q_OBJECT
  QML_NAMED_ELEMENT(AnimationEngine)

  Q_PROPERTY(QmlAnimationEngine::AnimationType animationType READ animationType
                 WRITE setAnimationType NOTIFY animationTypeChanged FINAL)
  Q_PROPERTY(int pixelCount READ pixelCount WRITE setPixelCount NOTIFY
                 pixelCountChanged FINAL)
  Q_PROPERTY(std::vector<QColor> pixelColors READ pixelColors NOTIFY
                 pixelColorsChanged FINAL)
public:
  enum class AnimationType
  {
    ShiftAnimation,
    CycleAnimation,
    OscillationAnimation
  };
  Q_ENUM(AnimationType)

  QmlAnimationEngine();

  const std::vector<QColor>& pixelColors() const;

  int pixelCount() const;
  void setPixelCount(int newPixelCount);

  AnimationType animationType() const;
  void setAnimationType(AnimationType newAnimationType);

signals:
  void pixelColorsChanged();
  void pixelCountChanged();
  void animationTypeChanged();

private:
  void nextFrame();
  void updateAnimation();

  int m_frameCount = 0;
  QTimer m_frameTimer;
  PixelState m_pixelState;
  SlicedPixelController m_digitThree;
  SlicedPixelController m_digitZero;
  std::unique_ptr<AnimationInterface> m_animation;
  AnimationType m_animationType = AnimationType::OscillationAnimation;
};
