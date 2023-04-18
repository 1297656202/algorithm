#ifndef LIST_H
#define LIST_H

// -----------------------------------------------------------------------------

struct Link;
struct List;

typedef struct Link   Link;
typedef struct List   List;

typedef long long Int;

// -----------------------------------------------------------------------------

struct Link {
    Int n, x;

    Link* prior;
    Link* next;
};

struct List {
    Int size;

    Link* head;
    Link* tail;
};

// -----------------------------------------------------------------------------

List* get_list(void);
void  insert_front(List*, Int n, Int x);
void  insert_back(List*, Int n, Int x);
void  remove_front(List*);
void  bubble_sort_x(List*);
void  list_free(List*);

// -----------------------------------------------------------------------------

#endif // ifndef LIST_H
