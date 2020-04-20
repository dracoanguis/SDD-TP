#ifndef GRAPH_C
#define GRAPH_C
#include <string.h>
#include "graph.h"
#include "liste.c"
/*
#define VARIABLE_SOMMET_DEF a ajouté et remplacé par les def des variables utiliser dans la lecture de doc
#define FORME_SOMMET a ajouté et remplacé par la forme "..." du sommet correspondant aux variables
#define VARIABLE_SOMMET_USE a ajouté et remplacé par les nom de var utiliser dans fichier sommet
#define INNITIALISER_DATA a ajouté dans le fichier d'utilisation et remplacer par la fonction d'initialisation de data.
#define AFFICHER_DATA a ajouté dans le fichier d'utilisation et remplacer par la fonction d'affichage de data.
*/

#define memoryTest(pointeur) if (pointeur == NULL){printf("\nMemory allocation Failure !\n");exit(EXIT_FAILURE);}
#define nomSuc(Successeur) Successeur->sommet_representer->nom
#define coutSuc(Successeur) Successeur->cout
#define True 1
#define False 0


//Sommet:

Sommet* initialiserSommet(void* data,Liste* successeurs,char* nom)
{
    if (data == NULL)
    {
        printf("\nError: Assigning a NULL Data to Sommet !\n");
        exit(EXIT_FAILURE);
    }
    Sommet* nouveau = malloc(sizeof(Sommet));
    char* nvnom = (char*)(malloc(sizeof(char)*strlen(nom)));
    memoryTest(nouveau);
    memoryTest(nvnom);

    strcpy(nvnom,nom);
    nouveau->nom = nvnom;
    nouveau->data = data;
    nouveau->liaisons = successeurs;
    nouveau->marque = 0;

    return nouveau;
}

void afficherSommet(Sommet* sommet)
{
    if (sommet == NULL)
    {
        printf("\nError: Trying to print a non-existant Sommet !\n");
        exit(EXIT_FAILURE);
    }

    printf("\nSommet %s:",sommet->nom);
    AFFICHER_DATA(sommet->data);
    afficherListe_Successeur(sommet->liaisons);
    if (sommet->marque)
    {
        printf("\nSommet visite");
    }
    else
    {
        printf("\nSommet non-visite");
    }
    printf("\n");
    printf("-----Fin-----\n");
}

Sommet* chercherSommet_Successeur(Liste* liste_sommet,char* nom)
{
    if (liste_sommet == NULL || liste_sommet->premier == NULL)
    {
        printf("\nError: non-existing or empty search list !\n");
        exit(EXIT_FAILURE);
    }

    Element* courrant = liste_sommet->premier;
    Sommet* som_courrant = courrant->data;

    while (courrant != NULL && strstr(nom,(som_courrant->nom)) == NULL)
    {
        courrant = courrant->prochain;
        if (courrant != NULL){som_courrant = courrant->data;}
    }

    if (courrant == NULL)
    {
        printf("\nError: Can't find Sommet \"%s\" in list !\n",nom);
        exit(EXIT_FAILURE);
    }
    
    return courrant->data;
}

void afficherListe_Sommet(Liste* liste)
{
    if (liste == NULL || liste->premier == NULL)
    {
        printf("\nError: Trying to print a non-existant or empty Liste of Sommet !\n");
        exit(EXIT_FAILURE);
    }

    Element* courrant = liste->premier;
    Sommet* som_courrant = courrant->data;

    printf("\nListe Sommet:");
    while (courrant != NULL)
    {
        afficherSommet(som_courrant);
        courrant = courrant->prochain;
        if (courrant != NULL){som_courrant = courrant->data;}
    }
    printf("\n------------------Fin Sommet----------------\n");

}

//Successeur:

Successeur* initialiserSuccesseur(Sommet* sommet, int cout)
{
    if (sommet == NULL)
    {
        printf("\nError: Assigning a NULL Sommet to Successeur !\n");
        exit(EXIT_FAILURE);
    }

    Successeur* nouveau = malloc(sizeof(Successeur));
    memoryTest(nouveau);

    nouveau->sommet_representer = sommet;
    nouveau->cout = cout;

    return nouveau;
}    

void afficherSuccesseur(Successeur* successeur)
{
    if (successeur == NULL)
    {
        printf("\nError: Trying to print a non-existing Successeur !\n");
        exit(EXIT_FAILURE);
    }

    printf("\n");
    printf("Sommet representer: %s\n",successeur->sommet_representer->nom);
    printf("Cout du deplacement: %d\n",coutSuc(successeur));
}

