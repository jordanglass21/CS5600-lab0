#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

	// create an instance of an empty queue
	queue_t queue;
	initialize_queue(&queue, print_process);

	printf("\nLet's create an empty queue:");
	// print empty queue
	print_queue(&queue);

	// create instances of some proccesses
	process_t *p1 = create_process(1, "A"); 
	process_t *p2 = create_process(2, "B"); 
        process_t *p3 = create_process(3, "C");
        process_t *p4 = create_process(4, "D");	
        process_t *p5 = create_process(5, "E");
        process_t *p6 = create_process(6, "F");

	
	printf("\nLet's enqeue and dequeue some processes:");
	// add proccess to the queue
	printf("\nEnqueue: ");
	print_process(p1); // print the process we want to enqueue
	enqueue(&queue, p1); // actually enqueue it 
	//view the queue
	print_queue(&queue);

        // add proccess to the queue
        printf("\nEnqueue: ");
        print_process(p2);
        enqueue(&queue, p2);
        //view the queue
        print_queue(&queue);

	// remove process from the queue
        printf("\nDequeue: ");
	print_process(dequeue(&queue));
        //view the queue
        print_queue(&queue);

	// add proccess to the queue
        printf("\nEnqueue: ");
        print_process(p3);
        enqueue(&queue, p3);
        //view the queue
        print_queue(&queue);

	// add proccess to the queue
        printf("\nEnqueue: ");
        print_process(p4);
        enqueue(&queue, p4);
        //view the queue
        print_queue(&queue);

        // add proccess to the queue
        printf("\nEnqueue: ");
        print_process(p5);
        enqueue(&queue, p5);
        //view the queue
        print_queue(&queue);

	// remove process from the queue
        printf("\nDequeue: ");
        print_process(dequeue(&queue));
        //view the queue
        print_queue(&queue);

        // add proccess to the queue
        printf("\nEnqueue: ");
        print_process(p6);
        enqueue(&queue, p6);
        //view the queue
        print_queue(&queue);

	// remove process from the queue
        printf("\nDequeue: ");
        print_process(dequeue(&queue));
        //view the queue
        print_queue(&queue);

	// remove process from the queue
        printf("\nDequeue: ");
        print_process(dequeue(&queue));
        print_queue(&queue); // view the queue

	// remove process from the queue
        printf("\nDequeue: ");
        print_process(dequeue(&queue));
        //view the queue
        print_queue(&queue);

	// remove process from the queue
        printf("\nDequeue: ");
        print_process(dequeue(&queue));
        //view the queue
        print_queue(&queue);

        // remove process from empty queue
        printf("\nDequeue: ");
	print_process(dequeue(&queue));	
        //view the queue
        print_queue(&queue);
	printf("\n");

	return(0); // exit gracefully
}
