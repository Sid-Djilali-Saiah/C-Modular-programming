
#ifndef CONTAINER_H
# define CONTAINER_H

# include "object.h"
# include "iterator.h"

typedef struct
{
	Class	base;
	int	reccord;
} IntClass;
typedef struct Container_s Container;

typedef Iterator* (*iter_t)(Container* self);
typedef size_t (*len_t)(Container* self);
typedef Object* (*getitem_t)(Container* self, ...);
typedef void (*setitem_t)(Container* self, ...);

struct Container_s {
    Class base;
    len_t       __len__;
    iter_t      __begin__;
    iter_t      __end__;
    getitem_t   __getitem__;
    setitem_t   __setitem__;
};

typedef struct list_entry_s
{
    Object *value;
    struct list_entry_s *next;
} list_entry_t;
typedef struct ListClass_s ListClass;
struct ListClass_s {
    Container base;
    Class* _type;
    size_t _size;
    size_t idx_cur;
    list_entry_t   *start;
    list_entry_t   *end;
    list_entry_t   *cur;
    void    (*_clear_)(ListClass *self);
    bool  (*__add_front__)(ListClass *self, Object *value);
    bool  (*__add_back__)(ListClass *self, Object *value);
    bool  (*__add__)(ListClass *self, Object *value, size_t position);
    bool  (*__del_front__)(ListClass *self);
    bool  (*__del_back__)(ListClass *self);
    bool  (*__del__)(ListClass *self, size_t position);
};

# define len(c)                 (((Container*) c)->__len__(c))
# define begin(c)               (((Container*) c)->__begin__(c))
# define end(c)                 (((Container*) c)->__end__(c))
# define getitem(c, ...)        (((Container*) c)->__getitem__(c, __VA_ARGS__))
# define setitem(c, ...)        (((Container*) c)->__setitem__(c, __VA_ARGS__))

#endif

