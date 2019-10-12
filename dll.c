#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *prev;
    int val;
    struct node *next;
}*ptr,*start;

void insert(void);
void delete(void);
void display(void);

void main(){
    start = NULL;
    int ch;

    for(;;){
        printf("\n\nCircular Doubly Link List\n\n1: insert\n2: delete\n3: display\n4: exit\nEnter Your Choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: insert();
            break;
            case 2: delete();
            break;
            case 3:display();
            break;
            case 4: exit(1);
            break;
            default: printf("\nInvalid Choice\n");
            break;
        }
    }
}

/**
 * Made By: Harsh Raj
 * Still Work in progress
*/