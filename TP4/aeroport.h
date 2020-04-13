#ifndef AEROPORT_H
#define AEROPORT_H

//Un aéroport sans liste de liaisons.
typedef struct Aeroport Aeroport;
struct Aeroport
{
    char iata[5];//Code unique par aeroport on considèere ca comme son nom.
    char ville[50];//Ville de localisation.
    char pays[50];//Pays de localisation.
};

//Element d'une liste qui contient un pointeur sur un aéroport.
typedef struct Element Element;
struct Element 
{
    Aeroport* aeroport;
    Element* suivant;
};

//Tête d'une liste d'element qui contient des pointeur sur des aéroports. Ranger en file pour faciliter la lecture des liaisons.
typedef struct Liste_Aeroport Liste_Aeroport;
struct Liste_Aeroport
{
    Element* premier;
};

//initilaise un aeroport contenant les données fourni et retourne sont pointeur.
Aeroport* initialiserAeroport(char iata[5],char ville[50],char pays[50]);
//Affiche les informations d'un aeroport.
void afficherAeroport(Aeroport* aeroport);

//Il n'y pas besoin de fonction pour modifier un aeroport car leur données sont constante dans le programme.

//Initilaise une liste vide d'Aeroports.
Liste_Aeroport* initialiserListe_Aeroport();
//Ajoute un element a la fin d'une liste.
void ajouterElementListe_Aeroport(Liste_Aeroport* liste,Aeroport* aeroport);
//Supprime un element au début de la liste.
void supprimerElementListe_Aeroport(Liste_Aeroport* liste);
//Affiche la liste des aeroports avec leurs informations.
void afficherListe_Aeroport(Liste_Aeroport* liste);

//Liste les aeroports a partir des informations du fichier.
Liste_Aeroport* lectureAeroports(const char *faeroports);
#endif // !AEROPORT_H