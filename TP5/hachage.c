#ifndef HACHAGE_C
#define HACHAGE_C
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "hachage.h"
#include "liste.c"
/* A definir dans le fichier pour utiliser.
#define ELEMENT_TYPE 
#define CHEMIN_CLEF(objet) 
#define CHEMIN_CLEF_B(objet) 
*/


//Le hache vide.
const Hache emptyhache = {0,-1,NULL};

int coderMotNombreSimple(char mot[], int taille)
{
    int taillem = strlen(mot);
    unsigned long long code = 0;
    char lettre = 0;

    for (int i = 0; i < taillem; i++)
    {
        lettre = (*(mot + i*sizeof(char)) - 64);
        for (int e = 0; e < i; e++)
        {
            lettre = lettre*26;
        }
        code = code + lettre;
    }

    code = code%taille;
    
    return (int)code;
}

Hache innitialiserHache(void* element)
{
    Hache nouveau;

    nouveau.element = element;
    nouveau.hache = -1;
    nouveau.essaie = 0;

    return nouveau;
}

void remplissageTableHacheVide(Hache table[],int taille)
{
    if (table == NULL)
    {
        printf("\nError: empty Table Hache!\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < taille; i++)
    {
        table[i] = emptyhache;
    }
}

void remplissageTableHacheSimple(Hache table[],int tailletable,Liste* liste)
{

    if (table == NULL || liste == NULL | liste->premier == NULL)
    {
        printf("\nError: Empty or non-existing Table Hache or Liste!\n");
        exit(EXIT_FAILURE);
    }
    
    int tailleliste = compterElementListe(liste);

    if (tailleliste > tailletable)
    {
        printf("\nError: incompatible lenght Table Hache < Liste Element!\n");
        exit(EXIT_FAILURE);
    }

    Element* courrant = liste->premier;

    for (int i = 0; i < tailleliste; i++)
    {
        ELEMENT_TYPE elem_val = courrant->data;
        char clef[] = CHEMIN_CLEF(elem_val);
        Hache nouveau = innitialiserHache(elem_val);
        nouveau.hache = coderMotNombre(clef,tailletable);
        int place = nouveau.hache;

        while (table[place].hache != -1)
        {
            nouveau.essaie++;
            place++;
            if (place == tailletable)
            {
                place = place - tailletable;//On retourne au dbut si on a atteins la fin. En théorie la table ne peut etre pleine.
            }
        }
        table[place] = nouveau;
        courrant = courrant->prochain;
    }
    
}

int coderMotNombreLinear(char mot[], int taille, int essaie)
{
    int taillem = strlen(mot);
    unsigned long long code = 0;
    char lettre = 0;

    for (int i = 0; i < taillem; i++)
    {
        lettre = (*(mot + i*sizeof(char)) - 64);
        for (int e = 0; e < i; e++)
        {
            lettre = lettre*26;
        }
        code = code + lettre;
    }

    code = (code + essaie)%taille;
    
    return (int)code;
}

void remplissageTableHacheLinear(Hache table[],int tailletable,Liste* liste)
{

    if (table == NULL || liste == NULL | liste->premier == NULL)
    {
        printf("\nError: Empty or non-existing Table Hache or Liste!\n");
        exit(EXIT_FAILURE);
    }
    
    int tailleliste = compterElementListe(liste);

    if (tailleliste > tailletable)
    {
        printf("\nError: incompatible lenght Table Hache < Liste Element!\n");
        exit(EXIT_FAILURE);
    }

    Element* courrant = liste->premier;

    for (int i = 0; i < tailleliste; i++)
    {
        ELEMENT_TYPE elem_val = courrant->data;
        char clef[] = CHEMIN_CLEF(elem_val);
        Hache nouveau = innitialiserHache(elem_val);
        nouveau.hache = coderMotNombreLinear(clef,tailletable,nouveau.essaie);

        while (table[nouveau.hache].hache != -1)
        {
            nouveau.essaie++;
            nouveau.hache = coderMotNombreLinear(clef,tailletable,nouveau.essaie);
        }
        table[nouveau.hache] = nouveau;
        courrant = courrant->prochain;
    }
    
}

int coderMotNombreQuadratique(char mot[], int taille, int essaie)
{
    int taillem = strlen(mot);
    unsigned long long code = 0;
    char lettre = 0;

    for (int i = 0; i < taillem; i++)
    {
        lettre = (*(mot + i*sizeof(char)) - 64);
        for (int e = 0; e < i; e++)
        {
            lettre = lettre*26;
        }
        code = code + lettre;
    }

    code = (((code%taille) + ((2*essaie + 3*essaie*essaie)%taille))%taille);//Pour eviter les nombre trop grand
    
    return (int)code;
}

void remplissageTableHacheQuadratique(Hache table[],int tailletable,Liste* liste)
{

    if (table == NULL || liste == NULL | liste->premier == NULL)
    {
        printf("\nError: Empty or non-existing Table Hache or Liste!\n");
        exit(EXIT_FAILURE);
    }
    
    int tailleliste = compterElementListe(liste);

    if (tailleliste > tailletable)
    {
        printf("\nError: incompatible lenght Table Hache < Liste Element!\n");
        exit(EXIT_FAILURE);
    }

    Element* courrant = liste->premier;

    for (int i = 0; i < tailleliste; i++)
    {
        ELEMENT_TYPE elem_val = courrant->data;
        char clef[] = CHEMIN_CLEF(elem_val);
        Hache nouveau = innitialiserHache(elem_val);
        nouveau.hache = coderMotNombreQuadratique(clef,tailletable,nouveau.essaie);

        while (table[nouveau.hache].hache != -1)
        {
            nouveau.essaie++;
            nouveau.hache = coderMotNombreQuadratique(clef,tailletable,nouveau.essaie);
        }
        table[nouveau.hache] = nouveau;
        courrant = courrant->prochain;
    }
    
}

int coderMotNombreDouble(char mot[],char motb[], int taille, int essaie)
{
    unsigned long long code = coderMotNombreSimple(mot,taille);
    int codeb = coderMotNombreSimple(motb,taille);

    if (codeb == 0)
    {
        codeb = 1;
    }
    
    code = (code + essaie*codeb)%taille;    
    return (int)code;
}

void remplissageTableHacheDouble(Hache table[],int tailletable,Liste* liste)
{

    if (table == NULL || liste == NULL | liste->premier == NULL)
    {
        printf("\nError: Empty or non-existing Table Hache or Liste!\n");
        exit(EXIT_FAILURE);
    }
    
    int tailleliste = compterElementListe(liste);

    if (tailleliste > tailletable)
    {
        printf("\nError: incompatible lenght Table Hache < Liste Element!\n");
        exit(EXIT_FAILURE);
    }

    Element* courrant = liste->premier;

    for (int i = 0; i < tailleliste; i++)
    {
        ELEMENT_TYPE elem_val = courrant->data;
        char clef[] = CHEMIN_CLEF(elem_val);
        char clefsec[] = CHEMIN_CLEF_B(elem_val);
        Hache nouveau = innitialiserHache(elem_val);
        nouveau.hache = coderMotNombreDouble(clef,clefsec,tailletable,nouveau.essaie);

        while (table[nouveau.hache].hache != -1)
        {
            nouveau.essaie++;
            nouveau.hache = coderMotNombreDouble(clef,clefsec,tailletable,nouveau.essaie);
        }
        table[nouveau.hache] = nouveau;
        courrant = courrant->prochain;
    }
    
}

void statistiques(Hache table[],int taille,Liste* objet,char typeobjet[],char clef[],char fileobjet[],char typehache[])
{
    if (table == NULL)
    {
        printf("\nError: statistiques on empty tables!\n");
        exit(EXIT_FAILURE);
    }

    int collision = 0;

    for (int i = 0; i < taille; i++)
    {
        collision = collision + table[i].essaie;
    }

    int nbrobjet = compterElementListe(objet); 
    int completion = (int)((nbrobjet/taille)*100);

    FILE* log = fopen("statistique.log","a+");

    fprintf(log,"\nStats: Hach %s",*typehache);
    fprintf(log,"\nType d'objet: %s;    Clef de hache: %s;\n    Nombre d'objet: %d;    Origine des objets: %s;",*typeobjet,*clef,nbrobjet,*fileobjet);
    fprintf(log,"\nTaile de la table: %d;   Completion de la table: %d",taille,completion);
    fprintf(log,"\nNombre de collision: %d;",collision);
    fprintf(log,"\n--------------------------------------------------------------------------------------------");
    fclose(log);
    
}

#endif//HACHAGE_C