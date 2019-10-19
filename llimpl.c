#include<stdio.h>
#include<stdlib.h>

struct node{
	int val;
	struct node* next;
}*ptr,*start;

int top;

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
	if(start == NULL || top <= 1){
		return(1);	
	}
	else{
		return(0);
	}
}

void ins_st(){
	int val2;
	if(is_full() == 1){
		printf("\nWarning: Memory is FUll\n");
	}
	else{
		ptr = (struct node*)malloc(sizeof(struct node));
		printf("\nEnter The Value to Store: ");
		scanf("%d",&val2);
		if(is_empty() == 1){
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
		printf("\nALERT: Value Inserted Sucessfully!\n");
	}
}

void ins_end(){
	int val2;
	struct node* tmp;
	tmp = start;
	if(is_full() == 1){
		printf("\nWarning: Memory is FUll\n");
	}
	else{
		ptr = (struct node*)malloc(sizeof(struct node));
		printf("\nEnter The Value to Store: ");
		scanf("%d",&val2);
		if(is_empty() == 1){
			ptr->val = val2;
			ptr->next = NULL;
			start = ptr;
		}
		else{
			while(tmp->next != NULL){
				tmp = tmp->next;			
			}
			ptr->val = val2;
			ptr->next = NULL;
			tmp->next = ptr;
		}
		top++;
		printf("\nALERT: Value Inserted Sucessfully!\n");
	}
}

int error(int n){
	int i;
	struct node* tmp;
	tmp = start;
	for(i=0;i<n;i++){
		if(tmp == NULL){
			return i;		
		}
		tmp = tmp->next;
	}
}

void ins_n(){
	int val2,n,i;
	struct node *tmp,*tmp2;
	tmp = start;
	if(is_full() == 1){
		printf("\nWarning: Memory is FUll\n");
	}
	else{
		ptr = (struct node*)malloc(sizeof(struct node));
		printf("\nEnter The Value to Store: ");
		scanf("%d",&val2);
		printf("\nEnter The Position in between 1 - %d: ",top);
		scanf("%d",&n);
		if(n>top || n<1){
			printf("\nAlert: Invalid Position\n");
			return;
		}
		for(i=0;i<n;i++){
			tmp = tmp->next;
		}
		if(is_empty() == 1){
			ptr->val = val2;
			ptr->next = NULL;
			start = ptr;
		}
		else{
			ptr->val = val2;
			tmp2 = tmp->next; 
			tmp->next = ptr;
			ptr->next = tmp2;
		}
		top++;
		printf("\nALERT: Value Inserted Sucessfully!\n");
	}
}

void display(){
	struct node* tmp;
	tmp = start;
	printf("\n\nPrinting The Stored Value\n****************************\n");
	while(tmp!=NULL){
		printf("%d\n",tmp->val);
		tmp = tmp->next;
	}
	printf("****************************\n\n");
}

void main(){
	start = NULL;
	top = 1;
	int ch;
	for(;;){
		printf("\nLinked List Implementation\n\n1: Insert at beg.\n2: Insert at end\n3: Insert at nth\n");
		printf("4: Delete at beg.\n5: Delete at end\n6: Delete at nth\n7: Display\n8: Exit\nEnter Your Choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1: ins_st();
			break;

			case 2: ins_end();
			break;
	
			case 3: ins_n();
			break;

			//case 4: del_st();
			//break;

			//case 5: del_end();
			//break;

			//case 6: del_n();
			//break;

			case 7: display();
			break;

			case 8: exit(1);

			default: printf("\nALERT: Invalid Choice\n");
		}
	}
}






















