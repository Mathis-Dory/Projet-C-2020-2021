

#ifndef PROJET_C_FINAL_STRUCTURE_H
#define PROJET_C_FINAL_STRUCTURE_H
typedef struct {
    int numberCar;
    double sector1;
    double sector2;
    double sector3;
    double bestSector1;
    double bestSector2;
    double bestSector3;
    double bestTime;
    double totalTime;
    int nbreTurns;
    int status; // 0 = Crash 1 = En course 2 = stand -1 = OUT 3 = READY
    int ranking; // Place dans le classement
    int crash; // 1 pour True 0 pour False
    int stand; // nombre de fois passé au stand
    int updateRanking; // 1 True 0 False
}CarF1;

typedef struct
{
    int timeForSession;
    int nbreOfCars;
    int nbreOfTurnsToWin;
}ConfigRace;

#endif //PROJET_C_FINAL_STRUCTURE_H
