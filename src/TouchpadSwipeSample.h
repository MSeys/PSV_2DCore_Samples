#pragma once
#include "pch.h"

class TouchpadSwipeSample
{
	// only going to show one swipe at a time - default is invisible
	Point2f m_PressTouch{ -100, -100 };
	Point2f m_ReleaseTouch{ -100, -100 };
	float m_Velocity{};
	float m_Length{};
	int m_AngleDegrees{};
	std::string m_Direction{};
	
public:
	TouchpadSwipeSample();

	TouchpadSwipeSample(const TouchpadSwipeSample& other) = delete;
	TouchpadSwipeSample& operator=(const TouchpadSwipeSample& rhs) = delete;
	TouchpadSwipeSample(const TouchpadSwipeSample&& other) = delete;
	TouchpadSwipeSample& operator=(const TouchpadSwipeSample&& rhs) = delete;

	~TouchpadSwipeSample();
	
	void Draw() const;
	void ProcessTouchpadSwipeEvent(const PSV_TouchpadEvent& tpEvent);
};

