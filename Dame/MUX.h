#ifndef _MUX_H_
#define _MUX_H_

#include <Adafruit_MCP23X17.h> // https://adafruit.github.io/Adafruit-MCP23017-Arduino-Library/html/functions_func.html
#include <vector>
#include <cstdint>


// -------- GETTER / SETTER MUX -------- //

void init_MCP(Adafruit_MCP23X17 MCP, uint8_t mode);

void set_pin_MCP23017(Adafruit_MCP23X17 MCP, uint8_t broche_MCP, uint8_t value);

void set_all_MCP23017(Adafruit_MCP23X17 MCP, uint8_t value);

bool get_pin_MCP23017(Adafruit_MCP23X17 MCP, uint8_t broche_MCP, uint8_t value);

uint16_t get_all_MCP23017(Adafruit_MCP23X17 MCP);

std::vector<int> get_coord_button_pushed(Adafruit_MCP23X17 MCP_IN, Adafruit_MCP23X17 MCP_OUT);

#endif