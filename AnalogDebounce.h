#ifndef ANALOGDEBOUNCE_H
#define ANALOGDEBOUNCE_H

    #if defined(ARDUINO) && ARDUINO >= 100
    #include <Arduino.h>
    #else
    #include <WProgram.h>
    #endif

    typedef void (*button_callback)(byte);
    class AnalogDebounce {
    public:
        int adc_key_old;
        int adc_key_in;
        int adc_key_reading;
        long time_detected;
        int NUM_KEYS;
        int key;
        int adc_key_val[5];
        int buttoncount[5];
  	int minPressTime;
	int repeatDelay;
        AnalogDebounce(byte Pin,button_callback f);
        ~AnalogDebounce();
        void loopCheck(void);
        int get_Key(unsigned int input);
    private:
        byte Pin;
        button_callback callback;

    };

#endif
