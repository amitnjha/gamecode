// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "Game.h"
#include <stdio.h>
const float WIDTH = 1920;
const float HEIGHT = 1000;

const int thickness = 15;
const float paddleH = 100.0f;

Game::Game()
:mWindow(nullptr)
,mRenderer(nullptr)
,mTicksCount(0)
,mIsRunning(true)
,mPaddleDir(0)
{
	
}

bool Game::Initialize()
{
	// Initialize SDL
	int sdlResult = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK);
	if (sdlResult != 0)
	{
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return false;
	}
	printf("%i joysticks were found.\n\n", SDL_NumJoysticks() );
	
	// Create an SDL Window
	mWindow = SDL_CreateWindow(
		"Aaryan's Pong Game - 67676767", // Window title
		10,	// Top left x-coordinate of window
		10,	// Top left y-coordinate of window
		WIDTH,	// Width of window
		HEIGHT,	// Height of window
		0		// Flags (0 for no flags set)
	);

	if (!mWindow)
	{
		SDL_Log("Failed to create window: %s", SDL_GetError());
		return false;
	}
	
	//// Create SDL renderer
	mRenderer = SDL_CreateRenderer(
		mWindow, // Window to create renderer for
		-1,		 // Usually -1
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);

	if (!mRenderer)
	{
		SDL_Log("Failed to create renderer: %s", SDL_GetError());
		return false;
	}
	//

	SDL_JoystickEventState(SDL_ENABLE);
        joystick0 = SDL_JoystickOpen(0);
	joystick1 = SDL_JoystickOpen(1);
	
	mPaddlePos.x = 10.0f;
	mPaddlePos.y = HEIGHT/2.0f;

	mPaddlePos2.x = WIDTH-24;
	mPaddlePos2.y = HEIGHT/2.0f;
	
	mBallPos.x = WIDTH/2.0f;
	mBallPos.y = HEIGHT/2.0f;
	mBallVel.x = -200.0f;
	mBallVel.y = 235.0f;
	return true;
}

void Game::RunLoop()
{
	while (mIsRunning)
	{
		ProcessInput();
		UpdateGame();
		GenerateOutput();
	}
}

void Game::ProcessInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
	        mPaddleDir = 0;
		mPaddle2Dir = 0;
	        switch (event.type)
		{

			// If we get an SDL_QUIT event, end loop
		  
			case SDL_QUIT:
				mIsRunning = false;
				break;
			case SDL_JOYAXISMOTION:
			  Sint16 axis_value1 = SDL_JoystickGetAxis(joystick1, 1);
			  Sint16 axis_value2 = SDL_JoystickGetAxis(joystick0, 1);
			  
			  if ((axis_value1 < -8000 || axis_value1 > 8000) || (axis_value2 < -8000 || axis_value2 > 8000)) {
			    //			  if ( ( event.jaxis.value < -8000 ) || (event.jaxis.value > 8000 ) ) 
				/* Up-Down movement code goes here */
				//printf("Up Down detected\n");
				if (axis_value1 < -8000 || axis_value2 < -8000 ) { // Moved Up (negative)
				  //printf("Left Stick UP!\n");
				  if(axis_value1 < -8000)
				    mPaddleDir -= 1;
				  if(axis_value2 < -8000)
				    mPaddle2Dir -=1;
				  break;
				  // Handle Up movement
				} else if (axis_value1 > 8000 || axis_value2 > 8000) { // Moved Down (positive)
				  //printf("Left Stick DOWN!\n");
				  // Handle Down movement
				  if(axis_value1 > 8000)
				      mPaddleDir += 1;
				  if(axis_value2 > 8000)
				      mPaddle2Dir += 1;
				  break;
				} else {
				  // Stick is near center (deadzone)
				  //printf("Left Stick Center\n");
				  break;
				}
			
			      }
			    break;
			  }
			  
		}

		
	
	
	// Get state of keyboard
	const Uint8* state = SDL_GetKeyboardState(NULL);
	// If escape is pressed, also end loop
	if (state[SDL_SCANCODE_ESCAPE])
	{
		mIsRunning = false;
	}
	
	// Update paddle direction based on W/S keys
	
	//
	  /*if (state[SDL_SCANCODE_W])
	{
		mPaddleDir -= 1;
	}
	if (state[SDL_SCANCODE_S])
	{
		mPaddleDir += 1;
		}*/
}

