#include <stdio.h>
#include <stdlib.h>
#include "stdprof.h"
#include "eleve.h"


struct coordonee_rahan coord={0,0};
struct rahan_stats rahan = {80,80,10,3};
struct carto *map;

void liberer_macron() {
    int i;
    for ( i = 0; i < map-> tailley; i++) {
        stdprof_free(map-> memoire[i]);
    }
    stdprof_free(map-> memoire);
    stdprof_free(map);
}


void VISION(){
    int i,j;
    printf("  0 1 2 3 4 5 6 7 8 9 \n");/*a remplacer après par une boucle jusqu'a taille x*/
    printf(" +-+-+-+-+-+-+-+-+-+-+\n");
    for(i=0; i<map->tailley;i++){
        printf("%d",i);
        printf("|");  
        for(j=0; j<map->taillex; j++){
            printf("%c",map->memoire[i][j]);
            if (j+1 != map->taillex) {
                printf(" ");
            } 
    }			
        printf("|\n");
}
    printf(" +-+-+-+-+-+-+-+-+-+-+\n");
}

void INVOCATION(){
    printf("\n ===STATISTIQUES===\nSANTé : %d/%d\nForce : %d\nVITESSE : %d\n================== \n",
    rahan.pdv,rahan.sante,rahan.force,rahan.vitesse);
}                   /*Affiche les statistiques du personnage*/


void HAUT() {
    int i=0;
    while(i<rahan.vitesse) {
        if (map->memoire[coord.x][coord.y - 1] == '#') {
            printf("Rahan : \" Aïe ! >:(\"\n");
            break;
        }
        map->memoire[coord.y][coord.x] = ' ';
        map->memoire[coord.y - 1][coord.x] = 'R';
        coord.y = coord.y - 1;
        i++;
    }
}

void BAS() {
    int i=0;
    while(i<rahan.vitesse){
        if (map->memoire[coord.x][coord.y + 1] == '#') {
            printf("Rahan : \" Aïe ! >:(\"\n");
            break;
        } 
        map->memoire[coord.y][coord.x] = ' ';
        map->memoire[coord.y + 1][coord.x] = 'R';
        coord.y = coord.y + 1;
        i++;
    }
}

void GAUCHE() {
    int i=0;    
    while(i<rahan.vitesse){
        if (map->memoire[coord.x-1][coord.y] == '#') {
            printf("Rahan : \" Aïe ! >:(\"\n");
            break;
        } 
        map->memoire[coord.y][coord.x] = ' ';
        map->memoire[coord.y][coord.x-1] = 'R';
        coord.x = coord.x - 1;
        i++;
    }
}

void DROITE() {
    int i=0;
    while(i<rahan.vitesse){
        if (map->memoire[coord.x+1][coord.y] == '#') {
            printf("Rahan : \" Aïe ! >:(\"\n");
            break;
        } 
        map->memoire[coord.y][coord.x] = ' ';
        map->memoire[coord.y][coord.x+1] = 'R';
        coord.x = coord.x + 1;
        i++;
    }
}
void GIGA_NIGGA_SWITCH(char  arg){
    switch (arg)
    {
    case 'I':
        INVOCATION();
        break;
    case 'V':
        VISION();
        break;
    case 'H':
        HAUT();
        break;
    case 'B':
        BAS();
        break;
    case 'G':
        GAUCHE();
        break;
    case 'D':
        DROITE();
        break;
    case 'd' :
        DROITE();
        break;
    default:
        break;
    }




}
carte* nouvelle_carte(int x,int y){
    int i;
    carte *carton=stdprof_malloc(sizeof(carte));
    carton->taillex=x;
    carton->tailley=y;
    carton->memoire = stdprof_malloc(y * sizeof(char *));
    for ( i = 0; i < y; i++) {
        carton->memoire[i] = stdprof_malloc(x * sizeof(char));
    }
    carton->x=0;
    carton->y=0;
    return carton;
}

stats spawn_rahan(){
    stats rahan;
    rahan.pdv = 80;
    rahan.sante = rahan.pdv;
    rahan.force = 10;
    rahan.vitesse = 1;
    return rahan;
}

coordone coord_r(){
    coordone coord;
    coord.x=0;
    coord.y=0;
    return coord;
}
void GRIMPER(){}    /*Affiche la carte*/    
void RANGER(){}     /*Affiche l'inventaire*/



