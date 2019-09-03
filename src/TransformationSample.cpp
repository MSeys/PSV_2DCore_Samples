#include "TransformationSample.h"

TransformationSample::TransformationSample()
{
}

TransformationSample::~TransformationSample()
{
}

void TransformationSample::Draw() const
{
	Vector2f firstTranslate{};
	Vector2f secondTranslate{};
	// Vector2f thirdTranslate{};
	// TEMP: temporarily removed third transformation due to not being correct. If you find out how this could be:
	// Answer the issue here: https://github.com/MSeys/PSV_2DCore/issues/1
	
	// Circle position has to scale with it as the scale goes on everything.
	PSV_Begin(); // begin 1
		PSV_Translate(m_Translations.x, m_Translations.y);
		PSV_Scale(m_Scale, m_Scale);
		FillCircle(Circlef{ 100, 100, 30 });
		Bank::FindFont("ArialRoundedMTBold")->Draw(Point2f{ float(SCREEN_WIDTH) / 2, float(SCREEN_HEIGHT) / 2 }, 20, "Centered at Translate (0, 0)", MID_CENTER);
		firstTranslate = PSV_Translations[PSV_CT];
	
		PSV_Begin(); // begin 2
			// Scale does change up the location the circle is drawn!
			// Suggest at the repo: https://github.com/MSeys/PSV_2DCore
			// If you want a translation that is independent from the scale!
			PSV_Translate(100, 100);
			PSV_Scale(0.5, 0.5);
			FillCircle(Circlef{ 200, 200, 30 });
			secondTranslate = PSV_Translations[PSV_CT];
		PSV_End(); // end 2
	PSV_End(); // end 1

	Bank::FindFont("ArialRoundedMTBold")->Draw(Point2f{ 5, 5 }, 20, "Always at (5, 5) - Position from TOP_LEFT", TOP_LEFT);
	
	Bank::FindFont("ArialRoundedMTBold")->Draw(Point2f{ 5, float(SCREEN_HEIGHT) - 55 }, 20, std::to_string(firstTranslate.x) + " - " + std::to_string(firstTranslate.y), BOTTOM_LEFT);
	Bank::FindFont("ArialRoundedMTBold")->Draw(Point2f{ 5, float(SCREEN_HEIGHT) - 30 }, 20, std::to_string(secondTranslate.x) + " - " + std::to_string(secondTranslate.y), BOTTOM_LEFT);
}

void TransformationSample::Update(float elapsedSec)
{
	// You can set limits to avoid translating too much
	// for the sample however, no limitations have been set to keep it simple

	m_Translations.x += m_TranslateVelocity.x * elapsedSec;
	m_Translations.y += m_TranslateVelocity.y * elapsedSec;
	m_Scale += m_ScaleVelocity * elapsedSec;
}

void TransformationSample::ProcessKeyUpEvent(const PSV_ButtonEvent& bEvent)
{
	switch (bEvent.buttonType)
	{
	case DPAD_UP:
		m_TranslateVelocity.y = 0;
		break;
		
	case DPAD_DOWN:
		m_TranslateVelocity.y = 0;
		break;

	case DPAD_LEFT:
		m_TranslateVelocity.x = 0;
		break;
		
	case DPAD_RIGHT:
		m_TranslateVelocity.x = 0;
		break;

	case TRIANGLE:
		m_ScaleVelocity = 0;
		break;
		
	case CROSS:
		m_ScaleVelocity = 0;
		break;
	}
}

void TransformationSample::ProcessKeyDownEvent(const PSV_ButtonEvent& bEvent)
{
	switch(bEvent.buttonType)
	{
	case DPAD_UP:
		m_TranslateVelocity.y = -100.f;
		break;
		
	case DPAD_DOWN:
		m_TranslateVelocity.y = 100.f;
		break;
		
	case DPAD_LEFT:
		m_TranslateVelocity.x = -100.f;
		break;
		
	case DPAD_RIGHT:
		m_TranslateVelocity.x = 100.f;
		break;

	case TRIANGLE:
		m_ScaleVelocity = 0.1f;
		break;

	case CROSS:
		m_ScaleVelocity = -0.1f;
		break;
	}
}
