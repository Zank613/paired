/************************************************************************************
MIT License

Copyright (c) 2024 ATAERK YILDIRIM

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*************************************************************************************/

#ifndef PAIRED_H
#define PAIRED_H

#include <stdlib.h>
#include <stdio.h>

// Macro for defining function implementations
#ifdef PAIRED_IMPLEMENTATION
#define PAIRED_DEF static inline
#else
#define PAIRED_DEF extern
#endif

// Pair structure
typedef struct Pair
{
    void* first;
    void* second;
} Pair;

// PairArray structure
typedef struct
{
    Pair** data;
    size_t size;
    size_t capacity;
} PairArray;

// Function declarations

// Creates a new Pair with the given first and second elements.
PAIRED_DEF Pair* createPair(void* first, void* second);

// Frees the memory allocated for a Pair.
PAIRED_DEF void freePair(Pair* pair);

// Creates a new PairArray with the specified initial capacity.
PAIRED_DEF PairArray* createPairArray(size_t initialCapacity);

// Adds a Pair to the PairArray, resizing if necessary.
PAIRED_DEF int addPairToArray(PairArray* array, Pair* pair);

// Prints the contents of the PairArray.
PAIRED_DEF void printPairArray(const PairArray* array);

// Frees the memory allocated for the PairArray and its contents.
PAIRED_DEF void freePairArray(PairArray* array);

#ifdef PAIRED_IMPLEMENTATION

// Function definitions

PAIRED_DEF Pair* createPair(void* first, void* second)
{
    Pair* newPair = malloc(sizeof(Pair));
    if (!newPair)
    {
        fprintf(stderr, "Memory allocation failed for Pair\n");
        return NULL;
    }
    newPair->first = first;
    newPair->second = second;
    return newPair;
}

PAIRED_DEF void freePair(Pair* pair)
{
    if (pair)
    {
        free(pair);
    }
}

PAIRED_DEF PairArray* createPairArray(size_t initialCapacity)
{
    PairArray* array = malloc(sizeof(PairArray));
    if (!array)
    {
        fprintf(stderr, "Memory allocation failed for PairArray\n");
        return NULL;
    }

    array->data = malloc(initialCapacity * sizeof(Pair*));
    if (!array->data)
    {
        free(array);
        fprintf(stderr, "Memory allocation failed for PairArray data\n");
        return NULL;
    }

    array->size = 0;
    array->capacity = initialCapacity;
    return array;
}

PAIRED_DEF int addPairToArray(PairArray* array, Pair* pair)
{
    if (!array || !pair)
    {
        fprintf(stderr, "Invalid input to addPairToArray\n");
        return -1;
    }

    if (array->size == array->capacity)
    {
        array->capacity *= 2;
        Pair** newData = realloc(array->data, array->capacity * sizeof(Pair*));
        if (!newData)
        {
            fprintf(stderr, "Memory reallocation failed in addPairToArray\n");
            return -1;
        }
        array->data = newData;
    }
    array->data[array->size++] = pair;
    return 0;
}

PAIRED_DEF void printPairArray(const PairArray* array)
{
    if (!array)
    {
        fprintf(stderr, "Invalid PairArray to print\n");
        return;
    }

    for (size_t i = 0; i < array->size; i++)
    {
        printf("Pair %zu: (%p, %p)\n", i + 1, array->data[i]->first, array->data[i]->second);
    }
}

PAIRED_DEF void freePairArray(PairArray* array)
{
    if (array)
    {
        for (size_t i = 0; i < array->size; i++)
        {
            freePair(array->data[i]);
        }
        free(array->data);
        free(array);
    }
}

#endif // PAIRED_IMPLEMENTATION

#endif // PAIRED_H
