#include <stdio.h>
#include <stdlib.h>
#include "stdprof.h"
#include "eleve.h"

coordone coord;
stats rahan;
carte *map;

void init_eleve_structures(void) {
    coord = coord_r();
    rahan = spawn_rahan();
    map = nouvelle_carte(10, 10);
}


void liberer_macron() {
    int i;
    for ( i = 0; i < map-> tailley; i++) {
        stdprof_free(map-> memoire[i]);
    }
    stdprof_free(map-> memoire);
    stdprof_free(map);
}

void afficher_carte(){
    int i,j;
    printf("  0 1 2 3 4 5 6 7 8 9 \n");/*a remplacer après par une boucle jusqu'a taille x*/
    printf(" +-+-+-+-+-+-+-+-+-+-+\n");
    for(i=0; i<map-> tailley;i++){
        printf("%d",i);
        printf("|");  
        for(j=0; j<map-> taillex; j++){
            printf("%c",map-> memoire[i][j]);
            if (j+1 != map-> taillex) {
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

    if (map-> memoire[coord.x][coord.y-1] =='#'){
        printf("Rahan :\" Aïe ! >:(\"\n");
    }
    else{
        map-> memoire[coord.y][coord.x] = ' ';
        map-> memoire[coord.y - 1][coord.x] = 'R';
        coord.y = coord.y - 1;
    }    
}

void BAS() {

    if (map-> memoire[coord.x][coord.y+1] =='#'){
        printf("Rahan :\" Aïe ! >:(\"\n");
        } 
    else{
        map-> memoire[coord.y][coord.x] = ' ';
        map-> memoire[coord.y+1][coord.x] = 'R';
        coord.y = coord.y + 1; 

    }            
}

void GAUCHE() {

    if (map -> memoire[coord.x-1][coord.y] =='#'){
    printf("Rahan :\" Aïe ! >:(\"\n");
}
else{
    map-> memoire[coord.y][coord.x] = ' ';
    map-> memoire[coord.y][coord.x - 1] = 'R';
    coord.x = coord.x - 1;
}
}    

void DROITE() {

    if (map-> memoire[coord.x + 1][coord.y] =='#'){
    printf("Rahan :\" Aïe ! >:(\"\n");
}
else{
    map-> memoire[coord.y][coord.x] = ' ';
    map-> memoire[coord.y][coord.x + 1] = 'R';
    coord.x = coord.x + 1;
}
}

void GRIMPER(){}    /*Affiche la carte*/    
void RANGER(){}     /*Affiche l'inventaire*/
void VISION(){

}
char lire_commande() {
    int n = 0;
    char c;
    char u;
    printf("entier> ");
    while ( (u=(c = getchar())) != '\n' && c != EOF && u != '#') {
        if ('0' <= c && c <= '9') {
            n = n*10 + (c-'0');
        } else {
          while ( (c = getchar()) != '\n' && c != EOF);
          return -1;
        }
    }
    return n;
}


