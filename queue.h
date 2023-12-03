#ifndef __QUEUE_H__
#define __QUEUE_H__
    
    /* Defintion de notre file */
    typedef struct QueueElement
    {
        int value;
        struct QueueElement *next;
    }QueueElement, *Queue;

    /* Parametres de la file */
    static QueueElement *first = NULL;    
    static QueueElement *last = NULL;
    static int nb_elements = 0;

    /* Prototypes */
    _Bool empty_Queue(void);
    _Bool full_Queue(void);
    int height_Queue(void);
    int first_Queue(void);
    int last_Queue(void);
    void Afficher_Queue(void);
    void Enfiler(int x);
    void Defiler(void);
    void reset_Queue(void);

#endif