
#include "circuit.h"

/** Simule un tour pour une période d'essai ou qualification
 *
 * @param car
 * @return total
 */
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
            default:
                perror("Erreur lors de la simulation des secteurs !");
        }
        if (timeSector == 0) {                 //test si il y a un crash
            car->status = 0;
            car->crash = 1;
            car->updateRanking = 1;
            resetSector(car);
            return 0;
        }
        if (i == 2) {             //si il passe dans le secteur 2
            car->sector2 = timeSector;
            if (car->bestSector2 > car->sector2){
                car->bestSector2 = car->sector2;
            }

        } else if (i == 3) {        //si il passe dans le secteur 3
            if (isInStand()) {
                timeSector += getRandomTimeStand();
                car->stand += 1;
                car->status = 2;

            }
            car->status = 1;
            car->sector3 = timeSector;
            if (car->bestSector3 > car->sector3){
                car->bestSector3 = car->sector3;
            }

        } else {                     //si il passe dans le secteur 1
            car->sector1 = timeSector;
            if (car->bestSector1 > car->sector1){
                car->bestSector1 = car->sector1;
            }
        }

        total += timeSector; //ajout au temps total de la voiture dans le circuit
    }
    return total;
}

/**Simule une période d'essai ou de qualification
 *
 * @param chrono
 * @param car
 */

void qualification(int chrono, CarF1 *car, int *listOfNumbers) {
    double timeThisTurn;
    double timeInRace = 0;
    initCar(car);
    car->numberCar = *listOfNumbers;
    while (timeInRace < chrono) {
        timeThisTurn = turn(car);
        timeInRace += timeThisTurn;
        if (timeThisTurn == 0) {
            car->status = -1;
            return;
        }
        car->nbreTurns += 1;
        if (car->bestTime > timeThisTurn || car->bestTime == 0) {
            car->bestTime = timeThisTurn;        //sauvegarde la valeur en memoire partagee
        }
    }
    if (car->updateRanking == 0) {
        car->updateRanking = 1;          //indique que le temps de la voiture a changeOrdre
    }
}

/**Simule un tour pour la course principale
 *
 * @param car
 * @param numberOfTurns
 * @param maxTurns
 * @return total
 */
double turnForRace(CarF1 *car, int numberOfTurns, int maxTurns) {
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
            default:
                perror("Erreur lors de la simulation des secteurs !");
        }
        if (timeSector == 0) {                 //test si il y a un crash
            car->status = 0;
            car->crash = 1;
            car->updateRanking = 1;
            car->bestTime = INT_MAX; // Donne une valeur enorme pour la classer à la fin
            car->totalTime = INT_MAX;
            resetSector(car);
            return 0;
        }
        if (i == 2) {             //si il passe dans le secteur 2
            car->sector2 = timeSector;
            if (car->bestSector2 > car->sector2){
                car->bestSector2 = car->sector2;
            }

        } else if (i == 3) {        //si il passe dans le secteur 3
            if (numberOfTurns == maxTurns - 1 && car->stand <
                                                 1) { // Si dernier tour de la voiture et qu'elle n'a jamais été au stand alors elle doit y aller
                car->status = 2;
                car->stand += 1;
                timeSector += getRandomTimeStand();
                car->sector3 = timeSector;
                if (car->bestSector3 > car->sector3){
                    car->bestSector3 = car->sector3;
                }
            } else {
                if (isInStand()) {
                    timeSector += getRandomTimeStand();
                    car->stand += 1;
                    car->status = 2;

                }
                car->status = 1;
                car->sector3 = timeSector;
            }
        } else {                     //si il passe dans le secteur 1
            car->sector1 = timeSector;
            if (car->bestSector1 > car->sector1){
                car->bestSector1 = car->sector1;
            }
        }

        total += timeSector; //ajout au temps total de la voiture dans le circuit
    }
    return total;
}

/** Simule la course principale
 *
 * @param car
 * @param numberOfTurns
 */

void race(int numberOfTurns, CarF1 *car, int *listOfNumbers) {
    double timeThisTurn = 0;
    double timeInRace = 0;
    initCar(car);
    car->numberCar = *listOfNumbers;
    while (car->nbreTurns < numberOfTurns) {
        timeThisTurn = turnForRace(car, car->nbreTurns, numberOfTurns);
        timeInRace += timeThisTurn;
        if (timeThisTurn == 0) {
            car->status = -1;
            car->bestTime = 0;
            return;
        }
        car->nbreTurns += 1;
        if (car->bestTime > timeThisTurn || car->bestTime == 0) {
            car->bestTime = timeThisTurn;        //sauvegarde la valeur en memoire partagee
        }
    }
    if (car->updateRanking == 0) {
        car->updateRanking = 1;          //indique que le temps de la voiture a changeOrdre
    }
}

void resetSector(CarF1 *car) {
    car->sector1 = 0;
    car->sector2 = 0;
    car->sector3 = 0;
}

void initCar(CarF1 *car) {
    resetSector(car);
    car->numberCar = 0;
    car->bestTime = 0;
    car->totalTime = 0;
    car->nbreTurns = 0;
    car->status = 3;
    car->ranking = 0;
    car->crash = 0;
    car->stand = 0;
    car->updateRanking = 0;
    car->bestSector1 = INT_MAX;
    car->bestSector2 = INT_MAX;
    car->bestSector3 = INT_MAX;


}

