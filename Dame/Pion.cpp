#include <Pion.h>
    
    


// Pion::Pion(){};

// Pion::Pion(){
// //(bool PionBlanc){//,int ligne, int colonne){

//     //this->ligne=ligne;
//     //this->colonne=colonne;
//     //this->PionBlanc=PionBlanc;

// };
    
// void Pion::setLigne(int ligne){
//     this->ligne=ligne;
// };

// int Pion::getLigne(){
//     return ligne;
// };

// void Pion::setColonne(int colonne){
//     this->ligne=ligne;
// };

// int Pion::getColonne(){
//     return colonne;
// };

// void Pion::setCoordonnees(int ligne, int colonne){
//     this->ligne=ligne;
//     this->colonne=colonne;
// };

// std::vector<int> Pion::getCoordonnees(){
//     return {ligne, colonne};
// };

void Pion::setReine(){
    this->Reine=true;
};

bool Pion::getReine(){
    return Reine;
};

bool Pion::getPionBlanc(){
    return PionBlanc;
};

uint32_t Pion::get_Couleur_led(){
        return couleur_led;
    };

void Pion::set_Couleur_led(uint32_t c){
        this->couleur_led=c;
    };

void Pion :: set_PionBlanc(bool pb){
    PionBlanc = pb;
}


Pion::~Pion(){
};

