#include <Plateau.h>
#include <Pion.h>
#include <Case.h>
#include <LED.h> 
#include <MUX.h>
#include <define.h>
#include <Jeu_de_Dame.h>
#include <Adafruit_NeoPixel.h> // https://adafruit.github.io/Adafruit_NeoPixel/html/functions_func.html
#include <Pion_Blanc.h>
#include <Pion_Noir.h>
#include <application.h>

// FAIRE EN SORTE QUE JEU DE DAME AIRRITTE DE PLATEAU



Jeu_de_Dame::Jeu_de_Dame() : tour(true), Plateau_jeu(){};

void Jeu_de_Dame::Initialisation_Pion()
{ 
    // Place les pions en début de partie
    // Placer les pions noirs et blancs
    // Case case;
    for (int i =0; i<10 ; i++){// [i]ligne
        for (int j=0; j<10;j++){// [j]colonne
            if (((i % 2 !=0) && (j % 2 !=0))){// i et j impaire ou i et j pair 
                    if(i<5){
                        Pion_Blanc* ptr_pion_blanc = new Pion_Blanc;
                        Plateau_jeu.get_CasePlateau(i,j).set_pion_sur_case(true); 
                        Plateau_jeu.get_CasePlateau(i,j).set_Pion_case(ptr_pion_blanc);
                    }
                    if (i>6){
                        Pion_Noir* ptr_pion_noir = new Pion_Noir;
                        Plateau_jeu.get_CasePlateau(i,j).set_pion_sur_case(true); 
                        Plateau_jeu.get_CasePlateau(i,j).set_Pion_case(ptr_pion_noir);
                    }
                }   
            else if((i % 2 ==0) && (j % 2 ==0)){
                Plateau_jeu.get_CasePlateau(i,j);;
                if(i<4){
                    Pion_Blanc* ptr_pion_blanc = new Pion_Blanc;
                    Plateau_jeu.get_CasePlateau(i,j).set_pion_sur_case(true); 
                    Plateau_jeu.get_CasePlateau(i,j).set_Pion_case(ptr_pion_blanc);
                }
                if(i>5){
                    Pion_Noir* ptr_pion_noir = new Pion_Noir;
                    Plateau_jeu.get_CasePlateau(i,j).set_pion_sur_case(true); 
                    Plateau_jeu.get_CasePlateau(i,j).set_Pion_case(ptr_pion_noir);
                }
            }
        }
    }
};
    


