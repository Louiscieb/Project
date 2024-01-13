#include <stdio.h>
#include <stdlib.h>
#include "stdprof.h"
#include "eleve.h"

int main(void){
    char test[30];
    int i,j;
    int character;
    char init_values[10][10] = {
        {'R', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' '},
        {' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', 'Y', ' ', ' ', '#', ' ', ' '},
        {' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };
    spawn_rahan();
    map= nouvelle_carte(10,10);
    for ( i = 0; i < map->tailley; i++) {
        for ( j = 0; j < map->taillex; j++) {
            map->memoire[i][j] = init_values[i][j];
        }
    }
    /*afficher_carte();
    BAS();
    BAS();
    INVOCATION();
    afficher_carte();
    DROITE();
    HAUT();
    afficher_carte(); 
    HAUT();
    afficher_carte();
    liberer_macron();
    printf("%d , %d",coord.x,coord.y);
    stdprof_afficher();*/
    /*printf("%d",lire_commande());*/
    
    printf("Entrez une chaîne de caractères (Ctrl+D pour terminer la saisie) :\n");


    printf("Vous avez saisi : ");
    
    while ((character = getchar()) != EOF && character != '\n') {
        printf("%c",character);
        
    }  
    test[1]=character;   
    printf("%s",test);

    printf("\n");
    return 0;
}   
