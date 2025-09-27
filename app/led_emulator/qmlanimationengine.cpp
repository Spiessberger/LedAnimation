#include "qmlanimationengine.h"

#include <pixel_animations/cycleanimation.h>
#include <pixel_animations/oscillationanimation.h>
#include <pixel_animations/parallelanimation.h>
#include <pixel_animations/shiftanimation.h>

namespace
{
const int FrameRate = 30;
}

QmlAnimationEngine::QmlAnimationEngine()
  : m_digitThree(m_pixelState), m_digitZero(m_pixelState)
{
  m_digitThree.setPixelCount(9);
  m_digitZero.setPixelCount(12);
  m_digitThree.setOffset(m_digitZero.pixelCount());

  connect(&m_pixelState, &PixelState::pixelColorsChanged, this,
          &QmlAnimationEngine::pixelColorsChanged);

  connect(&m_frameTimer, &QTimer::timeout, this,
          &QmlAnimationEngine::nextFrame);
  m_frameTimer.setSingleShot(false);
  m_frameTimer.start(1000 / FrameRate);

  updateAnimation();
}

const std::vector<QColor>& QmlAnimationEngine::pixelColors() const
{
  return m_pixelState.pixelColors();
}

void QmlAnimationEngine::nextFrame()
{
  if (m_animation == nullptr)
  {
    return;
  }

  m_animation->nextFrame(m_frameCount);
  m_frameCount++;
  m_pixelState.show();
}

void QmlAnimationEngine::updateAnimation()
{
  std::unique_ptr<AnimationInterface> newAnimation;

  switch (m_animationType)
  {
  case AnimationType::CycleAnimation:
    newAnimation = std::make_unique<CycleAnimation>(m_pixelState);
    break;
  case AnimationType::ShiftAnimation:
    newAnimation = std::make_unique<ShiftAnimation>(m_pixelState);
    break;
  case AnimationType::OscillationAnimation:
  {
    std::vector<std::unique_ptr<AnimationInterface>> animations;
    animations.emplace_back(
        std::make_unique<OscillationAnimation>(m_digitThree));
    animations.emplace_back(
        std::make_unique<OscillationAnimation>(m_digitZero));
    newAnimation = std::make_unique<ParallelAnimation>(std::move(animations));
    break;
  }
  }

  m_frameCount = 0;
  m_animation = std::move(newAnimation);
}

int QmlAnimationEngine::pixelCount() const
{
  return m_pixelState.pixelCount();
}

void QmlAnimationEngine::setPixelCount(int newPixelCount)
{
  if (pixelCount() == newPixelCount)
  {
    return;
  }
  m_pixelState.setPixelCount(newPixelCount);
  m_pixelState.resizePixelColors();
  emit pixelCountChanged();
}

QmlAnimationEngine::AnimationType QmlAnimationEngine::animationType() const
{
  return m_animationType;
}

void QmlAnimationEngine::setAnimationType(AnimationType newAnimationType)
{
  if (m_animationType == newAnimationType)
  {
    return;
  }
  m_animationType = newAnimationType;
  emit animationTypeChanged();

  updateAnimation();
}
