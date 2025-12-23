// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "Enemy.h"
#include "AnimSpriteComponent.h"
#include "Game.h"
#include <random>
#include <chrono>
#include <cmath>

Enemy::Enemy(Game* game, int index)
	:Actor(game)
	,mRightSpeed(10.0f + 5*index)
	,mDownSpeed(5.0f)
	,mIndex(index)
{
	// Create an animated sprite component
	AnimSpriteComponent* asc = new AnimSpriteComponent(this);
	std::vector<SDL_Texture*> anims = {
		game->GetTexture("Assets/Enemy01.png"),
		game->GetTexture("Assets/Enemy02.png"),
		game->GetTexture("Assets/Enemy03.png"),
		game->GetTexture("Assets/Enemy04.png"),
		game->GetTexture("Assets/Enemy05.png"),
		game->GetTexture("Assets/Enemy06.png"),
		
	};
	asc->SetAnimTextures(anims);
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    
        // 2. Seed the random number engine (Mersenne Twister is a common choice)
        std::mt19937 gen(seed);
	std::uniform_int_distribution<> dist(1, 10);

	
	
        // 5. Generate and print the random number
        mAmplitude = dist(gen);
	mFrequency = dist(gen);
	
	
}

void Enemy::UpdateActor(float deltaTime)
{
  //float amplitude = 2;
  //	float frequency = 2;
	Actor::UpdateActor(deltaTime);
	mTotalTime += deltaTime;

	float yOffset = mIndex % 2 ==0 ? mAmplitude * sin(mTotalTime * mFrequency) : cos(mTotalTime * mFrequency);
	
	// Update position based on speeds and delta time
	Vector2 pos = GetPosition();
	pos.x -= mRightSpeed * deltaTime;
	//unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    
        // 2. Seed the random number engine (Mersenne Twister is a common choice)
        //std::mt19937 gen(seed);
    
	//std::uniform_int_distribution<> dist(1, 1100);

	
	
        // 5. Generate and print the random number
        //int random_num = dist(gen);
	
      
	if (pos.x < 10){
	   pos.x = 1910;
	}
	pos.y -= yOffset;
	if(pos.y < 10 || pos.y > 1100)
	{
	  pos.y = 1100/2;
	}
	//random_num;
	/*if (pos.y < 20){
	  pos.y += mDownSpeed * deltaTime;
	}else{
	  pos.y -= mDownSpeed * deltaTime;
	}
	*/

	
	// Restrict position to left half of screen
	/*
	if (pos.x < 25.0f)
	{
		pos.x = 25.0f;
	}
	else if (pos.x > 500.0f)
	{
		pos.x = 500.0f;
	}
	if (pos.y < 25.0f)
	{
		pos.y = 25.0f;
	}
	else if (pos.y > 743.0f)
	{
		pos.y = 743.0f;

	}
	*/
	SetPosition(pos);
}

void Enemy::ProcessKeyboard(const uint8_t* state)
{
	mRightSpeed = 0.0f;
	mDownSpeed = 0.0f;
	// right/left
	if (state[SDL_SCANCODE_D])
	{
		mRightSpeed += 250.0f;
	}
	if (state[SDL_SCANCODE_A])
	{
		mRightSpeed -= 250.0f;
	}
	// up/down
	if (state[SDL_SCANCODE_S])
	{
		mDownSpeed += 300.0f;
	}
	if (state[SDL_SCANCODE_W])
	{
		mDownSpeed -= 300.0f;
	}
}
