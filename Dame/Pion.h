#ifndef _PION_H_
#define _PION_H_

#include <vector>
#include <define.h>
#include <cstdint>




class Pion {

    private :
    bool Reine;
    bool PionBlanc; //true = Blanc, false= noir
    uint32_t couleur_led;
    //int colonne;
    //int ligne;

    public :

    Pion(){};
    // Pion(bool PionBlanc);//, int ligne, int colonne);

    // void setLigne(int ligne);
    // int getLigne();

    // void setColonne(int colonne);
    // int getColonne();

    // void setCoordonnees(int ligne, int colonne);
    // std::vector<int> getCoordonnees(); //retourne {ligne, colonne}
    
    void setReine();
    bool getReine(); //true si Reine

    uint32_t get_Couleur_led();

    void set_Couleur_led(uint32_t c);
    void set_PionBlanc(bool pb);
    bool getPionBlanc();//true = blanc, false = noir
    ~Pion();
};

#endif