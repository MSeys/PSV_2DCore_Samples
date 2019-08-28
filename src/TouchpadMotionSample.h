#pragma once
#include "pch.h"

enum TouchMotionMode
{
	TOUCHPAD_DOWN, TOUCHPAD_UP, TOUCHPAD_MOTION
};

class TouchpadMotionSample
{
	std::vector<Point2f> m_FrontTouches; // 6 is max for front
	std::vector<Point2f> m_BackTouches; // 4 is max for back
	Color4 m_Color{ 255, 255, 255, 255 };

	std::vector<std::string> m_TMModeStrings{ "Touchpad Down", "Touchpad Up", "Touchpad Motion" };
	TouchMotionMode m_TouchMotionMode{ TOUCHPAD_DOWN };
	
public:
	TouchpadMotionSample();

	TouchpadMotionSample(const TouchpadMotionSample& other) = delete;
	TouchpadMotionSample& operator=(const TouchpadMotionSample& rhs) = delete;
	TouchpadMotionSample(const TouchpadMotionSample&& other) = delete;
	TouchpadMotionSample& operator=(const TouchpadMotionSample&& rhs) = delete;

	~TouchpadMotionSample();
	
	void Draw() const;

	void ProcessKeyDownEvent(const PSV_ButtonEvent& bEvent);

	void ProcessTouchpadDownEvent(const PSV_TouchpadEvent& tpEvent);
	void ProcessTouchpadUpEvent(const PSV_TouchpadEvent& tpEvent);
	void ProcessTouchpadMotionEvent(const PSV_TouchpadEvent& tpEvent);
};

