#include "common.h"
class Test
{
	friend class Stu; //Stu可以访问Test中的所有成员
public:
	void list(Stu &s);
	void show() const;
private:
	int m_x = 0;
	int m_y = 0;
};