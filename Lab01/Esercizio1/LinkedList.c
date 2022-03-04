#include<stdlib.h>
#include<stdio.h>
#include "LinkedList.h"



LinkedListHead* initList(LinkedListHead* list){
    list = (LinkedListHead*) malloc(sizeof(LinkedListHead));
    list->size = 0;
    list->head = (LinkedListItem*) malloc(sizeof(LinkedListItem));
    return list;
}

LinkedListItem* findItem(LinkedListHead* head, LinkedListItem* target){
    return NULL; //TODO: 
}

void insertKItem(LinkedListHead* head , LinkedListItem* it, int pos){
    return; //TODO
}
LinkedListItem* removeItem(LinkedListHead* head,  LinkedListItem* toRemove){
    return NULL; //TODO
}

void printList(LinkedListHead* list){
    if(list-> size == 0){   
        printf("L: []\n");
    } else{
        LinkedListItem* it = list->head;
        printf("L: [");
        while(it){
            printf(" %d",it->info);
            it = it->next;
        }
        printf("]\n");
    }
    
}

//wrappers
void appendItem(LinkedListHead* head, LinkedListItem* item);
void addFirstItem(LinkedListHead* head, LinkedListItem* item);
