#include <stdio.h>
#include <stdlib.h>
#include "stdprof.h"




typedef struct carto{
    int taillex;
    int tailley;
    char **memoire ;
    int x ;
    int y;	
}carte; 

/*Structures*/
typedef struct rahan_stats {
    int pdv;
    int sante;
    int force;
    int vitesse;
} stats;


typedef struct coordonee_rahan{
    signed int x;
    signed int y;
} coordone;


typedef struct equipement {
    char * description; /*bottes en peu de croco*/
    char * bonus; /*V+10*/
    char * classe; /*chaussure*/
} objet;

typedef struct bouffe {
    char * nom;
    int  vierecup;
    char * description;
} nouritures;

typedef struct monstre_stat {
    char * name;
    int  force;
    int  vie;
} monstre;

carte *nouvelle_carte(int x,int y){
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
coordone  coord_r(){
    coordone coord;
    coord.x=0;
    coord.y=0;
    return coord;
}

extern coordone coord;
extern stats rahan;
extern carte *map;



void liberer_macron();

void afficher_carte();

void INVOCATION();

void HAUT();

void BAS() ;

void GAUCHE();

void DROITE();

char lire_commande();
