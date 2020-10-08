
#ifndef PROJET_C_TIMEGENERATION_H
#define PROJET_C_TIMEGENERATION_H
#define MAX_TIME_DIZAINE  35
#define MIN_TIME_DIZAINE  55
#define MAX_TIME_CENTIEME  999
#define MIN_TIME_CENTIEME  001
#define MAX_TIME_STAND_DIZAINE 27
#define MIN_TIME_STAND_DIZAINE 23
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int getRandomTimeSector();
int getRandomTimeStand();
#endif //PROJET_C_TIMEGENERATION_H
