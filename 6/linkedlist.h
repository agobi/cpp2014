#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct s_linkedlist; // opaque
typedef s_linkedlist *linkedlist;

void linkedlist_init(linkedlist &l);
void linkedlist_destroy(linkedlist &l);
void linkedlist_push_back(linkedlist l, int value);
void linkedlist_pop_back(linkedlist l);
int  linkedlist_back(linkedlist l);
bool linkedlist_empty(linkedlist l);

#endif//LINKEDLIST_H
