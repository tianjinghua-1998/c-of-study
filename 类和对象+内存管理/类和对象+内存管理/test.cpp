#define _CRT_SECURE_NO_WARNINGS 
#include "test.h"
#include "stu.h"
void Test::list(Stu &s)
{
	s.myfun();
}
void Test::show() const
{
	cout << "this is Test::show() " << endl;
}