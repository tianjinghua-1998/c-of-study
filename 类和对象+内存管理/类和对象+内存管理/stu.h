#include "common.h"
class Stu
{
	friend class Test;
public:
	void fun(const Test &t);
public:
	void myfun();
private:
	int m_x = 0;
	int m_y = 0;
};