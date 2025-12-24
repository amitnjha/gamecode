// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "InputComponent.h"
#include "Actor.h"
#include <iostream>
using namespace std;

InputComponent::InputComponent(class Actor* owner)
:MoveComponent(owner)
,mForwardKey(0)
,mBackKey(0)
,mClockwiseKey(0)
,mCounterClockwiseKey(0)
{
	
}


void InputComponent::ProcessInput(Sint16 axis_value1, Sint16 axis_value2, Sint16 down_value1, Sint16 down_value2)
{
  //cout<< "coming in InputComponent::ProcessInput\n";
  
	// Calculate forward speed for MoveComponent
	float forwardSpeed = 0.0f;
	float angularSpeed = 0.0f;
	if ((axis_value1 < -8000 || axis_value1 > 8000) || (axis_value2 < -8000 || axis_value2 > 8000)) {
          if (axis_value1 < -8000 || axis_value2 < -8000 ){
      //cout << "negating" << "\n";
      //mDownSpeed -= 300.0f;
      forwardSpeed -= mMaxForwardSpeed;
    }else{
	    //mDownSpeed += 300.0f;
      forwardSpeed += mMaxForwardSpeed;
      //cout << "increasing" << "\n";
    }
  }else if((down_value1 < -8000 || down_value1 > 8000) || (down_value2 < -8000 || down_value2 > 8000)) {
    if (down_value1 < -8000 || down_value2 < -8000 ){
      //cout << "negating" << "\n";
      //mRightSpeed -= 300.0f;
      //forwardSpeed -= mMaxForwardSpeed;
      angularSpeed -= mMaxAngularSpeed;
    }else{
      //mRightSpeed += 300.0f;
      //forwardSpeed += mMaxForwardSpeed;
      angularSpeed += mMaxAngularSpeed;
      //cout << "increasing" << "\n";
    }
    
  }
	//cout << "forwardSpeed = " << forwardSpeed << "\n";
    SetForwardSpeed(forwardSpeed);
    SetAngularSpeed(angularSpeed);

}




void InputComponent::ProcessInput(const uint8_t* keyState)
{
	// Calculate forward speed for MoveComponent
	float forwardSpeed = 0.0f;
	if (keyState[mForwardKey])
	{
		forwardSpeed += mMaxForwardSpeed;
	}
	if (keyState[mBackKey])
	{
		forwardSpeed -= mMaxForwardSpeed;
	}
	SetForwardSpeed(forwardSpeed);
	
	// Calculate angular speed for MoveComponent
	float angularSpeed = 0.0f;
	if (keyState[mClockwiseKey])
	{
		angularSpeed += mMaxAngularSpeed;
	}
	if (keyState[mCounterClockwiseKey])
	{
		angularSpeed -= mMaxAngularSpeed;
	}
	SetAngularSpeed(angularSpeed);
}
