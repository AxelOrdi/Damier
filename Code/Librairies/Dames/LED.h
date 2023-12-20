 #ifndef _LED_H_
 #define _LED_H_

#include <define.h>
#include <Adafruit_NeoPixel.h> // https://adafruit.github.io/Adafruit_NeoPixel/html/functions_func.html
#include <cstdint>


//--------ALLUMER-LED----------

void setPixel_LED(Adafruit_NeoPixel STRIP_LED, uint8_t NumCase, uint32_t Couleur);

void init_LED(Adafruit_NeoPixel STRIP_LED);

#endif