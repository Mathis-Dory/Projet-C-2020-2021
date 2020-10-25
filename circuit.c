
#include "structure.h"
#include "circuit.h"

int tourEssai(){
    VoitureF1 voiture;
    initVoiture(&voiture);
    int etatTour = 0;
    if (etatTour < 2){

    }
    else if (etatTour == 3){

    }
}

void initVoiture(VoitureF1* voiture){
    voiture->numeroVoiture = 1;
    voiture->secteur1 = 0;
    voiture->secteur2 = 0;
    voiture->secteur3 = 0;
    voiture->bestTime= 0;
    voiture->totalTime = 0;
    voiture->nbreTours = 0;
    voiture->status = 0;
    voiture->etat = 0;
    voiture->crashed = 0;
    voiture->stand = 0;

}