#include<stdio.h>
#include<stdlib.h>

struct node{
    int val;
    struct node *next;
}*front,*rear;

struct node* getnode(int x){
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    if(temp != NULL){
        temp->val = x;
        return temp;
    }
    else{
        printf("\nALERT: Memory is full\n");
        exit(1);
    }
}

void enque(){
    struct node* tmp;
    int val2;
    printf("Enter the value to store: ");
    scanf("%d",&val2);
    if(front == NULL){
        front = getnode(val2);
        front->next = NULL;
        rear = front;
    }
    else{
        tmp = rear;
        rear = getnode(val2);
        tmp->next = rear;
        rear->next = NULL;
    }
    printf("\nValue Inserted Sucessfully\n");
}

void deque(){
    struct node *tmp;
    if(front == NULL){
        printf("\nList is empty!\n");
    }
    else{
        tmp = front;
        front = front->next;
        free(tmp);
    }
}

void display(){
    struct node *tmp;
    tmp = front;
    if(front == NULL){
        printf("\nList is empty!\n");
    }
    else{
        printf("\n***************\nStored Values\n***************");
        while(tmp != NULL){
            printf("\n%d",tmp->val);
            tmp = tmp->next;
        }
    }
}

void main(){
    front = rear = NULL;
    int ch;
    for(;;){
        printf("\nQueue using SLL\n\n1: Insert Value\n2: Delete Value\n3: Front Val\n4: Rear Val\n5: Diplay Values\n6: Exit\nEnter Your Choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: enque();
            break;
            case 2: deque();
            break;
            case 3: if(front != NULL) printf("\nFront: %d\n",front->val); else printf("\nFront is NULL\n");
            break;
            case 4: if(rear != NULL) printf("\nRear: %d\n",rear->val); else printf("\nRear is NULL\n");
            break;
            case 5: display();
            break;
            case 6: exit(1);
            break;
            default: printf("Wrong Choice\n");
            break;
        }
    }
}