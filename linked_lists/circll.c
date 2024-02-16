#include <stdio.h>
#include <stdlib.h>

struct node {
	int info;
	struct node* next;
};

struct node* insertbegin(struct node* head) {
	struct node* temp, * ptr;
	int item;

	if (head != NULL) {
		printf("List already exists.");
		return;
	}

	printf("\nEnter item: ");
	scanf("%d", &item);

	temp = (struct node*)malloc(sizeof(struct node));
	temp->info = item;
	temp->next = head;

	ptr = head;
	while (ptr->next != head) {
		ptr = ptr->next;
	}
	ptr->next = temp;
	head = temp;
	return head;
}
struct node* insertend(struct node* head) {
	struct node* temp, * ptr;
	int item;

	if (head != NULL) {
		printf("List already exists.");
		return;
	}

	printf("\nEnter item: ");
	scanf("%d", &item);

	temp = (struct node*)malloc(sizeof(struct node));
	temp->info = item;
	temp->next = head;

	ptr = head;

	while (ptr->next != head) {
		ptr = ptr->next;
	}
	
	ptr->next = temp;
	return head;
}

struct node* deletebegin(struct node* head) {
	struct node* ptr;
	
	if (head == NULL) {
		printf("List doesn't exist.");
		return;
	}

	while (ptr->next != head) {
		ptr = ptr->next;
	}
	
	ptr->next = head->next;
	free(head);
	head = ptr->next;
	return head;
}

struct node* deleteend(struct node* head) {
	struct node* ptr, * prevptr;

	if (head == NULL) {
		printf("List doesn't exist.");
		return;
	}

	ptr = head;
	prevptr = head;


	while (ptr->next != head) {
		prevptr = ptr;
		ptr = ptr->next;
	}
	prevptr->next = head;
	free(ptr);
	return head;
}

void traverse(struct node* head) {
	struct node* ptr;
	if (ptr == NULL) {
		printf("List doesn't exist.");
		return;
	}
	ptr = head;

	for (; ptr->next != head; ptr = ptr->next) {
		printf("\nINFO: %d Current Address: %p Next Address: %p", ptr->info, ptr, ptr->next);
	}
}

int main() {
	struct node* head = NULL;
	head = insertbegin(head);
	head = insertbegin(head);
	traverse(head);
	return 0;
}