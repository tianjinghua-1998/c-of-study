#include "common.h"
class Test
{
	friend class Stu; //Stu���Է���Test�е����г�Ա
public:
	void list(Stu &s);
	void show() const;
private:
	int m_x = 0;
	int m_y = 0;
};