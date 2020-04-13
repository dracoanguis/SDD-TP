#ifndef GRAPH_H
#define GRAPH_H
#include "aeroport.h"

//Elements du graph:
typedef struct Sommet Sommet;
struct Sommet
{
    Aeroport aeroport;//Les valeurs du graph.
    Liste_Aeroport* liaisons;//Les arcs du graph.
    int marque;//Si il a été visité ou pas.
};

//Liste de tous les sommet pour les parcourir:
typedef struct Liste_Sommet Liste_Sommet;
struct Liste_Sommet
{
    Sommet sommet;//Lieux de stockage du sommet.
    Sommet* prochain;//Le prochain sommet a voir dans la liste du graph.
};

//Tête de liste de tous les sommet.
typedef struct Graph Graph;
struct Graph
{
    Sommet* premier;//Le premier Sommet du graph.
};



#endif // !GRAPH_H