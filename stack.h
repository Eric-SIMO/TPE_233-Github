#ifndef __STACK__H__
#define __STACK__H__

    /* Defintion d'une pile */
    typedef struct StackElement
    {
        int value ;
        struct StackElement *next;
    }StackElement,*Stack;
    
    /* Prototypes des fonctions */
    Stack new_stack(void);
    _Bool empty_Stack(Stack st);
    _Bool full_Stack(Stack st);
    void Afficher_Stack(Stack st);
    Stack Empiler(Stack st, int x);
    Stack Depiler(Stack st);
    int sommet(Stack st);
    int height_Stack(Stack st);
    Stack reset(Stack st);
   
#endif