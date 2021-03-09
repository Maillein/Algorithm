//
// Created by maillein on 2021/02/24.
//

#ifndef ALGO_DATA_STRUCTURE_HEAP_H_
#define ALGO_DATA_STRUCTURE_HEAP_H_

#define HEAP_SIZE 1000000

struct heap {
	int data[HEAP_SIZE];
	int size;
};

void init_heap(struct heap *heap);
void push_heap(struct heap *heap, int a);
int pop_heap(struct heap *heap);

#endif //ALGO_DATA_STRUCTURE_HEAP_H_
