#ifndef LISTE_H
#define LISTE_H

//Definitions:
typedef struct Element Element;
typedef struct Liste Liste;

//Element d'une liste:
struct Element
{
    void* data;
    Element* prochain;  
};

//Liste ou Head de liste;
struct Liste
{
    Element* premier;  
};


//Initilaise une liste vide.
Liste* initialiserListe();
//Ajoute un element a la fin d'une liste.
void ajouterElementListe(Liste* liste,void* element);
//Supprime un element au début de la liste.
void supprimerElementListe(Liste* liste);


#endif // !LISTE_H