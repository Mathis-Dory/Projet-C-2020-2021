
#include "timeGeneration.h"

int getRandomTime(){
    double randomTimeTotal;
    int randomTimeDizaine = rand() % (MAX_TIME_DIZAINE  + 1 - MIN_TIME_DIZAINE) + MIN_TIME_DIZAINE;
    int randomTimeCentieme = rand() % (MAX_TIME_CENTIEME  + 1 - MIN_TIME_CENTIEME) + MIN_TIME_CENTIEME;
    randomTimeTotal = (randomTimeCentieme/100.000) + randomTimeDizaine;
    printf("Nombre: %.3f \n", randomTimeTotal);
}