#include<stdio.h>
#include<stdlib.h>

struct node{
    int val;
    struct node* left;
    struct node* right;
}*root,*son;

struct node* getnode(int x){
    struct node* tmp;
    tmp = (struct node*)malloc(sizeof(struct node));
    if(tmp == NULL){
        printf("\nERROR: Memory Allocation Unsuccessful!\n");
        exit(1);
    }
    else{
        tmp->val = x;
        tmp->left = NULL;
        tmp->right = NULL;
        return tmp;
    }
}

struct node* search(struct node* _root, int _key){
    if(_root == NULL){
        _root = getnode(_key);
    }

    if(_root->val < _key){
        _root->right = search(_root->right, _key);
    }
    else if(_root->val > _key){
        _root->left = search(_root->left, _key);
    }
}

void insert(){
    int dat;
    printf("\nEnter The Value To Store!\n");
    scanf("%d",&dat);
    search(root,dat);
    printf("\nInserted Sucessfully!\n");
}


void traverse(struct node* _root){
    if (_root != NULL) { 
        traverse(_root->left); 
        printf("%d \n", _root->val); 
        traverse(_root->right);
    }
}
// void insert();
// void delete();
// void traverse();

void main(){
    root = son = NULL;
    int ch;
    for(;;){
        printf("\nBinary Search Tree\n\n1: Insert\n2: Delete\n3: Traverse\n4: Exit\nEnter Your Choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: insert();
            break;

            // case 2: delete();
            // break;

            case 3: traverse(root);
            break;

            case 4: exit(1);
            break;

            default: printf("\nInvalid Choice\n");
            //exit(1);
            break;
        }
    }
}