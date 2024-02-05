#include <stdio.h>
#include <stdlib.h>

#define CQMAX 5
int CQ[CQMAX];
int front = -1,  rear = -1;

int isFull() {
	return (front == (rear + 1) % CQMAX);
}
int isEmpty() {
	return front == -1;
}
void enqueue() {
	int item;
	if (isFull()) {
		printf("Queue Overflow");
	}
	else {
		printf("\nEnter item:");
		scanf("%d", &item);
		if (front == -1) {
			front = 0;
		}
		rear = ((rear + 1) % CQMAX);
		CQ[rear] = item;
	}
}

void dequeue() {
	int item;
	if (isEmpty()) {
		printf("Queue Underflow");
	}
	else {
		item = CQ[front];
		if (front == rear) {
			front = rear = -1;
		}
		else {
			front = ((front + 1) % CQMAX);
		}
	}
}
void display() {
	int i;
	if (isEmpty()) {
		printf("Queue is Empty");
	}
	else {
		for (i = front ; i != rear; i = (i+1) % CQMAX)
		{
			printf("%d ", CQ[i]);
		}
		printf("%d\n\n", CQ[i]);
	}
}

int main() {
	int choice;
	
	while (1) {
		printf("\n\n1. Enqueue\n2. Dequeue \n3. Display \n4. Exit");
		printf("\nEnter your choice:");
		scanf("%d", &choice);

		switch (choice) {
		case 1: 
			enqueue();
			break;
		case 2:
			dequeue();
			break;
		case 3:
			display();
			break;
		case 4:
			exit(0);
		default:
			printf("Please enter a valid choice [1-4]");
		}
	}
}