//
// Created by maillein on 2021/02/24.
//

#include <stdio.h>
#include <heap.h>
#include <util.h>
#include "../include/sort.h"
// #include "../../../../util/include/util.h"
// #include "../../../../data_structure/heap/heap.h"

void bubble_sort(int a[], int begin, int end) {
	for (int i = begin; i < end; i++) {
		for (int j = end; j > begin; j--) {
			if (a[j - 1] > a[j]) {
				swap(&a[j - 1], &a[j]);
			}
		}
	}
}

void selection_sort(int *a, int begin, int end) {
	for (int i = begin; i <= end; i++) {
		int min = i;
		for (int j = i + 1; j <= end; j++) {
			if (a[j] < a[min]) min = j;
		}
		swap(a + min, a + i);
	}
}

void insertion_sort(int a[], int begin, int end) {
	for (int i = begin + 1; i <= end; i++) {
		int tmp = a[i];
		int j = i - 1;
		while (a[j] > tmp && j >= begin) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = tmp;
	}
}

void quick_sort(int a[], int begin, int end) {
	if (begin >= end) return;

	// partition
	int pivot = a[end];
	int i = begin - 1; // a[k] <= pivot (for all k, begin <= k <= i)
	for (int j = begin; j < end; j++) {
		if (a[j] <= pivot) {
			swap(&a[++i], &a[j]);
		}
	}
	swap(&a[i + 1], &a[end]);
	int m = i + 1;

	quick_sort(a, begin, m - 1);
	quick_sort(a, m + 1, end);
}

void merge_sort(int a[], int begin, int end) {
	static int w[(int)10e8];

	if (begin >= end) return;
	if (end > 10e8) {
		printf("data size must be smaller than 10e8.");
		return;
	}
	int mid = (begin + end) / 2;
	merge_sort(a, begin, mid);
	merge_sort(a, mid + 1, end);

	// merge_dll
	int i = begin;
	int j = mid + 1;
	for (int k = begin; k <= end; k++) {
		if (i > mid) {
			w[k] = a[j++];
		}
		else if (j > end) {
			w[k] = a[i++];
		}
		else {
			if (a[i] < a[j]) {
				w[k] = a[i++];
			}
			else {
				w[k] = a[j++];
			}
		}
	}
	for (int k = begin; k <= end; k++) {
		a[k] = w[k];
	}
}

void heap_sort(int a[], int begin, int end) {
	struct heap heap;
	init_heap(&heap);
	for (int i = begin; i <= end; i++) {
		push_heap(&heap, a[i]);
	}
	for (int i = begin; i <= end; i++) {
		a[i] = pop_heap(&heap);
	}
}
