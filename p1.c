#include<stdio.h>
#include<stdlib.h>

struct node{
    char val;
    struct node* next;
}*ptr,*start;

struct node* getnode(){
    ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL){
        printf("\nERROR: Memory is full!\n");
        exit(1);
    }
    else{
        return ptr;
    }
}

void arraytonode(int size, char *arr){
    int i;
    struct node* tmp;
    struct node* tmp2;
    for(i=0;i<size;i++){
        tmp = getnode();
        if(start == NULL){
            tmp->val = arr[i];
            tmp->next = NULL;
            start = tmp;
        }
        else{
            tmp2 = start;
            tmp->val = arr[i];
            tmp->next = NULL;
            while(tmp2->next!=NULL){
                tmp2 = tmp2->next;
            }
            tmp2->next = tmp;
        }
    }
}

void main(){
    start = NULL;
    char *arr,arr2;
    int i = 1;
    struct node* tmp;

    printf("Enter the string to check: ");

    arr = (char*)malloc(i*sizeof(char));
    while((arr2 = getc(stdin))!='\n'){
        arr[i-1] = arr2;
        arr = (char*)realloc(arr,++i);
    }
    arr[i-1] = '\0';
    arraytonode(i-1,arr);
    tmp = start;

    while(tmp!=NULL){
        printf("%c",tmp->val);
        tmp = tmp->next;
    }
}