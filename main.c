#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "queue.h"

int main(){
    int r = 1;
    while (r == 1)
    {
    int choix1;
    printf("*********  BIENVENUE DANS NOTRE PROGRAMME PORTANT SUR LES PILES ET FILES  *********\n\n");
    printf("=========  MENU PRINCIPAL  =========\n\n");
    printf("\t1 - Gestion d'une Pile\n");
    printf("\t2 - Gestion d'une File\n");
    printf("\t3 - Quitter le programme\n");
    printf("\tFaites votre choix : ");
    scanf("%d",&choix1);
    printf("\n");
    switch (choix1)
    {
        case 1:
        {
            printf("*******  BIENVENUE DANS LA GESTION D'UNE PILE  *******\n");
            printf("(Pile dont la taille est fixe a < 10 > elements)\n\n");
            Stack sta = new_stack();
            int choix;
            int r = 1;
            while (r == 1)
            {
                printf("Comment voulez-vous interagir avec votre pile :\n");
                printf("\t1 - Empiler\n");
                printf("\t2 - Depiler\n");
                printf("\t3 - Verifier si elle est vide\n");
                printf("\t4 - Verifiez si elle est pleine\n");
                printf("\t5 - Afficher le contenu de votre pile\n");
                printf("\tFaites votre choix : ");
                scanf("%d",&choix);
                printf("\n");
                switch (choix)
                {
                    case 1:
                    {
                        if (full_Stack(sta)){
                            printf("votre pile est pleine\n");
                        }
                        else{
                            int n;
                            printf("Combien d'entiers souhaitez-vous y ajouter : ");
                            scanf("%d",&n);
                            while (n>0)
                            {
                                int x;
                                printf("Entrer un entier : ");
                                scanf("%d",&x);
                                sta = Empiler(sta,x);
                                n--;
                            }
                        }
                    };break;
                    case 2: 
                    {
                        if(empty_Stack(sta))
                            printf("Aucun element a retirer de la pile\n");
                        else
                        {  
                            int n;
                            printf("Combien d'entiers souhaitez-vous retirer : ");
                            scanf("%d",&n);
                            while (n>0)
                            {
                                sta = Depiler(sta);  
                                n--; 
                            }
                        }    
                    };break;
                    case 3:
                    {
                        if(empty_Stack(sta))
                            printf("Oui, Votre pile est vide\n");
                        else
                            printf("Non, Votre pile contient des elements\n");
                    };break;
                    case 4:
                    {
                        if(full_Stack(sta))
                            printf("Oui, Votre pile est pleine\n");
                        else      
                            printf("Non, Votre pile ne l'est pas encore\n");    
                    };break;
                    case 5: Afficher_Stack(sta); break;
                    default:printf("Cette option n'est pas disponible\n");break;
                }
                printf("Souhaitez-vous interagir une fois de plus avec votre Pile\n 1 - Pour 'OUI'   0 - Pour 'NON': \n");
                scanf("%d",&r);
                printf("\n");
            }                      
        };break;
        case 2:
        {
            printf("*******  BIENVENUE DANS LA GESTION D'UNE FILE  *******\n");
            printf("(File dont la taille est fixe a < 10 > elements)\n\n ");
            int choix;
            int r = 1;
            while (r == 1)
            {
                printf("Comment souhaitez-vous interagir avec votre File :\n");
                printf("\t1 - Verifiez si elle est vide\n");
                printf("\t2 - Verifiez si elle est pleine\n");
                printf("\t3 - Enfiler un entier\n");
                printf("\t4 - Defiler un element de votre File\n");
                printf("\t5 - Afficher le contenu de votre file\n");
                printf("\tFaites votre choix : ");
                scanf("%d",&choix);
                printf("\n");
                switch (choix)
                {
                    case 1:
                    {
                        if(empty_Queue())
                            printf("Oui, votre File est vide\n");
                        else
                            printf("Non, votre File contient des elements\n");    
                    }break;
                    case 2:
                    {
                        if(full_Queue())
                            printf("Oui, votre file est pleine\n");
                        else
                            printf("Non, votre File ne l'est pas encore\n");    
                    };break;
                    case 3:
                    {
                        if(full_Queue()){
                            printf("Action inoperable!! File pleine\n");
                        }
                        else {
                            int n;
                            printf("Combien de valeurs voulez-vous ajouter : ");
                            scanf("%d",&n);
                            while (n>0)
                            {
                                int x;
                                printf("Entrer un entier : ");
                                scanf("%d",&x);
                                Enfiler(x);
                                n--;
                            }
                        }
                    };break;
                    case 4:
                    {
                        if(empty_Queue())
                           printf("Votre file est vide :(\n");
                        else
                        {
                            int n;
                            printf("Combien d'elememts souhaitez-vous retirer : ");
                            scanf("%d",&n);
                            while (n>0)
                            {
                                Defiler();
                                n--;
                            }
                        }   
                    };break;
                    case 5 : Afficher_Queue(); break;
                    default: printf("Cette option n'est disponible :(\n"); break;
                }
                printf("Souhaitez-vous interagir une fois de plus avec votre File \n 1 - Pour 'OUI'   0 - Pour 'NON': \n");
                scanf("%d",&r);
                printf("\n");
            }
        };break;
        case 3: return 0 ; break;
        default: printf("Option non disponible\n");break;
    }
    printf("Voulez-vous revenir au menu principal \n 1 - Pour 'OUI'   0 - Pour 'NON': \n");
    scanf("%d",&r);
    printf("\n");
    } 
    return 0;
}