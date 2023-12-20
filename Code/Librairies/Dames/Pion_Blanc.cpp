#include <Pion_Blanc.h>
#include <define.h>

int Pion_Blanc:: NbPionBlanc=0;
Pion_Blanc::Pion_Blanc()
{
    this->set_PionBlanc(true);
    this->set_Couleur_led(COULEUR_BLANC);
    NbPionBlanc++;
}

Pion_Blanc::~Pion_Blanc()
{
    NbPionBlanc--;
}

