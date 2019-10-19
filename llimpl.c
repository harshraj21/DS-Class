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
	if(start == NULL || top <= 0){
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

int error(int n){ //till now not implemented this part
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
		printf("\nEnter The Position in between 0 - %d: ",top);
		scanf("%d",&n);
		if(n>top || n<0){
			printf("\nAlert: Invalid Position\n");
			return;
		}
		for(i=0;i<n-1;i++){
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

void del_st(){
	struct node* tmp;
	if(is_empty() == 1){
		printf("\nWARNING: List is Empty\n");
	}
	else{
		tmp = start;
		start = start->next;
		printf("\nALERT: Value >%d< Deleted Sucessfully\n",tmp->val);
		if(top <= 0){
			start = NULL;
		}
		free(tmp);
		top--;
	}
}

void del_end(){
	struct node* tmp,*tmp2;
	if(is_empty() == 1){
		printf("\nWARNING: List is Empty\n");
	}
	else{
		tmp = start;
		while(tmp->next != NULL){
			tmp2 = tmp;
			tmp = tmp->next;
		}
		if(tmp == start){
			start = NULL;
		}
		else{
			tmp2->next = NULL;
		}
		printf("\nALERT: Value >%d< Deleted Sucessfully\n",tmp->val);
		free(tmp);
		top--;
	}
}

void del_val(){
	struct node* tmp,*tmp2,*tmp3;
	int val2;
	if(is_empty() == 1){
		printf("\nWARNING: List is Empty\n");
	}
	else{
		printf("\nEnter The Value To Delete: ");
		scanf("%d",&val2);
		tmp = start;
		while(tmp->val!=val2){
			tmp2 = tmp;
			tmp = tmp->next;
		}
		if(tmp->val == val2){
			printf("\nALERT: Value Found And Deleted Sucessfully!\n");
			if(top == 1){
				start = start->next;
				free(tmp);
			}
			else{
				tmp3 = tmp->next;
				if(tmp == start){
					start = NULL;
				}
				else{
					tmp2->next = tmp3;
				}
				free(tmp);
			}
			top--;
		}
		else{
			printf("\nALERT: Value Not Found!\n");
		}
	}
}

void del_n(){ //This part is incomplete
	struct node* tmp;
	int n,i;
	if(is_empty() == 1){
		printf("\nWARNING: List is Empty\n");
	}
	else{
		printf("\nEnter The Position in between 0 - %d: ",top);
		scanf("%d",&n);
		tmp = start;
		for(i=0;i<n-1;i++){
			tmp = tmp->next;
		}
	}
}

void main(){
	start = NULL;
	top = 0;
	int ch;
	for(;;){
		printf("\nLinked List Implementation\n\n1: Insert at beg.\n2: Insert at end\n3: Insert at nth\n");
		printf("4: Delete at beg.\n5: Delete at end\n6: Delete at nth\n7: Delete by val.\n8: Display\n9: Exit\nEnter Your Choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1: ins_st();
			break;

			case 2: ins_end();
			break;
	
			case 3: ins_n();
			break;

			case 4: del_st();
			break;

			case 5: del_end();
			break;

			//case 6: del_n();
			//break;

			case 7: del_val();
			break;

			case 8: display();
			break;

			case 9: exit(1);

			default: printf("\nALERT: Invalid Choice\n");
		}
	}
}





// Completed parts are working superfine <_> Enjoy




// Made By - HARSH RAJ
// Data Structures Using C
// Work in progress















