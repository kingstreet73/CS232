#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "slist.h"
#include "snode.h"

/*
 Dynamic Allocation
 return pointer to the list
 */
struct slist *slist_create() {
    struct slist* list;
    list = (struct slist*)malloc(sizeof(struct slist));    
    list->front = NULL;
    list->back = NULL;
    return list;
}

/*
  Inserts new node in slist after the last node.
 returns a pointer to the new node
 */
struct snode* slist_add_back(struct slist *l, char *str) {
    struct snode* node;
    node = snode_create(str);
    if (l->front == NULL) {
        l->front = node;
        l->back = node;
    } else {
        l->back->next = node;
        l->back = node;
    }
    return node;
}

/*
  Inserts new node in slist before the first node.
  returns a pointer to the newly added node
 */
struct snode* slist_add_front(struct slist *l, char *str) {
    struct snode* node;
    node = snode_create(str);
    if (l->front == NULL) {
        l->front = node;
        l->back = node;
    } else {
        node->next = l->front;
        l->front = node;
    }
    return node;

}

/*
  Return the first snode with the given string
 */
struct snode* slist_find(struct slist *l, char *str) {
    struct snode* node = l->front;
    while(node != NULL) {
        char* nodeString = node->str;
        if (strcmp(nodeString, str) == 0) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

/**
 Deallocate a list and all snodes
 */
void slist_destroy(struct slist *l) {
    struct snode* node = l->front;
    struct snode* temp;
    while(node != NULL) {
        temp = node->next;
        snode_destroy(node);
        node = temp;
    }
    free(l);
}

/*
  Traverse and print each node in list
 */
void slist_traverse(struct slist *l) {
    struct snode* node = l->front;
    while(node != NULL) {
        printf("%s\n", node->str);
        node = node->next;
    }
}

/*
  Returns the number of elements in the list (nodes)
 */
 slist_length(struct slist *l) {
    struct snode* node = l->front;
    int length = 0;
    while(node != NULL) {
        length++;
        node = node->next;
    }
    return length;
}

void slist_delete(struct slist *l, char *str){
struct snode* node = l->front;
    while(node != NULL) {
        free(node);
        
       
}
