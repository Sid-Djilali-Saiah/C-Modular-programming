/*
** EPITECH PROJECT, 2021
** C++_POOL
** Email: sid.djilali-saiah@epitech.eu
** Created by Sid Djilali Saiah,
*/

#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "new.h"
#include "raise.h"
#include "point.h"

Object 	*new(Class* class, ...)
{
	Object *object;
	va_list ap;

	va_start(ap, class);
	object = va_new(class, &ap);
	va_end(ap);
	return (object);
}

Object 	*va_new(Class *class, va_list *ap)
{
	Object *obj;
	Class base = *class;

	if (!(obj = malloc(base.__size__)))
		raise("Malloc fail");
	memcpy(obj, class, base.__size__);
	if (base.__init__)
		base.__init__(obj, ap);
	return (obj);
}

void 	delete(Object* ptr)
{
	Class *class;

	if (ptr)
	{
		class = ptr;
		if (class->__del__)
			class->__del__(ptr);
		free(ptr);
	}
}
