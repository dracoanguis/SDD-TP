#ifndef AEROPORT_H
#define AEROPORT_H
#include "liste.h"
#include "graph.h"

//def pour appelle double:

//Un aéroport avec code iata, ville, pays.
typedef struct Aeroport Aeroport;

//Un aéroport sans liste de liaisons:
struct Aeroport
{
    char iata[4];//Code unique par aeroport on considèere ca comme son nom.
    char ville[50];//Ville de localisation.
    char pays[50];//Pays de localisation.
};

//Fonctions d'initialisation de structure:

//Initilaise un aeroport contenant les données fourni et retourne sont pointeur.
Aeroport* initialiserAeroport(char iata[4],char ville[50],char pays[50]);

//Fonctions d'affichage d'element:

//Affiche les informations d'un aeroport.
void afficherAeroport(Aeroport* aeroport);

//Fonctions d'affichage de liste:

//Affiche la liste des aeroports avec leurs informations.
void afficherListe_Aeroport(Liste* liste);

#endif // !AEROPORT_H