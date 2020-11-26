
#include "circuit.h"


double turn(CarF1 *car) {
    double total = 0; // Temps pour un tour complet
    double timeSector = 0; // Temps pour un secteur
    for (int i = 1; i <= 3; ++i) {
        switch (i) {
            case 1:
                timeSector = sector();
                break;
            case 2:
                timeSector = sector();
                break;
            case 3:
                timeSector = sector();
                break;
        }
        if (timeSector == 0) {                 //test si il y a un crash
            car->status = 0;
            car->crash = 1;
            car->ranking = 1;
            printf("Il y a eu un crash");
            resetSector(car);
            return 0;
        }
        if ((i % 2) == 0) {             //si il passe dans le secteur 2
            car->sector2 = timeSector;

        }
        else if ((i % 3) == 0) {        //si il passe dans le secteur 3
           // Pas de stand en essai
            // if (isInStand()) {
            //    timeSector += getRandomTimeStand();
            //    car->status = 1;

           // }
            car->status = 2;
            car->sector3 = timeSector;

        } else {                     //si il passe dans le secteur 1
            car->sector1 = timeSector;
        }

        total += timeSector; //ajout au temps total de la voiture dans le circuit
    }
    printf("%f", total);
    return total;
}

void qualification(int chrono){
    double timeThisTurn = 0;
    double timeInRace = 0;
    while (timeInRace < chrono && timeThisTurn != 0){
        
    }


}

void resetSector(CarF1 *car) {
    car->sector1 = 0;
    car->sector2 = 0;
    car->sector3 = 0;
}
