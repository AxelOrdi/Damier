#include <Pion_Noir.h>
#include <define.h>


int Pion_Noir:: NbPionNoir=0;

Pion_Noir::Pion_Noir()
{
    this->set_PionBlanc(false);
    this->set_Couleur_led(COULEUR_NOIR);
    NbPionNoir++;
}

Pion_Noir::~Pion_Noir()
{
    NbPionNoir--;
}

