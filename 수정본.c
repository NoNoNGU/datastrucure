#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct hanoi {
	int n;
	char from;
	char via;
	char destination;
}hanoi;

typedef struct StackNode {
	hanoi data;
	struct StackNode* link;
} StackNode;

typedef struct {
	StackNode* top;
	int size;
} LinkedStackType;

void init(LinkedStackType* s)
{
	s->top = NULL;
	s->size = 0;
}

int is_empty(LinkedStackType* s)
{
	return (s->top == NULL);
}

void push(LinkedStackType* hanoi,int n,char from,char via,char destination )
{
	StackNode* newnode = (StackNode*)malloc(sizeof(StackNode));
	newnode->data.n = n;
	newnode->data.from = from;
	newnode->data.via = via;
	newnode->data.destination = destination;

	newnode->link = hanoi->top;
	hanoi->top = newnode;
	hanoi->size++;
}

void print_stack(LinkedStackType* s)
{
	for (StackNode* p = s->top; p != NULL; p = p->link)
		printf("n:%d, from:%c, via=%c , destination=%c -> ", p->data.n, p->data.from, p->data.via, p->data.destination);
	printf("NULL\n");
}

void pop(LinkedStackType* hanoi)
{
	if (is_empty(hanoi)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		StackNode* topnode = hanoi->top;
		hanoi->top = topnode->link;
		hanoi->size--;
		free(topnode);
		//return topnode;
	}
}

int main(void)
{
	LinkedStackType s;
	init(&s);
	push(&s, 3, 'A', 'B', 'C'); print_stack(&s);
	push(&s, 2, 'A', 'C', 'B'); print_stack(&s);
	push(&s, 1, 'A', 'B', 'C'); print_stack(&s);
	pop(&s); print_stack(&s);
	push(&s, 1, 'C', 'A', 'B'); print_stack(&s);
	pop(&s); print_stack(&s);
	pop(&s); print_stack(&s);
	push(&s, 2, 'B', 'A', 'C'); print_stack(&s);
	push(&s, 1, 'B', 'C', 'A'); print_stack(&s);
	pop(&s); print_stack(&s);
	push(&s, 1, 'A', 'B', 'C'); print_stack(&s);
	pop(&s); print_stack(&s);
	pop(&s); print_stack(&s);
	return 0;
}
