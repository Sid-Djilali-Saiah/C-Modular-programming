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
#include "int.h"

static int	int_len(int val)
{
	int	len = 0;

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
	return (len + 1);
}

typedef struct
{
	Class	base;
	int	reccord;
} IntClass;

static void Int_ctor(IntClass *self, va_list *ap)
{
	self->reccord = va_arg(*ap, int);
}

static void Int_dtor(IntClass* self)
{
	(void) self;
	printf("~Int()\n");
}

static	char	*Int_toString(IntClass *self)
{
	char *str;
	int size;

	if (!self)
		return (NULL);
	size = int_len(self->reccord) + 1;
	if ((str = malloc(sizeof(char) * size)) == NULL)
		return (NULL);
	memset(str, 0, size);
	snprintf(str, size, "%i", self->reccord);
	return (str);
}

static Object	*Int_binop_add(const IntClass *lhs,
	const IntClass *rhs)
{
	if (!lhs || !rhs)
		return (NULL);
	return (new(Int, (lhs->reccord + rhs->reccord)));
}

static Object	*Int_binop_sub(const IntClass *lhs,
	const IntClass *rhs)
{
	if (!lhs || !rhs)
		return (NULL);
	return (new(Int, (lhs->reccord - rhs->reccord)));
}

static Object	*Int_binop_mul(const IntClass *lhs,
	const IntClass *rhs)
{
	if (!lhs || !rhs)
		return (NULL);
	return (new(Int, (lhs->reccord * rhs->reccord)));
}

static Object	*Int_binop_div(const IntClass *lhs,
	const IntClass *rhs)
{
	if (!lhs || !rhs || (rhs->reccord == 0))
		return (NULL);
	return (new(Int, (lhs->reccord / rhs->reccord)));
}

static bool	Int_binop_eq(const IntClass *lhs,
	const IntClass *rhs)
{
	if (!lhs || !rhs)
		return (false);
	return (lhs->reccord == rhs->reccord);
}

static bool	Int_binop_lt(const IntClass *lhs,
	const IntClass *rhs)
{
	if (!lhs || !rhs)
		return (false);
	return (lhs->reccord < rhs->reccord);
}

static bool	Int_binop_gt(const IntClass *lhs,
	const IntClass *rhs)
{
	if (!lhs || !rhs)
		return (false);
	return (lhs->reccord < rhs->reccord);
}

static	IntClass _description =
	{
		{
			sizeof (IntClass),
			"Int",
			(ctor_t)&Int_ctor,
			(dtor_t)&Int_dtor,
			(to_string_t)&Int_toString,
			(binary_operator_t)&Int_binop_add,
			(binary_operator_t)&Int_binop_sub,
			(binary_operator_t)&Int_binop_mul,
			(binary_operator_t)&Int_binop_div,
			(binary_comparator_t)&Int_binop_eq,
			(binary_comparator_t)&Int_binop_gt,
			(binary_comparator_t)&Int_binop_lt
		},
		0
	};

Class* Int = (Class*)&_description;