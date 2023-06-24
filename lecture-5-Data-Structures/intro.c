/* Intro to Data Structures

Data Structures
- forms of organization in memory; many ways
- abstract data type can represent one thing but it differs on our own implementation

Queues
- form of abstract data structure
- FIFO - first in, first out (first person in queue will leave first)
- DISNEYLAND is a queue because first person to be in front of the line goes in first
- "enqueue" - add to end of queue
- "dequeue" - remove from beginning of queue

Stacks
- form of abstract data structure
- LIFO - last in, first out (pancake on top of stack will leave first)
- GMAIL is a stack because last email received will always be on top
- "push" - add to top of stack
- "pop" - remove from top of stack

*/

// STACK
const int CAPACITY = 50; // bad implementation to define CAPACITY with a number because we want enough room to grow... but we're using wasting memory (and space complexity) and could potentially become a "stack overflow"
typedef struct
{
    person people[CAPACITY];
    int size;
}
stack;

/*

Resizing Arrays
- array is a block of contiguous memory where we can store values
- there may be unused "gargage values" that utilize memory
- if we want to resize an array we have to look for other place where it has contiguous memory and enough space for the new array. we copy the old array item by item into a new one with more space
- by design it's a bad implementation

*/

int main(void)
{
    // allocate memory for a new list
    int *list = malloc(3 * sizeof(int)); // sizeof int is always 4bytes
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // ... if we needed more memory for the list?
    int *tmp = malloc(4 * sizeof(int));
    // check for errors in tmp
    if (tmp == NULL)
    {
        // freeing memory from list
        free(list);
        return 1;
    }

    // iterate over list array (original)
    for (int i = 0; i < 3; i++)
    {
        // set tmp[i] and copy from list[i]
        tmp[i] = list[i];
    }
    // set tmp[3] equal to 4
    tmp[3] = 4;

    // free list of size 3
    free(list);

    // remember list to new size of 4
    list = tmp;

    // print the list (now size 4)
    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]); // 1 2 3 4
    }

    // free newest list and exit
    free(list);
    return 0;
}

/* We can simplify malloc -> realloc
- reallocating memory(original memory, desired memory size)
- automatically frees up old memory and creates new memory
- it is possible to use "realloc" to get fewer memory than originally needed
- "realloc" will be useful for "QUEUE" OR "STACK"; as amount of data grows "realloc" could be used to grow or shink the STACK OR QUEUE

*/

int main(void)
{
    // allocate memory for a new list
    int *list = malloc(3 * sizeof(int));
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // ... we want more memory -> use realloc
    int *tmp = realloc(list, 4 * sizeof(int));
    // check for errors in tmp
    if (tmp == NULL)
    {
        free(list);
        return 1;
    }

    // remember "tmp" is "list"
    list = tmp;

    // set new integer
    list[3] = 4;

    // print the list (size 4)
    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    // free newest list and exit
    free(list);
    return 0;
}

/*

struct
- data type that we can use to create our own "structure" in memory
- "." operator - allows to access variables inside the "structure"
- "*" operator - used to "declare" a pointer or "dereference" a pointer
- "->" operator - (arrow symbol) goes to an address and looks inside a "structure"

Linked List
- one of the most powerful abstract data structures within C
- linked list allows us to link values at varying areas of memory (no need to be contiguous memory like arrays)
- we can dynamically grow/shrink the list as we desire
- ***** DEFERS FROM AN ARRAY BECAUSE WE DON'T NEED CONTIGUOUS CHUNK OF MEMORY
- ***** LINKED LIST WE SPEND MORE MEMORY BUT OUR DATA CAN BE ANYWHERE IN MEMORY, BUT JUST LINKED TOGETHER
- ***** END OF LINKED LIST WILL BE NULL (REPRESENTS EMPTY)
- ***** NODE contains an item and pointer NEXT
- linked lists can't be indexed (unlike arrays) because they're not contiguous so we need to search linearly O(n)
- A LINKED LIST IS LIKE A STACK, because we are pushing new nodes to the end of the linked list

 */

typedef struct node
{
    int number; // always integer number
    struct node *next; // pointer "next"
}
node;

// create a linked list
node *list; // it has a garbage value because we don't initialize to any value
node *list = NULL; // list is empty
node *n = malloc(sizeof(node)); // we allocate "n" in memory and returns the address where "n" is stored
// (*n).number = 1; // dereference "n" to go to an address and assign number to 1
n -> number = 1; // same as above; n leads to value 1
n -> next = NULL; // "next" is assigned NULL
list = n; // list is pointed at memory location where "n" points
node *n = malloc(sizeof(node)); // creates a new node
n -> number = 2; // "number" value of "n" node is updated to 2
n -> next = NULL; // "next" is assigned NULL
n -> next = list; // "next" is pointed to list
list = n; // we update "list" to point at "n", successfully having a linked list of 2 nodes

/*

Prepend (beginning) to Linked List?
- Search: O(n) - we search linearly for "n" values
- Insert: O(1) - we add new nodes without increasing memory

Appending (end) to Linked List?
- Search: O(n) - we search linearly for "n" values
- Insert: O(n) - we have to traverse

A Sorted Linked List?
- Insert: O(n) - we have to traverse linearly
- Search: O(n) - we search linearly for "n" values

*/

/*

Trees
- trees are an abstract data structure composed on "nodes"
- Binary Search Tree (BST)
-- any node at root will be > left subtree && < right subtree
- Trees

        4         -> root
      /   \
     2     6
   /  \   /  \
  1  3   5   7

*/

typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
}
node;

// Search a BST? with recursion...
bool search(node *tree, int number)
{
    // edge case: if tree is null? we'll return false
    if (tree == NULL) {
        return false;
    }
    else if (number < tree -> number)
    {
        return search(tree -> left, number);
    }
    else if (number > tree -> number)
    {
        return search(tree -> right, number);
    }
    else
    {
        return true;
    }
}

/*

Dictionaries
- another abstract data structure
- dictionaries have a "key" and "value" pair
- independent of size of data structure we'll get O(1) constant time for SEARCH

Hashing and Hash Tables
- taking a value and outputting a value that becomes a shortcut to it later
- concept of "bucketizing": a hashed value is used to shortcut finding such a value
- a hash function is an algorithm that reduces a larger value to something small and predictable. Function takes an item we want to add to hash table, and returns an integer representing the array index in which the item should be placed
- a hash table is a combination of arrays & linked lists; when implemented in code, a hash table is an "array of pointers to nodes"
- **** SEARCH - O(1) constant

Collisions?
- collisions are when we add values to the hash table and something already exists at hashed location
- collisions can be reduced by better programming hash table and hash algorithm

Tries
- another abstract data structure
- fancier Tree, each of whose nodes are an array 
- tries are always searchable in O(1) constant time
- downside? take a large amount of memory

*/