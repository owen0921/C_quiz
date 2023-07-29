#include<stdio.h>
#include<stdlib.h>

typedef struct listNode *listPointer;
typedef struct listNode{
    char data;
    listPointer nextPtr;
}listNode;

void freeList(listPointer head){
    listPointer temp;
    while(head != NULL){
        temp = head;
        head = head->nextPtr;
        free(temp);
    }
}

void printList(listPointer head){
    listPointer temp = head;
    while(temp != NULL){
        printf("%c->", temp->data);
        temp = temp->nextPtr;
    }
    printf("NULL\n\n");
}

void printRevList(listPointer head){
    listPointer temp = head;
    if(temp->nextPtr != NULL){
        printRevList(temp->nextPtr);
    }
    else{
        printf("NULL");
    }
    printf("<-%c", temp->data);
}

int main(void){
    listNode* head = NULL;
    head = (listPointer)malloc(sizeof(listNode));
    head->data = 'a';
    head->nextPtr = (listPointer)malloc(sizeof(listNode));
    head->nextPtr->data = 'b';
    head->nextPtr->nextPtr = (listPointer)malloc(sizeof(listNode));
    head->nextPtr->nextPtr->data = 'c';
    head->nextPtr->nextPtr->nextPtr = NULL;

    printList(head);
    printRevList(head);
    freeList(head);
    return 0;
}
