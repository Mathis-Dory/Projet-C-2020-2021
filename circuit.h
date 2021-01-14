
#ifndef PROJET_C_FINAL_CIRCUIT_H
#define PROJET_C_FINAL_CIRCUIT_H
#include "timeGeneration.h"
#include "structure.h"
#include "secteur.h"
#include <limits.h>

double turn(CarF1 *car);
void qualification(int chrono, CarF1 *car, int *listOfNumbers);
void resetSector();
double turnForRace(CarF1 *car, int numberOfTurns, int maxTurns);
void race(int numberOfTurns, CarF1 *car, int *listOfNumbers);
void initCar(CarF1 *car);
#endif //PROJET_C_FINAL_CIRCUIT_H
