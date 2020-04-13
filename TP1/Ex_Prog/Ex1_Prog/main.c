#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"

const Personne defaultPersonne = {"","","",""};
Voiture defaultVoiture = {"","","",0,0,""};
Voiture parking[200];
unsigned int decisionMenuPrincipal = 0;//Definie sur l'ensemble du fichier pas la meilleur solution mais plus facile que changer toute l'implementation du menu evite la boucle infinie definitive
Personne repertoire[200];
unsigned int decisionMenuModification = 0;

int main()
{
    initialisationRepertoire();
    initialisationParking();
    
    /*//Exemple: DEcommenter pour activer.
    strcpy((&(repertoire[1]))->nom,"Son");
    strcpy((&(repertoire[1]))->prenom,"Goku");
    strcpy((&(repertoire[1]))->addresse,"ile tortue");
    strcpy((&(repertoire[1]))->telephone,"000000000");
    strcpy((&(parking[1]))->immatriculation,"none");
    strcpy((&(parking[1]))->marque,"Nuage Volant");
    strcpy((&(parking[1]))->modele,"Jaune");
    strcpy((&(parking[1]))->etat,"vaguement endommage");
    (&(parking[1]))->repare = 0;
    strcpy((&(repertoire[2]))->nom,"inconnue");
    strcpy((&(repertoire[2]))->prenom,"Link");
    strcpy((&(repertoire[2]))->addresse,"chateau d'Hyrul");
    strcpy((&(repertoire[2]))->telephone,"0123456789");
    strcpy((&(parking[2]))->immatriculation,"none");
    strcpy((&(parking[2]))->marque,"Cheval");
    strcpy((&(parking[2]))->modele,"Epona");
    strcpy((&(parking[2]))->etat,"vaguement blesse");
    (&(parking[2]))->repare = 0;*/

    do
    {
        menuPrincipal();
        system("PAUSE");
    } while (decisionMenuPrincipal != 6);
    
    return 0;
}

void initialisationRepertoire()
{
    for (unsigned int i = 0; i < (200); i++)
    {
        repertoire[i] = defaultPersonne;
    }
}

void initialisationParking() //Met toute les voiture a défaut
{
    for (unsigned int i = 0; i < (200); i++)
    {
        strcpy(parking[i].marque,"");
        strcpy(parking[i].modele, "");
        strcpy(parking[i].etat,"");
        parking[i].repare = 0;
        strcpy(parking[i].immatriculation,"");
        parking[i].emplacement = i;
    }
    
}

void menuPrincipal()
{
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("Que voulez-vous faire ? (Indiquer un chiffre et presser enter pour valider votre choix.)\n");
    printf("1.Ajouter une Voiture.\n");
    printf("2.Modifier les informations d'une Voiture.\n");
    printf("3.Afficher les informations d'une voiture.\n");
    printf("4.Supprimer une voiture.\n");
    printf("5.Afficher la liste des voitures presentes.\n");
    printf("6.Quitter\n");
    scanf("%d",&decisionMenuPrincipal);

    Voiture *voitureDonnee = &defaultVoiture;
    char marqueDonnee[20];
    char modeleDonnee[20];
    switch (decisionMenuPrincipal)
    {
    case 1:
        printf("Entrer les informations de la voiture:\n");
        voitureDonnee = selecteurVoiture(0);
        printf("Quelle est la marque ?\n");
        do
        {
            fgets(marqueDonnee,20,stdin);
            marqueDonnee[strlen(marqueDonnee)-1] = '\0';
            if (!(strcmp(marqueDonnee,"")))
            {
                printf("La marque ne peut etre vide. Veuillez rentrer.\n");
            }
        } while (!(strcmp(marqueDonnee,"")));
        printf("Quelle est le modele ?\n");
        do
        {
            fgets(modeleDonnee,20,stdin);
            modeleDonnee[strlen(modeleDonnee)-1] = '\0';
            if (!(strcmp(modeleDonnee,"")))
            {
                printf("Le modele ne peut etre vide. Veuillez reentrer.\n");
            }
        } while (!(strcmp(modeleDonnee,"")));
        printf("%s\n",marqueDonnee);
        printf("%s\n",modeleDonnee);
        printf("\n");
        ajoutDeVoiture(voitureDonnee,marqueDonnee,modeleDonnee);//Ne créée pas la voiture ici mais marche ailleur
        afficherVoiture(voitureDonnee);
        break;
    
    case 2:
        voitureDonnee = selecteurVoiture(1);
        do
        {
            menuModificationVoiture(voitureDonnee);
            system("PAUSE");
        } while (decisionMenuModification != 8);
        break;
    
    case 3:
        voitureDonnee = selecteurVoiture(1);
        afficherVoiture(voitureDonnee);
        break;
    
    case 4:
        voitureDonnee = selecteurVoiture(1);
        supprimerVoiture(voitureDonnee);
        printf("Voiture supprimer!\n");
        break;
    
    case 5:
        afficherParking();
        break;

    case 6:
        break;

    default:
        printf("Je n'ai pas compris votre choix, veuillez le ressaisir!\n");
        scanf("%d",&decisionMenuPrincipal);
        break;
    }
}

