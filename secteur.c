

#include "secteur.h"

double sector(){

    double temp = 0;

    if(carCrashed()== 0){//si il n'y a pas de crash
        temp = getRandomTimeSector();//Generation du nombre aleatoire
        return temp;
    }
    return temp;//si il y a un crash
}