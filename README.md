AnalogDebounce Library by MatCat

I developed this library for use with voltage divided keypads that use a single analog input for multiple buttons.  The default values will work for most shields utilizing a standard 5 button design, however a few simple modifications to variables in the library can easily allow for any number of buttons up to 254 total.

Official discussion thread on Arduino Forum: http://arduino.cc/forum/index.php/topic,127128.0.html

Installation

To install this library please download and place in [Your Sketchbook Folder]/libraries/AnalogDebounce

To use this library simply check out the BasicUse example:

```C++
#include <AnalogDebounce.h>
  AnalogDebounce Buttons(A0,ButtonPush);  // Analog Input 0, 
                                          // ButtonPush is callback
void setup() {
  Serial.begin(9600);
}
void loop() {
  Buttons.loopCheck();
}

// Callback function
void ButtonPush(byte Button) {
  Serial.print("Button Pushed: ");
  Serial.println(Button);
  /* Will return 255 on release of a button
     Or 0 to 4 corrisponding to a specific button
     Depending on the resistors used to make your
     keypad you may need to adjust the analog value
     for each button, to do this you can change 
     Buttons.adc_key_val[0-4] to a slightly higher number
     then the highest number you get on a direct analog read.
     
     If you need more or less then 5 buttons, you can
     adjust the values accordingly in the library files.
  */
}
```

Changelog

10/15/2012
----------
Made the time in miliseconds it takes to determain a button change public via the minPressTime integer.
Made the repeat fire time in miliseconds available via the repeatDelay integer.
Added keywords contexts for all variables.

10/14/2012
----------
Initial Release of the library.
