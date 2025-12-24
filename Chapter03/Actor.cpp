// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "Actor.h"
#include "Game.h"
#include "Component.h"
#include <algorithm>

Actor::Actor(Game* game)
	:mState(EActive)
	, mPosition(Vector2::Zero)
	, mScale(1.0f)
	, mRotation(0.0f)
	, mGame(game)
{
	mGame->AddActor(this);
}

Actor::~Actor()
{
	mGame->RemoveActor(this);
	// Need to delete components
	// Because ~Component calls RemoveComponent, need a different style loop
	while (!mComponents.empty())
	{
		delete mComponents.back();
	}
}


void Actor::Update(float deltaTime)
{
	if (mState == EActive)
	{
		UpdateComponents(deltaTime);
		UpdateActor(deltaTime);
	}
}

void Actor::UpdateComponents(float deltaTime)
{
	for (auto comp : mComponents)
	{
		comp->Update(deltaTime);
	}
}

void Actor::UpdateActor(float deltaTime)
{
}

void Actor::ProcessInput(const uint8_t* keyState)
{
	if (mState == EActive)
	{
		// First process input for components
		for (auto comp : mComponents)
		{
			comp->ProcessInput(keyState);
		}

		ActorInput(keyState);
	}
}

void Actor::ActorInput(const uint8_t* keyState)
{
}

void Actor::ActorInput(bool keyState)
{
}


void Actor::AddComponent(Component* component)
{
	// Find the insertion point in the sorted vector
	// (The first element with a order higher than me)
	int myOrder = component->GetUpdateOrder();
	auto iter = mComponents.begin();
	for (;
		iter != mComponents.end();
		++iter)
	{
		if (myOrder < (*iter)->GetUpdateOrder())
		{
			break;
		}
	}

	// Inserts element before position of iterator
	mComponents.insert(iter, component);
}

void Actor::RemoveComponent(Component* component)
{
	auto iter = std::find(mComponents.begin(), mComponents.end(), component);
	if (iter != mComponents.end())
	{
		mComponents.erase(iter);
	}
}

void Actor::ProcessJoyStick(Sint16 axis_value1, Sint16 axis_value2, Sint16 down_value1, Sint16 down_value2){

                for (auto comp : mComponents)
		{
			comp->ProcessInput(axis_value1, axis_value2,  down_value1,  down_value2);
		}
  
  /*mRightSpeed = 0.0f;
  mDownSpeed = 0.0f;
	
  if ((axis_value1 < -8000 || axis_value1 > 8000) || (axis_value2 < -8000 || axis_value2 > 8000)) {
    if (axis_value1 < -8000 || axis_value2 < -8000 ){
      //cout << "negating" << "\n";
      mDownSpeed -= 300.0f;
    }else{
      mDownSpeed += 300.0f;
      //cout << "increasing" << "\n";
    }
  }else if((down_value1 < -8000 || down_value1 > 8000) || (down_value2 < -8000 || down_value2 > 8000)) {
    if (down_value1 < -8000 || down_value2 < -8000 ){
      //cout << "negating" << "\n";
      mRightSpeed -= 300.0f;
    }else{
      mRightSpeed += 300.0f;
      //cout << "increasing" << "\n";
    }
  */
  }
