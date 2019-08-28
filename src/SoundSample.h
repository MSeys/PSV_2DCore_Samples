#pragma once
#include "pch.h"

class SoundSample
{
	std::string m_CurrentlyPlaying;
	int m_Volume{ 100 };
public:
	SoundSample();

	SoundSample(const SoundSample& other) = delete;
	SoundSample& operator=(const SoundSample& rhs) = delete;
	SoundSample(const SoundSample&& other) = delete;
	SoundSample& operator=(const SoundSample&& rhs) = delete;

	~SoundSample();

	void Draw() const;

	void ProcessKeyUpEvent(const PSV_ButtonEvent& bEvent);
	void ProcessKeyDownEvent(const PSV_ButtonEvent& bEvent);
};

