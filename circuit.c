
#include "circuit.h"



double turn(CarF1* car){
    double total = 0; // Temps pour un tour
    double timeSector = 0; // Temps pour un secteur
    int i = 1;
    while (i <= 3) {
        switch (i) {
            case 1:
                timeSector = sector();
                break;
            case 2:
                timeSector = sector();
                break;
            case 3:
                timeSector = sector();
                break;
        }
        if(timeSector == 0){                 //test si il y a un crash
            //sem_wait(sem);
            car->status = 0;
            car->crash = 1;
            car->ranking = 1;
            resetSector(car);
            //sem_post(sem);
            return 0;
        }
        if((i%2)==0){             //si il passe dans le secteur 2
            //sem_wait(sem);
            car->sector2 = timeSector;
            //sem_post(sem);
        }
        else if((i%3)==0){        //si il passe dans le secteur 3
            if(isInStand()){
                timeSector += getRandomTimeStand();

                //sem_wait(sem);
                car->status=1;
                //sem_post(sem);

                //sleep(tempsStand/100);         // endormir le processus pendant s*10 milliseconde

            }
            //sem_wait(sem);
            car->status=2;
            car->sector3 = timeSector;
            //sem_post(sem);
        }
        else{                     //si il passe dans le secteur 1
            //sem_wait(sem);
            car->sector1 = timeSector;
            //sem_post(sem);
        }

        total += timeSector; //ajout au temps total de la voiture dans le circuit
        i ++;
    }
    printf("%f", total);
    return total;
}

void resetSector(CarF1* car){
    car->sector1 = 0;
    car->sector2 = 0;
    car->sector3 = 0;
}
