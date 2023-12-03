#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

_Bool empty_Queue(void){
    if(first == NULL && last == NULL)
        return true;
    
    return false;
}

/*-----------------------------------------------------------*/

_Bool full_Queue(void){
    if (height_Queue() == 10)
       return true;
    else 
       return false;
}

/*-----------------------------------------------------------*/

int height_Queue(void){
    return nb_elements;
}

/*-----------------------------------------------------------*/

int first_Queue(void){
    if(empty_Queue())
        exit(1);

    return first->value;
}

/*-----------------------------------------------------------*/

int last_Queue(void){
    if(empty_Queue())
        exit(1);

    return last->value;
}

/*-----------------------------------------------------------*/

void Afficher_Queue(void){
    if(empty_Queue()){
        printf("Rien a afficher, la File est vide. \n");
        return;
    }

    QueueElement *temp = first;

    while (temp != NULL)
    {
        printf("[%d]", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

/*-----------------------------------------------------------*/

void Enfiler(int x){
    if (full_Queue()){
        printf("Action inoperable!! File pleine\n");
    }
    else{
        QueueElement *element;
        element= malloc(sizeof(*element));
        if(element == NULL){
            fprintf(stderr,"Erreur : probleme allocation dynamique. \n");
            exit(EXIT_FAILURE);
        }

        element -> value = x;
        element ->next = NULL;

        if(empty_Queue()){
            first = element;
            last = element;
        }
        else{
            last->next = element;
            last = element;
        }
        nb_elements ++;
    }
}

/*-----------------------------------------------------------*/

void Defiler(void){
    if(empty_Queue()){
        printf("Rien a retirer, la File est deja  vide. \n");
        return;
    }

    QueueElement *temp = first; 

    if(first == last){
        first = NULL;
        last = NULL;
    }
    else
        first = first->next;
    

    free(temp);
    nb_elements --;
}

/*-----------------------------------------------------------*/

void reset_Queue(void){
    if(empty_Queue()){
        printf("Rien a nettoyer, la File est deja vide. \n");
        return;
    }
    while(!empty_Queue()){
        Defiler();
    }
}