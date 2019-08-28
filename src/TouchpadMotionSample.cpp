#include "TouchpadMotionSample.h"

TouchpadMotionSample::TouchpadMotionSample()
{
	for(int i{ 0 }; i < 6; i++)
	{
		m_FrontTouches.emplace_back(0, 0);
	}
	
	for (int i{ 0 }; i < 4; i++)
	{
		m_BackTouches.emplace_back(0, 0);
	}
}

TouchpadMotionSample::~TouchpadMotionSample()
{
}

void TouchpadMotionSample::Draw() const
{
	// necessary to set the correct touch sampling mode
	// While this can be put in the constructor, it would interfere with the other sample so we'll put it in Draw,
	// as this is the only function that is always called while in the sample.
	PSV_SetTouchSamplingMode(PSV_TOUCH_MOTION);

	// Drawing the circles
	for(Point2f point : m_FrontTouches)
	{
		if (point.x != 0 && point.y != 0)
			FillCircle(point, 10, m_Color);
	}
	
	for (Point2f point : m_BackTouches)
	{
		if(point.x != 0 && point.y != 0)
			FillCircle(point, 10, Color4{ 0, 0, 0, 100 });
	}
	
	// drawing some quick information
	Bank::FindFont("ArialRoundedMTBold")->Draw(Point2f{ 5, float(SCREEN_HEIGHT) - 30 }, m_Color, 20, "Use D-Pad UP/DOWN to switch...", BOTTOM_LEFT);
	Bank::FindFont("ArialRoundedMTBold")->Draw(Point2f{ 5, float(SCREEN_HEIGHT) - 5 }, m_Color, 20, "Current: " + m_TMModeStrings[m_TouchMotionMode], BOTTOM_LEFT);
}

void TouchpadMotionSample::ProcessKeyDownEvent(const PSV_ButtonEvent& bEvent)
{
	if(bEvent.buttonType == DPAD_UP)
	{
		if(m_TouchMotionMode > 0)
			m_TouchMotionMode = TouchMotionMode(int(m_TouchMotionMode - 1));
	}

	if (bEvent.buttonType == DPAD_DOWN)
	{
		if (m_TouchMotionMode < 2)
			m_TouchMotionMode = TouchMotionMode(int(m_TouchMotionMode + 1));
	}
}

void TouchpadMotionSample::ProcessTouchpadDownEvent(const PSV_TouchpadEvent& tpEvent)
{
	if (m_TouchMotionMode == TOUCHPAD_DOWN)
	{
		if (tpEvent.touchpadType == FRONT)
		{
			m_FrontTouches[tpEvent.touchVectorNum] = tpEvent.pressTouch;
		}

		else
		{
			m_BackTouches[tpEvent.touchVectorNum] = tpEvent.pressTouch;
		}
	}
}

void TouchpadMotionSample::ProcessTouchpadUpEvent(const PSV_TouchpadEvent& tpEvent)
{
	if (m_TouchMotionMode == TOUCHPAD_UP)
	{
		if (tpEvent.touchpadType == FRONT)
		{
			m_FrontTouches[tpEvent.touchVectorNum] = tpEvent.releaseTouch;
		}

		else
		{
			m_BackTouches[tpEvent.touchVectorNum] = tpEvent.releaseTouch;
		}
	}
}

void TouchpadMotionSample::ProcessTouchpadMotionEvent(const PSV_TouchpadEvent& tpEvent)
{
	if (m_TouchMotionMode == TOUCHPAD_MOTION)
	{
		if (tpEvent.touchpadType == FRONT)
		{
			m_FrontTouches[tpEvent.touchVectorNum] = tpEvent.motionTouch;
		}

		else
		{
			m_BackTouches[tpEvent.touchVectorNum] = tpEvent.motionTouch;
		}
	}
}
