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
int is_full(void);
int is_empty(void);

int top;

void main(){
    start = NULL;
    int ch;
    top = 0;
    for(;;){
        printf("\nCircular Doubly Link List\n\n1: insert\n2: delete\n3: display\n4: exit\n\nEnter Your Choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: insert();
            break;
            case 2: delete();
            break;
            case 3: display();
            break;
            case 4: exit(1);
            break;
            default: printf("\nERROR: Invalid Choice\n");
            break;
        }
    }
}

int is_full(){
    ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL){
        return(1);
    }
    else{
        free(ptr);
        return(0);
    }
}

int is_empty(){
    if(start == NULL && top <= 0){
        return(1);
    }
    else{
        return(0);
    }
}

void insert(){
    int val2;
    struct node *temp;
    if(is_full() == 1){
        printf("\nWARNING: Memory is Full!\n");
    }
    else{
        ptr = (struct node*)malloc(sizeof(struct node));
        printf("\nEnter The Value: ");
        scanf("%d",&val2);
        if(is_empty() == 1){
            ptr->val = val2;
            ptr->next = ptr;
            ptr->prev = ptr;
            start = ptr;
            top++;
        }
        else{
            temp = start->next;
            ptr->val = val2;
            ptr->next = start;
            ptr->prev = temp;
            temp->next = ptr;
            start->prev = ptr;
            top++;
        }
        printf("\nALERT: Value/Node Inserted Sucessfully\n");
    }
}

void delete(){
    
}

void display(){
    int i;
    struct node *tmp;
    tmp = start;
    printf("\nPrinting the Values Stored\n");
    //printf("\n%d",tmp->val);
    for(i=0;i<top;i++){
        printf("\n%d",tmp->val);
        tmp = tmp->next;
    }
    printf("\n\n");
}



/*
 * Made By: Harsh Raj
 * Still Work in progress
 */
