#ifndef _PLATEAU_H_
#define _PLATEAU_H_

#include <Adafruit_NeoPixel.h> // https://adafruit.github.io/Adafruit_NeoPixel/html/functions_func.html
#include <cstdint>
#include <define.h>
#include <LED.h>
#include <Case.h>


extern Adafruit_NeoPixel STRIP_LED;

class Plateau
{
private:
    Case Tableau[DIMENSION_TABLEAU][DIMENSION_TABLEAU]; // [Ligne] [Colonne]

public:
    //Plateau(){};
    
    // int Tirage_au_sort(){
    // ajouter un tirage au sort joueur 1 ou 2 est blanc; dans init mettre couleur du bon cote Plateau
    // }
    void Initialisation_tableau();
   

    void Commencer_Partie();
    

    // void verification_etat_tableau()
    // {
    //     // Verifie état si pion sur une case pour decider si on affiche couleur par defaur ou couleur d'un pion(N,B)
    // }

    // int Allumage()
    // {

    //     // A changer avec bouton

    //     char reponse = 'N';
    //     while (reponse == 'N')
    //     {
    //         cout << "Commencer une partie Y/N : " << endl;
    //         cin >> reponse;
    //         if (reponse == 'Y')
    //         {
    //             cout << "Debut partie" << endl;
    //             Commencer_Partie();
    //         }
    //     }
    //     return 1;
    // }

    void Set_Couleur_Tableau_sans_Pion();


    // void Affichage_Tableau_sans_Pion()
    // {

    //     // Afficher un caractère en fonction de case noire (X), blanche (O)
    //     // Parcourir le Plateau, en fonction du bool case_blanche, afficher le caractère
    //     // Set_Couleur_Tableau_sans_Pion();
    //     for (int i = 0; i < 10; i++)
    //     { // [i]ligne
    //         for (int j = 0; j < 10; j++)
    //         { // [j]colonne
    //             cout << "|" << Tableau[i][j].get_couleur_led() << "|";
    //         }
    //         cout << endl;
    //     }
    // }

    Case get_CasePlateau(int ligne, int colonne);
};

#endif