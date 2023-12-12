#include <define.h>
#include <LED.h>
#include <Adafruit_NeoPixel.h> // https://adafruit.github.io/Adafruit_NeoPixel/html/functions_func.html
#include <cstdint>



//--------ALLUMER-LED----------

void setPixel_LED(Adafruit_NeoPixel STRIP_LED, uint8_t NumCase, uint32_t Couleur){
    STRIP_LED.setPixelColor(NumCase, Couleur);
    STRIP_LED.setBrightness(BRIGHTNESS);
    STRIP_LED.show();
}

void init_LED(Adafruit_NeoPixel STRIP_LED){
    STRIP_LED.begin();

    STRIP_LED.fill(COULEUR_VERT,0,50);
    STRIP_LED.setBrightness(BRIGHTNESS);
    STRIP_LED.show();
    delay(300);
    STRIP_LED.fill(COULEUR_ROUGE,0,50);
    STRIP_LED.setBrightness(BRIGHTNESS);
    STRIP_LED.show();
    delay(300);
    STRIP_LED.fill(COULEUR_BLEU,0,50);
    STRIP_LED.setBrightness(BRIGHTNESS);
    STRIP_LED.show();
    delay(300);
    STRIP_LED.fill(COULEUR_BLANC,0,0);
    // STRIP_LED.fill(COULEUR_ROUGE,0,15);
    // STRIP_LED.fill(COULEUR_BLEU,35,15);
    STRIP_LED.setBrightness(BRIGHTNESS);
    STRIP_LED.show();
}

