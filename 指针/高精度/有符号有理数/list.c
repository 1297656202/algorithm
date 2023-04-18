#include <stdlib.h>
#include "list.h"

// -----------------------------------------------------------------------------

static Link* get_link(Int n, Int x)
{
    Link* link = malloc(sizeof(Link));
    link->n     = n;
    link->x     = x;
    link->prior = link->next = 0;
    return link;
}
List* get_list(void)
{
    List* list=(List*)malloc(sizeof(List));
    list->size=0;
    list->head=0;
    list->tail=0;
}
void insert_front(List* list, Int n, Int x)
{
   	Link* link=get_link(n,x);
	if(list->size>=1)list->head->prior=link;
	link->next=list->head;
    list->head=link;
    list->size++;
    if(list->size==1)list->tail=link;
}
void insert_back(List* list, Int n, Int x)
{
    Link* link=get_link(n,x);
    if(list->size>=1)list->tail->next=link;
	link->prior=list->tail;
    list->tail=link;
    list->size++;
    if(list->size==1)list->head=link;
}
void remove_front(List* list)
{
  	Link* link=list->head->next;
    list->size--;
    if(list->size>=1)link->prior=0;
	free(list->head);
	list->head=link;
	if(list->size==0)list->tail=0;
}
void bubble_sort_x(List* list)
{Int i,j;
    for(i=list->size-1;i>=1;i--)
    {
		Link* link=list->head;
		for(j=1;j<=i;j++)
		{
			if(link->x>link->next->x)
			{
	    		Link* link2=link->next;
	    		if(j!=1)link->prior->next=link2;
	    		if(j!=list->size-1)link2->next->prior=link;
	    		link->next=link2->next;
	    		link2->prior=link->prior;
	    		link->prior=link2;
	    		link2->next=link;
	    		if(j==1)list->head=link2;
	    		if(j==list->size-1)list->tail=link;
			}
			else link=link->next;
		}
	}
}
void list_free(List* list)
{
    if (!list)
        return;
    Link* link = list->head;
    while (link) {
        Link* p = link;
        link = link->next;
        free(p);
    }
    free(list);
}

// -----------------------------------------------------------------------------