void Game::UpdateGame()
{
	// Wait until 16ms has elapsed since last frame
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + 16))
		;

	// Delta time is the difference in ticks from last frame
	// (converted to seconds)
	float deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.0f;
	
	// Clamp maximum delta time value
	if (deltaTime > 0.05f)
	{
		deltaTime = 0.05f;
	}

	// Update tick counts (for next frame)
	mTicksCount = SDL_GetTicks();
	
	// Update paddle position based on direction
	if (mPaddleDir != 0)
	{
		mPaddlePos.y += mPaddleDir * 300.0f * deltaTime;
		// Make sure paddle doesn't move off screen!
		if (mPaddlePos.y < (paddleH/2.0f + thickness))
		{
			mPaddlePos.y = paddleH/2.0f + thickness;
		}
		else if (mPaddlePos.y > (HEIGHT - paddleH/2.0f - thickness))
		{
			mPaddlePos.y = HEIGHT - paddleH/2.0f - thickness;
		}
	}

	if (mPaddle2Dir != 0)
	{
		mPaddlePos2.y += mPaddle2Dir * 300.0f * deltaTime;
		// Make sure paddle doesn't move off screen!
		if (mPaddlePos2.y < (paddleH/2.0f + thickness))
		{
			mPaddlePos2.y = paddleH/2.0f + thickness;
		}
		else if (mPaddlePos2.y > (HEIGHT - paddleH/2.0f - thickness))
		{
			mPaddlePos2.y = HEIGHT - paddleH/2.0f - thickness;
		}
	}
	
	// Update ball position based on ball velocity
	mBallPos.x += mBallVel.x * deltaTime;
	mBallPos.y += mBallVel.y * deltaTime;
	
	// Bounce if needed
	// Did we intersect with the paddle?
	float diff = mPaddlePos.y - mBallPos.y;
	float diff2 = mPaddlePos2.y - mBallPos.y;
	
	// Take absolute value of difference
	diff = (diff > 0.0f) ? diff : -diff;
	diff2 = (diff2 > 0.0f) ? diff2 : -diff2;
	if (
		// Our y-difference is small enough
		diff <= paddleH / 2.0f &&
		// We are in the correct x-position
		mBallPos.x <= 25.0f && mBallPos.x >= 20.0f &&
		// The ball is moving to the left
		mBallVel.x < 0.0f)
	{
		mBallVel.x *= -1.0f;
	}
	else if (
		// Our y-difference is small enough
		diff2 <= paddleH / 2.0f &&
		// We are in the correct x-position
		mBallPos.x >= WIDTH-24 && mBallPos.x <= WIDTH &&
		// The ball is moving to the left
		mBallVel.x > 0.0f)
	{
		mBallVel.x *= -1.0f;
	}
	// Did the ball go off the screen? (if so, end game)
	else if (mBallPos.x <= 0.0f)
	{
		mIsRunning = false;
	}
	// Did the ball collide with the right wall
	else if (mBallPos.x >= (WIDTH - thickness) && mBallVel.x > 0.0f)
	  {    mIsRunning = false;
	      //mBallVel.x *= -1.0f;
	}
	
	// Did the ball collide with the top wall?
	if (mBallPos.y <= thickness && mBallVel.y < 0.0f)
	{
		mBallVel.y *= -1;
	}
	// Did the ball collide with the bottom wall?
	else if (mBallPos.y >= (HEIGHT - thickness) &&
		mBallVel.y > 0.0f)
	{
		mBallVel.y *= -1;
	}
}

void Game::GenerateOutput()
{
	// Set draw color to blue
	SDL_SetRenderDrawColor(
		mRenderer,
		0,		// R
		0,		// G 
		0,	// B
		255		// A
	);
	
	// Clear back buffer
	SDL_RenderClear(mRenderer);

	// Draw walls
	SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
	
	// Draw top wall
	SDL_Rect wall{
		0,			// Top left x
		0,			// Top left y
		WIDTH,		// Width
		thickness	// Height
	};
	SDL_RenderFillRect(mRenderer, &wall);
	
	// Draw bottom wall
	wall.y = HEIGHT - thickness;
	SDL_RenderFillRect(mRenderer, &wall);
	
	// Draw right wall
	//wall.x = 1024 - thickness;
	//wall.y = 0;
	//wall.w = thickness;
	//wall.h = 1024;
	//SDL_RenderFillRect(mRenderer, &wall);
	SDL_SetRenderDrawColor(mRenderer, 0, 0, 255, 255);
	// Draw paddle
	SDL_Rect paddle{
		static_cast<int>(mPaddlePos.x),
		static_cast<int>(mPaddlePos.y - paddleH/2),
		thickness,
		static_cast<int>(paddleH)
	};
	SDL_RenderFillRect(mRenderer, &paddle);
	SDL_SetRenderDrawColor(mRenderer, 255, 0, 0, 255);
	SDL_Rect paddle2{
		static_cast<int>(mPaddlePos2.x),
		static_cast<int>(mPaddlePos2.y - paddleH/2),
		thickness+10,
		static_cast<int>(paddleH)
	};
	SDL_RenderFillRect(mRenderer, &paddle2);


	SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
	
	// Draw ball
	SDL_Rect ball{	
		static_cast<int>(mBallPos.x - thickness/2),
		static_cast<int>(mBallPos.y - thickness/2),
		thickness,
		thickness
	};
	SDL_RenderFillRect(mRenderer, &ball);
	
	// Swap front buffer and back buffer
	SDL_RenderPresent(mRenderer);
}

void Game::Shutdown()
{
	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);
	SDL_Quit();
}
