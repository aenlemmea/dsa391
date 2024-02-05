#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int info;
	struct node* next;
} node;

node* create(node* h, int N)
{
	node* newn, * temp;
	int i, item;

	if (h != NULL)
	{
		printf("List already exists\n");
		return h;
	}

	for (i = 1; i <= N; i += 1)
	{
		printf("\nEnter item: ");
		scanf("%d", &item);

		newn = (node*)malloc(sizeof(node));
		newn->info = item;
		newn->next = NULL;
		if (h == NULL)
		{
			h = newn;
		}
		else
		{
			temp->next = newn;
		}

		temp = newn;
	}

	return h;
}

void insert_after(node* last, int item)
{
	if (last == NULL)
	{
		printf("%s\n", "\nThe List does not exist. Exiting...");
		return;
	}

	node* p = (node*)malloc(sizeof(node));
	p->info = item;
	p->next = NULL;

	for (; last->next != NULL; last = last->next);

	last->next = p;
}

node* insert_before(node* h, int item)
{
	node* p = (node*)malloc(sizeof(node));
	p->next = h;
	p->info = item;

	return p;
}

void traverse(node* h)
{
	node* p = h;
	for (; p != NULL; p = p->next)
	{
		printf("Value = %5d Address = %p Next Address = %p\n", p->info, p, p->next);
	}
}

node* delete_begin(node* head)
{
	node* ptr;
	if (head == NULL)
	{
		printf("List doesn't exists.\n");
		return head;
	}

	ptr = head;
	head = head->next;
	free(ptr);
	return head;
}

node* delete_after(node* head)
{
	node* ptr, * preptr;
	if (head == NULL)
	{
		printf("List doesn't exist.\n");
		return head;
	}

	ptr = head;

	while (ptr->next != NULL)
	{
		preptr = ptr;
		ptr = ptr->next;
	}

	preptr->next = NULL;
	free(ptr);
	return head;
}

int count(node* head)
{
	int n = 0;
	node* p = head;
	if (p == NULL)
	{
		return 0;
	}
	else
	{
		for (; p != NULL; p = p->next)
		{
			n++;
		}

		return n;
	}
}

node* reverse(node* head)
{
	node* t, * y = head, * r = NULL;
	while (y != NULL)
	{
		t = y->next;
		y->next = r;
		r = y;
		y = t;
	}

	return r;
}

node* insert_any(node* h, int location, int item)
{
	int c = 0, m = count(h);
	node* p = h;
	node* r = p;
	node* q = (node*)malloc(sizeof(node*));

	if (h == NULL)
	{
		printf("List doesn't exists\n");
		return r;
	}

	if (location == 0)
	{
		r = insert_before(h, item);
		return r;
	}

	if (location < m)
	{
		for (; p != NULL; p = p->next)
		{
			c++;
			if (c == location - 1)
			{
				break;
			}
		}

		q->next = p->next;
		p->next = q;
		q->info = item;
	}
	else if (location == (m - 1))
	{
		insert_after(h, item);
	}
}

node* delete_any(node* h, int location)
{
	int c = 0, m = count(h);
	node* p = h;
	node* r = p;
	node* x = (node*)malloc(sizeof(node*));

	if (location == 0)
	{
		return delete_begin(h);
	}

	if (location < m)
	{
		for (; p != NULL; p = p->next)
		{
			c++;
			if (c == location - 1)
			{
				break;
			}
		}

		x = p->next;
		p->next = p->next->next;
		free(x);
	}
	else if (location == m)
	{
		r = delete_after(h);
	}

	return r;
}

void sort(node* head)
{
	node* ptr, * cpt;
	int temp;
	ptr = head;
	while (ptr != NULL)
	{
		cpt = ptr->next;
		while (cpt != NULL)
		{
			if (ptr->info > cpt->info)
			{
				temp = ptr->info;
				ptr->info = cpt->info;
				cpt->info = temp;
			}
			cpt = cpt->next;
		}
		ptr = ptr->next;
	}
}

void search(node* head, int item)
{
	node* loc = head;
	int flag = 0, c = 0;
	while (loc != NULL)
	{
		c++;
		if (item == loc->info)
		{
			flag = 1;
			break;
		}
		loc = loc->next;
	}

	if (flag)
	{
		printf("\nFound item at %d\n", c);
	}
	else
	{
		printf("\nCannot find item\n");
	}
}

int main()
{
	int choice, N, item, location = 0;
	node* head = NULL;

	while (1)
	{
		printf("\n\nWelcome to Linked List Operations:\n");
		printf("Please create the list to continue\n");
		printf("Enter your choice of operations:\n\n");

		printf("\n\n0. Exit. \n1. Create the linked list. \n2. Insert a node after the linked list. \n3. Insert a node before the linked list. \n4. Traverse and print the content of the list. \n5. Delete the first element. \n6. Delete the last element. \n7. Reverse the list. \n8. Sort the List. \n9. Count the number of nodes \n10. Insert an element at a specific location \n11. Delete a node of a specific location \n12. Search for an item in the list. \n\n");

		scanf("%d", &choice);
		switch (choice)
		{
		case 0:
			exit(0);
		case 1:
			printf("\nEnter the number of elements you want to add:\n\n");
			scanf("%d", &N);
			head = create(head, N);
			break;
		case 2:
			printf("\nEnter the item you want to add:\n");
			scanf("%d", &item);
			insert_after(head, item);
			item = 0;
			break;
		case 3:
			printf("\nEnter the item you want to add:\n");
			scanf("%d", &item);
			head = insert_before(head, item);
			item = 0;
			break;
		case 4:
			printf("\n");
			traverse(head);
			break;
		case 5:
			head = delete_begin(head);
			printf("Done\n");
			break;
		case 6:
			head = delete_after(head);
			printf("Done\n");
			break;
		case 7:
			head = reverse(head);
			printf("Done\n");
			break;
		case 8:
			sort(head);
			printf("Done\n");
			break;
		case 9:
			printf("\nThe number of nodes are %d\n", count(head));
			break;
		case 10:
			printf("\nWhat item do you want to add?\n");
			scanf("%d", &item);
			printf("\nWhat location do you want to add the item?\n");
			scanf("%d", &location);
			head = insert_any(head, location, item);
			location = item = 0;
			printf("\nDone!\n");
			break;
		case 11:
			printf("\nWhat location do you want to delete the item?\n");
			scanf("%d", &location);
			head = delete_any(head, location);
			location = 0;
			printf("\nDone!\n");
			break;
		case 12:
			printf("\nWhat item do you want to search for?\n");
			scanf("%d", &item);
			search(head, item);
			break;
		default:
			break;
		}
	}

	return 0;
}