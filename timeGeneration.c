
#include "timeGeneration.h"

int getRandomTimeSector(){
    double randomTimeTotal;
    int randomTimeDizaine = rand() % (MAX_TIME_DIZAINE  + 1 - MIN_TIME_DIZAINE) + MIN_TIME_DIZAINE;
    int randomTimeCentieme = rand() % (MAX_TIME_CENTIEME  + 1 - MIN_TIME_CENTIEME) + MIN_TIME_CENTIEME;
    randomTimeTotal = (randomTimeCentieme/100.000) + randomTimeDizaine;
    printf("Nombre: %.3f \n", randomTimeTotal);
}

int getRandomTimeStand(){
    double timeStand;
    int timeStandDizaine= rand() % (MAX_TIME_STAND_DIZAINE + 1 - MIN_TIME_STAND_DIZAINE) + MIN_TIME_STAND_DIZAINE;
    int timeStandCentieme = rand() % (MAX_TIME_CENTIEME + 1 - MIN_TIME_CENTIEME) + MIN_TIME_CENTIEME;
    timeStand = (timeStandCentieme/100.000) + timeStandDizaine;
    printf("Temps au stand: %.3f \n", timeStand);

}
