#include "LinkedList.h"

int main(){
    LinkedList* l;
    l = initList(l);
    
    LinkedListItem* it = initItem(it , 0);
    LinkedListItem* it2 = initItem(it2 , 2);
    LinkedListItem* it3 = initItem(it3 , 3);
    LinkedListItem* it4 = initItem(it4 , 2);
    LinkedListItem* it5 = initItem(it5 , 5);
    
    insertKItem(l , it , 0);
    insertKItem(l , it2 , 0);
    insertKItem(l , it3 , 0);
    insertKItem(l , it5 , 2);
    
    printList(l);
    removeItem(l , it3);
    removeItem(l , it5);
    
    printList(l);
    return 0;
}
