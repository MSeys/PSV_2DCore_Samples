#include "DrawSample.h"

DrawSample::DrawSample()
{
}

DrawSample::~DrawSample()
{
}

void DrawSample::Update(float elapsedSec)
{
	if(m_DrawMenuIndex == Circles)
		UpdateCircles(elapsedSec);
}

void DrawSample::UpdateCircles(float elapsedSec)
{
	m_MovingCircle.center.x += m_CircleVelocity.x * elapsedSec;
	
	if (m_CircleVelocity.x > 0 && m_MovingCircle.center.x + m_MovingCircle.radius > float(SCREEN_WIDTH))
	{
		m_CircleVelocity.x = -m_CircleVelocity.x;
	}

	else if (m_CircleVelocity.x < 0 && m_MovingCircle.center.x - m_MovingCircle.radius < 0)
	{
		m_CircleVelocity.x = -m_CircleVelocity.x;
	}

	m_MovingCircle.center.y += m_CircleVelocity.y * elapsedSec;
	if (m_CircleVelocity.y > 0 && m_MovingCircle.center.y + m_MovingCircle.radius > float(SCREEN_HEIGHT))
	{
		m_CircleVelocity.y = -m_CircleVelocity.y;
	}

	else if (m_CircleVelocity.y < 0 && m_MovingCircle.center.y - m_MovingCircle.radius < 0)
	{
		m_CircleVelocity.y = -m_CircleVelocity.y;
	}
}

void DrawSample::Draw() const
{
	switch(DrawSampleMode(m_DrawMenuIndex))
	{
	case Rectangles:
		DrawRectangles();
		break;
		
	case Circles:
		DrawCircles();
		break;
		
	case Lines:
		DrawLines();	
		break;
		
	case Textures:
		DrawTextures();
		break;
		
	case Text:
		DrawText();
		break;
	}

	Bank::FindUI("draw_" + std::to_string(m_DrawMenuIndex))->Draw();
}

void DrawSample::DrawRectangles() const
{
	DrawRect(Rectf{ 5, 5, float(SCREEN_WIDTH) - 5, float(SCREEN_HEIGHT) - 5 }, 5);
	FillRect(Rectf{ 150, 300, 263, 75 }, Color4{ 125, 230, 153, 255 });
	DrawRect(Rectf{ 450, 211, 100, 125 }, 3);
	FillRect(Rectf{ 300, 100, 153, 245 }, Color4{ 0, 125, 240, 255 });
}

void DrawSample::DrawCircles() const
{
	FillCircle(m_MovingCircle);
	FillCircle(Circlef{ 150.f, 200.f, 20 }, Color4{ 255, 0, 0, 255 });
	FillCircle(Circlef{ 450.f, 75.f, 32 }, Color4{ 0, 0, 255, 255 });
	FillCircle(Circlef{ 524.f, 324.f, 26 }, Color4{ 0, 255, 0, 255 });
}

void DrawSample::DrawLines() const
{
	DrawLine(Point2f{ 0, 0 }, Point2f{ float(SCREEN_WIDTH), float(SCREEN_HEIGHT) }, 5);
	DrawLine(Point2f{ 0, float(SCREEN_HEIGHT) }, Point2f{ float(SCREEN_WIDTH), 0 }, 10, Color3{ 164, 67, 148 }, 255);
	DrawLine(Point2f{ 100, 50 }, Point2f{ 348, 183 }, 10, Color3{ 30, 145, 255 }, 255);
}

void DrawSample::DrawTextures() const
{
	// a srcRect of 0 width or 0 height means that it will take the complete image instead of a part.
	
	Bank::FindAsset("psvita")->Draw(Point2f{ 0, float(SCREEN_HEIGHT - Bank::FindAsset("psvita")->GetHeight() * 0.5) }, Rectf{ 0, 0, 0, 0 }, Scale2f{ 0.5, 0.5 });
	Bank::FindAsset("random")->Draw(Point2f{ 480, 100 }, Rectf{ 0, 0, 50, 50 }, Scale2f{ 1, 1 }, 0.5);
	Bank::FindAsset("random")->Draw(Point2f{ 371, 245 }, Rectf{ 75, 75, 50, 50 }, Scale2f{ 1, 1 }, 0.2);
}

void DrawSample::DrawText() const
{
	Bank::FindFont("ArialRoundedMTBold")->Draw(Point2f{ 5, float(SCREEN_HEIGHT) - 5 }, 18, "Press Triangle to change centered text.", BOTTOM_LEFT);
	Bank::FindFont("ArialRoundedMTBold")->Draw(Point2f{ float(SCREEN_WIDTH) / 2, float(SCREEN_HEIGHT) / 2 }, 30, m_ChangeText, MID_CENTER);
	Bank::FindFont("ArialRoundedMTBold")->Draw(Point2f{ float(SCREEN_WIDTH) / 2, 55 }, 40, "Hello World!", MID_CENTER);
}

void DrawSample::ProcessKeyDownEvent(const PSV_ButtonEvent& bEvent)
{
	if (bEvent.buttonType == DPAD_LEFT)
	{
		if (m_DrawMenuIndex > 0)
		{
			m_DrawMenuIndex--;
		}
	}

	if (bEvent.buttonType == DPAD_RIGHT)
	{
		if (m_DrawMenuIndex < 4)
		{
			m_DrawMenuIndex++;
		}
	}

	if(bEvent.buttonType == TRIANGLE)
	{
		m_ChangeText = VitaKeyboardGet("Text Sample Input", m_ChangeText, 100, 0);
	}
}