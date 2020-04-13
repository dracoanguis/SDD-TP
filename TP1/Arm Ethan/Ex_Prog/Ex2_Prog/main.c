#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"

unsigned char decisionMenuPrincipal = 0;

Vol volPrevu[50];
Equipage personnel[50];

const Equipage equipageDefault = {"","","","",""};

void initialisationVolPrevu()
{
    for (unsigned char i = 0; i < 50; i++)
    {
        strcpy(volPrevu[i].date,"");
        strcpy(volPrevu[i].depart,"");
        strcpy(volPrevu[i].arriver,"");
        volPrevu[i].numeroEquipe = 49;
    }
}

void initialisationPersonnel()
{
    for (unsigned char i = 0; i < 50; i++)
    {
        personnel[i] = equipageDefault;
    }
}

unsigned char remplissagePersonnel()
{
    unsigned char place = 0;
    while ((strcmp((personnel[place].capitaine),"")))
    {
        place ++;
    }
    return place;
}

void ajoutEquipage()
{
    unsigned char place = remplissagePersonnel();
    printf("Entrer les informations de l'equipage:\n");
        printf("Qui est le capitaine ?\n");
        do
        {
            fgets(personnel[place].capitaine,50,stdin);
            personnel[place].capitaine[strlen(personnel[place].capitaine)-1] = '\0';
            if (!(strcmp(personnel[place].capitaine,"")))
            {
                printf("Le capitaine ne peut etre vide. Veuillez rentrer.\n");
            }
        } while (!(strcmp(personnel[place].capitaine,"")));

        printf("Qui est le copilote ?\n");
        do
        {
            fgets(personnel[place].copilote,50,stdin);
            personnel[place].copilote[strlen(personnel[place].copilote)-1] = '\0';
            if (!(strcmp(personnel[place].copilote,"")))
            {
                printf("Le copilote ne peut etre vide. Veuillez rentrer.\n");
            }
        } while (!(strcmp(personnel[place].copilote,"")));

}

void afficherPersonnel()
{
    printf("--------------------------------Debut Liste------------------------------\n");
    for (unsigned char i = 0; i < 50 ; i++)
    {
        if (verificateurDispEmplacement(i,0))
        {
            printf("---------------------------------------------------\n");
            printf("Equipage numero %d :\n",(i+1));
            printf("    - Capitaine: %s\n",personnel[i].capitaine);
            printf("    - Copilote: %s\n",personnel[i].copilote);
            printf("    - Premier Steward: %s\n",personnel[i].stewardUn);
            printf("    - Deuxieme Steward: %s\n",personnel[i].stewardDeux);
            printf("    - Appareil: %s\n\n",personnel[i].avion);
        }
    }
    printf("--------------------------------Fin Liste------------------------------\n");
    
}

void afficherEquipage(Equipage *equipageDonnee)
{
    printf("---------------------------------------------------\n");
        printf("Equipage:\n");
        printf("    - Capitaine: %s\n",equipageDonnee->capitaine);
        printf("    - Copilote: %s\n",equipageDonnee->copilote);
        printf("    - Premier Steward: %s\n",equipageDonnee->stewardUn);
        printf("    - Deuxieme Steward: %s\n",equipageDonnee->stewardDeux);
        printf("    - Appareil: %s\n",equipageDonnee->avion);
}

void supprimerEquipage(Equipage *equipageDonnee)
{
    *equipageDonnee = equipageDefault;
}

void modifierEquipage(Equipage *equipageDonnee)
{
    afficherEquipage(equipageDonnee);
     printf("Entrer les informations de l'equipage:\n");
        printf("Qui est le capitaine ?\n");
        do
        {
            fgets(equipageDonnee->capitaine,50,stdin);
            equipageDonnee->capitaine[strlen(equipageDonnee->capitaine)-1] = '\0';
            if (!(strcmp(equipageDonnee->capitaine,"")))
            {
                printf("Le capitaine ne peut etre vide. Veuillez rentrer.\n");
            }
        } while (!(strcmp(equipageDonnee->capitaine,"")));

        printf("Qui est le copilote ?\n");
        do
        {
            fgets(equipageDonnee->copilote,50,stdin);
           equipageDonnee->copilote[strlen(equipageDonnee->copilote)-1] = '\0';
            if (!(strcmp(equipageDonnee->copilote,"")))
            {
                printf("Le copilote ne peut etre vide. Veuillez rentrer.\n");
            }
        } while (!(strcmp(equipageDonnee->copilote,"")));

        printf("Qui est le premier Steward ?\n");
        fgets(equipageDonnee->stewardUn,50,stdin);
        equipageDonnee->stewardUn[strlen(equipageDonnee->stewardUn)-1] = '\0';

        printf("Qui est le deuxieme Steward ?\n");
        fgets(equipageDonnee->stewardDeux,50,stdin);
        equipageDonnee->stewardDeux[strlen(equipageDonnee->stewardDeux)-1] = '\0';

        printf("Quel est l'avion ?\n");
        fgets(equipageDonnee->avion,50,stdin);
        equipageDonnee->avion[strlen(equipageDonnee->avion)-1] = '\0';
}

