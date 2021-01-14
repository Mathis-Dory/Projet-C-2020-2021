
#include "affichage.h"

ConfigRace config;
CarF1 copyCar[NB_CARS];

void displayResult(CarF1 *data, sem_t *semaphore){
        sem_wait(semaphore);
        for (int i=0; i<NB_CARS;i++) {
            copyCar[i] = data[i];
        }
        sem_post(semaphore);
        qsort(copyCar, config.nbreOfCars, sizeof(CarF1), sortCars);
        //Si la dernière voiture de la course a fini, on arrète le programme

        printf("|\tPos.\t|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|\t%s\t|\t%s\t|\n\n", "Numero", "Secteur 1", "Secteur 2", "Secteur 3", "Temps en course", "Nombre de Tours", "P", "O");

        for(int i=0; i<config.nbreOfCars; i++){
            printf("|\t%d\t|%10d\t|%10.3f\t|%10.3f\t|%10.3f\t|%10.3f\t|\t%d\t|\t%d\t|\t%d  |\n",
                   i+1, copyCar[i].numberCar, copyCar[i].sector1, copyCar[i].sector2, copyCar[i].sector3, copyCar[i].totalTime, copyCar[i].nbreTurns, copyCar[i].stand, copyCar[i].crash);

        }

        printf("\n\tBest S1: %d [%.3f]\t", copyCar[indexBestOfSector("S1")].numberCar, copyCar[indexBestOfSector("S1")].bestSector1);
        printf("Best S2: %d [%.3f]\t", copyCar[indexBestOfSector("S2")].numberCar, copyCar[indexBestOfSector("S2")].bestSector2);
        printf("Best S3: %d [%.3f]\t", copyCar[indexBestOfSector("S3")].numberCar, copyCar[indexBestOfSector("S3")].bestSector3);
        printf("Meilleur tour: %d [%.3f]\n",copyCar[indexBestOfLap()].numberCar, copyCar[indexBestOfLap()].bestTime);

        sleep(1); //sleep pour chaque refresh de la grille
        system("clear");
    sleep(3); //Sleep pour fin de course afin de voir le tableau finale

}

int sortCars(const void *a, const void *b){
    const CarF1 *p1 = (CarF1 *) a;
    const CarF1 *p2 = (CarF1 *) b;

    if(p1->bestTime > p2->bestTime){
        return 1;
    } else if(p1->bestTime < p2->bestTime){
        return -1;
    } else {
        return 0;
    }
}

int indexBestOfSector(char sectId[]){
    int index = 0;
    double bestOfThis = 0;

    for(int i=0; i < config.nbreOfCars; i++){
        if(sectId == "S1"){
            if(bestOfThis == 0 || copyCar[i].bestSector1 < bestOfThis){
                bestOfThis = copyCar[i].bestSector1;
                index = i;
            }

        } else if(sectId == "S2"){
            if(bestOfThis == 0 || copyCar[i].bestSector2 < bestOfThis){
                bestOfThis = copyCar[i].bestSector2;
                index = i;
            }

        } else if(sectId == "S3"){
            if(bestOfThis == 0 || copyCar[i].bestSector3 < bestOfThis){
                bestOfThis = copyCar[i].bestSector3;
                index = i;
            }

        }
    }
    return index;
}

int indexBestOfLap(){
    int index = 0;
    double record = 0;

    for(int i=0; i < config.nbreOfCars; i++){
        if(record = 0 || copyCar[i].bestTime < record){
            record = copyCar[i].bestTime;
            index = i;
        }
    }

    return index;
}
