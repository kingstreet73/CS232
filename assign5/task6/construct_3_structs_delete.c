#include<stdio.h>
#include<stdlib.h>
#include "snode.h"
typedef struct snode node_t;

node_t * setup() {
    node_t * head;
    //TODO:head declared for you
    //Allocate three more pointers
    //head for the first Node, and temporary pointers node1, node2 and node3
    node_t * node1;
	  node_t * node2;
	  node_t * node3;
    //Allocate three node pointees and store references to them in the three pointers
    head = node1 = malloc(sizeof(node_t));
  	node2 = malloc(sizeof(node_t));
    node3 = malloc(sizeof(node_t));
    //Dereference each pointer to store the appropriate number and string into the length and str fields in its pointee.
    strcpy(head->str,"");
    head->length=0;
    strcpy(node1->str,"hello");
    node1->length= 5;
    strcpy(node2->str,"there");
    node2->length = 5;
    strcpy(node3->str,"prof"); 
    node3->length = 4;
    //Dereference each pointer to access the .next field in its pointee, 
    //and use pointer assignment to set the .next field to point to the appropriate Node. 
    head->next=node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    
   return head;
}

void teardown(node_t* node) {
    //TODO: free all dynamic memory you requested.
    //Please complete the prototype of teardown.
    //You are not allowed to use globals
     struct snode* tmp;
    while(node != NULL){
      tmp = node;
      node = node->next;
      free(tmp);
 }
}

void add(node_t ** head, char * str, int length){
    //TODO: implement add to add a new node to front, pointed by head
    node_t * new_node;
    new_node = malloc(sizeof(node_t));
    strcpy(new_node->str, str);
    new_node->length= length;
    new_node->next = *head;
    *head = new_node;
}

void delete_node_at(node_t ** head, int idx) {
    //TODO: implement delete a node based on index
	//deletes a node at index idx, which ranges from zero to the length of the list - 1.
   node_t *h = *head;
   node_t *t = *head;
   if(idx == 0){
     if(h){
       *head = (h->next);
       free(h);
      }
      else printf("Index does not exist \n");
    }
    else{
      int i;
      for(i=0;h && i<idx;i++){
        t = h;
        h = h->next;
      }
      if(i == idx){
        t->next = h->next;
        free(h);
      }
      else printf("Index does not exist \n");
    }
}
void delete_node_key(node_t **head, char * key) {
  //TODO: implement delete a node based on key
	//given a certain key, find and delete. 
  node_t *h = *head;
  node_t *t = h;
  while(h){
    if(strcmp(h->str,key)==0){
      if(t == h){
        *head = (h->next);
        free(h);
      }
        else{
          t->next = h->next;
          free(h);
        }
    }
    t = h;
    h = h->next;
  }
}

void dump_all(node_t*);
int main (int argc, char ** argv) {
    node_t * head = setup();
    add(&head, "hi", 2);
    delete_node_key(&head, "prof");
    delete_node_at(&head, 0);
    dump_all(head);
    teardown(head);
    return 0;
}

void dump_all(node_t * head) {
    printf("head -> ");
    node_t * cur = head;
    while(cur != NULL) {
        printf("%s ", cur->str);
	cur = cur->next;
    }
    printf("\ndone\n ");
}