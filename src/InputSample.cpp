#include "InputSample.h"

InputSample::InputSample()
{
}

InputSample::~InputSample()
{
}

void InputSample::Draw() const
{
	// Note: This code was based on VitaTester (hence the code inside the Draw function instead of the respective event functions). 
	// https://github.com/SMOKE5/VitaTester
	// 
	// You can however check ONE button state (accessible through ButtonEvent / bEvent inside the function)
	// These are used in the menu, you can check out that class for an example how it works.
	
	// Draw background
	FillRect(Rectf{ 0, 0, float(SCREEN_WIDTH), float(SCREEN_HEIGHT) }, Color4{ 0, 0, 0, 255 });
	Bank::FindUI("input_background")->Draw(Point2f{ 0, 54 });

	// Draw analog sticks
	Bank::FindUI("analog")->Draw(Point2f{ 85.f + float(PSV_Joysticks.at(LSTICK).x - 128) / 8, 285.f + float(PSV_Joysticks.at(LSTICK).y - 128) / 8.f });
	Bank::FindUI("analog")->Draw(Point2f{ 802.f + float(PSV_Joysticks.at(RSTICK).x - 128) / 8, 285.f + float(PSV_Joysticks.at(RSTICK).y - 128) / 8.f });
	
	// This is a way to check directly in other functions besides the Event functions
	// These are also handy if you want to check multiple buttons states at the same time.
	if(PSV_Buttons.at(DPAD_UP).isPressed || PSV_Buttons.at(DPAD_UP).isHeld)
	{
		Bank::FindUI("dpad")->Draw(Point2f{ 59, 134 });
	}
	
	if (PSV_Buttons.at(DPAD_DOWN).isPressed || PSV_Buttons.at(DPAD_DOWN).isHeld)
	{
		Bank::FindUI("dpad")->Draw(Point2f{ 130, 272 }, 3.14f);
	}

	if (PSV_Buttons.at(DPAD_LEFT).isPressed || PSV_Buttons.at(DPAD_LEFT).isHeld)
	{
		Bank::FindUI("dpad")->Draw(Point2f{ 24.3f, 238.6f }, -1.57f);
	}

	if (PSV_Buttons.at(DPAD_RIGHT).isPressed || PSV_Buttons.at(DPAD_RIGHT).isHeld)
	{
		Bank::FindUI("dpad")->Draw(Point2f{ 164, 166 }, 1.57f);
	}

	if (PSV_Buttons.at(CROSS).isPressed || PSV_Buttons.at(CROSS).isHeld)
	{
		Bank::FindUI("cross")->Draw(Point2f{ 830, 202 });
	}

	if (PSV_Buttons.at(CIRCLE).isPressed || PSV_Buttons.at(CIRCLE).isHeld)
	{
		Bank::FindUI("circle")->Draw(Point2f{ 869, 165 });
	}

	if (PSV_Buttons.at(SQUARE).isPressed || PSV_Buttons.at(SQUARE).isHeld)
	{
		Bank::FindUI("square")->Draw(Point2f{ 790, 165 });
	}

	if (PSV_Buttons.at(TRIANGLE).isPressed || PSV_Buttons.at(TRIANGLE).isHeld)
	{
		Bank::FindUI("triangle")->Draw(Point2f{ 830, 127 });
	}

	if (PSV_Buttons.at(START).isPressed || PSV_Buttons.at(START).isHeld)
	{
		Bank::FindUI("start")->Draw(Point2f{ 841, 373 });
	}

	if (PSV_Buttons.at(SELECT).isPressed || PSV_Buttons.at(SELECT).isHeld)
	{
		Bank::FindUI("select")->Draw(Point2f{ 781, 375 });
	}

	if (PSV_Buttons.at(LTRIGGER).isPressed || PSV_Buttons.at(LTRIGGER).isHeld)
	{
		Bank::FindUI("ltrigger")->Draw(Point2f{ 38, 40 });
	}

	if (PSV_Buttons.at(RTRIGGER).isPressed || PSV_Buttons.at(RTRIGGER).isHeld)
	{
		Bank::FindUI("rtrigger")->Draw(Point2f{ 720, 40 });
	}
}

void InputSample::ProcessKeyUpEvent(const PSV_ButtonEvent& bEvent)
{
	// Example of key event - triggered on release

	if(bEvent.buttonType == SQUARE)
	{
		// if Square is released
	}

	// you can also use a switch
	switch (bEvent.buttonType)
	{
	case CROSS: break;
	case CIRCLE: break;
	case SQUARE: break;
	case TRIANGLE: break;
	case LTRIGGER: break;
	case RTRIGGER: break;
	case DPAD_UP: break;
	case DPAD_DOWN: break;
	case DPAD_LEFT: break;
	case DPAD_RIGHT: break;
	case START: break;
	case SELECT: break;
	default: break;
	}

	// Note: There is not much data to send with button actions except held, pressed or released, but these are handled separately.
}

void InputSample::ProcessKeyDownEvent(const PSV_ButtonEvent& bEvent)
{
	// Example of key event - triggered on press
	// pressed state changes to false if button gets released or goes into held after 0.4 seconds
	
	if(bEvent.buttonType == CIRCLE)
	{
		// if Circle is pressed
	}

	// you can also use a switch
	switch (bEvent.buttonType)
	{
	case CROSS: break;
	case CIRCLE: break;
	case SQUARE: break;
	case TRIANGLE: break;
	case LTRIGGER: break;
	case RTRIGGER: break;
	case DPAD_UP: break;
	case DPAD_DOWN: break;
	case DPAD_LEFT: break;
	case DPAD_RIGHT: break;
	case START: break;
	case SELECT: break;
	default: break;
	}

	// Note: There is not much data to send with button actions except held, pressed or released, but these are handled separately.
}

void InputSample::ProcessKeyHeldEvent(const PSV_ButtonEvent& bEvent)
{
	// Example of key event - triggered on held (which is after 0.4 seconds)
	// held state changes to false if button gets released
	
	if(bEvent.buttonType == CROSS)
	{
		// if Cross is held
	}

	// you can also use a switch
	switch (bEvent.buttonType)
	{
	case CROSS: break;
	case CIRCLE: break;
	case SQUARE: break;
	case TRIANGLE: break;
	case LTRIGGER: break;
	case RTRIGGER: break;
	case DPAD_UP: break;
	case DPAD_DOWN: break;
	case DPAD_LEFT: break;
	case DPAD_RIGHT: break;
	case START: break;
	case SELECT: break;
	default: break;
	}

	// Note: There is not much data to send with button actions except held, pressed or released, but these are handled separately.
}

void InputSample::ProcessJoystickMotionEvent(const PSV_JoystickEvent& jEvent)
{
	//Example of joystick motion

	if(jEvent.joyType == LSTICK)
	{
		// Direction of joystick, including 4 main directions, the diagonals and the middle/idle position.
		if(jEvent.joyDirection == MIDDLE)
		{
			// Middle position
		}

		else if(jEvent.joyDirection == NE)
		{
			// North east direction
		}

		// You can also use a switch case
		switch(jEvent.joyDirection)
		{
		case NW: break;
		case N: break;
		case NE: break;
		case W: break;
		case E: break;
		case SW: break;
		case S: break;
		case SE: break;
		case MIDDLE: break;
		default: break;
		}
	}

	// There is also more values you can get using the JoystickEvent such as the x and y value, aswell as the angle the stick is positioned in, in radians or degrees.
}
