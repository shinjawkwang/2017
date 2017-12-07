#define MAX_STACK 100
#define MAX_QUEUE 100

typedef enum { false, true } bool;

typedef struct {
	int items[MAX_STACK];
	int top;
} Stack;

typedef struct {
	int front, rear;
	int items[MAX_QUEUE];
} Queue;

void InitStack(Stack *pstack) {
	pstack->top = -1;
}

bool IsSFull(Stack *pstack) {
	return pstack->top == MAX_STACK - 1;
}

bool IsSEmpty(Stack *pstack) {
	return pstack->top == -1;
}

int SPeek(Stack *pstack) {
	if (IsSEmpty(pstack))
		exit(1); //error: empty stack
	return pstack->items[pstack->top];
}

void Push(Stack *pstack, int item) {
	if (IsSFull(pstack))
		exit(1); //error: stack full
	pstack->items[++(pstack->top)] = item;
}

void Pop(Stack *pstack) {
	if (IsSEmpty(pstack))
		exit(1); //error: empty stack
	--(pstack->top);
}

void InitQueue(Queue *pqueue) {
	pqueue->front = pqueue->rear = 0;
}

bool IsQFull(Queue *pqueue) {
	return pqueue->front == (pqueue->rear + 1) % MAX_QUEUE;
}

bool IsQEmpty(Queue *pqueue) {
	return pqueue->front == pqueue->rear;
}

int QPeek(Queue *pqueue) {
	if (IsQEmpty(pqueue))
		exit(1); //error: empty stack
	return pqueue->items[pqueue->front];
}

void EnQueue(Queue *pqueue, int item) {
	if (IsQFull(pqueue))
		exit(1); //error: stack full
	pqueue->items[pqueue->rear] = item;
	pqueue->rear = (pqueue->rear + 1) % MAX_QUEUE;
}

void DeQueue(Queue *pqueue) {
	if (IsQEmpty(pqueue))
		exit(1); //error: empty stack
	pqueue->front = (pqueue->front + 1) % MAX_QUEUE;
}
