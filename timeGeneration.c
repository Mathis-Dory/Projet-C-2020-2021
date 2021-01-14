
#include "timeGeneration.h"


double getRandomTimeSector() {
    double randomTimeTotal;
    int randomTimeDizaine = rand() % (MAX_TEMPS_DIZAINE + 1 - MIN_TEMPS_DIZAINE) + MIN_TEMPS_DIZAINE;
    int randomTimeCentieme = rand() % (MAX_TEMPS_CENTIEME + 1 - MIN_TEMPS_CENTIEME) + MIN_TEMPS_CENTIEME;
    randomTimeTotal = (randomTimeCentieme / 1000.000) + randomTimeDizaine;
    return randomTimeTotal;
}

double getRandomTimeStand() {
    double timeStand;
    int timeStandDizaine = rand() % (MAX_TEMPS_STAND_DIZAINE + 1 - MIN_TEMPS_STAND_DIZAINE) + MIN_TEMPS_STAND_DIZAINE;
    int timeStandCentieme = rand() % (MAX_TEMPS_CENTIEME + 1 - MIN_TEMPS_CENTIEME) + MIN_TEMPS_CENTIEME;
    timeStand = (timeStandCentieme / 100.000) + timeStandDizaine;
    return timeStand;

}

int carCrashed() {
    int randomCrash = rand() % (1001);
    if (randomCrash <= 0.5) {
        return 1;
    } else {
        return 0;
    }
}

int isInStand(){
    int randomStand = rand() % (101);
    if (randomStand <= 20){
        return 1;
    }
    else{
        return 0;
    }
}