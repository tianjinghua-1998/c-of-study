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
//		//���� const t:t:Ϊ������;
//		//t.m_data = 100;���ܸ���t��ֵ;
//		//���ã�����Ҫ���ٿռ�;
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
//	//Test t();//������������t����,����û�в�������������ΪTest;
//	//Test t;//����Ĭ��ֵ���캯�����߲��ṩ���������캯��;
//	Test t1(10);
//	// t2.Test(t1);�൱����Test(&t2,t1)
//	//Test t2 = t1;
//	Test t2;
//	//t2 = t1;
//	//fun(t2);
//	//fun(fun(t2));
//	return 0;
//}
