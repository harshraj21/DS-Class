#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

#define size 20

struct stack{
    int top;
    int s[size];
}s1;

void push(int item){
    if(s1.top == size-1){
        printf("Stack is full\n");
        return;
    }
    else{
        s1.top++;
        s1.s[s1.top]=item;
    }
}

char pop(){
    if(s1.top == -1){
        printf("Stack is Empty\n");
    }
    else{
        s1.top--;
        return s1.s[s1.top+1];
    }
}

int evalv(char* postfix){
    int i=0,x,y,z;
    char ch;
    ch = postfix[i];

    while(ch!='\0'){
        if(isdigit(ch)){
            push(ch-'0');
        }
        else if(ch == '+'||ch == '-'||ch == '/'||ch == '*'||ch == '^'){
            x=pop();
            y=pop();
            switch(ch){
                case '^': z = pow(y,x);
                break;
                case '/': z = y/x;;
                break;
                case '*': z = y*x;
                break;
                case '+': z = y+x;
                break;
                case '-': z = y-x;
                break;
            }
            push(z);
        }
        i++;
        ch = postfix[i];
    }
    return pop();
}

void main(){
    s1.top = -1;
    char postfix[size];
    int eval;
    printf("Enter the postfix expression: ");
    scanf("%s",postfix);
    eval = evalv(postfix);
    printf("Evaluated Value: %d\n",eval);
}