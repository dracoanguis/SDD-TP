#ifndef LISTE_H
#define LISTE_H

//Definitions:
//Element d'une liste qui contien un pointeur sur la donnée, et un vers l'element prochain.
typedef struct Element Element;
//Tete de la liste qui contient un pointeur vers le premier element.
typedef struct Liste Liste;
//Tete de la pile qui contient un pointeur vers le premier element.
typedef struct Pile Pile;

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

//Pile ou Head de Pile
struct Pile
{
    Element* premier;
};

//Initilaise une liste vide.
Liste* initialiserListe();
//Initialise une Pile vide.
Pile* initialiserPile();
//Ajoute un element a la fin d'une liste.
void ajouterElementListe(Liste* liste,void* element);
//Ajoute un Element au debut d'une Pile.
void ajouterElementPile(Pile* pile,void* element);
//Supprime un Element au début d'une Pile.
void supprimerElementPile(Pile* pile);
//Supprime un Element au début d'une File.
void supprimerElementFile(Liste* pile);

//Compte le nombre d'element dans une Liste.
int compterElementListe(Liste* liste);

#endif // !LISTE_H