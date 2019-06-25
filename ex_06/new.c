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

Object 	*new(Class* class, ...)
{
	Object *object;
	va_list ap;

<<<<<<< HEAD
	if (!class)
		return (NULL);
=======
>>>>>>> 66aeb4beaef42209870d8678e9eb17d6d9f18fbf
	va_start(ap, class);
	object = va_new(class, &ap);
	va_end(ap);
	return (object);
}

Object 	*va_new(Class *class, va_list *ap)
{
	Object *object;
	Class base = *class;

	if (!(object = malloc(base.__size__)))
		raise("Malloc fail");
	memcpy(object, class, base.__size__);
	if (base.__init__)
		base.__init__(object, ap);
	return (object);
}

void 	delete(Object* ptr)
{
	Class *base;

<<<<<<< HEAD
	if (!ptr)
		return ;

	base = ptr;
	if (base->__del__)
		base->__del__(ptr);
	free(ptr);
}
=======
	if (ptr)
	{
		base = ptr;
		if (base->__del__)
			base->__del__(ptr);
		free(ptr);
	}
}
>>>>>>> 66aeb4beaef42209870d8678e9eb17d6d9f18fbf
