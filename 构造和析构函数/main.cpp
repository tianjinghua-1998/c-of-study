#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace::std;
//class Person
//{
//public:
//	Person()
//	{
//		index = 0;
//		age = 12;
//		strcpy(name, "zhangsan");
//	}
//	Person(int x,int y, char *s)
//	{
//		index = x;
//		age = y;
//		strcpy(name, s);
//	}
//	Person(Person &copyperson)
//	{
//		index = copyperson.index;
//		age = copyperson.age;
//		strcpy(name,copyperson.name);
//	}
//	int getIndex()
//	{
//		return index;
//	}
//	int getAge()
//	{
//		return age;
//	}
//	char* getName()
//	{
//		return name;
//	}
//private:
//	int index;
//	int age;
//	char name[10];
//};
//int main()
//{
//	/*Person s1;
//	cout << "index = " << s1.getIndex() << endl;
//	cout << "age = " << s1.getAge() << endl;
//	cout << "name = " << s1.getName() << endl;*/
//	Person s2(1, 22, "tianxin");
//	Person s3 = s2;
//	cout << "index = " << s2.getIndex() << endl;
//	cout << "age = " << s2.getAge() << endl;
//	cout << "name = " << s2.getName() << endl;
//	cout << "index = " << s3.getIndex() << endl;
//	cout << "age = " << s3.getAge() << endl;
//	cout << "name = " << s3.getName() << endl;
//}
//析构函数:
class Person
{
public:
	Person();
	Person(int x, char *name, char *gender);
	~Person();
private:
	int age;
	char name[10];
	char gender[10];
};
Person::Person(int x, char *name, char *gender)
{
	cout << "the t1 is created,t1的地址为" << this<<endl;
}
Person::~Person()
{
	cout << "the object is deleted,对象的地址为"<<this << endl;
}
Person::Person()
{
	cout << "the t2 is created，t2的地址为" <<this<< endl;
}
int main()
{
	Person t1(20, "tianxin", "women");
	Person t2;
	return 0;
}
