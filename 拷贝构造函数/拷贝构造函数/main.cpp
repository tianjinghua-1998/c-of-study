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
		//���� const t:t:Ϊ������;
		//t.m_data = 100;���ܸ���t��ֵ;
		//���ã�����Ҫ���ٿռ�;
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
	//	return *this;//thisָ�룬���ص�ǰ����;
	//	cout << "Assign," << this << " : " << &t << endl;
	//}
	Test& operator=(const Test t)//�������ã�������ÿ������ƺ���,��������Ч�ʡ�
		//operator= һ����ϣ����ɺ�������
	{
		cout << "Assign," << this << " : " << &t << endl;
		if (this != &t) //����������Լ���ֵ��û�����壻
			m_data = t.m_data;
		return *this;
			//��ַ����ͬ�Ļ�������t����Ե�ǰ����ֵ
	}
	//���˺��������õĶ����Ƿ񻹴���;���صĶ���Ϊ��ʱ�����Ƿ��ܺ����������Ӱ�죩
	
	~Test()
	{
		cout << "Free Test Obj:" << this << endl;
	}
	//ȡ��ַ�����
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
//���������
//Test& fun(Test &x)
//{
//	int value = x.GetData();
//	Test tmp(value);
//	return tmp;
//}
//Test fun(Test &x)
//{
//	int value = x.GetData();
//	return Test(value);//������ʱ������﷨
//}
//Test fun(const Test &x)
//{
//	int value = x.GetData();
//	Test tmp(value);
//	return tmp;//������ʱ������﷨
//}
//���������÷��ص�
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
	//Test t();//������������t����,����û�в�������������ΪTest;
	//Test t;//����Ĭ��ֵ���캯�����߲��ṩ���������캯��;
	//Test t1(10);
	//// t2.Test(t1);�൱����Test(&t2,t1)
	////Test t2 = t1;
	//Test t2;//�״α���ʼ��;
	//Test t3;
	//t3 = t2 = t1;//��ֵ���
	//t2.operator=(t1);//operator(&t2,t1);
	//t2 = t1;
	//fun(t2);
	//fun(fun(t2));
	//Test t(100);
	const Test t(100);
	//pt����ָ���κοռ䣬��tΪ������.
	const Test *pt = &t;
	return 0;
}
