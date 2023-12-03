#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"


Stack new_stack(void){

    return NULL;
}

/*------------------------------------------------------------------*/

_Bool  empty_Stack(Stack st){
    if(st == NULL)
       return true;
    else 
       return false;
}

/*------------------------------------------------------------------*/

_Bool full_Stack( Stack st) {
    if (height_Stack(st) == 10)
        return true;
    else
        return false;  
}

/*------------------------------------------------------------------*/

void Afficher_Stack(Stack st){
    if(empty_Stack(st)){
        printf("Rien a afficer, la Pile est vide. \n");
        return;
    }
    while(!empty_Stack(st)){
        printf("[%d]\n",st->value);
        st = st->next;
    }
}

/*------------------------------------------------------------------*/

Stack Empiler(Stack st, int x){
    if (full_Stack(st)){
        printf("Action inoperable!! Pile pleine\n");
        return st;
    }
    else{
        StackElement *element;
        element = malloc(sizeof(*element));
        if(element == NULL){
            fprintf(stderr,"Probleme d'allocation dynamique.\n");
            exit(EXIT_FAILURE);
        } 
        element->value = x;
        element->next = st;

        return element;
   }
}

/*------------------------------------------------------------------*/

Stack Depiler(Stack st){
    StackElement *element;

    if(empty_Stack(st))
        return new_stack();
    
    element = st->next;
    free(st);

    return element;
}
/*------------------------------------------------------------------*/

int sommet(Stack st){
    if(empty_Stack(st)){
        printf("Aucun sommet. La pile est vide .\n");
        exit(EXIT_FAILURE);
    }

    return st->value;
}
/*------------------------------------------------------------------*/

int height_Stack(Stack st){
    int h = 0;
    while (!empty_Stack(st))
    {
        h++;
        st = st->next;
    }
    return h;
}

/*------------------------------------------------------------------*/

Stack reset(Stack st){
   
   while (!empty_Stack(st)){
       st = Depiler(st);
    }
   return new_stack();

   // Ou l'on pouvait tout aussi utiliser ce bout de code
   /*
    StackElement *element;
    static int i = 1;
    if(est_vide(Stack st))
        return new_stack();
    
    element = st->next;
    free(st);

    return reset(element);
   */ 
}



