/*
** EPITECH PROJECT, 2021
** C++_POOL
** Email: sid.djilali-saiah@epitech.eu
** Created by Sid Djilali Saiah,
*/

#include <string.h>
#include "new.h"
#include "raise.h"

void 	*new(Class *class)
{
	Object *obj;

	if ((obj = malloc(class->__size__)) == NULL)
		raise("Out of Memory");
	memcpy(obj, class, class->__size__);
	if (class->__init__)
		class->__init__(obj);
	return (obj);
}

void	delete(Object* ptr)
{
	Class *class;

	class = ptr;
	if (class->__del__)
		class->__del__(ptr);
	free(ptr);
}