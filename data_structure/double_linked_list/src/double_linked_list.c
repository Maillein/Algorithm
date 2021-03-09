//
// Created by maillein on 2021/02/24.
//

#include <stdio.h>
#include <stdlib.h>
#include "../include/double_linked_list.h"

struct Node *create_node(int data) {
	struct Node *new = (struct Node *)malloc(sizeof(struct Node));
	new->data = data;
	new->next = new;
	new->prev = new;
	return new;
}

void init_dll(struct DoubleLinkedList *list) {
	list->head = create_node(0);
	list->len = 0;
}

void push_front_of_dll(struct DoubleLinkedList *list, int data) {
	struct Node *new = create_node(data);
	new->next = list->head->next;
	new->prev = list->head;
	new->next->prev = new;
	new->prev->next = new;
	list->len++;
}

void push_back_of_dll(struct DoubleLinkedList *list, int data) {
	struct Node *new = create_node(data);
	new->next = list->head;
	new->prev = list->head->prev;
	new->next->prev = new;
	new->prev->next = new;
	list->len++;
}

void pop_first_from_dll(struct DoubleLinkedList *list) {
	struct Node *remove = list->head->next;
	list->head->next = remove->next;
	remove->next->prev = list->head;
	list->len--;
	free(remove);
	remove = NULL;
}

void pop_last_from_dll(struct DoubleLinkedList *list) {
	struct Node *remove = list->head->prev;
	list->head->prev = remove->prev;
	remove->prev->next= list->head;
	list->len--;
	free(remove);
	remove = NULL;
}

void add_next_of_dll_node(struct DoubleLinkedList *list, struct Node *node, int data) {
	if (node == NULL) return;
	struct Node *new = create_node(data);
	new->next = node->next;
	new->prev = node;
	new->next->prev = new;
	new->prev->next = new;
	list->len++;
}

void add_prev_of_dll_node(struct DoubleLinkedList *list, struct Node *node, int data) {
	if (node == NULL) return;
	struct Node *new = create_node(data);
	new->next = node;
	new->prev = node->next;
	new->next->prev = new;
	new->prev->next = new;
	list->len++;
}

struct Node *find_first_of_dll(struct DoubleLinkedList *list, int data) {
	for (struct Node *node = list->head->next; node != list->head; node = node->next) {
		if (node->data == data) {
			return node;
		}
	}
	return NULL;
}

struct Node *find_last_of_dll(struct DoubleLinkedList *list, int data) {
	for (struct Node *node = list->head->prev; node != list->head; node = node->prev) {
		if (node->data == data) {
			return node;
		}
	}
	return NULL;
}

void reverse_dll(struct DoubleLinkedList *list) {
	struct Node *tmp = list->head->next;
	list->head->next = list->head->prev;
	list->head->prev = tmp;
	for (struct Node *node = list->head->next; node != list->head; node = node->next) {
		tmp = node->next;
		node->next = node->prev;
		node->prev = tmp;
	}
}

void merge_dll(struct DoubleLinkedList *list1, struct DoubleLinkedList *list2) {
	list2->head->next->prev = list1->head->prev;
	list2->head->prev->next = list1->head;
	list2->head->next->prev->next = list2->head->next;
	list2->head->prev->next->prev = list2->head->prev;
	list1->len += list2->len;
	free(list2->head);
	list2->head = NULL;
}

void sort_dll(struct DoubleLinkedList *list) {
	if (list->len <= 2) return;
	struct Node *mid = list->head;
	struct DoubleLinkedList list2;
	init_dll(&list2);
	for (int i = 0; i < list->len / 2; i++) mid = mid->next;
	list2.head->next = mid->next;
	list2.head->prev = list->head->prev;
	list2.head->next->prev = list2.head;
	list2.head->prev->next = list2.head;
	list2.len = list->len - list->len / 2;

	list->head->prev = mid;
	mid->next = list->head;
	list->len = list->len / 2;
	sort_dll(list);
	sort_dll(&list2);

	struct DoubleLinkedList list3;
	init_dll(&list3);
	struct Node *node1 = list->head->next;
	struct Node *node2 = list2.head->next;
	while (node1 != list->head && node2 != list2.head) {
		if (node1 == list->head) {
			push_back_of_dll(&list3, node2->data);
			node2 = node2->next;
		}
		else if (node2 == list2.head) {
			push_back_of_dll(&list3, node1->data);
			node1 = node1->next;
		}
		else {
			if (node1->data < node2->data) {
				push_back_of_dll(&list3, node1->data);
				node1 = node1->next;
			}
			else {
				push_back_of_dll(&list3, node2->data);
				node2 = node2->next;
			}
		}
	}
	struct Node *tmp = list->head;
	list->head = list3.head;
	list3.head = tmp;
	delete_dll(&list3);
}

void delete_dll(struct DoubleLinkedList *list) {
	while (list->head->next != list->head) {
		pop_first_from_dll(list);
	}
	free(list->head);
	list->head = NULL;
}

void print_dll(struct DoubleLinkedList *list) {
	for (struct Node *node = list->head->next; node != list->head; node = node->next) {
		printf("%d ", node->data);
	}
	printf("\n");
}
