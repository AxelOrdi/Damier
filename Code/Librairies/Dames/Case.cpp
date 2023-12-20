#include <iostream>
#include <vector>
#include <array>
#include <cstring>
#include <cstdint>
#include <Pion.h>
#include <Case.h>
#include <LED.h>
#include <define.h>
#include <Adafruit_NeoPixel.h> // https://adafruit.github.io/Adafruit_NeoPixel/html/functions_func.html

using namespace std;


    
    

    Case::Case():couleur_led(COULEUR_NOIR),pion_sur_case(false){};
    Case::Case(uint32_t c,bool etat):couleur_led(c),pion_sur_case(etat){};
   ////////////////////// Method ////////////////
    uint32_t Case::get_couleur_led(){
        return couleur_led;
    }
    void Case::set_couleur_led(Adafruit_NeoPixel STRIP_LED, uint32_t couleur_led){
        this -> couleur_led = couleur_led;
        setPixel_LED(STRIP_LED,this->num_case_strip,couleur_led);
    }
    bool Case::get_pion_sur_case(){
        return pion_sur_case;
    }
    void Case::set_pion_sur_case(bool b){
        pion_sur_case=b;
    }
    bool Case::get_case_blanche(){
        return case_blanche;
    }
    void Case::set_case_blanche(bool b){
        case_blanche=b;
    }
    void Case::set_ligne(int ligne){
        this->ligne=ligne;
    }
    int Case::get_ligne(){
        return ligne;
    }
    void Case::set_colonne(int colonne){
        this->colonne=colonne;
    }   
    int Case::get_colonne(){
        return colonne;
    }

    void Case::set_coordonnees(int ligne, int colonne){

        this->ligne=ligne;
        this->colonne=colonne;

    }

    vector<int> Case::get_coordonnees(){// ligne colonne

        return {ligne,colonne};
    }
    // void Case::set_case_blanche(bool c){
    //     case_blanche=c;
    // }
    // bool Case::get_case_blanche(){
    //     return case_blanche;
    // }

    Pion*  Case::get_Pion_case(){
        return Pion_case;
    }

    void Case::set_Pion_case(Pion* p){
        Pion_case=p;
    }

    void Case :: Change_Couleur_Fct_Pion(){
        uint32_t couleur_pion = Pion_case->get_Couleur_led();
    }
