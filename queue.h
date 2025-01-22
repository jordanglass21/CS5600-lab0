/**
 * Structure representing a process with an ID and a name.
 */
typedef struct process_t {
	int identifier;
	char * name;
} process_t;

/**
 * Structure representing a node in the linked queue.
 */
typedef struct node_t {
	void * data; // void * means a pointer to any type of data
	struct node_t * next; // points to the next node in the queue
} node_t;

/**
 * Structure representing a FIFO queue.
 */
typedef struct queue_t {
	node_t * first; // points to the first node of the queue
	node_t * last; // last node of the queue
	int size;
	void (*print_data)(void *); // a function used to print the data of the nodes
} queue_t;

/**
 * Adds an element to the end of a queue.
 *
 * @param queue The queue to modify.
 * @param element The element to add.
 */
void enqueue(queue_t *queue, void *element);

/**
 * Removes and returns the element at the front of the queue.
 *
 * @param queue The queue to modify.
 * @return The element removed from the front.
 */ 
void * dequeue(queue_t *queue);

/**
 * Prints the elements of the queue to the console.
 *
 * @param queue The queue to print.
 */
void print_queue(queue_t *queue);

/**
 * Creates an instance of the process struct.
 *
 * @param identifier The process ID.
 * @param name The name of the process.
 * @return A pointer to the created process.
 */
process_t *create_process(int identifier, char *name);

/**
 * Prints a process.
 *
 * @param process A pointer to the process to print.
 */
void print_process(void *process);

/**
 * Initializes the queue.
 *
 * @param queue Pointer to the queue to initialize.
 * @param print_func Function to print queue data.
 */
void initialize_queue(queue_t *queue, void (*print_func)(void *));