void menuModificationVoiture(Voiture *voitureDonnee)
{
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("Que voulez-vous modifier ? (Indiquer un chiffre et presser enter pour valider votre choix.)\n");
    printf("1.Immatriculation.\n");
    printf("2.Marque\n");
    printf("3.Modele\n");
    printf("4.Statut\n");
    printf("5.Emplacement\n");
    printf("6.Commentaire\n");
    printf("7.Proprietaire\n");
    printf("8.Retour au menu principal.\n");
    scanf("%d",&decisionMenuModification);

    switch (decisionMenuModification)
    {
    case 1:
        changerImmatriculation(voitureDonnee);
        break;
    
    case 2:
        changerMarque(voitureDonnee);
        break;
    
    case 3:
        changerModele(voitureDonnee);
        break;
    
    case 4:
        changerRepare(voitureDonnee);
        break;
    
    case 5:
        changerEmplacement(voitureDonnee);
        decisionMenuModification = 8;
        break;
    
    case 6:
        changerEtat(voitureDonnee);
        break;
    
    case 7:
        modifierPersonne((&(repertoire[voitureDonnee->emplacement])));
        break;

    case 8:
        break;

    default:
        printf("Je n'ai pas compris votre choix, veuillez le ressaisir!\n");
        scanf("%d",&decisionMenuModification);
        break;
    };
}

Voiture* selecteurVoiture(int mode)// mode = 0: normale -> verifie libre mode = 1: inverse verifie occupé
{
    unsigned int emplacement = 0;
    printf("Quelle est l'emplacement ?\n");
    if (!(mode))
    {
        do
        {
            scanf("%d",&emplacement);
            if (verificateurDispEmplacement(emplacement))
            {
                printf("L'emplacement n'est pas valide veuiller le reentrer!\n");
            }
        } while (verificateurDispEmplacement(emplacement));
    } else
    {
        do
        {
            scanf("%d",&emplacement);
            if (!(verificateurDispEmplacement(emplacement)))
            {
                printf("L'emplacement n'est pas valide veuiller le reentrer! Entrer 0 pour annuler l'operation.\n");
                if (emplacement == 0)
                {
                    return &(parking[0]);
                }
            }
        } while (!(verificateurDispEmplacement(emplacement)));
    }
    return &(parking[emplacement]);
}

int verificateurDispEmplacement(unsigned int emplacementDonnee)//return:0 -> emplacement valide(voiture absente), 1 -> emplacement invalide(voiture presente) cause: arret de boucle quand juste
{
    if (emplacementDonnee>0)//Les doubles conditions ne fonctionne pas avec && ne fonctionne -> condition imbriqué
    {
        if (emplacementDonnee<201)
        {
            if (strcmp(parking[emplacementDonnee].marque,""))
            {
                return 1;
            } else {return 0;}
        }else
        {
            return 1;
        }
        
    } else {return 1;}
}

void afficherVoiture(Voiture *voitureDonnee)
{
    if ((verificateurDispEmplacement(voitureDonnee->emplacement)))
    {
        printf("--------------------------------------------------------------------------------------\n");
        printf("Voici les characteristiques de la voiture:\n");
        printf("Marque: %s\n",voitureDonnee->marque);
        printf("Modele : %s\n",voitureDonnee->modele);
        printf("Immatriculation : %s\n",voitureDonnee->immatriculation);
        afficherPersonne(&(repertoire[voitureDonnee->emplacement]));
        printf("Statut :");
        if (voitureDonnee->repare)
        {
            printf("Repare \n");
        } else {printf("Non-Repare \n");}
        printf("Emplacement: %d\n",voitureDonnee->emplacement);
        printf("Commentaires : %s\n",voitureDonnee->etat);
    } else
    {
        printf("Il s'agit d'un emplacement libre. \n");
    }
    
}

