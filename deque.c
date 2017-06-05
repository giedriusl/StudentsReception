#include <stdio.h>
#include <stdlib.h>
#include "deque.h"
#include <assert.h>
#include <stdbool.h>
deque_type* createEmpty(deque_type* h){
   deque_type* d = (elem*)malloc(sizeof(elem));
   if (d != NULL)
       d->head = d->tail = NULL;
       d->count = 0;
   return d;
}
void pushBeg(deque_type* d,int v){
   elem* temp = (elem*)malloc(sizeof(elem));
   assert(temp != NULL); //error jeigu neisskiria vietos
      temp->data = v;
      temp->next = d->head;
      temp->previous = NULL;
      if(d->tail == NULL) { //jei nebuvo ivesta niekur
         d->head = d->tail = temp;
      }
      else {
         d->head->previous = temp;
         d->head = temp;
      }
      d->count++;
}
void pushEnd(deque_type* d,int v){
   elem* temp = (elem*)malloc(sizeof(elem));
   assert(temp != NULL);
      temp->data = v;
      temp->previous = d->tail;
      temp->next = NULL;
      if(d->head == NULL){
         d->head = d->tail = temp;
      }
      else {
         d->tail->next = temp;
         d->tail = temp;
      }
      d->count++;
}
void delBeg(deque_type* d,int *err){
   elem* temp = d->head;

   if(checkEmpty(d) == 1) {
      *err = 1;
   } else
   {
      if(d->head == d->tail){ //jei head == tail
         d->head = d->tail = NULL;
         free(temp);
      }
      else if(d->head->next == d->tail){ //jei kitas lygus tail
         d->head = d->tail;
         free(temp);
      }
      else { //jei head->next ne tail
         d->head = temp->next;
         d->head->previous = NULL;
         free(temp);
      }
      d->count--;
   }
}

void delEnd(deque_type* d,int *err){
   elem* temp = d->tail;

   if(checkEmpty(d) == 1)
   {
       *err = 2;
   } else
   {
       if(d->tail == d->head){ //Jei head lygus tail
         d->head = NULL;
         d->tail = NULL;
         free(temp);
      }
      else if (d->tail->previous == d->head) { //Jei ankstesnis yra head
         d->tail = d->head;
         free(temp);
      }
      else {
         d->tail = temp->previous;
         d->tail->next = NULL;
         free(temp);
      }
      d->count--;
   }

}
bool checkEmpty(deque_type* d){
   if ((d->head == NULL) && (d->tail == NULL)){
      return true; //Jei tuscias
   }
   else if(d->tail->next == NULL){
      return false; //jei netuscias
   } else if(d->tail == d->head)
   {
       return false;
   }
}
int getHead(deque_type* d,int *err){
   int v;

      if(checkEmpty(d) == 1) {
          *err = 3;
      } else
      {
         elem* temp = d->head;
         v = temp->data;
         return v;
      }
}
int getTail(deque_type* d,int *err){
   int v;

   if(checkEmpty(d) == 1) {
      *err = 4;
   } else
   {
      elem* temp = d->tail;
      v = temp->data;
      return v;
   }
}
void deleteDeque(deque_type* d){
   elem* temp = d->head;
   do{
       temp = d->head;
      d->head = temp->next;
      free(temp);
   }while(d->head != NULL);
}
int getCount(deque_type* d){
    return d->count;
}
