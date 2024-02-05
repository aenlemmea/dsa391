#include <stdio.h>
#include <stdlib.h>

#define MAX 5
int top = -1;

int stack[MAX];

void push() {
	int item;
	printf("Enter item: \n");
	scanf("%d", &item);

	if (top == MAX - 1) {
		printf("Stack Overflow.");
	}
	else {
		stack[++top] = item;
	}
}

void pop() {
	if (top == -1) {
		printf("Stack Underflow");
	}
	else {
		printf("%d", stack[top]);
		top -= 1;
	}
}
void display() {
	int i;
	if (top == -1) {
		printf("Stack Underflow");
	}
	else {
		for (i = top; i >= 0; i--)
		{
			printf("%7d", stack[i]);
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
	return 0;
}