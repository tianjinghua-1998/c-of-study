//#define _CRT_SECURE_NO_WARNINGS 
//#define _CRT_SECURE_NO_WARNINGS 
//#include <iostream>
//using namespace std;
//class tmp{
//public:
//	tmp()
//	{
//		++N;
//		sum += N;
//	}
//	~tmp()
//	{}
//	//static void reset(){ N = 0; sum = 0; }
//	static unsigned int  getsum()
//	{
//		return sum;
//	}
//private:
//	static unsigned int N;
//	static unsigned int sum;
//};
//unsigned int tmp::N = 0;
//unsigned int tmp::sum = 0;
//class Solution1 {
//public:
//	int Sum_Solution(int n)
//	{
//		//tmp::reset();
//		tmp *a = new tmp[n];
//		delete[]a;
//		a = nullptr;
//		return tmp::getsum();
//	}
//};
//
//int main()
//{
//	Solution1 s1;
//	int ret = s1.Sum_Solution(4);
//	cout << "ret == " << ret << endl;
//	return 0;
//}
#include <iostream>
using namespace std;
class C{
public:
	C()
	{
		cout << "c的创建" << endl;
	}
	~C()
	{
		cout << "c的析构" << endl;
	}
};
class A{
public:
	A()
	{
		cout << "a的创建" << endl;
	}
	~A()
	{
		cout << "a的析构" << endl;
	}
};
class D{
public:
	D()
	{
		cout << "d的创建" << endl;
	}
	~D()
	{
		cout << "d的析构" << endl;
	}
};
class B{
public:
	B()
	{
		cout << "b的创建" << endl;
	}
	~B()
	{
		cout << "b的析构" << endl;
	}
};
C c1;
int main()
{
	A*pa = new A();
	B b;
	static D d;
	delete pa;
	return 0;
}