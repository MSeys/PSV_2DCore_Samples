#pragma once
#include "pch.h"

class InputSample
{
	
public:
	InputSample();

	InputSample(const InputSample& other) = delete;
	InputSample& operator=(const InputSample& rhs) = delete;
	InputSample(const InputSample&& other) = delete;
	InputSample& operator=(const InputSample&& rhs) = delete;

	~InputSample();
	
	void Draw() const;
	
	void ProcessKeyUpEvent(const PSV_ButtonEvent& bEvent);
	void ProcessKeyDownEvent(const PSV_ButtonEvent& bEvent);
	void ProcessKeyHeldEvent(const PSV_ButtonEvent& bEvent);

	void ProcessJoystickMotionEvent(const PSV_JoystickEvent& jEvent);
};

