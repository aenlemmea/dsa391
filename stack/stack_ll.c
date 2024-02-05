#include <stdio.h>
#include <stdlib.h>


struct node {
	int info;
	struct node* next;
} *top;

void push() {
	int item;
	printf("Enter item: \n");
	scanf("%d", &item);

	struct node* newn = (struct node*)malloc(sizeof(struct node));
	newn->info = item;
	newn->next = top;
	top = newn;
}
void pop() {
	struct node* temp;
	if (top == NULL) {
		printf("Stack undeflow");
	}
	else {
		temp = top;
		printf("%d", top->info);
		top = top->next;
		free(temp);
	}
}


void display() {
	struct node* temp = top;
	if (top == NULL) {
		printf("Stack Underflow");
	} {
		while (temp != NULL) {
			printf("%7d", temp->info);
			temp = temp->next;
		}
	}
}

int main() {
	int choice;
	while (1) {
		printf("\n\n1. Push \n2. Pop \n3. Display \n4. Exit");
		printf("\nEnter the choice: \n");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			push();
			break;
		case 2:
			pop();
			break;
		case 3:
			display();
			break;
		case 4:
			exit(0);
		default:
			printf("Enter a valid choice between [1-4]\n");
		}
	}
}