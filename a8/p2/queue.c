/* 
   CH-230-A 
   a8_p2.c
   Rumen Mitov
   rmitov@jacobs-university.de 
*/


/**
 * @file queue.c
 */

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

void initialize_queue(Queue *pq)
{
	pq->front = pq->rear = NULL;
	pq->items = 0;
}

int queue_is_full(const Queue *pq)
{
	return pq->items == MAXQUEUE;
}

int queue_is_empty(const Queue *pq)
{
	return pq->items == 0;
}

int queue_item_count(const Queue *pq)
{
	return pq->items;
}

int enqueue(Item item, Queue *pq)
{
        // instantiate new node
        Node* newEl = (Node*) malloc(sizeof(Node));
        if (!newEl) 
        {
            printf("Memory allocation failed.\n");
            exit(1);
        }

        newEl->item = item;
        newEl->next = NULL;

        // add new node to queue

        if (queue_is_empty(pq)) 
        {
            pq->front = newEl;
            pq->rear = newEl;
            pq->items++;

            return 0;
        }

        pq->rear->next = newEl;
        pq->rear = newEl;
        pq->items++;

        return 0;
}

int dequeue(Item *pitem, Queue *pq)
{
        // instantiate node to be deleted
        Node* marker = pq->front;

        // shift front pointer
        pq->front = pq->front->next;

        // record and delete node
        *pitem = marker->item;
        free(marker);
        marker = NULL;

        pq->items--;

        // reset queue if empty
        if (queue_is_empty(pq)) 
        {
            pq->front = pq->rear = NULL;
        }

        return 0;
}

void empty_queue(Queue *pq)
{
    // implement this as well
	Item dummy;
	while (!queue_is_empty(pq)) 
    {
		dequeue(&dummy, pq);
	}
}
