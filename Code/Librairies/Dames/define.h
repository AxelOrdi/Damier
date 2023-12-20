#ifndef _DEFINE_H_
#define _DEFINE_H_

#define LINE_0 0     // MCP23XXX pin LINE_0 is attached to 0
#define LINE_1 1     // MCP23XXX pin LINE_1 is attached to 1
#define LINE_2 2     // MCP23XXX pin LINE_2 is attached to 2
#define LINE_3 3     // MCP23XXX pin LINE_3 is attached to 3
#define LINE_4 4     // MCP23XXX pin LINE_4 is attached to 4
#define LINE_5 5     // MCP23XXX pin LINE_5 is attached to 5
#define LINE_6 6     // MCP23XXX pin LINE_6 is attached to 6
#define LINE_7 7     // MCP23XXX pin LINE_7 is attached to 7
#define LINE_8 8     // MCP23XXX pin LINE_8 is attached to 8
#define LINE_9 9     // MCP23XXX pin LINE_9 is attached to 9

#define COL_0 0     // MCP23XXX pin COL_0 is attached to 0
#define COL_1 1     // MCP23XXX pin COL_1 is attached to 1
#define COL_2 2     // MCP23XXX pin COL_2 is attached to 2
#define COL_3 3     // MCP23XXX pin COL_3 is attached to 3
#define COL_4 4     // MCP23XXX pin COL_4 is attached to 4
#define COL_5 5     // MCP23XXX pin COL_5 is attached to 5
#define COL_6 6     // MCP23XXX pin COL_6 is attached to 6
#define COL_7 7     // MCP23XXX pin COL_7 is attached to 7
#define COL_8 8     // MCP23XXX pin COL_8 is attached to 8
#define COL_9 9     // MCP23XXX pin COL_9 is attached to 9

//----------DEFINE BANDE LED---------
#define NUM_LED 50
#define PIN_LED 2
#define BRIGHTNESS 150

//----------DEFINE MCP---------
#define MCP_INPUT_ADDR 0x20
#define MCP_OUTPUT_ADDR 0x21

//----------DEFINE DELAY---------
#define dlay 100

//----------DEFINE COULEURS---------

#define COULEUR_BLANC 0xFFFFFF //Adafruit_NeoPixel.Color(BRIGHTNESS_MAX,BRIGHTNESS_MAX,BRIGHTNESS_MAX)
#define COULEUR_NOIR 0x000000 //Adafruit_NeoPixel.Color(0,0,0)
#define COULEUR_ROUGE 0xFF0000 //Adafruit_NeoPixel.Color(BRIGHTNESS_MAX,0,0)
#define COULEUR_VERT 0x00FF00 //Adafruit_NeoPixel.Color(0,BRIGHTNESS_MAX,0)
#define COULEUR_BLEU 0x0000FF //Adafruit_NeoPixel.Color(0,0,BRIGHTNESS_MAX)


//-------------DEFINE DIMENSION TABLEAU DE CASE
#define DIMENSION_TABLEAU 10

#endif