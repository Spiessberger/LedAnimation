#include "neopixelcontroller.h"

#include <Adafruit_NeoPixel.h>
#include <Arduino.h>
#include <pixel_animations/color.h>
#include <pixel_animations/oscillationanimation.h>
#include <pixel_animations/parallelanimation.h>
#include <pixel_animations/slicedpixelcontroller.h>

const int NumLeds = 21;
const int LedPin = PB8;
const int NEnablePin = PB9;

Adafruit_NeoPixel neoPixel{NumLeds, LedPin, NEO_GRB};
NeoPixelController ledController{neoPixel};
SlicedPixelController digitThree{ledController};
SlicedPixelController digitZero{ledController};

std::unique_ptr<AnimationInterface> animation;

void setup()
{
  digitThree.setPixelCount(9);
  digitZero.setPixelCount(12);
  digitThree.setOffset(digitZero.pixelCount());

  std::vector<std::unique_ptr<AnimationInterface>> animations;
  animations.emplace_back(std::make_unique<OscillationAnimation>(digitThree));
  animations.emplace_back(std::make_unique<OscillationAnimation>(digitZero));
  animation = std::make_unique<ParallelAnimation>(std::move(animations));

  neoPixel.begin();
  neoPixel.setBrightness(255);
  pinMode(NEnablePin, OUTPUT);
  digitalWrite(NEnablePin, LOW);
}

int frameCount = 0;
const int frameRate = 30;
const int frameTime = 1000 / frameRate;

void loop()
{
  const int time = millis();

  animation->nextFrame(frameCount);
  neoPixel.show();

  const int now = millis();
  if (time + frameTime > now)
  {
    delay(time + frameTime - now);
  }

  if (frameCount == std::numeric_limits<int>::max())
  {
    frameCount = 0;
  }
  else
  {
    frameCount++;
  }
}
