#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

typedef struct Equipage Equipage;
struct Equipage
{
    char capitaine[50];
    char copilote[50];
    char stewardUn[50];
    char stewardDeux[50];
    char avion[50];
};

typedef struct Vol Vol;
struct Vol
{
    char date[20];
    char depart[50];
    char arriver[50];
    unsigned char numeroEquipe;
};

void initialisationPersonnel();
void initialisationVolPrevu();

unsigned char remplissagePersonnel();

void ajoutEquipage();
void afficherPersonnel();
void afficherEquipage(Equipage *equipageDonnee);
void supprimerEquipage(Equipage *equipageDonnee);
void modifierEquipage(Equipage *equipageDonnee);

unsigned char remplissageVolPrevu();

void ajoutVol();
void afficherVolPrevu();
void afficherVol(Vol *volDonnee);
void modifierVol(Vol *volDonnee);
void supprimerVol(Vol *volDonnee);

void menuPrincipal();
unsigned char selectionEmplacement(unsigned char mode);
int verificateurDispEmplacement(unsigned char emplacementDonnee,unsigned char mode);

#endif