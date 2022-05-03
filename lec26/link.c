#include <stdio.h>
#include <stdlib.h>


typedef struct Struct item;
struct Struct 
{
    int data;
    item *next;
};

int additem2(item *head, int input){
    item *newitem = (item*) malloc(sizeof(item));
    if(newitem == NULL) return 0;
    newitem->data = input;
    newitem->next = head->next;
    head->next = newitem;
    return 1;
}
int additem(item **head, int input){
    item *newitem = (item*) malloc(sizeof(item));
    if(newitem == NULL) return 0;
    newitem->data = input;
    newitem->next = *head;
    *head = newitem;
    return 1;
}

void printitem(item *head){
    item *cursor = head;
    while(cursor != NULL){
        printf("%d ", cursor->data);
        cursor = cursor->next;
    }
    printf("\n");
}

void delete_node(item **headpptr, int val){
}
int main(){
    /*
    item *head = NULL;
    additem(&head,5);
    additem(&head,10);
    */

    item head;
    head.next = NULL; // head pointer
    additem2(&head, 5);
    additem2(&head, 10);

    printf("%d\n", head.next);
    printitem(head.next);
}
