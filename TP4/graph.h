#ifndef GRAPH_H
#define GRAPH_H
#include "liste.h"

//def pour appelle double:
typedef struct Aeroport Aeroport;
typedef struct Sommet Sommet;
typedef struct Successeur Successeur;

//Un aéroport sans liste de liaisons:
struct Aeroport
{
    char iata[5];//Code unique par aeroport on considèere ca comme son nom.
    char ville[50];//Ville de localisation.
    char pays[50];//Pays de localisation.
};

//Succeseur possible a un sommet:
struct Successeur
{
    Sommet* sommet_representer;//L'element qu'il représente.
    int cout;//Le cout du déplacement.
    Successeur* prochain;//Prochain successeur possible de la liste.
};

//Elements du graph:
struct Sommet
{
    Aeroport* aeroport;//Les valeurs du graph.
    Liste* liaisons;//Les arcs du graph.
    int marque;//S'il a été visité ou pas, 0 non, 1 oui.
};


//Fonctions d'initialisation de structure:

//initilaise un aeroport contenant les données fourni et retourne sont pointeur.
Aeroport* initialiserAeroport(char iata[5],char ville[50],char pays[50]);

//Fonctions d'affichage d'element:

//Affiche les informations d'un aeroport.
void afficherAeroport(Aeroport* aeroport);

//Fonctions d'afichage de liste:

//Affiche la liste des aeroports avec leurs informations.
void afficherListe_Aeroport(Liste* liste);

//Fonctions de lecture de document:

//Liste les aeroports a partir des informations du fichier.
Liste* lectureAeroports(const char *faeroports);

#endif // !GRAPH_H