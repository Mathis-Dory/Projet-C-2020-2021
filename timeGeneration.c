
#include "timeGeneration.h"

double getRandomTimeSector() {
    double randomTimeTotal;
    int randomTimeDizaine = rand() % (MAX_TIME_DIZAINE + 1 - MIN_TIME_DIZAINE) + MIN_TIME_DIZAINE;
    int randomTimeCentieme = rand() % (MAX_TIME_CENTIEME + 1 - MIN_TIME_CENTIEME) + MIN_TIME_CENTIEME;
    randomTimeTotal = (randomTimeCentieme / 1000.000) + randomTimeDizaine;
    return randomTimeTotal;
}

double getRandomTimeStand() {
    double timeStand;
    int timeStandDizaine = rand() % (MAX_TIME_STAND_DIZAINE + 1 - MIN_TIME_STAND_DIZAINE) + MIN_TIME_STAND_DIZAINE;
    int timeStandCentieme = rand() % (MAX_TIME_CENTIEME + 1 - MIN_TIME_CENTIEME) + MIN_TIME_CENTIEME;
    timeStand = (timeStandCentieme / 100.000) + timeStandDizaine;
    return timeStand;

}

int carCrashed() {
    int randomCrash = rand() % (100 + 1);
    if (randomCrash <= CHANCE_DE_CRASH) {
        return 1;
    } else {
        return 0;
    }
}

int isInStand(){
    int randomStand = rand() % (100 + 1);
    if (randomStand <= CHANCE_DE_STAND){
        return 1;
    }
    else{
        return 0;
    }
}
