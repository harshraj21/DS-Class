#include<stdio.h>
#include<stdlib.h>

/*struct node{
	int val;
	struct node *next;
};*/

#define size 50

struct queue{
	int front;
	int rear;
	int arr[size];
}q1;

int isFull(){
	if(q1.front == 0 && q1.rear == size-1)
		return 1;
	else
		return 0;
}

int isEmpty(){
	if(q1.front == -1)
		return 1;
	else
		return 0;
}

void Insert(){
	int element;

	if(isFull() == 1){
		printf("\nQueue is Full\n");
		return;
	}
	else{
		if(q1.front == -1)
			q1.front = 0;
		printf("Value To Push: ");
		scanf("%d",&element);
		//getc(element);		
		q1.rear++;
		q1.arr[q1.rear] = element;
		printf("\nInsertion Was Sucessfull!\n");
		return;
	}

}

void Delete(){
	int element;

	if(isEmpty() == 1){
		printf("\nQueue is empty!\n");
		return;
	}
	else{
		element = q1.arr[q1.front];
		if(q1.front >= q1.rear){
			q1.front = -1;
			q1.rear = -1;
		}
		else{
			q1.front++;
		}
		printf("\nDeletion was sucessful!\nElement %d Was Deleted\n",element);
		return;
	}
}

void Prt(){
	int i;
	
	if(isEmpty()){
		printf("\nQueue is empty!\n");
		return;
	}
	else{
		printf("\nStored Data\n\n");
		for(i=0;i<=q1.rear;i++){
			printf("%d",q1.arr[i]);
		}
		printf("\n");
		return;
	}
}

void main(){
	int ch;
	q1.front = -1;
	q1.rear = -1;
	while(1){
		printf("\n\n1: Insert\n2: Delete\n3: Print\n4: Exit\n\nEnter A Choice: ");
		scanf("%d",&ch);
		//ch = toupper(ch);
		switch(ch){
			case 1: Insert();
					break;
			case 2: Delete();
					break;
			case 3: Prt();
					break;
			case 4: exit(1);
					break;
			default: printf("\nInvalid Choice!\nTry Again!\n");
					break;
		}
	}
}










































