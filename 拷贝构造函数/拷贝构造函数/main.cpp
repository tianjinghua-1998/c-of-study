#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vld.h>
using namespace std;
class Test
{
public :
	Test(int d = 0)
	{
		m_data = d;
		cout << "Create Test Obj:" << this << endl;
	}
	Test(const Test &t) //Test( Test const *this,const Test &t)
	{
		//加入 const t:t:为常引用;
		//t.m_data = 100;不能更改t的值;
		//引用：不需要开辟空间;
		m_data = t.m_data;
		cout << "Copy Create Test Obj:" << this << endl;

	}
	int GetData()const
	{
		return m_data;
	}
	//Test& operator =(const Test& t)
	//{
	//	m_data = t.m_data;
	//	return *this;//this指针，返回当前对象;
	//	cout << "Assign," << this << " : " << &t << endl;
	//}
	Test& operator=(const Test t)//传递引用：不会调用拷贝复制函数,可以提升效率。
		//operator= 一个组合，看成函数名；
	{
		cout << "Assign," << this << " : " << &t << endl;
		if (this != &t) //用于自身给自己赋值，没有意义；
			m_data = t.m_data;
		return *this;
			//地址不相同的话，利用t对象对当前对象赋值
	}
	//出了函数，引用的对象是否还存在;返回的对象为临时对象（是否受函数作用域的影响）
	
	~Test()
	{
		cout << "Free Test Obj:" << this << endl;
	}
	//取地址运算符
	const Test* operator&()const
	{
		return this;
	}
	void fun()
	{
		cout << "this is fun" << endl;
	}
	void fun()const
	{
		cout << "this is fun() const" << endl;
	}
private:
	int m_data;
};
//Test fun(Test x)
//{
//	int value = x.GetData();
//	Test tmp(value);
//	return tmp;
//}

class string1
{
public:
	string1(const char*str = "")
	{
		//m_data = (char *)malloc(sizeof(str)+1);
		m_data = (char*)malloc(strlen(str) + 1);
		strcpy(m_data, str);
	}
	~string1()
	{
		free(m_data);
		m_data =  nullptr;
	}
private:
	char* m_data;
};
//错误的做法
//Test& fun(Test &x)
//{
//	int value = x.GetData();
//	Test tmp(value);
//	return tmp;
//}
//Test fun(Test &x)
//{
//	int value = x.GetData();
//	return Test(value);//创建临时对象的语法
//}
//Test fun(const Test &x)
//{
//	int value = x.GetData();
//	Test tmp(value);
//	return tmp;//创建临时对象的语法
//}
//不能以引用返回的
Test fun(const Test &x)
{
	int value = x.GetData();
	return Test(value);
}
int main()
{
	//Test t1(10);
	//Test t2;
	//t2 = fun(t1);
	//Test t2 = fun(t1);
	//char arr[] = "my name is tianxin";
	//string1 str1(arr);
    // string1 str2(str1);
	/*int a = 1;
	int b, c;
	c = b = a;*/
	//Test t();//函数的声明，t函数,函数没有参数。返回类型为Test;
	//Test t;//采用默认值构造函数或者不提供参数来构造函数;
	//Test t1(10);
	//// t2.Test(t1);相当于是Test(&t2,t1)
	////Test t2 = t1;
	//Test t2;//首次被初始化;
	//Test t3;
	//t3 = t2 = t1;//赋值语句
	//t2.operator=(t1);//operator(&t2,t1);
	//t2 = t1;
	//fun(t2);
	//fun(fun(t2));
	//Test t(100);
	const Test t(100);
	//pt可以指向任何空间，而t为常对象.
	const Test *pt = &t;
	return 0;
}
