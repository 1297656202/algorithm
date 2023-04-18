#include <stdlib.h>
#include "unsigned.h"

// -----------------------------------------------------------------------------

static const Int ignore = 42;

// 在此处可定义若干辅助函数，以供定义其它函数时使用

// -----------------------------------------------------------------------------

Unsigned* unsigned_from_ll(long long x)
{
    Unsigned* ret = get_list();

    insert_front(ret, x % 10, ignore);
    while (x /= 10)
        insert_front(ret, x % 10, ignore);
    return ret;
}

Unsigned* unsigned_copy(const Unsigned* x)
{
    if (!x)
        return 0;
    Unsigned* y = get_list();
    for (Link* link = x->head; link; link = link->next)
        insert_back(y, link->n, link->x);
    return y;
}

void unsigned_free(Unsigned* x)
{
    list_free(x);
}

long long unsigned_to_ll(const Unsigned* x)
{
    long long ret = 0;
    for (Link* link = x->head; link; link = link->next) {
        ret *= 10;
        ret += link->n;
    }
    return ret;
}

int unsigned_cmp(const Unsigned* x, const Unsigned* y)
{
   	if(x->size>y->size)return 1;
	if(x->size<y->size)return -1;
	for (Link *link=x->head,*link2=y->head;link;link=link->next,link2=link2->next)
	{
		if(link->n>link2->n)return 1;
		if(link->n<link2->n)return -1;
	}
	return 0;
}

Unsigned* unsigned_add(const Unsigned* x, const Unsigned* y)
{Unsigned *z;Int tmp;Link *link,*link2;
    z=get_list();
	if(x->size>y->size){link=x->tail;link2=y->tail;}
	else {link=y->tail;link2=x->tail;}
	for(;link;link=link->prior)
	{
		if(link2)insert_front(z,link->n+link2->n,ignore);
		else  insert_front(z,link->n,ignore);
		if(link2)link2=link2->prior;
	}
	for (link=z->tail;link;link=link->prior)
	{
		tmp=link->n/10;
		link->n%=10;
		if(tmp>0)
		{
			if(link==z->head)insert_front(z,tmp,ignore);
			else link->prior->n+=tmp;
		}
	}
	return z;
}
Unsigned* unsigned_sub(const Unsigned* x, const Unsigned* y)
{Unsigned* z;Int tmp;
	z=unsigned_copy(x);
    for(Link* link=z->tail,*link2=y->tail;link;link=link->prior)
    {
    	if(link2)tmp=link2->n;
    	else tmp=0;
    	if(link->n<tmp)
    	{
    		link->prior->n--;
    		link->n+=10;
		}
		link->n=link->n-tmp;
		if(link2)link2=link2->prior;
	}
	while(z->head->n==0&&z->size>=2)
	remove_front(z);
	return z;
}

Unsigned* unsigned_mul(const Unsigned* x, const Unsigned* y)
{Unsigned* z;Int i,j;Link *link,*link2,*link3,*tmp;
	z=get_list();
    for(i=1;i<=x->size+y->size;i++)
    	insert_front(z,0,0);
    tmp=z->tail;
	link=x->tail;
    for(i=1;i<=x->size;i++)
    {	
    	link3=tmp;
    	for(link2=y->tail;link2;link2=link2->prior)
    	{
    		link3->n=link3->n+link->n*link2->n;
    		link3=link3->prior;
		}
    	tmp=tmp->prior;
    	link=link->prior;
	}
	for(link=z->tail;link;link=link->prior)
	{
		if(link->prior)link->prior->n+=link->n/10;
		link->n%=10;
	}
	while(z->head->n==0&&z->size>=2)
	remove_front(z);
	return z;
}

Unsigned* unsigned_div(const Unsigned* x, const Unsigned* y, Unsigned** rem)
{Unsigned *z,*tmp;Int i,j;Link *l,*l2,*l3;
    *rem=unsigned_copy(x);
    z=get_list();
    for(i=1;i<=x->size-y->size+1;i++)
    	insert_front(z,0,0);
    for(i=z->size,l=z->head;i>=1;i--)
    {
    	tmp=get_list();
    	for(j=1;j<=y->size+i-1;j++)
    		insert_front(tmp,0,0);
    	for(j=1,l2=tmp->tail;j<=i-1;j++)
    		l2=l2->prior;
    	for(j=1,l3=y->tail;j<=y->size;j++)
    	{
    		l2->n=l3->n;
    		l2=l2->prior;
    		l3=l3->prior;
		}
		while(unsigned_cmp(*rem,tmp)>=0){l->n++;*rem=unsigned_sub(*rem,tmp);}
		l=l->next;
		unsigned_free(tmp);
	}
	if(z->size==0)insert_front(z,0,0);
	while(z->head->n==0&&z->size>=2)
	remove_front(z);
	if((*rem)->size==0)insert_front(*rem,0,0);
	while((*rem)->head->n==0&&(*rem)->size>=2)
	remove_front(*rem);
	return z;
}

// -----------------------------------------------------------------------------
