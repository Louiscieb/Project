#ifndef ELEVE_H
#define ELEVE_H

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


struct coord;
struct rahan;
struct map;

carte nouvelle_carte(int x,int y);

void GIGA_NIGGA_SWITCH(char arg);
void liberer_macron();
void VISION();
void INVOCATION();
void HAUT();
void BAS();
void GAUCHE();
void DROITE();
char lire_commande();


#endif
