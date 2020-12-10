
#ifndef PROJET_C_STRUCTURE_H
#define PROJET_C_STRUCTURE_H


typedef struct {
    int numberCar;
    double sector1;
    double sector2;
    double sector3;
    int bestTime;
    int totalTime;
    int nbreTurns;
    int status; // 0 = Crash 1 = En course 2 = stand -1 = OUT
    int ranking; // Place dans le classement
    int crash; // 1 pour True 0 pour False
    int stand; // 1 pour True 0 pour False
    int updateRanking; // 1 True 0 False
}CarF1;

#endif //PROJET_C_STRUCTURE_H

