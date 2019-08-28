#include "SoundSample.h"

SoundSample::SoundSample()
{
}

SoundSample::~SoundSample()
{
}

void SoundSample::Draw() const
{
	Bank::FindMusic("bg_music")->SetVolume(m_Volume);
	Bank::FindSound("menu_button_press")->SetVolume(m_Volume);
	
	Bank::FindFont("ArialRoundedMTBold")->Draw(Point2f{ 5, 5 }, Color4{ 255, 255, 255, 255 }, 20, "Triangle (press to play, release to stop): Background Music", TOP_LEFT);
	Bank::FindFont("ArialRoundedMTBold")->Draw(Point2f{ 5, 30 }, Color4{ 255, 255, 255, 255 }, 20, "Cross (press to play, release to stop): Button Press", TOP_LEFT);
	Bank::FindFont("ArialRoundedMTBold")->Draw(Point2f{ 5, 55 }, Color4{ 255, 255, 255, 255 }, 20, "Volume: " + std::to_string(m_Volume), TOP_LEFT);
	
	Bank::FindFont("ArialRoundedMTBold")->Draw(Point2f{ float(SCREEN_WIDTH) / 2, float(SCREEN_HEIGHT) / 2 }, Color4{ 255, 255, 255, 255 }, 30, m_CurrentlyPlaying, MID_CENTER);
}

void SoundSample::ProcessKeyUpEvent(const PSV_ButtonEvent& bEvent)
{
	switch (bEvent.buttonType)
	{
	case TRIANGLE:
		Bank::FindMusic("bg_music")->Stop();
		m_CurrentlyPlaying = "Stopped: Background Music";
		break;
		
	case CROSS:
		Bank::FindSound("menu_button_press")->Stop();
		m_CurrentlyPlaying = "Stopped: Button Press";
		break;
		
	default:
		break;
	}
}

void SoundSample::ProcessKeyDownEvent(const PSV_ButtonEvent& bEvent)
{
	switch(bEvent.buttonType)
	{
	case TRIANGLE:
		Bank::FindMusic("bg_music")->Play(true);
		m_CurrentlyPlaying = "Playing: Background Music";
		break;
	
	case CROSS:
		Bank::FindSound("menu_button_press")->Play();
		m_CurrentlyPlaying = "Playing: Button Press";
		break;
		
	case DPAD_UP:
		if(m_Volume < 100)
			m_Volume++;
		break;
		
	case DPAD_DOWN:
		if (m_Volume > 0)
			m_Volume--;
		break;
		
	default:
		break;
	}
}
