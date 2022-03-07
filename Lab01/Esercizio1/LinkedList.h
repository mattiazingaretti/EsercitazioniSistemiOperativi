#pragma once

struct LinkedListItem;
struct LinkedList;

typedef struct LinkedListItem{
    struct LinkedListItem* prev;
    struct LinkedListItem* next;
    int info; //extend it to generic
}LinkedListItem;


typedef struct LinkedList{
    struct LinkedListItem* head;
    struct LinkedListItem* tail;
    int size;
} LinkedList;


LinkedListItem* initItem(LinkedListItem* it , int info);
LinkedList* initList(LinkedList* list);
LinkedListItem* findItem(LinkedList* list, LinkedListItem* target);
void insertKItem(LinkedList* list , LinkedListItem* it, int pos);
void removeItem(LinkedList* list,  LinkedListItem* toRemove);
void printList(LinkedList* list);

//wrappers
void appendItem(LinkedList* list, LinkedListItem* item);
void addFirstItem(LinkedList* list, LinkedListItem* item);




