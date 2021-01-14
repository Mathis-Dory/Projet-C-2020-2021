
#include <stdio.h>
#include <stdlib.h>
#include "circuit.h"
#include "config.h"
#include "config.c"
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <semaphore.h>
#include "affichage.h"
#include <sys/wait.h>

int typeOfRace(char *argv[]) ;

ConfigRace config;
CarF1 *car;
int listOfNumbers [NB_CARS] = {7, 99, 5, 16, 8, 20, 4, 55, 10, 26, 44, 77, 11, 18, 23, 33, 3, 27, 63, 88}; // Liste de numéros

int main(int argc, char *argv[]) {
    srand(time(0)+getpid());
    if (argc != 2){
        perror("Veuillez passer 1 paramètre au programme !");
        exit(EXIT_FAILURE);
    }

    int idRace = typeOfRace(argv);

    if (idRace == -1) {
        perror("le paramètre rentré en premier au programme n'est pas conforme!\nVeuillez rentrer P1, P2, P3, Q1, Q2, Q3 ou R !");
        exit(EXIT_FAILURE);
    }
    else{
        // Création de la mémoire partagée pour la voiture
        int shmid = shmget(IPC_PRIVATE, sizeof(car) * config.nbreOfCars, 0666 | IPC_CREAT); // key, taille, permissions de base + création
        if (shmid == -1){
            perror("la création de la mémoire partagée pour la structure voiture a raté !");
            exit(EXIT_FAILURE);
        }
        // On attache la mémoire partagée à la structure car
        car = shmat(shmid, NULL, 0); // id, trouve une adresse libre, read only
        if (car == (void *) (-1)){
            perror("L'attachement de la mémoiré partagée pour la voiture a raté !");
            exit(EXIT_FAILURE);
        }
        // Création de la mémoire partagée pour le sémaphore
        int shmid_sem = shmget(IPC_PRIVATE, sizeof(sem_t), 0666 | IPC_CREAT); // key, taille (struct semaphore), permissions
        if(shmid_sem == -1){
            perror("la création de la mémoire partagée pour la structure semaphore a raté !");
            exit(EXIT_FAILURE);
        }
        // Attachement de la mémoire partagée au sémaphore
        sem_t *semaphore = shmat(shmid_sem, NULL, 0); // id, trouve une adresse libre, read only
        if (semaphore == (void *) (-1)){
            perror("L'attachement de la mémoire partagée pour le semaphore a raté !");
            exit(EXIT_FAILURE);
        }
        // Création d'un sémaphore
        sem_init(semaphore, 1,1); // pointer, 1 pour dire qu'il peut être partagé entre plusieurs processus et sera situé dans la mémoire partagée avec possibilité
        // de la fork, le dernier parametre est la valeur de ce semaphore
        // Création d'un fils
        int i = 0;
        pid_t pid;
        for (i ; i < config.nbreOfCars; i++) // On fork autant de fois qu'il y a de voitures dans la course
        {
            pid = fork();
            if (pid == 0){
                break; // empeche de lancer 20^20 processus
            }
        }
        switch (pid) {
            case -1:
                perror("Erreur lors du fork !");
                exit(EXIT_FAILURE);
            case 0:
                if (idRace == 1 || idRace == 2 || idRace == 3 || idRace == 4 || idRace == 5 || idRace == 6){
                    qualification(config.timeForSession, &car[i], &listOfNumbers[i]);
                }
                else if (idRace == 7){
                    race(config.nbreOfTurnsToWin, &car[i], &listOfNumbers[i]);
                }
                exit(EXIT_SUCCESS);
            default:
                for(int j=0; j<config.nbreOfCars; j++){
                    wait(NULL);
                }
                displayResult(car, semaphore);
        }
        // On detache la voiture de la mémoire partagée
        shmdt(car);
        // On détruit la mémoire partagée
        shmctl(shmid, IPC_RMID, NULL); // pointer, action de destruction,

        return EXIT_SUCCESS;
    }
}


int typeOfRace(char *argv[]) {

    if(!strcmp(argv[1], "P1")){
        config.nbreOfCars = 20;
        config.timeForSession = CHRONO_E1;
        return 1;

    }
    else if(!strcmp(argv[1], "P2")) {
        config.nbreOfCars = 20;
        config.timeForSession = CHRONO_E2;
        return 2;

    }
    else if(!strcmp(argv[1], "P3")) {
        config.nbreOfCars = 20;
        config.timeForSession = CHRONO_E3;
        return 3;

    }
    else if(!strcmp(argv[1], "Q1")) {
        config.nbreOfCars = 20;
        config.timeForSession = CHRONO_Q1;
        return 4;

    }
    else if(!strcmp(argv[1], "Q2")) {
        config.nbreOfCars = 15;
        config.timeForSession = CHRONO_Q2;
        return 5;

    }
    else if(!strcmp(argv[1], "Q3")) {
        config.nbreOfCars = 10;
        config.timeForSession = CHRONO_Q3;
        return 6;

    }
    else if(!strcmp(argv[1], "R")) {
        config.nbreOfCars = 20;
        config.nbreOfTurnsToWin = NUMBER_OF_TURNS;
        return 7;

    }
    else {
        return -1;
    }
}

