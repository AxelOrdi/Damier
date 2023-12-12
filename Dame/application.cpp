#include <define.h>
#include <Case.h>
#include <Pion.h>
#include <Pion_Blanc.h>
#include <Pion_Noir.h>
#include <Jeu_de_Dame.h>
#include <Plateau.h>
#include <Adafruit_MCP23X17.h> // https://adafruit.github.io/Adafruit-MCP23017-Arduino-Library/html/functions_func.html
#include <Adafruit_NeoPixel.h> // https://adafruit.github.io/Adafruit_NeoPixel/html/functions_func.html
#include <vector>
#include <cstdint>
#include <MUX.h>
#include <LED.h>

void init_application(){
    Adafruit_MCP23X17 MCP_IN; //PINS I2C 
    Adafruit_MCP23X17 MCP_OUT;

    Adafruit_NeoPixel STRIP_LED(NUM_LED, PIN_LED, NEO_GRB + NEO_KHZ800);

    // Plateau D1;

    init_MCP(MCP_IN, INPUT_PULLDOWN);
    init_MCP(MCP_OUT, OUTPUT);

    init_LED(STRIP_LED);
}

void run_application(){
    Jeu_de_Dame JdD;
    JdD.Commencer_Partie_Jeu_De_Dame();
}