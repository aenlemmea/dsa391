#include <stdio.h>
#include <stdlib.h>

#define MAX 5
int top = -1;

// circular ll, searching, mergesort, bst 

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
		printf("PUSHED");
	}
}

void pop() {
	if (top == -1) {
		printf("Stack Underflow");
	}
	else {
		printf("POP: %d", stack[top]);
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

void display_top() {
	if (top == -1) {
		printf("Stack Underflow.");
	}
	else {
		printf("STACK TOP: %d\n", stack[top]);
	}
}

int main() {
	int choice;
	while (1) {
		printf("\n\n1. Push \n2. Pop \n3. Display \n4. Display Top \n5. Exit");
		printf("\nEnter the choice: \n");
		if (scanf("%d", &choice) != 1) {
			while (getchar() != '\n');
			printf("Invalid input. Please enter a number between 1 and 5.\n");
			continue;
		}
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
			display_top();
			break;
		case 5:
			exit(0);
		default:
			printf("Enter a valid choice between [1-5]\n");
		}
	}
	return 0;
}