Successeur* lectureBlocSuccesseur(char bloc[], Liste* liste_sommet)
{
    char* nom = NULL;
    char* cout = NULL;
    Successeur* retour = NULL;
    int icout = 1;//Valeur par défaut d'un déplacement.

    nom = strtok(bloc,"."); 
    cout = strtok(NULL,".");

    if (cout != NULL)
    {
        icout = ((int)strtol((cout + sizeof(char)),NULL,10));
    }

    retour = initialiserSuccesseur(chercherSommet_Successeur(liste_sommet,nom),icout);

    if (retour == NULL)
    {
        printf("\nError: Can't initiate Successeur from bloc !\n");
        exit(EXIT_FAILURE);
    }
    
    return retour;
}

Liste* lectureLigneSuccesseur(char ligne[], Liste* liste_sommet)
{
    Liste* successeurs = initialiserListe();

    if (strlen(ligne) == 0)
    {
        return NULL;
    }
    
    char * line = (char *)(malloc(strlen(ligne)));
    char * base = (char *)(malloc(strlen(ligne)));
    strcpy(line,ligne);
    strcpy(base,ligne);
    line = strtok(line," ");
    ajouterElementListe(successeurs,lectureBlocSuccesseur(line,liste_sommet));
    while (line != NULL)
    {
        strcpy(line,(base + (1 + strlen(line))*sizeof(char)));
        line = strtok(line," ");
        if (strchr(base,' ') == NULL)
        {
            return successeurs;
        }
        strcpy(base,(base + (1 + strlen(line))*sizeof(char)));
        ajouterElementListe(successeurs,lectureBlocSuccesseur(line,liste_sommet));
    }
}

void afficherListe_Successeur(Liste* liste)
{
    if (liste == NULL || liste->premier == NULL)
    {
        printf("\nError: Trying to print an non-existing or empty Liste !\n");
        exit(EXIT_FAILURE);
    }

    Element* courrant = liste->premier;

    printf("\nSuccesseurs: ");
    while (courrant != NULL)
    {
        afficherSuccesseur(courrant->data);
        courrant = courrant->prochain;
    }
    printf("--Fin Successeurs------\n");
}


//Autre:

Liste* lectureSommets(const char *fsommet)
{
    Liste* sommets = initialiserListe();
    VARIABLE_SOMMET_DEF
    FILE* file = NULL;
    file = fopen(fsommet,"r+");
    if (file == NULL)
    {
        printf("\nError: Invalid file!!!\n");
        exit(EXIT_FAILURE);
    }
    while (fscanf(file,FORME_SOMMET,VARIABLE_SOMMET_USE) != EOF)
    {
        ajouterElementListe(sommets,(initialiserSommet(INNITIALISER_DATA,NULL,CODE_SOMMET)));
    }
    fclose(file);
    return sommets;
}

Liste* lectureAeroports(const char* faeroport)
{
    Liste* aeroports = initialiserListe();
    char iata[4];
    char ville[50];
    char pays[50];
    FILE* file = NULL;
    file = fopen(faeroport,"r+");
    if (file == NULL)
    {
        printf("\nError: Invalid file!!!\n");
        exit(EXIT_FAILURE);
    }
    while (fscanf(file,"%4s %50s %50s",iata,ville,pays) != EOF)
    {
        ajouterElementListe(aeroports,initialiserAeroport(iata,ville,pays));
    }
    fclose(file);
    return aeroports;
}

void lectureSuccesseurs(const char* fsuccesseur, Liste* liste_sommet)
{
    if (liste_sommet == NULL || liste_sommet->premier == NULL)
    {
        printf("\nError: non-existing or empty Sommet list !\n");
        exit(EXIT_FAILURE);
    }

    Element* courrant = liste_sommet->premier;
    Sommet* som_courrant = courrant->data;
    int count = 0;
    char* ligne;
    if (ligne == NULL) {ligne++;}
    FILE* file = NULL;
    file = fopen(fsuccesseur,"r+");

    if (file == NULL)
    {
        printf("\nError: Invalid file!!!\n");
        exit(EXIT_FAILURE);
    }

    while (courrant != NULL)
    {
        ligne = readline(file);
        som_courrant->liaisons = lectureLigneSuccesseur(ligne,liste_sommet);
        courrant = courrant->prochain;
        if (courrant == NULL) {break;}
        som_courrant = courrant->data;
    }  
    fclose(file);
}

char* readline(FILE* file)
{
    int count = 1;
    char x = fgetc(file);
    while (x != '\n' && x != EOF)
    {
        count ++;
        x=fgetc(file);  
    }
    char* ligne = (char*)(malloc(count*(sizeof(char))));
    fseek(file, (- count -1),SEEK_CUR);
    if (x == EOF) {fseek(file,2,SEEK_CUR);}
    for (int i = 0; i < (count); i++)
    {
        *(ligne + i*(sizeof(char))) = fgetc(file);
    }
    *(ligne + (count -1)*(sizeof(char))) = '\0';
    return ligne;
}

#endif // !GRAPH_C