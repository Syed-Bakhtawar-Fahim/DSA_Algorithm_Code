#include <stdio.h>
#include <stdlib.h>

struct Queue
{
	int size, front, rear;
	int * arr;
};

int isFull(struct Queue * q)
{
	if((q->rear + 1)%q->size == q->front)
		return 1;
	else
		return 0;
}

int isEmpty(struct Queue * q)
{
	if(q->front == q->rear)
		return 1;
	else
		return 0;
}

void enQueue(struct Queue * q, int value)
{
	if(isFull(q))
	{
		printf("Queue Overflow\n");
	}
	else
	{
		q->rear = (q->rear + 1)% q->size;
		q->arr[q->rear] = value;
		printf("enQueuing value is: %d\n",value);
	}
}

int deQueue(struct Queue * q)
{
	int a = -1;
	if(isEmpty(q))
	{
		printf("No element to deQueue\n");
	}
	else
	{
		q->front = (q->front + 1)% q->size;
		a = q->arr[q->front];
	}
	return a;
}

int main()
{
	struct Queue q;
	q.size = 4;
	q.rear = q.front = 0;
	q.arr = (int *)malloc(q.size * sizeof(int));
	
	
	//enQueue few elements
	enQueue(&q, 12);
	enQueue(&q, 15);
	enQueue(&q, 13);
	
	// deQueue Elements
	printf("Dequeuing element is: %d \n", deQueue(&q));
	printf("Dequeuing element is: %d \n", deQueue(&q));
	printf("Dequeuing element is: %d \n", deQueue(&q));
	
	//enQueue few elements
	enQueue(&q, 12);
	enQueue(&q, 15);
	enQueue(&q, 13);
	
	// Check empty or not
	if(isEmpty(&q))
	{
		printf("Queue is Empty");
	}
	
	// Check full or not
	if(isFull(&q))
	{
		printf("Queue is Full");
	}
}
