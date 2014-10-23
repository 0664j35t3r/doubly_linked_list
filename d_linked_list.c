/* 
 * File:   main.c
 * Author: plorenz
 *
 * Created on 23. Oktober 2014, 17:34
 */

#include <stdio.h>
#include <stdlib.h>
   

typedef struct _sorted_list_ {
  struct _sorted_list* next; //warum struct? ist einfach ein pointer? könnt auch mehr sein
  struct _sorted_list* prev;
  int data; 
} sorted_list;

void sorted_list_add(sorted_list** list, int data) {//pointer of a pointer -> goes around to corners!!!
  sorted_list* new_e = (sorted_list*)malloc(sizeof(sorted_list));
  new_e->data = data;
  
  //What happens if list is not yet created?
  if((*list) == NULL) {
    new_e->next = new_e->prev = NULL;
    (*list) = new_e; //übergebe den anchor
  } 
  //fill the the list - fill it in the first row!!!!
  else if((*list)->data >= data) {
    *list->prev = new_e;
    new_e->prev = NULL;
    new_e->next = (*list);
    (*list) = new_e;
  } 
  
  //insert in the middle
  else {
    sorted_list* compare = *list; 
    while(compare->data < data && compare->next != NULL)
    {
      compare = compare->next;
    }
    
    if(compare->data >= data)
    {
      new_e->next = compare;
      new_e->prev = compare->prev;
      (new_e->prev)->next = new_e;
      
      compare->next = new_e;
    }
  }
  
}
int main(int argc, char** argv) {
  
  sorted_list* l = NULL;
  sorted_list_add(&l,2);
  sorted_list_add(&l,3);
  sorted_list_add(&l,4);
  sorted_list_add(&l,3);
  sorted_list_add(&l,1);
  
  sorted_list* iter = l;
  while(iter != NULL) {
    printf("%d ", iter->data);
    iter = iter->next;
  }
  printf("\n");
  //sorted_list_destroy(&l);
  return (EXIT_SUCCESS);
}

