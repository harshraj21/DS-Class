#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define size 20

struct stk{
    int top;
    char stack[size];
}s1;

void push(char item){
    if(s1.top == size-1){
        exit(1);
    }
    else{
        s1.top++;
        s1.stack[s1.top] = item;
    }
}

char pop(){
    if(s1.top == -1){
        exit(1);
    }
    else{
        s1.top--;
        return s1.stack[s1.top+1];
    }
}

int is_operator(char symbol){
    if(symbol == '^'||symbol == '/'||symbol == '*'||symbol == '-'||symbol == '+'){
        return 1;
    }
    else{
        return 0;
    }
}

int precedence(char symbol){
    switch(symbol){
        case '^': 
        return 3;
        break;
        case '/': 
        case '*':
        return 2;
        break;
        case '+': 
        case '-':
        return 1;
        break;
        default: return 0;
        break;
    }
}

void ifxtpfx(char* infix, char* postfix){
    int i=0,j=0;
    char item,x;
    
    push('(');
    strcat(infix,")");

    item = infix[i];
    while(item!='\0'){

        if(item == '('){
            push(item);
        }
        else if(isalpha(item)||isdigit(item)){
            postfix[j] = item;
            j++;
        }
        else if(is_operator(item) == 1){
            x = pop();
            while(is_operator(x) == 1 && precedence(x) >= precedence(item)){
                postfix[j]=x;
                j++;
                x=pop();
            }
            push(x);
            push(item);
        }
        else if(item == ')'){
            x = pop();
            while(x!='('){
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

void reverse(char* infix,char* postfix){
    int i,j,k,z,y;
    char temp2[size];
    i=0;
    while(infix[i]!='\0'){
        i++;
    }
    y=i;
    k=i-1;
    for(j=0;j<i;j++){
        temp2[j] = infix[k];
        k--;
    }
    temp2[j] = '\0';
    z=0;
    while(y!=0){
        infix[z] = temp2[z];
        z++;
        y--;
    }
    for(j=0;j<i;j++){
        if(infix[j] == ')'){
            infix[j] = '(';
        }
        else if(infix[j] == '('){
            infix[j] = ')';
        }
    }
    ifxtpfx(infix,postfix);
    i=0;
    while(postfix[i]!='\0'){
        i++;
    }
    k=i-1;
    for(j=0;j<i;j++){
        temp2[j] = postfix[k];
        k--;
    }
    temp2[j] = '\0';
    z=0;
    while(i!=0){
        postfix[z] = temp2[z];
        z++;
        i--;
    }
}

int main(){
    char infix[size],postfix[size];
    s1.top = -1;
    printf("Infix Expression: ");
    scanf("%s",infix);
    reverse(infix,postfix);
    // ifxtpfx(infix,postfix);
    printf("Postfix Expression: ");
    printf("%s\n",postfix);
    return 0;
}