unsigned char remplissageVolPrevu()
{
    unsigned char place = 0;
    while ((strcmp((volPrevu[place].date),"")))
    {
        place ++;
    }
    return place;
}

void ajoutVol()
{
    unsigned char place = remplissageVolPrevu();
    printf("Entrer les informations de Vol:\n");
        printf("Quelle est la date de Vol ?\n");
        do
        {
            fgets(volPrevu[place].date,20,stdin);
            volPrevu[place].date[strlen(volPrevu[place].date)-1] = '\0';
            if (!(strcmp(volPrevu[place].date,"")))
            {
                printf("La date ne peut etre vide. Veuillez rentrer.\n");
            }
        } while (!(strcmp(volPrevu[place].date,"")));

        printf("Quel est le point de depart ?\n");
        do
        {
            fgets(volPrevu[place].depart,50,stdin);
            volPrevu[place].depart[strlen(volPrevu[place].depart)-1] = '\0';
            if (!(strcmp(volPrevu[place].depart,"")))
            {
                printf("Le point de depart ne peut etre vide. Veuillez rentrer.\n");
            }
        } while (!(strcmp(volPrevu[place].depart,"")));

        printf("Quel est le point d'arriver ?\n");
        do
        {
            fgets(volPrevu[place].arriver,50,stdin);
            volPrevu[place].arriver[strlen(volPrevu[place].arriver)-1] = '\0';
            if (!(strcmp(volPrevu[place].depart,"")))
            {
                printf("Le point d'arriver ne peut etre vide. Veuillez rentrer.\n");
            }
        } while (!(strcmp(volPrevu[place].arriver,"")));
}

void afficherVolPrevu()
{
    printf("--------------------------------Debut Liste------------------------------\n");
    for (unsigned char i = 0; i < 50 ; i++)
    {
        if (verificateurDispEmplacement(i,1))
        {
            printf("---------------------------------------------------\n");
            printf("Vol numero %d :\n",(i+1));
            printf("    - Date: %s\n",volPrevu[i].date);
            printf("    - Point de Depart: %s\n",volPrevu[i].depart);
            printf("    - Point d'Arriver: %s\n",volPrevu[i].arriver);
            afficherEquipage(&(personnel[volPrevu[i].numeroEquipe]));
        }
    }
    printf("--------------------------------Fin Liste------------------------------\n");
}

void afficherVol(Vol *volDonnee)
{
    printf("---------------------------------------------------\n");
        printf("Vol:\n");
        printf("    - Date: %s\n",volDonnee->date);
        printf("    - Point de Depart: %s\n",volDonnee->depart);
        printf("    - Point d'Arriver: %s\n",volDonnee->arriver);
        afficherEquipage(&(personnel[volDonnee->numeroEquipe]));
}

void modifierVol(Vol *volDonnee)
{
    printf("Entrer les informations de Vol:\n");
        printf("Quelle est la date de Vol ?\n");
        do
        {
            fgets(volDonnee->date,20,stdin);
            volDonnee->date[strlen(volDonnee->date)-1] = '\0';
            if (!(strcmp(volDonnee->date,"")))
            {
                printf("La date ne peut etre vide. Veuillez rentrer.\n");
            }
        } while (!(strcmp(volDonnee->date,"")));

        printf("Quel est le point de depart ?\n");
        do
        {
            fgets(volDonnee->depart,50,stdin);
            volDonnee->depart[strlen(volDonnee->depart)-1] = '\0';
            if (!(strcmp(volDonnee->depart,"")))
            {
                printf("Le point de depart ne peut etre vide. Veuillez rentrer.\n");
            }
        } while (!(strcmp(volDonnee->depart,"")));

        printf("Quel est le point d'arriver ?\n");
        do
        {
            fgets(volDonnee->arriver,50,stdin);
            volDonnee->arriver[strlen(volDonnee->arriver)-1] = '\0';
            if (!(strcmp(volDonnee->depart,"")))
            {
                printf("Le point d'arriver ne peut etre vide. Veuillez rentrer.\n");
            }
        } while (!(strcmp(volDonnee->arriver,"")));

        printf("Quel est le numero de l'equipage ?\n");
        scanf("%d",&(volDonnee->numeroEquipe));
        volDonnee->numeroEquipe -- ;
}

