#include <stdlib.h>
#include <stdio.h>
#include "personne.c"
#define ELEMENT_TYPE Personne*
#define CHEMIN_CLEF(objet) objet->prenom
#define CHEMIN_CLEF_B(objet) objet->nom
#include "hachage.c"

int main(int argc, char const *argv[])
{
    Hache table[100000];
    const int taille = 100000;
    remplissageTableHacheVide(table,taille);
    printf("\nCreation d'une table de Hache vide de taille: %d",taille);
    char fichier[] = "TP5.passagers-100000.txt";
    printf("\nCreation d'une Liste de Personnes a partir de %s",fichier);
    Liste* personnes = listerPersonne(fichier);
    printf("\nRemplissage de la table avec des Hache Linear");
    remplissageTableHacheLinear(table,taille,personnes);
    printf("\nEcriture des statistiques");
    statistiques(table,taille,personnes,"Personne","Prenom",fichier,"Linear");
    printf("\nStatiques update, voir \"Statistique.log\"");
    printf("\nVidage de table");
    remplissageTableHacheVide(table,taille);
    printf("\nRemplissage de la table avec des Hache Quadratique");
    remplissageTableHacheQuadratique(table,taille,personnes);
    printf("\nEcriture des statistiques");
    statistiques(table,taille,personnes,"Personne","Prenom",fichier,"Quadratique");
    printf("\nStatiques update, voir \"Statistique.log\"");
    printf("\nVidage de table");
    remplissageTableHacheVide(table,taille);
    printf("\nRemplissage de la table avec des Hache Double");
    remplissageTableHacheDouble(table,taille,personnes);
    printf("\nEcriture des statistiques");
    statistiques(table,taille,personnes,"Personne","Prenom puis Nom",fichier,"Double");
    printf("\nStatiques update, voir \"Statistique.log\"");
    printf("\nFin");
    return 0;
}
