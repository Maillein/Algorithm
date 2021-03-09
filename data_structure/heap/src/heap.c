//
// Created by maillein on 2021/02/24.
//

#include "../include/heap.h"
#include <util.h>
// #include "../../../util/include/util.h"

void init_heap(struct heap *heap) {
	heap->size = 0;
}

void push_heap(struct heap *heap, int a) {
	heap->data[++heap->size] = a;
	int i = heap->size;
	while (i > 0 && heap->data[i / 2] > heap->data[i]) {
		swap(&heap->data[i / 2], &heap->data[i]);
		i /= 2;
	}
}

int pop_heap(struct heap *heap) {
	int ret = heap->data[1];
	heap->data[1] = heap->data[heap->size--];
	int i = 1;
	while (i <= heap->size / 2) {
		if (heap->data[i * 2] >= heap->data[i] && heap->data[i * 2 + 1] >= heap->data[i]) {
			break;
		}
		else {
			if (heap->data[i * 2] < heap->data[i * 2 + 1]) {
				swap(&heap->data[i], &heap->data[i * 2]);
				i = i * 2;
			}
			else {
				swap(&heap->data[i], &heap->data[i * 2 + 1]);
				i = i * 2 + 1;
			}
		}
	}
	return ret;
}
