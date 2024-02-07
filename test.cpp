#include <stdio.h>

int main() {
	printf("Hello!");
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
		printf("Here!!!!!!!!");
	}
	else if (location == (m - 1))
	{
		insert_after(h, item);
	}
	return r;
}