void supprimerVol(Vol *volDonnee)
{
    strcpy(volDonnee->date,"");
    strcpy(volDonnee->depart,"");
    strcpy(volDonnee->arriver,"");
    volDonnee->numeroEquipe = 49;
}

unsigned char selectionEmplacement(unsigned char mode)//mode: 0 -> verifie Equipage, 1 verifie vol
{
    unsigned char emplacement = 0;
    printf("Quelle est l'emplacement ?\n");
    do
        {
            scanf("%d",&emplacement);
            if (verificateurDispEmplacement(emplacement,mode))
            {
                printf("L'emplacement n'est pas valide veuiller le reentrer!\n");
            }
        } while (verificateurDispEmplacement(emplacement,mode));
}

//mode: 0 -> verifie Equipage, 1 verifie vol
int verificateurDispEmplacement(unsigned char emplacementDonnee,unsigned char mode)//return:0 -> emplacement valide(objet absente), 1 -> emplacement invalide(objet presente) cause: arret de boucle quand juste
{
    if (mode)
    {
        if (emplacementDonnee>=0)//Les doubles conditions ne fonctionne pas avec && ne fonctionne -> condition imbriqué
        {
            if (emplacementDonnee<50)
            {
                if (strcmp(volPrevu[emplacementDonnee].date,""))
                {
                    return 1;
                } else {return 0;}
            }else
            {
                return 1;
            }
            
        } else {return 1;}
    } else
    {
        if (emplacementDonnee>=0)
        {
            if (emplacementDonnee<50)
            {
                if (strcmp(personnel[emplacementDonnee].capitaine,""))
                {
                    return 1;
                } else {return 0;}
            }else
            {
                return 1;
            }
            
        } else {return 1;}
    }
    
}

void menuPrincipal()
{
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("Que voulez-vous faire ? (Indiquer un chiffre et presser enter pour valider votre choix.)\n");
    printf("1.Ajouter un Equipage.\n");
    printf("2.Modifier un Equipage.\n");
    printf("3.Afficher les informations d'un Equipage.\n");
    printf("4.Supprimer un Equipage.\n");
    printf("5.Afficher la liste des Equipages.\n");
    printf("6.Ajouter un Vol\n");
    printf("7.Modifier un Vol\n");
    printf("8.Supprimer un Vol\n");
    printf("9.Afficher un Vol\n");
    printf("10.Afficher la liste des Vols\n");
    printf("11.Quitter\n");
    scanf("%d",&decisionMenuPrincipal);

    unsigned char emplacement;

    switch (decisionMenuPrincipal)
    {
    case 1:
        ajoutEquipage();
        break;
    
    case 2:
        emplacement = selectionEmplacement(0);
        modifierEquipage(&(personnel[emplacement]));
        break;
    
    case 3:
        emplacement =   selectionEmplacement(0);
        afficherEquipage(&(personnel[emplacement]));
        break;
    
    case 4:
        emplacement = selectionEmplacement(0);
        supprimerEquipage(&(personnel[emplacement]));
        break;
    
    case 5:
        afficherPersonnel();
        break;

    case 6:
        ajoutVol();
        break;
    
    case 7:
        selectionEmplacement(1);
        modifierVol(&(volPrevu[emplacement]));
        break;
    
    case 8:
        emplacement = selectionEmplacement(1);
        supprimerVol(&(volPrevu[emplacement]));
        break;
    
    case 9:
        emplacement = selectionEmplacement(1);
        afficherVol(&(volPrevu[emplacement]));
        break;
    
    case 10:
        afficherVolPrevu();
        break;
    
    case 11:
        break;
    
    default:
        printf("Je n'ai pas compris votre choix, veuillez le ressaisir!\n");
        scanf("%d",&decisionMenuPrincipal);
        break;
    }

}

int main() {
    initialisationPersonnel();
    initialisationVolPrevu();
    do
    {
        menuPrincipal();
        system("PAUSE");
    } while (decisionMenuPrincipal != 11);
    
    return 0;
}