void ajoutDeVoiture(Voiture *voitureDonnee,char marqueDonnee[20],char modeleDonnee[20])
{
    strcpy(voitureDonnee->marque,marqueDonnee);
    strcpy(voitureDonnee->modele, modeleDonnee);
    strcpy(voitureDonnee->etat,"");
    voitureDonnee->repare = 0;
    strcpy(voitureDonnee->immatriculation,"");
    //Pas besoin de donner un emplacement car celui ci est défini par la place dans le tableau qui est vérifié au préalable par verificateurDipsEmplacement()
}

void ajoutDePersonne(Personne *personneDonnee,char nomDonnee[20],char prenomDonnee[20])
{
    strcpy(personneDonnee->nom,nomDonnee);
    strcpy(personneDonnee->prenom,prenomDonnee);
    strcpy(personneDonnee->addresse,"");
    strcpy(personneDonnee->telephone,"");
}

int demandeChoix()//return 1 si oui, 0 si non (bool)
{
    char choix[10];
    do
    {
        printf("\nVoulez-vous changer l'information ? oui/non\n");
        fgets(choix,10,stdin);
        choix[strlen(choix)-1] ='\0';
        if (!(strcmp(choix,"oui"))) {return strcmp(choix,"non");};
    } while (strcmp(choix,"non"));
    return strcmp(choix,"non"); 
}

void changerImmatriculation(Voiture *voitureDonnee)
{
    printf("L'immatriculation actuel est : %s\n", voitureDonnee->immatriculation);
    if (demandeChoix()) 
    {
        printf("Entre la nouvelle immatriculation :\n");
        fgets(voitureDonnee->immatriculation,30,stdin);
        voitureDonnee->immatriculation[strlen(voitureDonnee->immatriculation)-1] = '\0';
    }
    printf("Retour au menu.\n");

}

void changerRepare(Voiture *voitureDonnee)
{
    if (voitureDonnee->repare)
    {
        printf("La voiture a actuellement le statut: Repare\n");
    } else
    {
        printf("La voiture a actuellement le statut: Non Repare\n");
    }
    int choix = demandeChoix();
    if (choix && voitureDonnee->repare)
    {
        voitureDonnee->repare = 0;
    } else if (choix && voitureDonnee->repare != 1)
    {
        voitureDonnee->repare = 1;
    }
    printf("Retour au menu.\n");
}

void changerEtat(Voiture *voitureDonnee)
{
    printf("Le commentaire actuel est :\n%s\n",voitureDonnee->etat);
    if (demandeChoix())
    {
        printf("Entre le nouveau commentaire :\n");
        fgets(voitureDonnee->etat,300,stdin);
        voitureDonnee->etat[strlen(voitureDonnee->etat)-1] = '\0';
    }
    printf("Retour au menu.\n");
}

void changerMarque(Voiture *voitureDonnee)
{
    printf("La marque de la voiture actuel est : %s\n",voitureDonnee->marque);
    if (demandeChoix())
    {
        printf("Entrer la nouvelle marque:\n");
        do
        {
            fgets(voitureDonnee->marque,20,stdin);
            voitureDonnee->marque[strlen(voitureDonnee->marque)-1] ='\0';
            if (strcmp(voitureDonnee->marque,"") == 0)
            {
                printf("La marque ne peut etre vide. Veuillez reentrer.\n");
            }
        } while (strcmp(voitureDonnee->marque,"") == 0);
        
    }
    printf("Retour au menu.\n");
}

void changerModele(Voiture *voitureDonnee)
{
    printf("Le modele de la voiture actuel est : %s\n",voitureDonnee->modele);
    if (demandeChoix())
    {
        printf("Entrer le nouveau modele:\n");
        do
        {
            fgets(voitureDonnee->modele,20,stdin);
            voitureDonnee->modele[strlen(voitureDonnee->modele)-1] = '\0';
            if (strcmp(voitureDonnee->modele,"") == 0)
            {
                printf("Le modele ne peut etre vide. Veuillez reentrer.\n");
            }
        } while (strcmp(voitureDonnee->modele,"") == 0);
        
    }
    printf("Retour au menu.\n");
}

void afficherPersonne(Personne *personneDonnee)
{
    printf("Proprietaire:\n");
    printf("             - Nom: %s\n",personneDonnee->nom);
    printf("             - Prenom: %s\n",personneDonnee->prenom);
    printf("             - Adresse: %s\n",personneDonnee->addresse);
    printf("             - Telephone: %s\n",personneDonnee->telephone);

}

