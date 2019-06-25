/*
** EPITECH PROJECT, 2021
** C++_POOL
** Email: sid.djilali-saiah@epitech.eu
** Created by Sid Djilali Saiah,
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "vertex.h"

typedef struct
{
	Class base;
	int x;
	int y;
	int z;
} VertexClass;

static void Vertex_ctor(VertexClass* self, va_list *ap)
{
	self->x = va_arg(*ap, int);
	self->y = va_arg(*ap, int);
	self->z = va_arg(*ap, int);
}

static void Vertex_dtor(Object* self)
{
	(void) self;
	printf("~Vertex()\n");
}

static int	int_len(int val)
{
	int len = 0;

	if (val < 0)
	{
		val = -val;
		len = 1;
	}
	while (val > 0)
	{
		val /= 10;
		len++;
	}
	return (len);
}

static char	*Vertex_toString(VertexClass *self)
{
	char *str;
	int size;

	size = strlen(self->base.__name__) + int_len(self->x) +
		int_len(self->y) + int_len(self->z) + 10;
	if ((str = malloc(sizeof(char) * size)) == NULL)
		return (NULL);
	memset(str, 0, size);
	snprintf(str, size, "<%s (%i, %i, %i)>", self->base.__name__,
		self->x, self->y, self->z);
	return (str);
}

static	VertexClass _description = {
	{ sizeof (VertexClass), "Vertex", (ctor_t) & Vertex_ctor, NULL,
		(to_string_t) & Vertex_toString},
	0,
	0,
	0
};

Class* Vertex = (Class*) & _description;