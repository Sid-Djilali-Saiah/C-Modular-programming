#include <stdlib.h>
#include <stdarg.h>
#include "raise.h"
#include "list.h"
#include "new.h"
#include "container.h"
#include "int.h"
typedef struct
{
    Iterator base;
    ListClass* reccord;
    size_t _idx;
} ListIteratorClass;
void ListIterator_ctor(ListIteratorClass *self, va_list *args)
{
    self->reccord = va_arg(*args, ListClass *);
    self->_idx = va_arg(*args, int);
}
bool ListIterator_eq(ListIteratorClass *self, ListIteratorClass *other)
{
    return (self->_idx == other->_idx);
}
bool ListIterator_gt(ListIteratorClass *self, ListIteratorClass *other)
{
    return (self->_idx > other->_idx);
}
bool ListIterator_lt(ListIteratorClass *self, ListIteratorClass *other)
{
    return (self->_idx < other->_idx);
}
void ListIterator_incr(ListIteratorClass *self)
{
    self->_idx += 1;
}
Object *ListIterator_getval(ListIteratorClass *self)
{
    Container  *crec;

    if (!self)
        return (NULL);
    if (self->_idx >= self->reccord->_size)
        raise("Out of range");

    crec = (Container *)self->reccord;
    return (((list_entry_t *)crec->__getitem__(crec, self->_idx))->value);
}
void ListIterator_setval(ListIteratorClass* self, ...)
{
    va_list ap;
    Object  *value;

    va_start(ap, self);
    if (self->_idx >= self->reccord->_size)
        raise("Out of range");
    value = va_new(self->reccord->_type, &ap);
    ((Container *)self->reccord)->__setitem__((Container *)self->reccord, value, self->_idx);
}
static ListIteratorClass ListIteratorDescr =
{
    {
        {
            sizeof(ListIteratorClass),
            "ListIterator",
            (ctor_t) &ListIterator_ctor,
            NULL, /* dtor */
            NULL, /* str */
            NULL,
            NULL,
            NULL,
            NULL, /* add, sub, mul, div */
            (binary_comparator_t) &ListIterator_eq,
            (binary_comparator_t) &ListIterator_gt,
            (binary_comparator_t) &ListIterator_lt,
        },
        (incr_t) &ListIterator_incr,
        (getval_t) &ListIterator_getval,
        (setval_t) &ListIterator_setval,
    },
    NULL,
    0
};
static Class* ListIterator = (Class *)&ListIteratorDescr;
list_entry_t    *list_get_entry(ListClass *self, size_t pos_desired)
{
    size_t  pos_cur = 0;
    size_t  travelled = 0;
    list_entry_t   *entry;

    if (!self || (pos_desired > self->_size))
        return (NULL);
    if (self->idx_cur < pos_desired)
    {
        pos_cur = self->idx_cur;
        entry = self->cur;
    }
    else
        entry = self->start;
    self->idx_cur = pos_cur;
    while (pos_cur++ < pos_desired)
    {
        entry = entry->next;
        travelled += 1;
    }
    self->idx_cur += travelled;
    self->cur = entry;
    return (entry);    
}
void    List_unop_clear(ListClass *self)
{
    list_entry_t    *entry;
    list_entry_t    *next;

    if (!self || !self->start)
        return ;
    entry = self->start;
    while (entry)
    {
        next = entry->next;
        free(entry);
        entry = next;        
    }
    self->start = NULL;
    self->cur = NULL;
    self->end = NULL;
}
bool  list_add_front(ListClass *self, Object *value)
{
    list_entry_t  *entry;

    if (!self)
        return (false);
    if (!(entry = malloc(sizeof(list_entry_t))))
        return (false);
    entry->value = value;
    entry->next = self->start;
    self->start = entry;
    if (self->idx_cur == 0)
        self->cur = self->start;
    if (self->_size == 0)
        self->end = self->start;
    self->_size += 1;
    return (true);
}
bool  list_add_back(ListClass *self, Object *value)
{
    list_entry_t  *entry;

    if (!self)
        return (false);
    if (!(entry = malloc(sizeof(list_entry_t))))
        return (false);
    entry->value = value;
    entry->next = NULL;
    if (self->end)
        self->end->next = entry;
    self->end = entry;
    if (self->_size == 0)
    {
        self->start = entry;
        self->cur = entry;
    }
    self->_size += 1;
    return (0);
}
bool  list_add
(
    ListClass *self,
    Object *value,
    size_t position
)
{
    list_entry_t    *entry;
    list_entry_t    *previous;

    if (!self)
        return (false);
    if (position == 0)
        return (list_add_front(self, value));
    else if (position == self->_size)
        return (list_add_back(self, value));
    if (!(entry = malloc(sizeof(list_entry_t))))
        return (false);
    previous = list_get_entry(self, position - 1);
    entry->next = previous->next;
    entry->value = value;
    previous->next = entry;
    self->_size += 1;
    return (true);
}
bool  list_del_front(ListClass *self)
{
    return (true);
}
bool  list_del_back(ListClass *self)
{
    return (false);
}
bool  list_del(ListClass *self, size_t position)
{
    return (true);
}
/*
    @Type = Class *
*/
void List_ctor(ListClass *self, va_list *args)
{

    self->_type = va_arg(*args, Class *);
    self->_size = 0;
    self->idx_cur = 0;
    self->start = NULL;
    self->end = NULL;
    self->cur = NULL;
    self->_clear_ = &List_unop_clear;
    self->__add_front__ = &list_add_front;
    self->__add_back__ = &list_add_back;
    self->__add__ = &list_add;
    self->__del_front__ = &list_del_front;
    self->__del_back__ = &list_del_back;
    self->__del__ = &list_del;
}
void List_dtor(ListClass *self)
{
    if (!self)
        return ;
    self->_clear_(self);
}
size_t List_len(ListClass *self)
{
    return (self->_size);
}
Iterator *List_begin(ListClass *self)
{
    return new(ListIterator, self, 0);
}
Iterator *List_end(ListClass *self)
{
    return new(ListIterator, self, self->_size);
}
/*
    @pos = size_t;
*/
Object *List_getitem(ListClass *self, ...)
{
    list_entry_t    *entry;
    size_t          pos;
    va_list         ap;

    va_start(ap, self);
    pos = va_arg(ap, size_t);
    va_end(ap);
    entry = list_get_entry(self, pos);
    return (entry ? entry : NULL);
}
/*
    @pos = size_t;
    @value = Object *;
*/
void List_setitem(ListClass* self, ...)
{
    list_entry_t    *entry;
    size_t          pos;
    Object          *value;
    va_list         ap;

    va_start(ap, self);
    value = va_arg(ap, Object *);
    pos = va_arg(ap, size_t);
    va_end(ap);
    entry = list_get_entry(self, pos);
    if (entry)
        entry->value = value;
}
static ListClass _descr =
{
    { /* Container */
        { /* Class */
            sizeof(ListClass),
            "List",
            (ctor_t)&List_ctor,
            (dtor_t)&List_dtor,
            NULL, /*str */
            NULL,
            NULL,
            NULL,
            NULL, /* add, sub, mul, div */
            NULL,
            NULL,
            NULL, /* eq, gt, lt */
        },
        (len_t)&List_len,
        (iter_t)&List_begin,
        (iter_t)&List_end,
        (getitem_t)&List_getitem,
        (setitem_t)&List_setitem,
    },
    NULL, //_type
    0,    //_size
    0,    //idx_cur
    NULL, //start
    NULL, //cur
    NULL, //end
    NULL, // _clear_
    NULL, //add_front
    NULL, //add_back
    NULL, //add
    NULL, //del_front
    NULL, //del_back
    NULL  //del
};
Class *List = (Class*)&_descr;