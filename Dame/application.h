#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include <define.h>
#include <Case.h>
#include <Pion.h>
#include <Pion_Blanc.h>
#include <Pion_Noir.h>
#include <Plateau.h>
#include <Adafruit_MCP23X17.h> // https://adafruit.github.io/Adafruit-MCP23017-Arduino-Library/html/functions_func.html
#include <Adafruit_NeoPixel.h> // https://adafruit.github.io/Adafruit_NeoPixel/html/functions_func.html
#include <vector>
#include <cstdint>
#include "MUX.h"
#include "LED.h"
#include <Jeu_de_Dame.h>




void init_application();
void run_application();


#endif






