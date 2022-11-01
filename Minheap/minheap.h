#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

typedef struct MinHeap MinHeap;
struct MinHeap {
    int* arr;
    // Current Size of the Heap
    int size;
    // Maximum capacity of the heap
    int capacity;
};

int parent(int i);
int left_child(int i);
int right_child(int i);
int get_min(MinHeap* heap);

MinHeap* init_minheap(int capacity);
MinHeap* insert_minheap(MinHeap* heap, int element);
MinHeap* heapify(MinHeap* heap, int index);
MinHeap* delete_minimum(MinHeap* heap);
MinHeap* delete_element(MinHeap* heap, int index);

void print_heap(MinHeap* heap);
void fprint_heap(MinHeap* heap);
void free_minheap(MinHeap* heap);