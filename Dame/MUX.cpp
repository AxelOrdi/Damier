#include <Adafruit_MCP23X17.h> // https://adafruit.github.io/Adafruit-MCP23017-Arduino-Library/html/functions_func.html
#include <Adafruit_NeoPixel.h> // https://adafruit.github.io/Adafruit_NeoPixel/html/functions_func.html
#include <Plateau.h>
#include <vector>
#include <cstdint>

uint16_t COLONNE_READ;

void init_MCP(Adafruit_MCP23X17 MCP, uint8_t mode){
    MCP.begin_I2C(MCP_INPUT_ADDR);
    for(int i=0; i<16; i++){
        MCP.pinMode(i,mode);
    }
}

void set_pin_MCP23017(Adafruit_MCP23X17 MCP, uint8_t broche_MCP, uint8_t value){
    uint8_t port_value = 0;
    if(broche_MCP <= 7){
        port_value = MCP.readGPIO(0);
        port_value &= ~(0x01<<broche_MCP);
        port_value |= value << broche_MCP;
        MCP.writeGPIO(port_value, 0);
    }
    else{
        port_value = MCP.readGPIO(1);
        port_value &= ~(0x01<<broche_MCP);
        port_value |= value << broche_MCP;
        MCP.writeGPIO(port_value, 1);
    }
}

void set_all_MCP23017(Adafruit_MCP23X17 MCP, uint8_t value){
    MCP.writeGPIOAB(value);
}

bool get_pin_MCP23017(Adafruit_MCP23X17 MCP, uint8_t broche_MCP, uint8_t value){
    uint8_t port_value = 0;
    bool bool_value = 0;

    if(broche_MCP <= 7){
        bool_value = ((MCP.readGPIO(0) >> broche_MCP) & 1) == 1;
    }
    else{
        bool_value = ((MCP.readGPIO(1) >> broche_MCP) & 1) == 1;
    }
    return(bool_value);
}

uint16_t get_all_MCP23017(Adafruit_MCP23X17 MCP){
    uint16_t value = (MCP.readGPIOAB())&~(0b111111<<9);
    return(value);
}

std::vector<int> get_coord_button_pushed(Adafruit_MCP23X17 MCP_IN, Adafruit_MCP23X17 MCP_OUT){
    int colonne = 0; 
    int ligne = 0; 
    
    // std::vector<int> coordonnees{ligne,colonne};

    for(int LIGNE = 0; LIGNE <10; LIGNE++){
        MCP_OUT.writeGPIOAB(0x01<<LIGNE);
        int COLONNE_READ = MCP_IN.readGPIOAB();
        for(int COLONNE = 0; COLONNE <10; COLONNE++){
            if((COLONNE_READ & (0b1 << COLONNE)) != 0){
                return(std::vector<int>{LIGNE,COLONNE});
            }
        }
    }
    return(std::vector<int>{-1,-1});
}

