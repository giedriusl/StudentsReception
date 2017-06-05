//652
#ifndef DEQUE_H
#define DEQUE_H
#include <stdbool.h>
typedef struct node_struct{
    int data;
    struct node_struct *next;
    struct node_struct *previous;
}elem;
typedef struct deque_struct{
   struct node_struct *head;
   struct node_struct *tail;
   int count; //deko elementu kiekis
}deque_type;

deque_type* createEmpty();  //Sukuria tuscia deka
void pushBeg(deque_type*,int);  //Ideda elementa i prieki
void pushEnd(deque_type*,int);  //Ideda elementa i gala
void delBeg(deque_type*,int*);  //Istrina is pradzios  || err = 1 jei tuscias
void delEnd(deque_type*,int*);  //Istrina is pabaigos  || err = 1 jei tuscias
bool checkEmpty(deque_type* );  //Patikrina ar tuscias
int getHead(deque_type*, int*);  //Paima pradzios elementa NEISTRINDAMAS!  || err = 1 jei tuscias
int getTail(deque_type*, int* );  //Paima pabaigos elementa NEISTRINDAMAS!  || err = 1 jei tuscias
void deleteDeque(deque_type* ); //Istrina visa deka
int getCount(deque_type* );  //grazinamas deko elementu kiekis
#endif
