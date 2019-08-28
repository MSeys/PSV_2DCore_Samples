#pragma once
#include "pch.h"
#include "DrawSample.h"
#include "MenuButton.h"

#include "InputSample.h"
#include "TouchpadMotionSample.h"
#include "TouchpadSwipeSample.h"
#include "TransformationSample.h"
#include "SoundSample.h"

enum SampleState
{
	Menu, SDraw, SInput, STouchpad_Motion, STouchpad_Swipe, STransformations, SSounds
};

class GameHandler
{
	DrawSample* m_pDrawSample;
	InputSample* m_pInputSample;
	TouchpadMotionSample* m_pTouchpadMotionSample;
	TouchpadSwipeSample* m_pTouchpadSwipeSample;
	TransformationSample* m_pTransformationSample;
	SoundSample* m_pSoundSample;
	
	SampleState m_State{ Menu };

	std::vector<MenuButton*> m_MenuButtons;
	int m_MenuIndex{ 0 };
	
public:
	GameHandler();

	GameHandler(const GameHandler& other) = delete;
	GameHandler& operator=(const GameHandler& rhs) = delete;
	GameHandler(const GameHandler&& other) = delete;
	GameHandler& operator=(const GameHandler&& rhs) = delete;

	~GameHandler();

	void Update(float elapsedSec);
	void Draw() const;

	void ProcessKeyUpEvent(const PSV_ButtonEvent& bEvent);
	void ProcessKeyDownEvent(const PSV_ButtonEvent& bEvent);
	void ProcessKeyHeldEvent(const PSV_ButtonEvent& bEvent);

	void ProcessJoystickMotionEvent(const PSV_JoystickEvent& jEvent);

	void ProcessTouchpadDownEvent(const PSV_TouchpadEvent& tpEvent);
	void ProcessTouchpadUpEvent(const PSV_TouchpadEvent& tpEvent);
	void ProcessTouchpadMotionEvent(const PSV_TouchpadEvent& tpEvent);
	void ProcessTouchpadSwipeEvent(const PSV_TouchpadEvent& tpEvent);
	
private:
	void Initialize();
	void Cleanup();

	void DrawButtons() const;

	void ProcessButtonSelect(const PSV_ButtonEvent& bEvent);
};

