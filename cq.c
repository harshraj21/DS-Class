#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define size 5

struct queue{
    int rear;
    int front;
    char q[size];
}q1;

int is_full(){
    if((q1.front == q1.rear+1) || (q1.front == 0 && q1.rear == size-1)){
        return 1;
    }
    else{
        return 0;
    }
}

int is_empty(){
    if(q1.front == -1){
        return 1;
    }
    else{
        return 0;
    }
}

void enque(){
    if(is_full() == 1){
        printf("Queue is Full\n");
    }
    else{
        int n;
        printf("Enter the Value to store: ");
        scanf("%d",&n);
        if(q1.front == -1){
            q1.front=0;
        }
        q1.rear = (q1.rear+1)%size;
        q1.q[q1.rear] = n;
        printf("\nValue Inserted Sucessfully!\n");
    }
}

void deque(){
    if(is_empty() == 1){
        printf("Queue is empty\n");
    }
    else{
        int x;
        x = q1.q[q1.front];
        if(q1.front == q1.rear){
            q1.front = -1;
            q1.rear = -1;
        }
        else{
            q1.front = (q1.front+1)%size;
        }
        printf("Value Deleted Was: %d",x);
    }
}

void display(){
    int i;
    if(is_empty() == 1){
        printf("Queue is empty\n");
    }
    else{
        printf("\nPrinting The Values Stored\n");
        i = q1.front;
        do{
            printf("%d\n",q1.q[i]);
            i=(i+1)%size;
        }
        while(i!=(q1.rear+1)%size);
    }
}

void main(){
    q1.front = -1;
    q1.rear = -1;
    int ch;
    for(;;){
        printf("\nCircular Queue\n1: insert\n2: delete\n3: display\n4: exit\nEnter Your Choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: enque();
            break;

            case 2: deque();
            break;

            case 3: display();
            break;

            case 4: exit(1);
            break;

            default: printf("\nInvalid Choice\n");
            break;
        }
    }
}