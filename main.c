#include <stdio.h>
#include <util.h>
#include <heap.h>
#include <sort.h>
#include <double_linked_list.h>

void test_heap(void);
void test_sort(void);
void test_dllist(void);

int main(void) {
    test_heap();
    test_sort();
    test_dllist();
    return 0;
}

// ヒープが実装できているかのテスト
void test_heap(void) {
    struct heap heap;
    init_heap(&heap);
    push_heap(&heap, 3);
    push_heap(&heap, 2);
    push_heap(&heap, 1);
    printf("min = %d\n", pop_heap(&heap));
}

// ソートが実装できているかのテスト
void test_sort(void) {
    int arr[10] = {3, 0, 6, 1, 2, 7, 4, 8, 5, 9};
    quick_sort(arr, 0, 9);  // この行を色々変える
    print_array(arr, 0, 9);
}

// 双方向リスト（Double Linked List）が正しく実装できているかのテスト
void test_dllist(void) {
	struct DoubleLinkedList list;

	printf("A: リストの構築\n");
	init_dll(&list);
	push_back_of_dll(&list, 1);
	push_back_of_dll(&list, 2);
	push_back_of_dll(&list, 2);
	push_back_of_dll(&list, 2);
	push_back_of_dll(&list, 3);
	print_dll(&list);
	printf("len fo list: %d\n\n", list.len);

	printf("B: リストの先頭と末尾が取得できるか\n");
	struct Node *firsr2 = find_first_of_dll(&list, 2);
	struct Node *last2 = find_last_of_dll(&list, 2);
	printf("%d, %d, %d\n", firsr2->prev->data, firsr2->data, firsr2->next->data);
	printf("%d, %d, %d\n\n", last2->prev->data, last2->data, last2->next->data);

	printf("C: リストの反転\n");
	reverse_dll(&list);
	print_dll(&list);
	printf("len fo list: %d\n\n", list.len);

	printf("D: リストから削除できるか\n");
	pop_first_from_dll(&list);
	print_dll(&list);
	printf("len fo list: %d\n\n", list.len);

	printf("E: リストのマージができるか\n");
	struct DoubleLinkedList list2;
	init_dll(&list2);
	push_back_of_dll(&list2, 10);
	push_back_of_dll(&list2, 20);
	push_back_of_dll(&list2, 30);
	merge_dll(&list, &list2);
	print_dll(&list);
	printf("len fo list: %d\n\n", list.len);

    // ソートができないバグあり
	printf("F: リストのソートができるか\n");
	sort_dll(&list);
	print_dll(&list);
	printf("len fo list: %d\n\n", list.len);

    // リストの削除
	delete_dll(&list);
}
