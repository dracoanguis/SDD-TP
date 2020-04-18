#ifndef GRAPH_C
#define GRAPH_C
#include <string.h>
#include "graph.h"
#include "liste.c"
#define memoryTest(pointeur) if (pointeur == NULL){printf("\nMemory allocation Failure !\n");exit(EXIT_FAILURE);}
#define nomSom(Sommet) Sommet->aeroport->iata
#define nomSuc(Successeur) Successeur->nomSom(sommet_representer)
#define coutSuc(Successeur) Successeur->cout
#define True 1
#define False 0

//Aeroports:

Aeroport* initialiserAeroport(char iata[4],char ville[50],char pays[50])
{
    Aeroport *nouveau = malloc(sizeof(Aeroport));
    memoryTest(nouveau);

    strcpy(nouveau->iata, iata);
    strcpy(nouveau->ville,ville);
    strcpy(nouveau->pays, pays);

    return nouveau;
}

void afficherAeroport(Aeroport* aeroport)
{
    if (aeroport == NULL)
    {
        printf("\nError: Trying to print an non-existant Aeroport !\n");
        exit(EXIT_FAILURE);
    }

    printf("\n");
    printf("Code Iata: %s\n",aeroport->iata);
    printf("Ville: %s\n",aeroport->ville);
    printf("Pays: %s\n",aeroport->pays);
}

void afficherListe_Aeroport(Liste* liste)
{
    if (liste == NULL || liste->premier == NULL)
    {
        printf("\nError: Trying to print a non-existant or empty Liste_Aeroport !\n");
        exit(EXIT_FAILURE);
    }

    Element* courrant = liste->premier;

    while (courrant != NULL)
    {
        afficherAeroport(courrant->data);
        courrant = courrant->prochain;
    }
}

//Sommet:

Sommet* initialiserSommet(Aeroport* aeroport,Liste* successeurs)
{
    if (aeroport == NULL)
    {
        printf("\nError: Assigning a NULL Aeroport to Sommet !\n");
        exit(EXIT_FAILURE);
    }

    Sommet* nouveau = malloc(sizeof(Sommet));
    memoryTest(nouveau);

    nouveau->aeroport = aeroport;
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

    printf("\nSommet %s:",nomSom(sommet));
    afficherAeroport(sommet->aeroport);
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

    while (courrant != NULL && strstr(nom,nomSom(som_courrant)) == NULL)
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
    printf("Sommet representer: %s\n",nomSuc(successeur));
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

Liste* lectureSommets(const char *faeroport)
{
    Liste* sommets = initialiserListe();
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
        ajouterElementListe(sommets,(initialiserSommet(initialiserAeroport(iata,ville,pays),NULL)));
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