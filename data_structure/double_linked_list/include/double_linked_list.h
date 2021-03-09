//
// Created by maillein on 2021/02/24.
//

#ifndef ALGO_DATA_STRUCTURE_DOUBLE_LINKED_LIST_H_
#define ALGO_DATA_STRUCTURE_DOUBLE_LINKED_LIST_H_

struct Node {
	int data;
	struct Node *prev;
	struct Node *next;
};

struct Node *create_node(int data);

struct DoubleLinkedList {
	struct Node *head;
	int len;
};

void init_dll(struct DoubleLinkedList *list);
void push_front_of_dll(struct DoubleLinkedList *list, int data);
void push_back_of_dll(struct DoubleLinkedList *list, int data);
void pop_first_from_dll(struct DoubleLinkedList *list);
void pop_last_from_dll(struct DoubleLinkedList *list);
void add_next_of_dll_node(struct DoubleLinkedList *list, struct Node *node, int data);
void add_prev_of_dll_node(struct DoubleLinkedList *list, struct Node *node, int data);
struct Node *find_first_of_dll(struct DoubleLinkedList *list, int data);
struct Node *find_last_of_dll(struct DoubleLinkedList *list, int data);
void reverse_dll(struct DoubleLinkedList *list);
void merge_dll(struct DoubleLinkedList *list1, struct DoubleLinkedList *list2);
void sort_dll(struct DoubleLinkedList *list);
void delete_dll(struct DoubleLinkedList *list);

void print_dll(struct DoubleLinkedList *list);

#endif //ALGO_DATA_STRUCTURE_DOUBLE_LINKED_LIST_H_
