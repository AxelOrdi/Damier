#ifndef _CASE_H_
#define _CASE_H_

#include <define.h>
#include <iostream>
#include <vector>
#include <array>
#include <cstring>
#include <Pion.h>
#include <Adafruit_NeoPixel.h> // https://adafruit.github.io/Adafruit_NeoPixel/html/functions_func.html


using namespace std;

class Case {
    private:
    uint32_t couleur_led;/////////////////Changer a Adafruit...
    bool pion_sur_case;
    bool case_blanche; //True =  Blanc, False = Noir
    int num_case_strip;//0 à 49
    int colonne ; // creer get set (HUGO) ++ fct dans damie pour les mettre a jour
    int ligne; //creer get set (HUGO) ++ fonctions Plateau
    //vector<int> coordonnees{ligne,colonne}; //On s'en passera, le getter coordonnees retournera vector<int>{ligne, colonne}
    Pion* Pion_case;

    public:
    Case();
    Case(uint32_t c,bool etat);
   ////////////////////// Method ////////////////
    uint32_t get_couleur_led();
    void set_couleur_led(Adafruit_NeoPixel STRIP_LED, uint32_t couleur_led);

    bool get_pion_sur_case();
    void set_pion_sur_case(bool b);

    bool get_case_blanche();
    void set_case_blanche(bool b);

    void set_ligne(int ligne);
    int get_ligne();

    void set_colonne(int colonne);
    int get_colonne();

    void set_coordonnees(int ligne, int colonne);
    vector<int> get_coordonnees();

    Pion*  get_Pion_case();

    void set_Pion_case(Pion* p);

    void Change_Couleur_Fct_Pion();
};

#endif