// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#pragma once
#include "Actor.h"
#include "SDL2/SDL.h"
#include <cstdint>
class Enemy : public Actor
{
public:
  Enemy(class Game* game, int index);
	void UpdateActor(float deltaTime) override;
	void ProcessKeyboard(const uint8_t* state);
	float GetRightSpeed() const { return mRightSpeed; }
	float GetDownSpeed() const { return mDownSpeed; }
        
private:
	float mRightSpeed;
	float mDownSpeed;
        float mTotalTime;
        int mIndex;
        int mAmplitude;
        int mFrequency;
};
