

#ifndef PROJET_C_FINAL_AFFICHAGE_H
#define PROJET_C_FINAL_AFFICHAGE_H
#include <stdlib.h>
#include <stdio.h>
#include "circuit.h"
#include <semaphore.h>
#include <unistd.h>
#include <string.h>
void displayResult(CarF1 *car, sem_t *semaphore);
int sortCars(const void *a, const void *b);
int indexBestOfSector(char sectId[]);
int indexBestOfLap();
#endif //PROJET_C_FINAL_AFFICHAGE_H
