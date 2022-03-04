#pragma once

struct LinkedListItem;
struct LinkedListHead;

typedef struct LinkedListItem{
    struct LinkedListItem* prev;
    struct LinkedListItem* next;
    int info; //extend it to generic
}LinkedListItem;


typedef struct LinkedListHead{
    struct LinkedListItem* head;
    int size;
} LinkedListHead;


LinkedListHead* initList(LinkedListHead* head);
LinkedListItem* findItem(LinkedListHead* head, LinkedListItem* target);
void insertKItem(LinkedListHead* head , LinkedListItem* it, int pos);
LinkedListItem* removeItem(LinkedListHead* head,  LinkedListItem* toRemove);
void printList(LinkedListHead* head);

//wrappers
void appendItem(LinkedListHead* head, LinkedListItem* item);
void addFirstItem(LinkedListHead* head, LinkedListItem* item);