int Jeu_de_Dame:: Verif_Deplacement_Possible(bool couleurTour, int ligneDepart, int colonneDepart, int ligneArrivee, int colonneArrivee){
    //Etat 4
    //MODIFIER LE RETOUR POUR RENVOYER AUSSI LES INFORMATIONS POUR LE DEPLACEMENT
    
    //ici le pion sélectionné est déjà de la bonne couleur
    //Vérifier que la case visée soit à portée
    //donc une case d'écart si on ne veut pas manger de pion
    //deux cases d'écart si on veut manger un pion
    //obligation de manger un pion quand c'est possible
    //POUR L'INSTANT ON NE FAIT PAS LA DIFF ENTRE LE MILIEU DU PLATEAU ET LES BORDS (A VERIFIER SI BUG) (je crois que c'est bon le sang)
    
    if(couleurTour){ //True = blanc
        //Blanc remonte le plateau, on vérifie donc d'abord que la case visée n'est pas derrière le pion
        //On vérifie aussi qu'on ne tente pas de se déplacer sur la même ligne ou la même colonne
        if(ligneArrivee<=ligneDepart || colonneArrivee==colonneDepart) return 3;
        //Si case visée à 1 case d'écart, vérifier que la case n'est pas occupée
        if((ligneArrivee==ligneDepart+1) && ((colonneArrivee==colonneDepart+1) || (colonneArrivee==colonneDepart-1))){
            if(Plateau_jeu.get_CasePlateau(ligneArrivee,colonneArrivee).get_pion_sur_case()) return 3; //la case n'est pas libre
            else return 5; //Déplacement normal, cf machine à états
        } 
        //Si case visée à 2 cases d'écart, vérifier que la case n'est pas occupée et qu'il y a bien un pion à manger entre les deux
        if((ligneArrivee==ligneDepart+2)&&((colonneArrivee==colonneDepart+2) || (colonneArrivee==colonneDepart-2) )){
            //Vérfier que la case visée n'est pas occuppée
            if(Plateau_jeu.get_CasePlateau(ligneArrivee,colonneArrivee).get_pion_sur_case()) return 3; //la case n'est pas libre
            //Vérifier qu'il y a un pion de l'autre couleur au milieu
            else {
                if(Plateau_jeu.get_CasePlateau(ligneArrivee-1,(colonneArrivee+colonneDepart)/2).get_Pion_case()->getPionBlanc()) return 3;
                else return 6;
            }
            
        }
    }
    else{ //False = noir
        //Noir descend le plateau, on vérifie d'abord que la case visée n'est pas derrière le pion ou sur la même colonne
        if(ligneArrivee>=ligneDepart || colonneArrivee==colonneDepart) return 3;
        //Si case visée à 1 case d'écart, vérifier que la case n'est pas occupée
        if((ligneArrivee==ligneDepart-1) && (colonneArrivee==colonneDepart+1 || colonneArrivee==colonneDepart-1)){
            if(Plateau_jeu.get_CasePlateau(ligneArrivee,colonneArrivee).get_pion_sur_case()) return 3; //la case n'est pas libre
            else return 5;
        }
        //Si case visée à 2 cases d'écart, vérifier que la case n'est pas occupée et qu'il y a bien un pion à manger entre les deux
        if((ligneArrivee==ligneDepart+2)&&((colonneArrivee==colonneDepart+2) || (colonneArrivee==colonneDepart-2) )){
            //Vérfier que la case visée n'est pas occuppée
            if(Plateau_jeu.get_CasePlateau(ligneArrivee,colonneArrivee).get_pion_sur_case()) return 3; //la case n'est pas libre
            //Vérifier qu'il y a un pion de l'autre couleur au milieu
            else {
                if(!(Plateau_jeu.get_CasePlateau(ligneArrivee+1,(colonneArrivee+colonneDepart)/2).get_Pion_case()->getPionBlanc())) return 3;
                else return 6;
            }
            
        }
    }

}; //Etat 4 (Discord Balance #general 07/12/23 15:19)

void Jeu_de_Dame:: Commencer_Partie_Jeu_De_Dame (){
    Plateau_jeu.Commencer_Partie();
    Initialisation_Pion();
    Deroulement_Tour();
};

void Jeu_de_Dame:: Deroulement_Tour(){
    int Etat;
    std ::vector<int> Vecteur_Coordonnee_Initiale;
    std ::vector<int> Vecteur_Coordonnee_Finale;
    Pion_Blanc pb;
    Pion_Noir pn;
    
    while(Etat != 8){
       switch (Etat) {
        case 1: 
            Etat = Etat_Attente_1(Vecteur_Coordonnee_Initiale);
            break;
        case 2:
            Etat = Verif_Couleur_Pion(Vecteur_Coordonnee_Initiale);
            break;
        case 3:
            Etat = Etat_Attente_2(Vecteur_Coordonnee_Finale);
            break;
        case 4:
            Etat=Verif_Deplacement_Possible(tour, Vecteur_Coordonnee_Initiale[1], Vecteur_Coordonnee_Initiale[2], Vecteur_Coordonnee_Finale[1],Vecteur_Coordonnee_Finale[2]);
            break;
        case 5:
            Etat= Deplacer_Pion(Vecteur_Coordonnee_Initiale , Vecteur_Coordonnee_Finale);
            break;
        case 6:
            Etat = Manger_Pion(Vecteur_Coordonnee_Initiale[1],Vecteur_Coordonnee_Initiale[2],Vecteur_Coordonnee_Finale[1],Vecteur_Coordonnee_Finale[2]);
            break;
        
        case 7:
            Etat = Verif_Deplacement_Manger_Pion(Vecteur_Coordonnee_Finale[1],Vecteur_Coordonnee_Finale[2]);
            break;
       }

       // Etat 8 fin de tour
        tour = !tour;
        
        if(pb.NbPionBlanc==1 || pn.NbPionNoir == 1){
            Fin_de_jeu();
        }
    }
       
};

