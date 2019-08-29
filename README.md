**Welcome to the Samples repository, here you will find the samples for the PSVita 2D Core.**

# List of Samples
* Draw and Update
* Input (Buttons and Joysticks)
* Touchpad Press / Release / Motion
* Touchpad Swiping
* View/Camera Transformation
* Sound

## Draw and Update
This sample shows how you can:
* Draw Rectangles
* Draw Filled Rectangles
* Draw Filled Circles
* Draw Textures
  * Rotated
  * Scaled
  * Part
  * Rotated Hotspot (Not fully tested)
* Draw Text / Font
  * Includes using the Vita Keyboard

## Input 
This Sample was heavily based on VitaTester.

**Warning:**
This sample does not use the power of the event handling of joysticks and buttons.
However, I did put some example code (without action) in the functions for you to learn from aswell as put a few comments in place.

## Touchpad Press / Release / Motion
This sample sets the TouchSamplingMode to TOUCHPAD_MOTION and uses the events for Touchpad Press, Release and Motion.
I used DPAD UP and DPAD DOWN to allow you to check each event handled separately in the application.

## Touchpad Swiping
This sample sets the TouchSamplingMode to TOUCHPAD_SWIPE and uses the only event used for Swiping.
This sample does NOT trigger press and release to avoid issues with eachother.

This event sends a lot of extra data that you could use for your own purposes.
The positions have been drawn and the other data has been shown in the top left corner.

## Transformations (Experimental)
This sample is very experimental.
This is an alternative way to fake a View Camera as Vita2D has it "locked" and I haven't messed with trying to avoid issues.

This only goes 2 levels deep and breaks with the third.
You can use this to fake a View Camera for a 2D sidescroller for example.

Transformations do depend on each other, translation does get scaled with the given scale, if you wish to have another translation independent from translation, do tell.

# Like what I do?
Maybe send a small donation to let me know that you appreciate the work!

[Paypal](https://www.paypal.me/mattseys)

# Questions or help needed?
* Contact me on [Twitter](https://twitter.com/seys_matthias).
* Join me on my [Discord](https://discord.gg/DHSRWnt)!
