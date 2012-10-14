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
     
     Library works out of the box for Cytron LCD and 
     Keypad shield, and should work for SainsSmart one as well.
  */
}