int Jeu_de_Dame :: Manger_Pion(int Ligne_Position_Initiale,int Colonne_Position_initiale,int Ligne_Position_Finale,int Colonne_Position_Finale){ // Etat 6

    int decalage_ligne;
    int decalage_colonne;
    extern  Adafruit_NeoPixel STRIP_LED;

    if ((Ligne_Position_Finale == Ligne_Position_Initiale +2) && (Colonne_Position_Finale == Colonne_Position_initiale+2)){
        //- - - x
        //- - N -
        //- B - -
        decalage_colonne=1;
    }
    else if ((Ligne_Position_Finale == Ligne_Position_Initiale +2) && (Colonne_Position_Finale == Colonne_Position_initiale-2)){
        //- x - -
        //- - N -
        //- - - B
        decalage_colonne=-1;
    }

    if (Plateau_jeu.get_CasePlateau(Ligne_Position_Initiale,Colonne_Position_initiale).get_Pion_case()->getPionBlanc()== true){
        decalage_ligne=1;
        // Pion Blanc
        // On remonte le plateau
       
    }
    else
    {
        decalage_ligne =-1;
       
    }
    

    delete Plateau_jeu.get_CasePlateau(Ligne_Position_Initiale + (decalage_ligne*1),Colonne_Position_initiale + (decalage_colonne*1)).get_Pion_case(); // Supprime l'objet pion sur case mangé (get_Pion_case retourne pointeur sur Pion)
    Plateau_jeu.get_CasePlateau(Ligne_Position_Initiale+(decalage_ligne*1),Colonne_Position_initiale+(decalage_colonne*1)).set_pion_sur_case(false);// Met à jour l'attribut case donnant la presence de pion
    Plateau_jeu.get_CasePlateau(Ligne_Position_Initiale+(decalage_ligne*1),Colonne_Position_initiale+(decalage_colonne*1)).set_couleur_led(STRIP_LED, COULEUR_BLANC);//Met la couleur de la case en Blanc (CASE_VIDE) du pion mangé
    Plateau_jeu.get_CasePlateau(Ligne_Position_Finale,Colonne_Position_Finale).set_Pion_case(Plateau_jeu.get_CasePlateau(Ligne_Position_Initiale,Colonne_Position_initiale).get_Pion_case());//Change le pion sur la case apres avoir mangé un pion diag +2 (x)
    

    //case initial , la case ou etait le pion avant de manger => on la vide
    Plateau_jeu.get_CasePlateau(Ligne_Position_Initiale,Colonne_Position_initiale).set_Pion_case(nullptr);// pointeur pion dans cette case pointe vers aucun pion
    Plateau_jeu.get_CasePlateau(Ligne_Position_Initiale,Colonne_Position_initiale).set_pion_sur_case(false);// On met a jour l'attribut, il n'y a plus de pion sur cette case
    Plateau_jeu.get_CasePlateau(Ligne_Position_Initiale,Colonne_Position_initiale).set_couleur_led(STRIP_LED, COULEUR_BLANC);//Cette case est mtnt vide on la met en Blanc


    return 7;// Va vers état Verif_Deplacement_Manger_Pion
};

