#include <stdio.h>
#include <stdbool.h>
#include "list.h"

const Int unused = 42;

int main(void)
{int i;
    List* list = get_list();

    bool ok = list->size == 0 &&
              list->head == 0 &&
              list->tail == 0;

    insert_front(list, unused, 4);
    ok = ok &&
         list->size == 1 &&
         list->head->x == 4 &&
         list->tail->x == 4;
	
    bubble_sort_x(list);
    ok = ok &&
         list->size == 1 &&
         list->head->x == 4 &&
         list->tail->x == 4;
	
    insert_front(list, unused, 5);
    ok = ok &&
         list->size == 2 &&
         list->head->x == 5 &&
         list->tail->x == 4;
	
    bubble_sort_x(list);
    ok = ok &&
         list->size == 2 &&
         list->head->x == 4 &&
         list->tail->x == 5;
	
    insert_front(list, unused, 9);
    ok = ok &&
         list->size == 3 &&
         list->head->x == 9 &&
         list->tail->x == 5;
	
    bubble_sort_x(list);
    ok = ok &&
         list->size == 3 &&
         list->head->x == 4 &&
         list->tail->x == 9;

    insert_back(list, unused, 3);
    ok = ok &&
         list->size == 4 &&
         list->head->x == 4 &&
         list->tail->x == 3;
	
    insert_back(list, unused, 7);
    ok = ok &&
         list->size == 5 &&
         list->head->x == 4 &&
         list->tail->x == 7;

    insert_front(list, unused, 10);
    ok = ok &&
         list->size == 6 &&
         list->head->x == 10 &&
         list->tail->x == 7;

    insert_back(list, unused, 8);
    ok = ok &&
         list->size == 7 &&
         list->head->x == 10 &&
         list->tail->x == 8;
	
    insert_back(list, unused, 6);
    ok = ok &&
         list->size == 8 &&
         list->head->x == 10 &&
         list->tail->x == 6;
	
    bubble_sort_x(list);
    ok = ok &&
         list->size == 8 &&
         list->head->x == 3 &&
         list->tail->x == 10;
	
    for (i = 0; i < 8; ++i) {
        ok = ok &&
             list->size == 8 - i &&
             list->head->x == 3 + i &&
             list->tail->x == 10;
		
        remove_front(list);
    }
	
    ok = ok &&
         list->size == 0 &&
         list->head == 0 &&
         list->tail == 0;

    printf(ok ? "pass" : "fail");
    putchar('\n');

    list_free(list);
	return 0; 
}
