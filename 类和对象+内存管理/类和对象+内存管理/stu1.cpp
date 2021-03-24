#define _CRT_SECURE_NO_WARNINGS 
#include "stu.h"
#include "test.h"
void Stu:: fun(const Test &t)
{
	t.show();
}
void Stu::myfun()
{
	cout << "this is Stu::myfun()" << endl;
}