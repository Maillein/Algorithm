//
// Created by maillein on 2021/02/24.
//

#include <stdio.h>
#include "../include/util.h"

void print_array(int a[], int begin, int end) {
	for (int i = begin; i <= end; i++) {
		printf("%d ", a[i]);
	}
	puts("");
}

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
