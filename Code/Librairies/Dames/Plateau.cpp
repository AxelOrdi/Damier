#include <Plateau.h>




 void Plateau:: Initialisation_tableau(){
    // Met des tirets dans tous le tableau

    for (int i = 0; i < 10; i++)
    { // [i]Ligne
        for (int j = 0; j < 10; j++)
        { // [j]Colonne

            Tableau[i][j].set_couleur_led(STRIP_LED, COULEUR_BLANC); // couleur tout case en blanc
            Tableau[i][j].set_ligne(i);                              // Met les coordonnées dans chaque case
            Tableau[i][j].set_colonne(j);
            // Définie les cases blanches et case noire
            if (((i % 2 != 0) && (j % 2 != 0)))
            { // i et j impaire ou i et j pair
                Tableau[i][j].set_case_blanche(true);
            }
            else if ((i % 2 == 0) && (j % 2 == 0))
            {
                Tableau[i][j].set_case_blanche(true);
            }
            else
            {
                Tableau[i][j].set_case_blanche(false);
            }
        }
    }
}

void Plateau::Commencer_Partie()
    {
        Initialisation_tableau();
        Set_Couleur_Tableau_sans_Pion();
        // Affichage_Tableau_sans_Pion();
        init_LED(STRIP_LED);
    }

void Plateau::Set_Couleur_Tableau_sans_Pion()
{
    // Parcourir le Plateau, en fonction du bool case_blanche, changer le caractère
    for (int i = 0; i < 10; i++)
    { // [i]ligne
        for (int j = 0; j < 10; j++)
        { // [j]colonne
            // Tableau[i][j].set_couleur_led(" - ");
            if (Tableau[i][j].get_case_blanche() == true)
            { // case blanche
                Tableau[i][j].set_couleur_led(STRIP_LED,COULEUR_BLANC);
                Tableau[i][j].set_case_blanche(true);
            }
            else
            {
                Tableau[i][j].set_couleur_led(STRIP_LED,COULEUR_NOIR);
                Tableau[i][j].set_case_blanche(false);
            }
        }
    }
}

Case Plateau::get_CasePlateau(int ligne, int colonne)
    {
        return Tableau[ligne][colonne];
    }