int Jeu_de_Dame :: Verif_Deplacement_Manger_Pion(int Ligne_Position,int Colonne_Position){ //Etat 7
    //Verifier si un autre pion peut etre mangé apres avoir mangé un pion
    // Si pas de pion a manger disp on passe a Etat 8 soit fin du Tour

    int decalage_ligne;
    int decalage_colonne;

    if (Plateau_jeu.get_CasePlateau(Ligne_Position,Colonne_Position).get_Pion_case()->getPionBlanc()== true){
        decalage_ligne=1;
        // Pion Blanc
        // On remonte le plateau
    }
    else
    {
        decalage_ligne =-1;
        // Pion noir on descend le plateau
    }

    decalage_colonne=1; // check a droite

    if ((Plateau_jeu.get_CasePlateau(Ligne_Position+decalage_ligne,Colonne_Position+decalage_colonne).get_pion_sur_case() == true) && (Plateau_jeu.get_CasePlateau(Ligne_Position+decalage_ligne,Colonne_Position+decalage_colonne).get_Pion_case()->getPionBlanc() != (Plateau_jeu.get_CasePlateau(Ligne_Position,Colonne_Position).get_Pion_case()->getPionBlanc() ) )){
        // Si la case diag a un pion de couleur différente
        //- - N -
        //- B - -
       if ((Plateau_jeu.get_CasePlateau(Ligne_Position+(decalage_ligne*2),Colonne_Position+(decalage_colonne*2)).get_pion_sur_case() == false)){
            // Si la case diag +2 ,case x, est libre
            //- - - x
            //- - M -       M-> Pion Mangé
            //- P - -       P-> Pion en Jeu
            return 6; // On retourne vers état manger_pion
       }
    }

    decalage_colonne=-1; //check a gauche

    if ((Plateau_jeu.get_CasePlateau(Ligne_Position+decalage_ligne,Colonne_Position+decalage_colonne).get_pion_sur_case() == true) && (Plateau_jeu.get_CasePlateau(Ligne_Position+decalage_ligne,Colonne_Position+decalage_colonne).get_Pion_case()->getPionBlanc() != (Plateau_jeu.get_CasePlateau(Ligne_Position,Colonne_Position).get_Pion_case()->getPionBlanc() ) )){
        // Si la case diag a un pion de couleur différente
        //- - N -
        //- - - B
       if ((Plateau_jeu.get_CasePlateau(Ligne_Position+(decalage_ligne*2),Colonne_Position+(decalage_colonne*2)).get_pion_sur_case() == false)){
            // Si la case diag +2 ,case x, est libre
            //- x - -
            //- - M -       M-> Pion Mangé
            //- - - P       P-> Pion en Jeu
            return 6; // On retourne vers état manger_pion
       }
    }

    // Si une des deux conditions précendentes est vrai on retourne vers etat 6 Manger_pion
    // Sinon on va a etat 8 fin de tour

    return 8;
};

int Jeu_de_Dame :: Etat_Attente_1(std ::vector<int> &Vecteur_Coordonnee_Initiale){
    extern Adafruit_MCP23X17 MCP_IN; 
    extern Adafruit_MCP23X17 MCP_OUT;

    // Etat 1 on attend que le joueur selectionne un de ses pions
        // On initialise le vect coordonné initiale pour etre sur qu'il rentre dans boucle while
        Vecteur_Coordonnee_Initiale[1]=-1;
        Vecteur_Coordonnee_Initiale[2]=-1;
            while((Vecteur_Coordonnee_Initiale[1] == -1) && (Vecteur_Coordonnee_Initiale[2] == -1)){
                // Tant que la fct get bouton retourne valeur par défaut
                Vecteur_Coordonnee_Initiale = get_coord_button_pushed(MCP_IN,MCP_OUT);
                //la valeur de position initiale est stocké dans Vecteur_Coordonnee_Initiale qui est changé dans la fct appelante car appelé par référence.
            }
           return 4;
}

