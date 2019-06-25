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
#include "new.h"
#include "float.h"

typedef struct
{
	Class	base;
	float	reccord;
} FloatClass;

static int	int_len(int val)
{
	int len = 0;

	if (val < 0) {
		val = -val;
		len = 1;
	}
	while (val > 0) {
		val /= 10;
		len++;
	}
	return (len);
}

char *float_to_str(float nb)
{
	char	*number;
	int 	int_1 = (int)nb;
	int 	alloc = int_len(int_1);

	alloc += 11;
	if ((number = malloc(sizeof(char) * (alloc))))
		snprintf(number , alloc, "%f", nb);
	else
		return (NULL);
	return (number);
}

static void Float_ctor(FloatClass *self, va_list *ap)
{
	self->reccord = va_arg(*ap, double);
}

static void Float_dtor(FloatClass* self)
{
	(void) self;
	printf("~Float()\n");
}

static	char	*Float_toString(FloatClass *self)
{
	if (!self)
		return (NULL);
	return (float_to_str(self->reccord));
}

static Object	*Float_binop_add(const FloatClass *lhs,
	const FloatClass *rhs)
{
	if (!lhs || !rhs)
		return (NULL);
	return (new(Float, (lhs->reccord + rhs->reccord)));
}

static Object	*Float_binop_sub(const FloatClass *lhs,
	const FloatClass *rhs)
{
	if (!lhs || !rhs)
		return (NULL);
	return (new(Float, (lhs->reccord - rhs->reccord)));
}

static Object	*Float_binop_mul(const FloatClass *lhs,
	const FloatClass *rhs)
{
	if (!lhs || !rhs)
		return (NULL);
	return (new(Float, (lhs->reccord * rhs->reccord)));
}

static Object	*Float_binop_div(const FloatClass *lhs,
	const FloatClass *rhs)
{
	if (!lhs || !rhs || (rhs->reccord == 0))
		return (NULL);
	return (new(Float, (lhs->reccord / rhs->reccord)));
}

static bool	Float_binop_eq(const FloatClass *lhs,
	const FloatClass *rhs)
{
	if (!lhs || !rhs)
		return (false);
	return (lhs->reccord == rhs->reccord);
}

static bool	Float_binop_lt(const FloatClass *lhs,
	const FloatClass *rhs)
{
	if (!lhs || !rhs)
		return (false);
	return (lhs->reccord < rhs->reccord);
}

static bool	Float_binop_gt(const FloatClass *lhs, const FloatClass *rhs)
{
	if (!lhs || !rhs)
		return (false);
	return (lhs->reccord < rhs->reccord);
}

static	FloatClass _description =
	{
		{
			sizeof (FloatClass),
			"Float",
			(ctor_t)&Float_ctor,
			(dtor_t)&Float_dtor,
			(to_string_t)&Float_toString,
			(binary_operator_t)&Float_binop_add,
			(binary_operator_t)&Float_binop_sub,
			(binary_operator_t)&Float_binop_mul,
			(binary_operator_t)&Float_binop_div,
			(binary_comparator_t)&Float_binop_eq,
			(binary_comparator_t)&Float_binop_gt,
			(binary_comparator_t)&Float_binop_lt
		},
		0
	};

Class* Float = (Class*)&_description;