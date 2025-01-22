#include "queue.h"
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

	printf("\nLet's create an empty queue:\n");
	// print empty queue
	print_queue(&queue);

	// create instances of some proccesses
	process_t *p1 = create_process(1, "A"); 
	process_t *p2 = create_process(2, "B"); 
        process_t *p3 = create_process(3, "C");
        process_t *p4 = create_process(4, "D");	
        process_t *p5 = create_process(5, "E");
        process_t *p6 = create_process(6, "F");

	
	printf("\nLet's enqeue and dequeue some processes:\n");
	// add proccess to the queue
	printf("Enqueue:");
	print_process(p1);
        printf("\n");
	enqueue(&queue, p1);

	//view the queue
	printf("Queue: ");	
	print_queue(&queue);

        // add proccess to the queue
        printf("\nEnqueue:");
        print_process(p2);
        printf("\n");
        enqueue(&queue, p2);

        //view the queue
        printf("Queue: ");
        print_queue(&queue);

	// remove process from the queue
        printf("\nDequeue: ");
	print_process(dequeue(&queue));
	printf("\n");

        //view the queue
        printf("Queue: ");
        print_queue(&queue);

	// add proccess to the queue
        printf("\nEnqueue:");
        print_process(p3);
        printf("\n");
        enqueue(&queue, p3);

        //view the queue
        printf("Queue: ");
        print_queue(&queue);

	// add proccess to the queue
        printf("\nEnqueue:");
        print_process(p4);
        printf("\n");
        enqueue(&queue, p4);

        //view the queue
        printf("Queue: ");
        print_queue(&queue);

        // add proccess to the queue
        printf("\nEnqueue:");
        print_process(p5);
        printf("\n");
        enqueue(&queue, p5);

        //view the queue
        printf("Queue: ");
        print_queue(&queue);

	// remove process from the queue
        printf("\nDequeue: ");
        print_process(dequeue(&queue));
	printf("\n");

        //view the queue
        printf("Queue: ");
        print_queue(&queue);

        // add proccess to the queue
        printf("\nEnqueue:");
        print_process(p6);
        printf("\n");
        enqueue(&queue, p6);

        //view the queue
        printf("Queue: ");
        print_queue(&queue);

	        // remove process from the queue
        printf("\nDequeue: ");
        print_process(dequeue(&queue));
        printf("\n");

        //view the queue
        printf("Queue: ");
        print_queue(&queue);

	// remove process from the queue
        printf("\nDequeue: ");
        print_process(dequeue(&queue));
        printf("\n");

        //view the queue
        printf("Queue: ");
        print_queue(&queue);

	// remove process from the queue
        printf("\nDequeue: ");
        print_process(dequeue(&queue));
        printf("\n");

        //view the queue
        printf("Queue: ");
        print_queue(&queue);

	// remove process from the queue
        printf("\nDequeue: ");
        print_process(dequeue(&queue));
        printf("\n");

        //view the queue
        printf("Queue: ");
        print_queue(&queue);

        // remove process from empty queue
        printf("\nDequeue: ");
	print_process(dequeue(&queue));	
        printf("\n"); 

        //view the queue
        printf("Queue: ");
        print_queue(&queue);
        printf("\n");
}
