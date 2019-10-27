#include<stdio.h>
#include<stdlib.h>

struct node{
    int val;
    struct node* next;
    struct node* prev;
}*start,*ptr;

struct data{
    int large;
    int small;
}st;

int count;
int pos;

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
    if(start == NULL || count <= 0){
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
        }
        else{
            temp = start->prev;
            ptr->val = val2;
            ptr->next = start;
            ptr->prev = temp;
            temp->next = ptr;
            start->prev = ptr;
        }
        count++;
        printf("\nALERT: Value/Node Inserted Sucessfully\n");
    }
}

void delete(){
    struct node *tmp,*tmp2;
    if(is_empty() == 1){
        printf("\nWARNING: List is empty!\n");
    }
    else{
        tmp = start->prev;
        tmp2 = tmp->prev;
        printf("\nALERT: Value >%d< Deleted\n",tmp->val);
        start->prev = tmp->prev;
        tmp2->next = start;
        free(tmp);
        count--;
        if(count <= 0){
            start = NULL;
        }
    }
}

void display(){
    int i;
    struct node *tmp;
    tmp = start;
    printf("\n#################################\n#  Printing the Values Stored   #\n#################################");
    for(i=0;i<count;i++){
        printf("\n#\t\t%d\t\t#",tmp->val);
        tmp = tmp->next;
    }
    printf("\n#################################\n");
}

void uptodown(){//wip
    int val1,val2;
    
}

void downtoup(){//wip

}

void mysort(){//wip
    struct node *tmp;
    int i;
    tmp = start;
    if(is_empty() == 1){
        printf("\nALERT: List is Empty!\n");
    }
    else{
        st.large = st.small = start->val;
        for(i=0;i<count;i++){
        //while(pos!=count){
            if(tmp->val > st.large){
                st.large = tmp->val;
            }
            if(tmp->val < st.small){
                st.small = tmp->val;
            }
            tmp = tmp->next;
            //pos++;
        }

        printf("\nLargest: %d\n\nSmallest: %d\n",st.large,st.small);
    }
}

void main(){
    int ch;
    count = pos = 0;
    st.large = st.small = 0;
    start = NULL;
    for(;;){
        printf("\nLink List Operations\n\n1: Insert\n2: Delete\n3: Diplay\n4: Sort\n5: Exit\nEnter Your Choice: ");
        scanf("%d",&ch);
        // switch(ch){
        //     case 1: insert();
        //     break;

        //     case 2: delete();
        //     break;

        //     case 3: display();
        //     break;

        //     case 4: mysort();
        //     break;

        //     case 5: exit(1);
            
        //     default: printf("\nWarning: Invalid Choice\n");
        // }


        // Desi Style :P
        if(ch == 1){
            insert();
        }
        else if(ch == 2){
            delete();
        }
        else if(ch == 3){
            display();
        }
        else if(ch == 4){
            mysort();
        }
        else if(ch == 5){
            exit(1);
        }
        else{
            printf("\nWarning: Invalid Choice\n");
        }
    }
}

