#include <stdlib.h>
#include "raise.h"
#include "object.h"
#include "bool.h"
#include "new.h"
#include "container.h"
#include "list.h"
#ifdef Char
# undef Char
#endif
#include "char.h"
#include "float.h"
#ifdef Int
# undef Int
#endif
#include "int.h"
/*
void compareAndDivide(Object* a, Object* b)
{
	if (gt(a, b))
		printf("a > b\n");
	else if (lt(a, b))
		printf("a < b\n");
	else
		printf("a == b\n");
	printf("b / a = %s\n", str(div(b, a)));
}

static Object	*c1;
static Object	*c2;
static Object	*f1;
static Object	*f2;
static Object	*i1;
static Object	*i2;

//static Object	*v1;
//static Object	*v2;
void 	tests_new(void)
{
	printf("| Test: new\n");
	c1 = new(Char, 'b');
	c2 = new(Char, 'b');
	f1 = new(Float, 1.500);
	f2 = new(Float, 1.5);
	i1 = new(Int, 15);
	i2 = new(Int, 15);
	//v1 = new(Vertex, 1, 2, 3);
	//v2 = new(Vertex, 4, 5, 6);
	printf("+--------------------------------------------+\n");
}
void	tests_destroy()
{
	printf("| Test: destroy\n");
	printf("+--------------------------------------------+\n");
}
void	tests_str(void)
{
	printf("| Test: str\n");
	printf("|\tc1 = %s\n", str(c1));
	printf("|\tc2 = %s\n", str(c2));
	printf("|\tf1 = %s\n", str(f1));
	printf("|\tf2 = %s\n", str(f2));
	printf("|\ti1 = %s\n", str(i1));
	printf("|\ti2 = %s\n", str(i2));
	//printf("|\tv1 = %s\n", str(v1));
	//printf("|\tv2 = %s\n", str(v2));
	printf("+--------------------------------------------+\n");
}
void	tests_add(void)
{
	printf("| Test: add\n");
	printf("|\t%s + %s = %s\n", str(c1), str(c2), str(add(c1, c2)));
	printf("|\t%s + %s = %s\n", str(f1), str(f2), str(add(f1, f2)));
	printf("|\t%s + %s = %s\n", str(i1), str(i2), str(add(i1, i2)));
	//printf("|\t%s + %s = %s\n", str(v1), str(v2), str(add(v1, v2)));
	printf("+--------------------------------------------+\n");}
void	tests_sub(void)
{
	printf("| Test: sub\n");
	printf("|\t%s - %s = %s\n", str(c1), str(c2), str(sub(c1, c2)));
	printf("|\t%s - %s = %s\n", str(f1), str(f2), str(sub(f1, f2)));
	printf("|\t%s - %s = %s\n", str(i1), str(i2), str(sub(i1, i2)));
	//printf("|\t%s - %s = %s\n", str(v1), str(v2), str(sub(v1, v2)));
	printf("+--------------------------------------------+\n");
}
void	tests_mul()
{
	printf("| Test: mul\n");
	printf("|\t%s * %s = %s\n", str(c1), str(c2), str(mul(c1, c2)));
	printf("|\t%s * %s = %s\n", str(f1), str(f2), str(mul(f1, f2)));
	printf("|\t%s * %s = %s\n", str(i1), str(i2), str(mul(i1, i2)));
	printf("+--------------------------------------------+\n");
}
void	tests_div()
{
	printf("| Test: div\n");
	printf("|\t%s / %s = %s\n", str(f1), str(f2), str(div(f1, f2)));
	printf("|\t%s / %s = %s\n", str(i1), str(i2), str(div(i1, i2)));
	printf("+--------------------------------------------+\n");
}
void	tests_eq()
{
	printf("| Test: eq\n");
	printf("|\t%s == %s = %c\n", str(c1), str(c2), eq(c1, c2) + '0');
	printf("|\t%s == %s = %c\n", str(f1), str(f2), eq(f1, f2) + '0');
	printf("|\t%s == %s = %c\n", str(i1), str(i2), eq(i1, i2) + '0');
	printf("+--------------------------------------------+\n");
}
void	tests_gt()
{
	printf("| Test: gt\n");
	printf("|\t%s > %s = %c\n", str(c1), str(c2), gt(c1, c2) + '0');
	printf("|\t%s > %s = %c\n", str(f1), str(f2), gt(f1, f2) + '0');
	printf("|\t%s > %s = %c\n", str(i1), str(i2), gt(i1, i2) + '0');
	printf("+--------------------------------------------+\n");
}
void	tests_lt()
{
	printf("| Test: lt\n");
	printf("|\t%s < %s = %c\n", str(c1), str(c2), lt(c1, c2) + '0');
	printf("|\t%s < %s = %c\n", str(f1), str(f2), lt(f1, f2) + '0');
	printf("|\t%s < %s = %c\n", str(i1), str(i2), lt(i1, i2) + '0');
	printf("+--------------------------------------------+\n");
}*/
static ListClass *list;
static Object* it;
static Object* it_end;
int main()
{
	IntClass	*i0 = new(Int, 5);
	IntClass	*i1 = new(Int, 6);
	IntClass	*i2 = new(Int, 99);
	Class 		*tmp;

	printf("+--------------------------------------------+\n");
	printf("|                                            |\n");
	printf("|                    EX06                    |\n");
	printf("|                                            |\n");
	printf("+--------------------------------------------+\n");
  list = new(List, Int);
  printf("list size: %zu\n", len((Container *)list));
  list->__add_back__(list, i0);
  list->__add_front__(list, i1);
  list->__add__(list, i2, 1);
  printf("list size: %zu\n", len((Container *)list));
  it = begin((Container *)list);
  it_end = end((Container *)list);
  while (lt(it, it_end))
  {
    tmp = getval(it);
    printf("\t-%s\n", str(tmp));
    incr(it);
  }
  delete(it);
 	printf("after delete it.\n");  
  delete(it_end);
   	printf("after delete it_end.\n");
  delete(list);
 	printf("after delete list.\n");
	/*tests_new();
	tests_str();
	tests_add();
	tests_sub();
	tests_mul();
	tests_div();
	tests_eq();
	tests_gt();
	tests_lt();
	tests_destroy();
	compareAndDivide(c1, c2);
	compareAndDivide(f1, f2);*/
	return (0);
}