int Jeu_de_Dame :: Etat_Attente_2(std ::vector<int> &Vecteur_Coordonnee_Finale){
    // Etat 3 on attend que le joueur selectionne un de ses pions
        // On initialise le vect coordonné initiale pour etre sur qu'il rentre dans boucle while
        extern Adafruit_MCP23X17 MCP_IN; 
        extern Adafruit_MCP23X17 MCP_OUT;
        Vecteur_Coordonnee_Finale[1]=-1;
        Vecteur_Coordonnee_Finale[2]=-1;
        while((Vecteur_Coordonnee_Finale[1] == -1) && (Vecteur_Coordonnee_Finale[2] == -1)){
            // Tant que la fct get bouton retourne valeur par défaut
            Vecteur_Coordonnee_Finale = get_coord_button_pushed(MCP_IN,MCP_OUT);
            //la valeur de position initiale est stocké dans Vecteur_Coordonnee_Initiale car appelé par référence.
        }
        if(Verif_Couleur_Pion(Vecteur_Coordonnee_Finale) == 3 ){
            return 1;
        }
        else {
            return 4;
        }
}

int Jeu_de_Dame:: Verif_Couleur_Pion(std ::vector<int> Vecteur_Coordonnee_Initiale){ // Etat 2

    if (Plateau_jeu.get_CasePlateau(Vecteur_Coordonnee_Initiale[1],Vecteur_Coordonnee_Initiale[2]).get_Pion_case()->getPionBlanc() == this->tour){
            // Si la couleur du Pion (déterminé par bool PionBlanc) et la meme que le boul tour qui donne la couleur qui doit jouer
            return 3; // On va a l'état 3 
        }
        else{
            // On recommence l'état 1 d'attente
            return 1;
        }
}

int Jeu_de_Dame :: Deplacer_Pion(std :: vector<int> Vecteur_Coordonnee_Initiale, std :: vector<int> Vecteur_Coordonnee_Finale){
    extern Adafruit_NeoPixel STRIP_LED;

    // Met le pion sur case finale
    // Change le pointeur Pion(Pion_case) dans case finale a celui qui était dans cas initiale
    Plateau_jeu.get_CasePlateau(Vecteur_Coordonnee_Finale[1],Vecteur_Coordonnee_Finale[2]).set_Pion_case(Plateau_jeu.get_CasePlateau(Vecteur_Coordonnee_Initiale[1],Vecteur_Coordonnee_Initiale[2]).get_Pion_case());
    //On change sur la case final le bool pion_sur_case a true et on affiche la couleur du pion
    Plateau_jeu.get_CasePlateau(Vecteur_Coordonnee_Finale[1],Vecteur_Coordonnee_Finale[2]).set_pion_sur_case(true);
    Plateau_jeu.get_CasePlateau(Vecteur_Coordonnee_Finale[1],Vecteur_Coordonnee_Finale[2]).set_couleur_led(STRIP_LED,Plateau_jeu.get_CasePlateau(Vecteur_Coordonnee_Finale[1],Vecteur_Coordonnee_Finale[2]).get_Pion_case()->get_Couleur_led());
    
    //case initial , la case ou etait le pion avant de deplacer => on la vide
    Plateau_jeu.get_CasePlateau(Vecteur_Coordonnee_Initiale[1] ,Vecteur_Coordonnee_Initiale[2]).set_Pion_case(nullptr);// pointeur pion dans cette case pointe vers aucun pion
    Plateau_jeu.get_CasePlateau(Vecteur_Coordonnee_Initiale[1] ,Vecteur_Coordonnee_Initiale[2]).set_pion_sur_case(false);// On met a jour l'attribut, il n'y a plus de pion sur cette case
    Plateau_jeu.get_CasePlateau(Vecteur_Coordonnee_Initiale[1] ,Vecteur_Coordonnee_Initiale[2]).set_couleur_led(STRIP_LED,COULEUR_BLANC);//Cette case est mtnt vide on la met en Blanc
    return 8;
}

void Jeu_de_Dame :: Fin_de_jeu(){
    extern  Adafruit_NeoPixel STRIP_LED;

    STRIP_LED.fill(COULEUR_BLEU,0,50);
    STRIP_LED.setBrightness(BRIGHTNESS);
    STRIP_LED.show();
}