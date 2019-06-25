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
#include "new.h"

typedef struct
{
	Class base;
	int x;
	int y;
	int z;
} VertexClass;

static	void Vertex_ctor(VertexClass* self, va_list *ap)
{
	self->x = va_arg(*ap, int);
	self->y = va_arg(*ap, int);
	self->z = va_arg(*ap, int);
}

static	int	int_len(int val)
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

static	void Vertex_dtor(Object* self)
{
	(void) self;
	printf("~Vertex()\n");
}
static	char	*Vertex_toString(VertexClass *self)
{
	char *str;
	int size;

	if (!self)
		return (NULL);
	size = strlen(self->base.__name__) + int_len(self->x) +
		int_len(self->y) + int_len(self->z) + 10;
	if ((str = malloc(sizeof(char) * size)) == NULL)
		return (NULL);
	memset(str, 0, size);
	snprintf(str, size, "<%s (%i, %i, %i)>", self->base.__name__,
		self->x, self->y, self->z);
	return (str);
}

static Object	*Vertex_binop_add(const VertexClass *lhs,
	const VertexClass *rhs)
{
	if (!lhs  || !rhs)
		return (NULL);
	return (new
	(
		Vertex,
		lhs->x + rhs->x,
		lhs->y + rhs->y,
		lhs->z + rhs->z
	));
}

static Object	*Vertex_binop_sub(const VertexClass *lhs,
	const VertexClass *rhs)
{
	if (!lhs  || !rhs)
		return (NULL);
	return (new
	(
		Vertex,
		lhs->x + rhs->x,
		lhs->y + rhs->y,
		lhs->z + rhs->z
	));
}

static	VertexClass _description =
{
	{
		sizeof (VertexClass),
		"Vertex",
		(ctor_t)&Vertex_ctor,
		(dtor_t)&Vertex_dtor,
		(to_string_t)&Vertex_toString,
		(binary_operator_t)&Vertex_binop_add,
		(binary_operator_t)&Vertex_binop_sub
	},
	0,
	0,
	0
};

Class* Vertex = (Class*)&_description;