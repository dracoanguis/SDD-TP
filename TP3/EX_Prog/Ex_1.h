#ifndef EX1_H_INCLUDED
#define EX1_H_INCLUDED

typedef struct Passager Passager;
struct Passager
{
    int numClient;
    char nom[50];
    char prenom[50];
    int age;
    int place;
};

typedef struct Element Element;//Un élément de la liste
struct Element
{
    Passager passager;
    Element * prochain;
};

typedef struct Liste Liste;//La tête de liste
struct Liste
{
    //Pointeur sur le premier élément de la liste
    Element * premier;
};

//initialise une liste vide
Liste* initialiserListe();
//insere des élément dans une liste
void insererDebutListe(Liste *liste, Passager* nvPassager);
//supprime le premier élément d'une liste
void supprimerElementListe(Liste *liste);
//crée un passager
Passager *initialiserPassager(int numClient,char *nom, char*prenom,int age,int place);
//affiche une liste de passagers
void afficherListe(Liste * liste);
//Rentrer la localisation du fichier passagers
Liste *listerPassager(const char *fpassager);
//Ajoute a la fin d'une liste
void insererFinListe(Liste *liste, Passager* nvPassager);
#endif // !MAIN_H_INCLUDED