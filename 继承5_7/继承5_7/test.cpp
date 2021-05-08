#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <string>
using namespace std;
class person
{
public:
	person(const char* name) :_name(name)
	{
		cout << "person()" << endl;
	}
	person(const person& p) :_name(p._name)
	{
		cout << "person(const person& p)" << endl;
	}
	person& operator=(const person& p)
	{
		if (this != &p)
		{
			_name = p._name;
		}
		cout << "person& operator=(const person& p)" << endl;
		return *this;
	}
	~person()
	{
		cout << "~person()" << endl;
	}
private:
	string _name;
};
class student :public person
{
public:
	//因为person没有默认的构造函数，person里面的const char *name没有给初始值,所以尽量一般
	//都显示初始化;
	/*student(const char *name="tianjinghua", int num=12) :_num(num)
	{
		cout << "student()" << endl;
	}*/
	student(const char *name = "tianjinghua", int num = 12) :person(name),_num(num)
	{
		cout << "student()" << endl;
	}
	student(const student&s) :person(s), _num(s._num)
	{
		cout << "student(const student&s)" << endl;
	}
	student& operator=(const student &s)
	{
		if (this != &s)
		{
			_num = s._num;
		}
		cout << "student& operator=(const student &s)" << endl;
		return *this;
	}
	~student()
	{
		cout << "~student()" << endl;
	}
private:
	int _num;
};
void main()
{
	student s1;
	student s2(s1);
	student s3("rose", 27);
	s1 = s3;

	
}
//class Person
//{
//protected:
//	string _name = "小李子"; // 姓名
//	int _num = 111; // 身份证号
//};
//
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " 姓名:" << _name << endl;
//		cout << " 身份证号:" << Person::_num << endl;
//		cout << " 学号:" << _num << endl;
//	}
//protected:
//	int _num = 999; // 学号
//};
//
//void main()
//{
//	Student s;
//	s.Print();
//}
//class Base
//{
//public:
//	Base(int a = 0) :m_a(a)
//	{
//		//cout<<"Base::Base()"<<endl;
//	}
//	~Base()
//	{
//		//cout<<"Base::~Base()"<<endl;
//	}
//public:
//	void fun()
//	{
//		cout << "Base::fun()" << endl;
//	}
//	void fun(int a)
//	{
//		cout << "Base::fun(int)" << endl;
//	}
//	void list()
//	{
//		cout << "Base::list()" << endl;
//	}
//
//private:
//	int m_a;
//	int m_b;
//	int m_c;
//};
//class D : public Base
//{
//public:
//	D(int d = 0) :m_d(d)
//	{
//		//cout<<"D::D()"<<endl;
//	}
//	~D()
//	{
//		//cout<<"D::~D()"<<endl;
//	}
//public:
//	void show()
//	{
//		cout << "D::show()" << endl;
//	}
//	//同名隐藏
//	void fun()
//	{
//		cout << "D::fun()" << endl;
//	}
//	/*void fun(int a)
//	{
//		cout << "D::fun(int)" << endl;
//	}*/
//private:
//	int m_d;
//};
//void main()
//{
//	Base b;
//	D d;
//	//b.fun();
//	//d.show();
//	d.fun();
//	d.Base::fun(10);
//
//}
//class A
//{
//public:
//	A(int a = 0) : m_a(a)
//	{
//		cout << "A::A()" << endl;
//	}
//public:
//	void fun()
//	{
//		cout << "This is A::fun()" << endl;
//	}
//	void call()
//	{
//		print();
//	}
//protected:
//	void show()
//	{
//		cout << "This is A::show()" << endl;
//	}
//private:
//	void print()
//	{
//		cout << "This is A::print()" << endl;
//	}
//private:
//	int m_a;
//};
//
//
//class D :private A
//{
//public:
//	D(int d = 0) :m_d(d)
//	{
//		cout << "D::D()" << endl;
//	}
//public:
//	void list()
//	{
//		fun();
//		show();
//		//继承方式为私有，在父类中为共有,故最终在子类中为私有成员;自己的公有函数访问
//		//自己的私有函数是被允许的。
//		call();
//	}
//private:
//	int m_d;
//};
//class E :public D
//{
//public:
//	void fun()
//	{
//		//这里的call不可以访问，因为call()已经是D中的私有数据
//		call();
//	}
//};
//
//int main()
//{
//	D d;
//	d.list();
//	E e;
//	//d.fun();
//	//d.list();
//	return 0;
//}