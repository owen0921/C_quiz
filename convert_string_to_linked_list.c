#include<stdio.h>
#include<stdlib.h>
typedef struct listNode *listPointer;
typedef struct listNode{
    char data;
    listPointer nextPtr;
}listNode;

void printList(listPointer head){
    listPointer temp = head;
    while(temp != NULL){
        printf("%c->", temp->data);
        temp = temp->nextPtr;
    }
    printf("NULL\n");
}

listPointer stringToList(char* s){
    //create a listNode
    listPointer head, temp = NULL;
    head = (listPointer)malloc(sizeof(listNode));
    temp = head;

    int i = 0;
    while(s[i + 1] != '\0'){
        temp->data = s[i];
        temp->nextPtr = (listPointer)malloc(sizeof(listNode));
        temp = temp->nextPtr;
        i++;
    }
    temp->data = s[i];
    temp->nextPtr = NULL;

    return head;
}

int main(void){
    char s[] = "abc test";
    listPointer head = stringToList(s);
    printList(head);

    // free list
    listPointer temp = NULL;
    while(head != NULL){
        temp = head;
        head = head->nextPtr;
        free(temp);
    }
    return 0;
}
