#pragma once
#include "pch.h"

class TransformationSample
{
	Vector2f m_Translations{ 0, 0 };
	Vector2f m_TranslateVelocity{ 0, 0 };
	float m_Scale{ 1 };
	float m_ScaleVelocity{ 0 };
	
public:
	TransformationSample();

	TransformationSample(const TransformationSample& other) = delete;
	TransformationSample& operator=(const TransformationSample& rhs) = delete;
	TransformationSample(const TransformationSample&& other) = delete;
	TransformationSample& operator=(const TransformationSample&& rhs) = delete;

	~TransformationSample();
	
	void Draw() const;
	void Update(float elapsedSec);
	
	void ProcessKeyUpEvent(const PSV_ButtonEvent& bEvent);
	void ProcessKeyDownEvent(const PSV_ButtonEvent& bEvent);
};