void supprimerVoiture(Voiture *voitureDonnee)
{
    strcpy(voitureDonnee->marque,"");
    strcpy(voitureDonnee->modele, "");
    strcpy(voitureDonnee->etat,"");
    voitureDonnee->repare = 0;
    strcpy(voitureDonnee->immatriculation,"");
    strcpy((&(repertoire[voitureDonnee->emplacement]))->nom,"");
    strcpy((&(repertoire[voitureDonnee->emplacement]))->prenom,"");
    strcpy((&(repertoire[voitureDonnee->emplacement]))->addresse,"");
    strcpy((&(repertoire[voitureDonnee->emplacement]))->telephone,"");
}

void supprimerPersonne(Personne *personneDonnee)
{
    strcpy(personneDonnee->nom,"");
    strcpy(personneDonnee->prenom,"");
    strcpy(personneDonnee->addresse,"");
    strcpy(personneDonnee->telephone,"");
}

void afficherParking()
{
    printf("-----------------------------Debut Liste------------------------------\n");
    for (unsigned int i = 1; i < (200); i++)
    {
        if(verificateurDispEmplacement(i))
        {
            afficherVoiture(&parking[i]);
        }
    }
    printf("-----------------------------Fin Liste--------------------------------\n");
    
}

void changerEmplacement(Voiture *voitureDonnee)
{
    Voiture* nouvelEmplacement;
    printf("L'emplacement actuel est: %d",voitureDonnee->emplacement);
    if (demandeChoix())
    {
        nouvelEmplacement = selecteurVoiture(0);
        strcpy(nouvelEmplacement->marque,voitureDonnee->marque);
        strcpy(nouvelEmplacement->modele, voitureDonnee->modele);
        strcpy(nouvelEmplacement->etat,voitureDonnee->etat);
        nouvelEmplacement->repare = voitureDonnee->repare;
        strcpy(nouvelEmplacement->immatriculation,voitureDonnee->immatriculation);

        strcpy((&(repertoire[(nouvelEmplacement->emplacement)]))->nom,(&(repertoire[(voitureDonnee->emplacement)]))->nom);
        strcpy((&(repertoire[(nouvelEmplacement->emplacement)]))->prenom,(&(repertoire[(voitureDonnee->emplacement)]))->prenom);
        strcpy((&(repertoire[(nouvelEmplacement->emplacement)]))->addresse,(&(repertoire[(voitureDonnee->emplacement)]))->addresse);
        strcpy((&(repertoire[(nouvelEmplacement->emplacement)]))->telephone,(&(repertoire[(voitureDonnee->emplacement)]))->telephone);

        supprimerVoiture(voitureDonnee);
        supprimerPersonne(&(repertoire[(voitureDonnee->emplacement)]));
        printf("La voiture a ete deplace a l'emplacement %d \n",nouvelEmplacement->emplacement);

    }
}

void modifierPersonne(Personne *personneDonnee)
{
    printf("Le nom de la personne actuel est : %s\n",personneDonnee->nom);
    if (demandeChoix())
    {
        printf("Entrer le nouveau nom:\n");
        do
        {
            fgets(personneDonnee->nom,20,stdin);
            personneDonnee->nom[strlen(personneDonnee->nom)-1] ='\0';
            if (strcmp(personneDonnee->nom,"") == 0)
            {
                printf("Le nom ne peut etre vide. Veuillez reentrer.\n");
            }
        } while (strcmp(personneDonnee->nom,"") == 0); 
    }
    printf("Le prenom de la personne actuel est : %s\n",personneDonnee->prenom);
    if (demandeChoix())
    {
        printf("Entrer le nouveau prenom:\n");
        do
        {
            fgets(personneDonnee->prenom,20,stdin);
            personneDonnee->prenom[strlen(personneDonnee->prenom)-1] = '\0';
            if (strcmp(personneDonnee->prenom,"") == 0)
            {
                printf("Le prenom ne peut etre vide. Veuillez reentrer.\n");
            }
        } while (strcmp(personneDonnee->prenom,"") == 0); 
    }
    printf("L'adresse actuel est :\n%s\n",personneDonnee->addresse);
    if (demandeChoix())
    {
        printf("Entre la nouvelle adresse :\n");
        fgets(personneDonnee->addresse,100,stdin);
        personneDonnee->addresse[strlen(personneDonnee->addresse)-1] ='\0';
    }
    printf("Le numero de telephone actuel est :\n%s\n",personneDonnee->telephone);
    if (demandeChoix())
    {
        printf("Entre le nouveau numero :\n");
        fgets(personneDonnee->telephone,15,stdin);
        personneDonnee->telephone[strlen(personneDonnee->telephone)-1] = '\0';
    }
}