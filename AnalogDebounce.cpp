#include "AnalogDebounce.h"

AnalogDebounce::AnalogDebounce(byte pin,button_callback f) {
    Pin = pin;
    adc_key_old = -1;
    adc_key_in = -2;
    NUM_KEYS = 5;
    key = -1;
    adc_key_val[0] = 30;
    adc_key_val[1] = 160;
    adc_key_val[2] = 360;
    adc_key_val[3] = 550;
    adc_key_val[4] = 780;
    minPressTime = 70;
    repeatDelay = 150;
    callback = f;
    for (int a = 0; a < 5; a++) {buttoncount[a] = 0;}
    time_detected = millis();
    adc_key_old = analogRead(Pin);
}
AnalogDebounce::~AnalogDebounce() {}

void AnalogDebounce::loopCheck() {
    adc_key_reading = analogRead(Pin);         // Read for keypress
    adc_key_reading = get_Key(adc_key_reading);
    if (adc_key_reading != adc_key_old) {         // Debounce routine
      time_detected = millis();
    }
    long timediff = millis() - time_detected;
    if (timediff > minPressTime) {
      adc_key_in = adc_key_reading;
      time_detected = millis() + repeatDelay;  // This makes sure if button is held it doesn't go crazy fast
      (*callback)(adc_key_in);
      if (adc_key_in != 255) {
        buttoncount[adc_key_in]+=1;
      }
    }
    adc_key_old = adc_key_reading;
}
int AnalogDebounce::get_Key(unsigned int input) {
    int k;
    for (k = 0; k < NUM_KEYS; k++) {
      if (input < adc_key_val[k]) {
        return k;
      }
    }
      k = 255;
    return k;
  }
