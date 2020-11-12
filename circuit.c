
#include "structure.h"
#include "circuit.h"

int tourEssai(){
    VoitureF1 voiture;
    initVoiture(&voiture);
    double tmpsSecteur = 0;
    int crash = 0;
    int stand = 0;
    int etatTour = 1;
    for (int i = 0; i < 10; ++i) {
        if (etatTour == 1 && crash == 0){
            tmpsSecteur = getRandomTimeSector();
            crash = carCrashed();
            voiture.secteur1 = tmpsSecteur;
            if (crash == 1){
                // Alors mettre la voiture en etat de crash et mettre son temps = à Abs pour le reste de la course
                voiture.crashed = 0;
                voiture.secteur2 = -1;
                voiture.secteur3 = -1;
            }
            etatTour ++;
        }
        if (etatTour == 2 && crash == 0){
            tmpsSecteur = getRandomTimeSector();
            crash = carCrashed();
            voiture.secteur2 = tmpsSecteur;
            if (crash == 1){
                // Alors mettre la voiture en etat de crash et mettre son temps = à Abs pour le reste de la course
                voiture.crashed = 0;
                voiture.secteur3 = -1;
            }
            etatTour ++;
        }
        if (etatTour == 3 && crash == 0){
            tmpsSecteur = getRandomTimeSector();
            crash = carCrashed();
            if (crash == 1){
                voiture.crashed = 0;
            }
            else{
                stand = isInStand();
                if (stand == 1){
                    // Alors mettre la voiture en stand et mettre a jour le temps S3
                    tmpsSecteur += getRandomTimeStand();
                    voiture.stand = 1;
                    voiture.secteur3 = tmpsSecteur;

                }
                else{
                    tmpsSecteur = getRandomTimeSector();
                    voiture.secteur3 = tmpsSecteur;
                }

            }
        }
        printf("Voici les temps : Secteur1: %3.3f Secteur2: %3.3f Secteur3: %3.3f \n", voiture.secteur1, voiture.secteur2, voiture.secteur3);
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
