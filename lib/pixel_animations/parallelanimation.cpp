#include <pixel_animations/parallelanimation.h>

ParallelAnimation::ParallelAnimation(
    std::vector<std::unique_ptr<AnimationInterface>> animations)
  : m_animations(std::move(animations))
{
}

void ParallelAnimation::nextFrame(int frameCount)
{
  for (const std::unique_ptr<AnimationInterface>& animation : m_animations)
  {
    animation->nextFrame(frameCount);
  }
}
