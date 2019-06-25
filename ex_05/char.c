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
#include "char.h"

static char	*cs_copy_n(char *s, size_t n)
{
	char	*out;

	if (!s)
		return (NULL);
	if (!(out = malloc((sizeof(char *) * n) + 1)))
		return (NULL);
	strncpy(out, s, n);
	out[n] = '\0';
	return (out);
}

typedef struct
{
	Class	base;
	char	reccord;
} CharClass;

static void Char_ctor(CharClass *self, va_list *ap)
{
	self->reccord = (char)va_arg(*ap, int);
}

static void Char_dtor(CharClass* self)
{
	(void) self;
	printf("~Char()\n");
}

static	char	*Char_toString(CharClass *self)
{
	if (!self)
		return (NULL);
	return (cs_copy_n(&self->reccord, 1));
}

static Object	*Char_binop_add(const CharClass *lhs,
	const CharClass *rhs)
{
	if (!lhs || !rhs)
		return (NULL);
	return (new(Char, (lhs->reccord + rhs->reccord)));
}

static Object	*Char_binop_sub(const CharClass *lhs,
	const CharClass *rhs)
{
	if (!lhs || !rhs)
		return (NULL);
	return (new(Char, (lhs->reccord - rhs->reccord)));
}

static Object	*Char_binop_mul(const CharClass *lhs,
	const CharClass *rhs)
{
	if (!lhs || !rhs)
		return (NULL);
	return (new(Char, (lhs->reccord * rhs->reccord)));
}

static Object	*Char_binop_div(const CharClass *lhs,
	const CharClass *rhs)
{
	if (!lhs || !rhs || (rhs->reccord == 0))
		return (NULL);
	return (new(Char, (lhs->reccord / rhs->reccord)));
}

static bool	Char_binop_eq(const CharClass *lhs,
	const CharClass *rhs)
{
	if (!lhs || !rhs)
		return (false);
	return (lhs->reccord == rhs->reccord);
}

static bool	Char_binop_lt(const CharClass *lhs,
	const CharClass *rhs)
{
	if (!lhs || !rhs)
		return (false);
	return (lhs->reccord < rhs->reccord);
}

static bool	Char_binop_gt(const CharClass *lhs,
	const CharClass *rhs)
{
	if (!lhs || !rhs)
		return (false);
	return (lhs->reccord < rhs->reccord);
}

static	CharClass _description =
{
	{
		sizeof (CharClass),
		"Char",
		(ctor_t)&Char_ctor,
		(dtor_t)&Char_dtor,
		(to_string_t)&Char_toString,
		(binary_operator_t)&Char_binop_add,
		(binary_operator_t)&Char_binop_sub,
		(binary_operator_t)&Char_binop_mul,
		(binary_operator_t)&Char_binop_div,
		(binary_comparator_t)&Char_binop_eq,
		(binary_comparator_t)&Char_binop_gt,
		(binary_comparator_t)&Char_binop_lt
	},
	0
};

Class* Char = (Class*)&_description;