# Paired

**Paired** is a library of custom data structures and algorithms built around the concept of "pairs." The library is designed for efficient handling of paired data, allowing users to integrate flexible data structures into their C projects.

## Features

- **Written in Pure C99**: Paired is designed to be simple and efficient, adhering to the C99 standard.
- **Single-Header Library**: Easy to include and integrate into your projects with just one header file.
- **Efficient Data Structures**: Provides basic data structures optimized for handling pairs of data.
- **Simple and Readable Code**: The library is designed to be easily understandable by reading the source code, making it a great educational tool.

## Getting Started

### Adding Paired to Your Project

To use the **Paired** library in your project, simply include the header file `paired.h` in your source files.

### Installation

1. **Clone or Download** the `paired.h` file from the repository.
2. **Include** it in your project directory.
3. **Use** the `#include` directive in your C source files.

```c
#define PAIRED_IMPLEMENTATION
#include "paired.h"

#include <string.h> // For strcpy and strdup
#include <stdio.h>  // For printf

// Function to create a new string pair
Pair* createStringPair(const char* first, const char* second)
{
    char* firstCopy = strdup(first);
    char* secondCopy = strdup(second);

    return createPair(firstCopy, secondCopy);
}

// Function to print a string pair
void printStringPair(const Pair* pair)
{
    if (pair)
    {
        printf("Pair: (%s, %s)\n", (char*)pair->first, (char*)pair->second);
    }
}

int main()
{
    // Create a new PairArray with initial capacity
    PairArray* array = createPairArray(2);
    if (!array)
    {
        fprintf(stderr, "Failed to create PairArray\n");
        return 1;
    }

    // Example data
    int a = 10;
    double b = 3.14;
    int c = 20;
    double d = 2.71;

    // Add pairs to the array
    if (addPairToArray(array, createPair(&a, &b)) != 0 ||
        addPairToArray(array, createPair(&c, &d)) != 0)
    {
        fprintf(stderr, "Failed to add Pair to PairArray\n");
        freePairArray(array);
        return 1;
    }

    // Print pairs
    printf("Numeric Pairs:\n");
    printPairArray(array);

    // Create and add string pairs
    if (addPairToArray(array, createStringPair("Hello", "World")) != 0 ||
        addPairToArray(array, createStringPair("Foo", "Bar")) != 0)
    {
        fprintf(stderr, "Failed to add String Pair to PairArray\n");
        freePairArray(array);
        return 1;
    }

    // Print string pairs
    printf("\nString Pairs:\n");
    for (size_t i = 2; i < array->size; ++i)
    {
        printStringPair(array->data[i]);
    }

    // Clean up
    freePairArray(array);

    return 0;
}
```

### Compilation Instructions

Compile the example code using your preferred C compiler. Here’s an example using `gcc`:

```bash
gcc main.c -o paired_example
```

### Contributing
Contributions to the **Paired** library are welcome! Feel free to submit issues, feature requests, or pull requests on the project's GitHub repository.

### License
The **Paired** library is licensed under MIT License. See the `LICENSE` file for more details.

## Future Development

### TODOs

- **Implement Skipping Data Structure:**
  - Design a custom data structure that allows access to one type of element in the pair while skipping the other.
  - Provide methods to efficiently traverse and access the data using the skipping technique.

- **Custom Data Structures Using Pairs:**
  - **Pair Queue:**
    - Implement a queue where each element is a pair, allowing enqueue and dequeue operations.
    - Consider use cases such as task scheduling or processing pairs in order.
  
  - **Pair Stack:**
    - Develop a stack data structure utilizing pairs for LIFO (Last In, First Out) operations.
    - Useful for scenarios like tracking state or managing paired undo operations.

  - **Pair Linked List:**
    - Create a linked list where each node contains a pair, supporting efficient insertion and deletion.
    - Implement both singly and doubly linked lists for various applications.
  
  - **Pair Hash Map:**
    - Design a hash map that allows keys or values to be pairs, facilitating complex mapping relationships.
    - Optimize for fast lookups and efficient memory usage.
  
  - **Pair Set:**
    - Develop a set data structure to store unique pairs, preventing duplicates.
    - Provide operations for union, intersection, and difference of pair sets.

- **Advanced Algorithms for Pairs:**
  - **Sorting Algorithms:**
    - Implement sorting algorithms tailored to pairs, with options to sort by the first or second element.
    - Include comparisons based on custom criteria.

  - **Search Algorithms:**
    - Develop efficient search algorithms for pairs, supporting both linear and binary search methods.
    - Allow searches by specific elements or custom conditions.

  - **Pair Combination and Transformation:**
    - Create functions for combining and transforming pairs, such as merging pairs or mapping one pair to another.
