#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "queue.h"

/**
 * Prints a process.
 *
 * @param data A pointer to the process to print.
 */
void print_process(void *process);

/**
 * Adds an element to the end of the queue.
 *
 * @param queue The queue to which the element will be added.
 * @param element The element to be added to the queue.
 */
void enqueue(queue_t *queue, void *element) {
	
	// allocate memory for node
	node_t *node = malloc(sizeof(node_t));

	// populate the node with data
	node->data = element;
	node->next = NULL; // there is no next node so we set that to NULL

	// if queue is empty
	if (queue->first == NULL) {
		// this node will be the first and last
		queue->first = node;
		queue->last = node;
	} else { // if queue is not empty
		queue->last->next = node; // add this node to the end of the queue 
		queue->last = node; // tell the queue that this is now the last node
	}

	// we added a node so the queue grew by one
	queue->size++;
}

/**
 * Removes and returns the element at the front of the queue.
 *
 * @param queue The queue to modify.
 * @return The data removed from the front of the queue, or NULL if the queue is empty.
 */
void * dequeue(queue_t *queue) {
	
	// if there is nothing in the queue
	if (queue->size == 0 || queue == NULL) {
		return NULL;
	}

	// get the data of the first node (which we will return)
	node_t *first = queue->first;
	void *data = first->data;

	// update the state of queue struct
	queue->first = first->next;
	queue->size --;

	// free allocated mememory of the dequeued node
	free(first);
	
	return data;
}

/**
 * Prints the elements of the queue to the console.
 *
 * @param queue The queue whose elements will be printed.
 */
void print_queue(queue_t *queue) {
	
	// create a pointer to the next element of the queue
	node_t *next = queue->first;

	printf("\nQueue: ");
	if (next == NULL) {
		printf("[]");
	}

	while(next != NULL) {
		// print data inside the node
		queue->print_data(next->data);

		// increment to the next node
		next = next->next;

		// if this is not the last node
		if(next != NULL) {
			printf(" -> ");
		}
	}
	printf("\n");

}

/**
 * Creates an instance of the process struct.
 *
 * @param identifier The process ID.
 * @param name The name of the process.
 * @return A pointer to the created process.
 */
process_t *create_process(int identifier, char *name) {

	process_t *process = malloc(sizeof(process_t));
	process->identifier = identifier;
	process->name = name;
	return process;
}

/**
 * Prints a process.
 *
 * @param data A pointer to the process to print.
 */
void print_process(void *data) {
	if (data == NULL) {
		return;
	}
	 // cast void pointer to process_t pointer
    	process_t *process = (process_t *)data;
	printf("[id: %d, name: %s]", process->identifier, process->name);
}

/**
 * Initializes the queue.
 *
 * @param queue Pointer to the queue to initialize.
 * @param print_func Function to print queue data.
 */
void initialize_queue(queue_t *queue, void (*print_func)(void *)) {
    queue->first = NULL;
    queue->last = NULL;
    queue->size = 0;
    queue->print_data = print_func; // Set the function pointer
}
