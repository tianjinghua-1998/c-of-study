//#define _CRT_SECURE_NO_WARNINGS 
//#include <iostream>
//using namespace std;
//class Test
//{
//public :
//	Test(int d = 0)
//	{
//		m_data = d;
//		cout << "Cretea Test Obj:" << this << endl;
//	}
//	Test(const Test &t) //Test( Test const *this,const Test &t)
//	{
//		//加入 const t:t:为常引用;
//		//t.m_data = 100;不能更改t的值;
//		//引用：不需要开辟空间;
//		m_data = t.m_data;
//		cout << "Copy Create Test Obj:" << this << endl;
//
//	}
//	int GetData()const
//	{
//		return m_data;
//	}
//	/*Test& operator =(const Test& t)
//	{
//		m_data = t.m_data;
//		cout << "Assign," << this << " : " << &t << endl;
//	}*/
//	~Test()
//	{
//		cout << "Free Test Obj:" << this << endl;
//	}
//private:
//	int m_data;
//};
//Test fun(Test x)
//{
//	int value = x.GetData();
//	Test tmp(value);
//	return tmp;
//}
//int main()
//{
//	//Test t();//函数的声明，t函数,函数没有参数。返回类型为Test;
//	//Test t;//采用默认值构造函数或者不提供参数来构造函数;
//	Test t1(10);
//	// t2.Test(t1);相当于是Test(&t2,t1)
//	//Test t2 = t1;
//	Test t2;
//	//t2 = t1;
//	//fun(t2);
//	//fun(fun(t2));
//	return 0;
//}
