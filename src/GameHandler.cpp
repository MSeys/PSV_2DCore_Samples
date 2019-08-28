#include "GameHandler.h"

GameHandler::GameHandler()
	: m_pDrawSample(new DrawSample())
	, m_pInputSample(new InputSample())
	, m_pTouchpadMotionSample(new TouchpadMotionSample())
	, m_pTouchpadSwipeSample(new TouchpadSwipeSample())
	, m_pTransformationSample(new TransformationSample())
	, m_pSoundSample(new SoundSample())
{
	Initialize();
}

GameHandler::~GameHandler()
{
	Cleanup();
}

void GameHandler::Update(float elapsedSec)
{
	switch (m_State)
	{
	case SDraw:
		m_pDrawSample->Update(elapsedSec);
		break;

	case STransformations:
		m_pTransformationSample->Update(elapsedSec);
		break;
	}
}

void GameHandler::Draw() const
{	
	// Drawing basic menu textures (using the bank, specifically from the UI files)
	Bank::FindUI("background")->Draw();
	
	switch (m_State)
	{
	case Menu:
		Bank::FindUI("menu_bar")->Draw();
		Bank::FindUI("controls")->Draw(Point2f{ float(SCREEN_WIDTH) - Bank::FindUI("controls")->GetWidth(), 210.f }, Rectf{ 0, 0, 0, 0 }, Scale2f{ 1, 1 });
		DrawButtons();
		break;
		
	case SDraw:
		m_pDrawSample->Draw();
		break;
		
	case SInput:
		m_pInputSample->Draw();
		break;
		
	case STouchpad_Motion:
		m_pTouchpadMotionSample->Draw();
		break;
		
	case STouchpad_Swipe:
		m_pTouchpadSwipeSample->Draw();
		break;

	case STransformations:
		m_pTransformationSample->Draw();
		break;
		
	case SSounds:
		m_pSoundSample->Draw();
		break;
	}

	if (m_State != Menu)
	{
		Bank::FindUI("start_return")->Draw(Point2f{ float(SCREEN_WIDTH) - Bank::FindUI("start_return")->GetWidth(), float(SCREEN_HEIGHT) - Bank::FindUI("start_return")->GetHeight() });
	}
}

void GameHandler::ProcessKeyUpEvent(const PSV_ButtonEvent& bEvent)
{
	// "global" event, this will put the state back in Menu, no matter the other state you are in
	if (bEvent.buttonType == START)
	{
		m_State = Menu;
	}

	switch(m_State)
	{
	case SInput:
		m_pInputSample->ProcessKeyUpEvent(bEvent);
		break;
		
	case STransformations:
		m_pTransformationSample->ProcessKeyUpEvent(bEvent);
		break;

	case SSounds:
		m_pSoundSample->ProcessKeyUpEvent(bEvent);
		break;
		
	default:
		break;
	}		
}

void GameHandler::ProcessKeyDownEvent(const PSV_ButtonEvent& bEvent)
{
	switch (m_State)
	{
	case Menu:
		ProcessButtonSelect(bEvent);
		break;

	case SDraw:
		m_pDrawSample->ProcessKeyDownEvent(bEvent);
		break;

	case SInput:
		m_pInputSample->ProcessKeyDownEvent(bEvent);
		break;

	case STouchpad_Motion:
		m_pTouchpadMotionSample->ProcessKeyDownEvent(bEvent);
		break;

	case STransformations:
		m_pTransformationSample->ProcessKeyDownEvent(bEvent);
		break;

	case SSounds:
		m_pSoundSample->ProcessKeyDownEvent(bEvent);
		break;

	default:
		break;
	}
}

void GameHandler::ProcessKeyHeldEvent(const PSV_ButtonEvent& bEvent)
{
	if (m_State == SInput)
		m_pInputSample->ProcessKeyHeldEvent(bEvent);
}

