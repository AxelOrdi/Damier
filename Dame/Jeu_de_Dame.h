#ifndef _JEU_DE_DAME_H_
#define _JEU_DE_DAME_H_

#include <Plateau.h>
#include <Pion.h>
#include <Case.h>
#include <vector>
#include <Adafruit_NeoPixel.h> // https://adafruit.github.io/Adafruit_NeoPixel/html/functions_func.html
#include <application.h>


class Jeu_de_Dame{
    private:
    Plateau Plateau_jeu;
    
    
    bool tour=true; //True =blanc ; false=noir
    public:
    
    Jeu_de_Dame();


    void Initialisation_Pion();
    
    void Commencer_Partie_Jeu_De_Dame ();

    int Deplacer_Pion(std :: vector<int> Vecteur_Coordonnee_Initiale, std :: vector<int> Vecteur_Coordonnee_Finale);

    int Verif_Deplacement_Possible(bool couleurTour, int ligneDepart, int colonneDepart, int ligneArrivee, int colonneArrivee);

    int Manger_Pion(int Ligne_Position_Initiale,int Colonne_Position_initiale,int Ligne_Position_Finale,int Colonne_Position_Finale);
    
    int Verif_Deplacement_Manger_Pion(int Ligne_Position,int Colonne_Position);

    void Deroulement_Tour();

    int Verif_Couleur_Pion(std ::vector<int> Vecteur_Coordonnee_Initiale);
    
    int Etat_Attente_1(std::vector <int> &Vecteur_Coordonnee_Initiale);

    int Etat_Attente_2(std ::vector<int> &Vecteur_Coordonnee_Initiale);

    void Fin_de_jeu();
    


};

#endif

