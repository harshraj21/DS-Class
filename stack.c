#include<stdio.h>
#include<stdlib.h>

//#define size 50
//Modifying TO Dynamic
//And Acessing using structure pointer

struct stack{
    int top;
    int *arr;
}s1;

void push(struct stack *ptr){
    int item;
    printf("Enter The Value To Push: ");
    scanf("%d",&item);
    ptr->top++;
    ptr->arr = (int*)realloc(ptr->arr,ptr->top+1);
    ptr->arr[ptr->top] = item;
    printf("\n%d Pushed into stack sucessfully\n\n",item);
    return;
}

void pop(struct stack *ptr){
    int item;
    if(ptr->top == -1){
        printf("\nWarning: Stack Underflow\n");
        return;
    }
    else{
        item = ptr->arr[ptr->top];
        ptr->top--;
        ptr->arr = (int*)realloc(ptr->arr,ptr->top+1);
        printf("\n%d Deleted From Stack Sucessfully\n\n",item);
        return;
    }
}

void disp(struct stack *ptr){
    int i;
    if(ptr->top == -1){
        printf("\nWarning: Stack Underflow\n");
        return;
    }
    else
    {
        printf("\nStored Data\n\n");
        for(i=ptr->top;i>=0;i--){
            printf("%d\n",ptr->arr[i]);
        }
        printf("\n\n");
        return;
    }
}

void main(){
    int ch;
    struct stack *str;
    str = &s1;
    str->top = -1;
    str->arr = (int*)malloc(1*sizeof(int));
    for(;;){
        printf("\n1: Push\n2: Pop\n3: Display\n4: Quit\n\nEnter Your Choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: push(str);
                    break;
            case 2: pop(str);
                    break;
            case 3: disp(str);
                    break;
            case 4: exit(1);
                    break;
            default: printf("Invalid Choice!\nTry Again!\n");
                    break;
        }
    }
}