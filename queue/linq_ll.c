#include <stdio.h>
#include <stdlib.h>

struct node {
	int info;
	struct node* next;
};

struct node* front = NULL, * rear = NULL;

void enqueue() { 
	int item;
    printf("\nEnter item:");
    scanf("%d", &item);
    
    struct node* newn = (struct node*)malloc(sizeof(struct node));
    newn->info = item;
    newn->next = NULL;

    if ((front == NULL) && (rear == NULL)) {
        front = rear = newn;
    }
    else {
        rear->next = newn;
        rear = newn;
    }
}
void dequeue() {
    struct node* temp;
    temp = front;
    if ((front == NULL) && (rear == NULL)) {
        printf("Queue is Empty");
    }
    else {
        front = front->next;
        free(temp);
    }
}
void display() {
    struct node* temp;
    if ((front == NULL) && (rear == NULL)) {
        printf("Queue is Empty");
    }
    else {
        temp = front;
        while (temp) {
            printf("%7d", temp->info);
            temp = temp->next;
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n\n1. Enqueue\n2. Dequeue \n3. Display \n4. Exit");
        printf("\nEnter your choice: \n");
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
            continue;
        }
    }
}