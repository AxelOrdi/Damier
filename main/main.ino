#include <Case.h>
#include <Jeu_de_Dame.h>
#include <LED.h>
#include <MUX.h>
#include <Pion.h>
#include <Pion_Blanc.h>
#include <Pion_Noir.h>
#include <Plateau.h>
#include <application.h>
#include <define.h>

// #include <application.h>
  Adafruit_MCP23X17 MCP_IN; //PINS I2C 
  Adafruit_MCP23X17 MCP_OUT;
  Adafruit_NeoPixel STRIP_LED(NUM_LED, PIN_LED, NEO_GRB + NEO_KHZ800);

void setup(){


   init_application();
   run_application();
}

void loop(){

}