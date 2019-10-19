#include<stdio.h>
#include<stdlib.h>

struct node{
    int val;
    struct node *next;
}*start,*ptr;

int top;

void push(){
    int val2;
    ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL){
        printf("\nStack Overflow\n");
    }
    else{
        printf("\nEnter The Value To Push: ");
        scanf("%d",&val2);
        if(start == NULL){
            ptr->val = val2;
            ptr->next = NULL;
            start = ptr;
        }
        else{
            ptr->val = val2;
            ptr->next = start;
            start = ptr;
        }
        top++;
    }
}

void pop(){
    struct node* tmp;
    if(start == NULL){
        printf("\nStack Underflow\n");
    }
    else{
        tmp = start;
        start = start->next;
        printf("\nValue >%d< Popped From stack\n",tmp->val);
        free(tmp);
        top--;
        if(top <= 0){
            start = NULL;
        }
    }
}

void display(){
    struct node *tmp;
    tmp = start;
    if(start == NULL){
        printf("\nList is empty\n");
    }
    else{
        printf("*********************");
        while(tmp!=NULL){
            printf("%d\n",tmp->val);
            tmp = tmp->next;
        }
        printf("*********************");
    }
}

void main(){
    start = NULL;
    int ch;
    top = 0;
    for(;;){
        printf("\nImplementaion of stacks using SLL\n1: push\n2: pop\n3: display\n4: exit\nEnter Your Choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: push();
            break;

            case 2: pop();
            break;

            case 3: display();
            break;

            case 4: exit(1);

            default: printf("\nInvalid Choice\n");
        }
    }
}