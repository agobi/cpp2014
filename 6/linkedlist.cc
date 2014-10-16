#include "linkedlist.h"

struct link
{
    int value;
    link *prev, *next;
};

struct s_linkedlist
{
    link *front, *back;
};

//typedef s_linkedlist *linkedlist;
void linkedlist_init(linkedlist &l)
{
    l = new s_linkedlist;
    l->front = l->back = 0;

    // (*l).front // l->front
    // *l.front
}

void linkedlist_destroy(linkedlist &l)
{
    while(!linkedlist_empty(l))
        linkedlist_pop_back(l);
    delete l;
}

void linkedlist_push_back(linkedlist l, int value)
{
    link *p = new link;
    p->prev = l->back;
    p->next = 0;
    p->value = value;

    if(l->back)
        l->back->next = p;
    else
        l->front = p;
    l->back = p;
}

void linkedlist_pop_back(linkedlist l)
{
    link *p = l->back;
    l->back = l->back->prev;
    delete p;

    if(l->back)
        l->back->next=0;
    else
        l->front=0;
}

int  linkedlist_back(linkedlist l)
{
    return l->back->value;
}

bool linkedlist_empty(linkedlist l)
{
    return !l->front;
}
