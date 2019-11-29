/*
 * dll.c
 *
 *  Created on: Nov. 27, 2019
 *      Author: Jonathan Cui
 */


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "dllheader.h"


struct dll *dll_create(void){
	struct dll* new = malloc(sizeof(struct dll));
	new -> head = NULL;
	return new;
}
struct dll *dll_destroy(struct dll* lst){
  struct dllnode* next_node = lst->head;
  while(next_node){
	  struct dllnode* curr_node = next_node;
	  next_node = curr_node->next;
	  free(curr_node);
  }
  free(lst);
  return NULL;
}
void dll_add_item(struct dll* lst, int item){ // DONT NEED TO HOLD NEXT OINTER
	struct dllnode* new_node = malloc(sizeof(struct dllnode));
	new_node->item = item;
	if(lst->head){
		struct dllnode* curr_node = lst->head;
		while(curr_node->next){	//Navigate to the last node
				curr_node = curr_node->next;
	} curr_node->next = new_node;
	new_node->prev = curr_node;
	} else {
		lst->head = new_node;
		new_node->prev = NULL;
	}
	new_node->next = NULL;

}
bool dll_remove_item(struct dll* lst, int item){
  struct dllnode* curr_node = lst->head;
  while(curr_node){
	  if(curr_node->item == item){
		  struct dllnode* next_node = curr_node->next;
		  struct dllnode* prev_node = curr_node->prev;
		  if(prev_node){
			  prev_node->next = next_node;
		  } else{
			  lst->head = curr_node->next;
		  }
		  if (next_node){
			  next_node->prev = prev_node;
		  }
		  free(curr_node);
		  return true;
	  }
  curr_node = curr_node->next;
  }
  return false;
}
struct dll *arr_to_dll(int *arr, size_t n){
	struct dll* new_dll = malloc(sizeof(struct dll));
	if (n){//Initiate the first node;
		struct dllnode* new_node = malloc(sizeof(struct dllnode));
		new_node->item = arr[0];
		new_node->next = NULL;
		new_node->prev = NULL;
		new_dll->head = new_node;
		struct dllnode* prev_node = new_node;
		for(int i = 1; i < n; i++){
			struct dllnode* new_node = malloc(sizeof(struct dllnode));
			new_node->item = arr[i];
			new_node->prev = prev_node;
			new_node->next = NULL;
			prev_node->next = new_node;
			prev_node = new_node;
		}
	}else{
		new_dll->head = NULL;
	}
	return new_dll;
}
//
//int main(void){
//  int a[] = {19,5,6,21,-2};
//  struct dll *dlst = arr_to_dll(a, 5);
//  assert(dll_remove_item(dlst,21));
//  print_dll(dlst);
//  dll_destroy(dlst);
//}


