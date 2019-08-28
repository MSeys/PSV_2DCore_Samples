#pragma once

// Be sure to include pch!
#include "pch.h"

enum DrawSampleMode
{
	Rectangles, Circles, Lines, Textures, Text
};

class DrawSample
{
	int m_DrawMenuIndex{ 0 };
	std::string m_ChangeText{ "Change me!" };

	Circlef m_MovingCircle{ float(SCREEN_WIDTH) / 2, float(SCREEN_HEIGHT) / 2, 35 };
	Scale2f m_CircleVelocity{ 150.f, 100.f };
public:
	DrawSample();

	DrawSample(const DrawSample& other) = delete;
	DrawSample& operator=(const DrawSample& rhs) = delete;
	DrawSample(const DrawSample&& other) = delete;
	DrawSample& operator=(const DrawSample&& rhs) = delete;

	~DrawSample();

	void Update(float elapsedSec);
	void Draw() const;
	void ProcessKeyDownEvent(const PSV_ButtonEvent& bEvent);

private:
	void UpdateCircles(float elapsedSec);

	void DrawRectangles() const;
	void DrawCircles() const;
	void DrawLines() const;
	void DrawTextures() const;
	void DrawText() const;
};