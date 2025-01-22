#include "queue.h"
#include "caesar.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

	queue_t queue; 
    	initialize_queue(&queue, print_process);

	int key = 3; // used for caesar cipher

	// create instances of some proccesses
        process_t *p1 = create_process(1, "A");
	process_t *p2 = create_process(2, "B");
        process_t *p3 = create_process(3, "C");

	printf("\nThis program enqueues three process_t elements and then dequeues all three elements.\n");
	printf("Caesar cipher with key=%d is used.\n", key);
        
	// view the process
        printf("\nEnqueue: ");
	print_process(p1);
	// encode the processes
        p1->name = encode(p1->name, key);
	// enqueue the process
        enqueue(&queue, p1);
	//view the queue
        print_queue(&queue);

	// view the process
	printf("\nEnqueue: ");
        print_process(p2);
        // encode the processes
        p2->name = encode(p2->name, key);
        // enqueue the process
        enqueue(&queue, p2);
        //view the queue
        print_queue(&queue);

	// view the process	
	printf("\nEnqueue: ");
        print_process(p3);
        // encode the processes
        p3->name = encode(p3->name, key);
        // enqueue the process
        enqueue(&queue, p3);
        //view the queue
        print_queue(&queue);
	
	printf("\nDequeue: ");
        dequeue(&queue);
	// decode the process
	p1->name = decode(p1->name, key);
	// view the process
        print_process(p1);
	//view the queue
        print_queue(&queue);

	printf("\nDequeue: ");
	dequeue(&queue);
	// deocode the process
        p2->name = decode(p2->name, key);
	// view the process
        print_process(p2);
        //view the queue
        print_queue(&queue);

	//remove process from the queue
	printf("\nDequeue: ");
	dequeue(&queue);
	// decode the process
        p3->name = decode(p3->name, key);
	// view the process
        print_process(p3);
        //view the queue
        print_queue(&queue);
	printf("\n");

	return(0); // exit gracefullt
}
