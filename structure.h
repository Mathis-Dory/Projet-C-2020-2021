
#ifndef PROJET_C_STRUCTURE_H
#define PROJET_C_STRUCTURE_H

typedef struct CarF1 CarF1;
struct CarF1 {
    int numberCar;
    double sector1;
    double sector2;
    double sector3;
    int bestTime;
    int totalTime;
    int nbreTurns;
    int status;
    int ranking;
    int crash;
    int stand;
};

#endif //PROJET_C_STRUCTURE_H