void GameHandler::ProcessJoystickMotionEvent(const PSV_JoystickEvent& jEvent)
{
	if (m_State == SInput)
		m_pInputSample->ProcessJoystickMotionEvent(jEvent);
}

void GameHandler::ProcessTouchpadDownEvent(const PSV_TouchpadEvent& tpEvent)
{
	if (m_State == STouchpad_Motion)
		m_pTouchpadMotionSample->ProcessTouchpadDownEvent(tpEvent);
}

void GameHandler::ProcessTouchpadUpEvent(const PSV_TouchpadEvent& tpEvent)
{
	if (m_State == STouchpad_Motion)
		m_pTouchpadMotionSample->ProcessTouchpadUpEvent(tpEvent);
}

void GameHandler::ProcessTouchpadMotionEvent(const PSV_TouchpadEvent& tpEvent)
{
	if (m_State == STouchpad_Motion)
		m_pTouchpadMotionSample->ProcessTouchpadMotionEvent(tpEvent);
}

void GameHandler::ProcessTouchpadSwipeEvent(const PSV_TouchpadEvent& tpEvent)
{
	if (m_State == STouchpad_Swipe)
		m_pTouchpadSwipeSample->ProcessTouchpadSwipeEvent(tpEvent);
}

void GameHandler::Initialize()
{
	float yPos{ 210.f };
	float gap{ 15.f };

	// set first
	m_MenuButtons.push_back(new MenuButton{ Point2f{ 0, yPos }, "Draw - Update" });
	m_MenuButtons[0]->SetSelected(true);

	// others
	const int amountBtns{ 5 };
	std::string ButtonNames[amountBtns]{ "PSVita Input", "Touchpad Motion", "Touchpad Swipe", "Transformations", "Sounds" };

	for (size_t i{}; i < amountBtns; i++)
	{
		yPos += m_MenuButtons[0]->GetHeight() + gap;
		m_MenuButtons.push_back(new MenuButton{ Point2f{ 0, yPos }, ButtonNames[i] });
	}
}

void GameHandler::Cleanup()
{
	for (MenuButton* button : m_MenuButtons)
	{
		delete button;
		button = nullptr;
	}

	delete m_pDrawSample;
	m_pDrawSample = nullptr;

	delete m_pInputSample;
	m_pInputSample = nullptr;

	delete m_pTouchpadMotionSample;
	m_pTouchpadMotionSample = nullptr;

	delete m_pTouchpadSwipeSample;
	m_pTouchpadSwipeSample = nullptr;

	delete m_pTransformationSample;
	m_pTransformationSample = nullptr;

	delete m_pSoundSample;
	m_pSoundSample = nullptr;
}

void GameHandler::DrawButtons() const
{
	for (MenuButton* button : m_MenuButtons)
	{
		button->Draw();
	}
}

void GameHandler::ProcessButtonSelect(const PSV_ButtonEvent& bEvent)
{
	if (bEvent.buttonType == DPAD_UP)
	{
		if (m_MenuIndex > 0)
		{
			m_MenuIndex--;

			// set correct selected
			for (int i{}; i < int(m_MenuButtons.size()); i++)
			{
				if (i != m_MenuIndex)
				{
					m_MenuButtons[i]->SetSelected(false);
				}

				else
				{
					m_MenuButtons[i]->SetSelected(true);
				}
			}
		}
	}

	if (bEvent.buttonType == DPAD_DOWN)
	{
		if (m_MenuIndex < int(m_MenuButtons.size() - 1))
		{
			m_MenuIndex++;

			// set correct selected
			for (int i{}; i < int(m_MenuButtons.size()); i++)
			{
				if (i != m_MenuIndex)
				{
					m_MenuButtons[i]->SetSelected(false);
				}

				else
				{
					m_MenuButtons[i]->SetSelected(true);
				}
			}
		}
	}

	if(bEvent.buttonType == CROSS)
	{
		m_State = SampleState(m_MenuIndex + 1);
	}
}
