#include<stdlib.h>
#include<stdio.h>
#include "LinkedList.h"



LinkedListItem* initItem(LinkedListItem* it , int info){
    it =  (LinkedListItem*) malloc(sizeof(LinkedListItem));
    it->info = info;
    return it;
}

LinkedList* initList(LinkedList* list){
    list = (LinkedList*) malloc(sizeof(LinkedList));
    list->size = 0;
    list->head = (LinkedListItem*) malloc(sizeof(LinkedListItem));
    list->tail = (LinkedListItem*) malloc(sizeof(LinkedListItem));
    return list;
}

LinkedListItem* findItem(LinkedList* list, LinkedListItem* target){
    if(!target || list->size == 0){
        return NULL;
    }else{
        LinkedListItem* it = list-> head;
        while(it){
            if(it->info == target->info){
                return it;
            }
            it = it->next;
        }
        return NULL;
    } 
}

//Insert afte position pos
void insertKItem(LinkedList* list , LinkedListItem* item, int pos){
    if(list->size == 0 && pos == 0){
        list->head = item;
        list->size += 1;
        list->tail->prev = item;
        return;
    }
    if(!item || !list){
        printf("Null Item or List !\n");
        return;
    }

    if( pos >= list->size ){
        printf("target pos >= list size! \n");
        return;
    }

    LinkedListItem* res = findItem(list, item);
    if(res) {
        printf("item already in list ! \n");
        return;
    }

    LinkedListItem* it;
    if(pos > 0){
        it = list->head;
        int count = 0;
        while(it && count < list->size){
            if(count+1 == pos ){
                item->next = it->next;
                it->next = item;
                item->prev = it;
                list->size += 1;
                return;
            }
            count++;
            it = it->next;
        }
    }else if(pos < 0){
        it = list->tail;
        int count = -1;
        while(it && count >= 0){
            if(count+1 == pos){
                item->next = it->next;
                item->prev = it;
                it->next = item;
                list->size += 1;
                return;
            }
            count--;
            it = it->prev;
        }
    }else{
        item->next = list->head;
        list->head->prev = item;
        list->size += 1;
        list->head = item;
    }
    
    return;

}

void removeItem(LinkedList* list,  LinkedListItem* toRemove){
    LinkedListItem* ret= findItem(list, toRemove);

    if(ret == NULL) return;

    if(ret->prev == NULL){
        if(ret->next){
            list->head = ret->next;
            ret->next->prev = list->head;
            list->size -= 1;
        }else{
            list->size = 0;
            ret = NULL;
        }
        return;
    }

    if(ret->next == NULL){
        if(ret->prev){
            list->tail = ret->prev;
            ret->prev->next = list->tail;
            list->size -= 1;
        }else{
            list->size = 0;
            ret = NULL;
        }
        return;
    }

    ret->prev->next = ret->next;
    ret->next->prev = ret->prev;
    list->size -= 1;
    return;
        
}

void printList(LinkedList* list){
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
void appendItem(LinkedList* head, LinkedListItem* item){
    return;
}

void addFirstItem(LinkedList* head, LinkedListItem* item){
    return;
}
