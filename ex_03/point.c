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
#include "point.h"
#include "new.h"

typedef struct
{
	Class base;
	int x;
	int y;
} PointClass;

static void Point_ctor(PointClass* self, va_list *ap)
{
	self->x = va_arg(*ap, int);
	self->y = va_arg(*ap, int);
}
static void Point_dtor(Object* self)
{
	(void) self;
	printf("~Point()\n");
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

static char	*Point_toString(PointClass *self)
{
	char *str;
	int size;

	if (!self)
		return (NULL);
	size = strlen(self->base.__name__) + int_len(self->x) +
		int_len(self->y) + 10;
	if ((str = malloc(sizeof(char) * size)) == NULL)
		return (NULL);
	memset(str, 0, size);
	snprintf(str, size, "<%s (%i, %i)>", self->base.__name__, self->x,
		self->y);
	return (str);
}
static Object	*Point_binop_add(const PointClass *lhs,
	const PointClass *rhs)
{
	if (!lhs || !rhs)
		return (NULL);
	return (new(Point, (lhs->x + rhs->x), (lhs->y + rhs->y)));
}
static Object	*Point_binop_sub(const PointClass *lhs,
	const PointClass *rhs)
{
	if (!lhs || !rhs)
		return (NULL);
	return (new(Point, (lhs->x - rhs->x), (lhs->y - rhs->y)));
}
static	PointClass _description =
{
	{
		sizeof (PointClass),
		"Point",
		(ctor_t)&Point_ctor,
		(dtor_t)&Point_dtor,
		(to_string_t)&Point_toString,
		(binary_operator_t)&Point_binop_add,
		(binary_operator_t)&Point_binop_sub
	},
	0,
	0
};

Class* Point = (Class*) & _description;