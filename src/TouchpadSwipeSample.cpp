#include "TouchpadSwipeSample.h"

TouchpadSwipeSample::TouchpadSwipeSample()
{
}

TouchpadSwipeSample::~TouchpadSwipeSample()
{
}

void TouchpadSwipeSample::Draw() const
{
	PSV_SetTouchSamplingMode(PSV_TOUCH_SWIPE);
	
	
	DrawLine(m_PressTouch, m_ReleaseTouch, Color4{ 0, 0, 0, 255 }, 3);
	FillCircle(m_PressTouch, 15);
	FillCircle(m_ReleaseTouch, 15);
	
	Bank::FindUI("swipe_details")->Draw();
	Bank::FindFont("ArialRoundedMTBold")->Draw(Point2f{ 27, 73 }, Color4{ 255, 255, 255, 255 }, 20, std::to_string(m_Length), TOP_LEFT);
	Bank::FindFont("ArialRoundedMTBold")->Draw(Point2f{ 27, 121 }, Color4{ 255, 255, 255, 255 }, 20, std::to_string(m_Velocity), TOP_LEFT);
	Bank::FindFont("ArialRoundedMTBold")->Draw(Point2f{ 27, 169 }, Color4{ 255, 255, 255, 255 }, 20, std::to_string(m_AngleDegrees) + "°", TOP_LEFT);
	Bank::FindFont("ArialRoundedMTBold")->Draw(Point2f{ 27, 214 }, Color4{ 255, 255, 255, 255 }, 20, m_Direction, TOP_LEFT);
}

void TouchpadSwipeSample::ProcessTouchpadSwipeEvent(const PSV_TouchpadEvent& tpEvent)
{
	m_PressTouch = tpEvent.pressTouch;
	m_ReleaseTouch = tpEvent.releaseTouch;
	m_Length = tpEvent.length;
	m_Velocity = tpEvent.velocity;
	m_AngleDegrees = tpEvent.angleDegrees;
	m_Direction = PSV_TouchSwipeDirectionStrings[int(tpEvent.touchpadSwipeDirection)];
}
