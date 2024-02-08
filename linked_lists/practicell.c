#include <stdio.h>
#include <stdlib.h>

struct node {
	int info;
	struct node* next;
};

struct node* create(struct node* head, int N) {
	struct node* temp, * newn;
	int i, item;
	
	if (head != NULL) {
		printf("List Not Empty");
		return head;
	}

	for (i = 0; i < N; i++)
	{
		newn = (struct node*)malloc(sizeof(struct node));
		printf("Enter item: ");
		scanf("%d", &item);
		newn->info = item;
		newn->next = NULL;

		if (head == NULL) {
			head = newn;
		}
		else {
			temp->next = newn;
		}
		temp = newn;
	}
	return head;
}
void traverse(struct node* head) {
	struct node* temp;

	if (head == NULL) {
		printf("EMPTY LIST");
	}
	else {
		temp = head;
		for (; temp != NULL; temp = temp->next) {
			printf("\nINFO: %d Current Address: %p Next Address: %p", temp->info, temp, temp->next);
		}
	}
}
struct node* reverse(struct node* head) {
	struct node *t,  * y = head, *r = NULL;

	while (y != NULL) {
		t = y->next;
		y->next = r;
		r = y;
		y = t;
	}
	return r;
}

int main() {
	struct node* head = NULL;
	head = create(head, 5);
	traverse(head);
	printf("\n\nREVERSE: \n");
	head = reverse(head);
	traverse(head);
}