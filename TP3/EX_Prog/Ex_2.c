#define EXIST_MAIN //Definie pour réutiliser Ex 1, supprime la fonction main de Ex1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Ex_2.h"
#include "Ex_1.h"
#include "Ex_1.c"

Racine* initialiserArbre()
{
    Racine* racineInit = malloc(sizeof(Racine));
    if (racineInit == NULL) {
        exit(EXIT_FAILURE);
    }

    racineInit->racine == NULL;

    return racineInit;
}

void remplirArbre(Racine* racineOrigin,Liste* liste)
{
    Element* elementCourrant = liste->premier;
    Arbre* arbreCourrant = NULL;//RacineOrigin->racine = NULL a la première itération normalement, impossible par conséquent de re remplir un arbre déja existant. 
    //Une erreure se produit si on laisse Arbre* arbreCourrant = RacineOrigin->racine alors que celle-ci = NULL

    while (elementCourrant != NULL)
    {
        Arbre* arbreNouveau = malloc(sizeof(Arbre));
        if (arbreNouveau == NULL)
        {
            printf("Failure\n");
            exit(EXIT_FAILURE);
        }
        
        arbreNouveau->valeur = &(elementCourrant->passager);
        arbreNouveau->racine = NULL;
        arbreNouveau->droit = NULL;
        arbreNouveau->gauche = NULL;

       if (arbreCourrant == NULL)  
       {
           racineOrigin->racine = arbreNouveau;
       } else {
           placement://Boucle pour le noeud suivant
           if (arbreNouveau->valeur->place > arbreCourrant->valeur->place)
           {    
               if (arbreCourrant->droit != NULL)
               {
                   arbreCourrant = arbreCourrant->droit;
                   goto placement;
               } else {
                   arbreCourrant->droit = arbreNouveau;
                   arbreNouveau->racine = arbreCourrant;
               } 
           } else {
               if (arbreCourrant->gauche != NULL)
               {
                   arbreCourrant = arbreCourrant->gauche;
                   goto placement;
               } else {
                   arbreCourrant->gauche = arbreNouveau;
                   arbreNouveau->racine = arbreCourrant;
               }       
           }
       }
        arbreCourrant = racineOrigin->racine;
        elementCourrant = elementCourrant->prochain;
    }
}

Liste* lectureArbre(Racine* racineOrigin)
{
   Liste* listeRetour = malloc(sizeof(Liste));
   Arbre* arbreCourrant = racineOrigin->racine;
   if (racineOrigin == NULL || listeRetour == NULL) 
   {
       printf("failure\n");
       exit(EXIT_FAILURE);
   }

    while (arbreCourrant != NULL)
    {
        while (arbreCourrant->droit != NULL)
        {   
            arbreCourrant = arbreCourrant->droit;
        }

        insererFinListe(listeRetour,arbreCourrant->valeur);//Fonction de l'exercice 1

        if (arbreCourrant->gauche != NULL)
        {
            if (arbreCourrant->racine == NULL)
            {
                racineOrigin->racine = arbreCourrant->gauche;
                arbreCourrant->gauche->racine = NULL;//on défini l'enfant gauche comme la nouvelle racine
                free(arbreCourrant);
                arbreCourrant = racineOrigin->racine;
            } else {
                arbreCourrant->racine->droit = arbreCourrant->gauche; //On définit l'enfant gauche comme l'enfant droit du parent
                free(arbreCourrant);
                arbreCourrant = racineOrigin->racine;
            }
        } else {
            if (arbreCourrant->racine == NULL)
            {
                supprimerElementListe(listeRetour);//Un élément faux se rajoute au début
                return listeRetour;
            } else {
                arbreCourrant = arbreCourrant->racine;
                free(arbreCourrant->droit);
                arbreCourrant->droit = NULL;
            }
        }
    }
    return listeRetour;
}

int main(int argc, char const *argv[])
{
    Liste *listeDesPassagers = listerPassager("passagers.txt");//Fonction de l'exercice 1
    Liste* listeResultat = initialiserListe();
    Racine* arbrePlace = initialiserArbre();
    printf("remplir arbre\n");//Si on retire cette ligne pas tout les éléments s'affiche
    remplirArbre(arbrePlace,listeDesPassagers);
    printf("lecture arbre\n");// Si on retire cette ligne rien ne s'affiche 
    listeResultat = lectureArbre(arbrePlace);
    printf("ca affiche\n");//Si on retire celle-ci pas tout les élément s'affiche
    afficherListe(listeResultat);//Fonction de l'exercice 1
    return 0;
}
/*Le problème que tous les éléments ne s'affiche pas si on ne met pas de printf("text"); avant est assz étrange car ses ligne ne devrai pas avoir 
d'influence entre elle. Il s'agit peut-être d'un problème d'output sur mon pc lié a une allocation mémoire ?*/