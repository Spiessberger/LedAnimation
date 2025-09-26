#pragma once

#include "animationinterface.h"

#include <memory>
#include <vector>

class ParallelAnimation : public AnimationInterface
{
public:
  ParallelAnimation(
      std::vector<std::unique_ptr<AnimationInterface>> animations);

  void nextFrame(int frameCount) override;

private:
  std::vector<std::unique_ptr<AnimationInterface>> m_animations;
};
