#include <stdio.h>
#include <stdlib.h>
#include "stdprof.h"
#include "eleve.h"

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

coordone coord_r(){
    coordone coord;
    coord.x=0;
    coord.y=0;
    return coord;
}