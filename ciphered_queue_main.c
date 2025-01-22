#include "queue.h"
#include "caesar.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

        // create an instance of an empty queue
        queue_t queue;
        queue.first = NULL;
        queue.last = NULL;
        queue.size = 0;
        queue.print_data = print_process; // this is setting the function we will use to print the data
        // since we have a queue of process_t, we have written a function to print a process_t

	// initialize data
	int key = 3; // used for caesar cipher

	// create instances of some proccesses
        process_t *p1 = create_process(1, "A");
	process_t *p2 = create_process(2, "B");
        process_t *p3 = create_process(3, "C");

	printf("\nThis program enqueues three process_t elements and then dequeues all three elements.\n");
	printf("Caesar cipher with key=%d is used.\n\n", key);
        
	// add proccess to the queue
        printf("Enqueue: ");
        print_process(p1);
        printf("\n");
	// encode the processes
        p1->name = encode(p1->name, key);
	// enque the process
        enqueue(&queue, p1);
	//view the queue
        printf("Queue: ");
        print_queue(&queue);

        printf("Enqueue: ");
        print_process(p2);
        printf("\n");
        // encode the processes
        p2->name = encode(p2->name, key);
        // enque the process
        enqueue(&queue, p2);
        //view the queue
        printf("Queue: ");
        print_queue(&queue);
	
	// add proccess to the queue
        printf("Enqueue: ");
        print_process(p3);
	printf("\n");
        // encode the processes
        p3->name = encode(p3->name, key);
        // enque the process
        enqueue(&queue, p3);
        //view the queue
        printf("Queue: ");
        print_queue(&queue);
	
	//remove process from the queue
        dequeue(&queue);
	printf("Dequeue: ");
	p1->name = decode(p1->name, key);
        print_process(p1);
        printf("\n");
	//view the queue
        printf("Queue: ");
        print_queue(&queue);

	//remove process from the queue
	dequeue(&queue);
        printf("Dequeue: ");
        p2->name = decode(p2->name, key);
        print_process(p2);
        printf("\n");
        //view the queue
        printf("Queue: ");
        print_queue(&queue);

	//remove process from the queue
	dequeue(&queue);
        printf("Dequeue: ");
        p3->name = decode(p3->name, key);
        print_process(p3);
        printf("\n");
        //view the queue
        printf("Queue: ");
        print_queue(&queue);
	printf("\n");
}
