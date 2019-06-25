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
<<<<<<< HEAD
	char			*out;
=======
	char	*out;
>>>>>>> 66aeb4beaef42209870d8678e9eb17d6d9f18fbf

	if (!s)
		return (NULL);
	if (!(out = malloc((sizeof(char *) * n) + 1)))
		return (NULL);
	strncpy(out, s, n);
	out[n] = '\0';
	return (out);
}
<<<<<<< HEAD
=======

>>>>>>> 66aeb4beaef42209870d8678e9eb17d6d9f18fbf
typedef struct
{
	Class	base;
	char	reccord;
} CharClass;
<<<<<<< HEAD
=======

>>>>>>> 66aeb4beaef42209870d8678e9eb17d6d9f18fbf
static void Char_ctor(CharClass *self, va_list *ap)
{
	self->reccord = (char)va_arg(*ap, int);
}
<<<<<<< HEAD
=======

>>>>>>> 66aeb4beaef42209870d8678e9eb17d6d9f18fbf
static void Char_dtor(CharClass* self)
{
	(void) self;
	printf("~Char()\n");
}
<<<<<<< HEAD
=======

>>>>>>> 66aeb4beaef42209870d8678e9eb17d6d9f18fbf
static	char	*Char_toString(CharClass *self)
{
	if (!self)
		return (NULL);
	return (cs_copy_n(&self->reccord, 1));
}
<<<<<<< HEAD
static Object	*Char_binop_add(const CharClass *lhs, const CharClass *rhs)
=======

static Object	*Char_binop_add(const CharClass *lhs,
	const CharClass *rhs)
>>>>>>> 66aeb4beaef42209870d8678e9eb17d6d9f18fbf
{
	if (!lhs || !rhs)
		return (NULL);
	return (new(Char, (lhs->reccord + rhs->reccord)));
}
<<<<<<< HEAD
static Object	*Char_binop_sub(const CharClass *lhs, const CharClass *rhs)
=======

static Object	*Char_binop_sub(const CharClass *lhs,
	const CharClass *rhs)
>>>>>>> 66aeb4beaef42209870d8678e9eb17d6d9f18fbf
{
	if (!lhs || !rhs)
		return (NULL);
	return (new(Char, (lhs->reccord - rhs->reccord)));
}
<<<<<<< HEAD
static Object	*Char_binop_mul(const CharClass *lhs, const CharClass *rhs)
=======

static Object	*Char_binop_mul(const CharClass *lhs,
	const CharClass *rhs)
>>>>>>> 66aeb4beaef42209870d8678e9eb17d6d9f18fbf
{
	if (!lhs || !rhs)
		return (NULL);
	return (new(Char, (lhs->reccord * rhs->reccord)));
}
<<<<<<< HEAD
static Object	*Char_binop_div(const CharClass *lhs, const CharClass *rhs)
=======

static Object	*Char_binop_div(const CharClass *lhs,
	const CharClass *rhs)
>>>>>>> 66aeb4beaef42209870d8678e9eb17d6d9f18fbf
{
	if (!lhs || !rhs || (rhs->reccord == 0))
		return (NULL);
	return (new(Char, (lhs->reccord / rhs->reccord)));
}
<<<<<<< HEAD
static bool	Char_binop_eq(const CharClass *lhs, const CharClass *rhs)
{
	if (!lhs || !rhs)
		return (false);
	return (lhs->reccord == rhs->reccord);	
}
static bool	Char_binop_lt(const CharClass *lhs, const CharClass *rhs)
{
	if (!lhs || !rhs)
		return (false);
	return (lhs->reccord < rhs->reccord);	
}
static bool	Char_binop_gt(const CharClass *lhs, const CharClass *rhs)
{
	if (!lhs || !rhs)
		return (false);
	return (lhs->reccord < rhs->reccord);	
}
/*static Object	*char_binop_(const CharClass *lhs, const CharClass *rhs)
{
	if (!lhs || !rhs)
		return (NULL);
	return (new(Char, (lhs->reccord + rhs->reccord)));	
}*/
=======

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

>>>>>>> 66aeb4beaef42209870d8678e9eb17d6d9f18fbf
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