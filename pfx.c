#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define size 20

struct stack{
    int top;
    int stk[size];
}s1;

void push(char ch){
    if(s1.top == size-1){
        printf("Stack Overflow\n");
    }
    else{
        s1.top++;
        s1.stk[s1.top] = ch;
    }
}

char pop(){
    if(s1.top == -1){
        printf("Stack Underflow\n");
    }
    else{
        s1.top--;
        return s1.stk[s1.top+1];
    }
}

int is_operator(char symbol){
    if(symbol == '/' || symbol == '*' || symbol == '+' || symbol == '^' || symbol == '-'){
        return 1;
    }
    else{
        return 0;
    }
}

int precedence(char symbol){
    if(symbol == '^'){
        return(3);
    }
    else if(symbol == '*' || symbol == '/'){
        return(2);
    }
    else if(symbol == '-' || symbol == '+'){
        return(1);
    }
    else{
        return(0);
    }
}

void iftpf(char* infix, char* postfix){
    int i=0,j=0;
    char item,x;

    push('(');
    strcat(infix,")");

    item = infix[i];

    while(item != '\0'){

        if(item == '('){
            push(item);
        }
        else if(isalpha(item) || isdigit(item)){
            postfix[j] = item;
            j++;
        }
        else if(is_operator(item) == 1){
            
            x = pop();
            while(is_operator(x) == 1 && precedence(x) >= precedence(item)){
                postfix[j] = x;
                j++;
                x = pop();
            }
            push(x);
            push(item);
        }
        else if(item == ')'){
            x = pop();
            while(x != '('){
                postfix[j] = x;
                j++;
                x = pop();
            }
        }

        i++;
        item = infix[i];
    }
    postfix[j] = '\0';

}

int main(){
    s1.top = -1;
    char infix[size],postfix[size];
    printf("Enter the Infix Expression: ");
    scanf("%s",infix);
    iftpf(infix,postfix);
    printf("The Postfix Expression is: ");
    printf("%s",postfix);
    printf("\n");
    return 0;
}