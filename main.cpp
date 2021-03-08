#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
#include<iostream>
using namespace std;
//int& fun(int a, int b)
//{
//	static int v;
//	v = a + b;
//	return v;
//}
//namespace N1
//{
//	int a = 10;
//	int b = 20;
//};
//namespace N2
//{
//	int a = 30;
//	int b = 40;
//};
//namespace Output
//{
//	void Show()
//	{
//		cout << "output's function" << endl;
//	}
//	namespace Myname
//	{
//		void Demo()
//		{
//			cout << "myname's function" << endl;
//		}
//	}
//}
//using namespace N1;
//void main()
//{
//	cout << "N1.a = " << a << endl;
//	/*cout << "N1.a= " << N1::a << endl;
//	cout << "N2.a= " << N2::a << endl;*/
//}
//void Test(int a,int b=30,int c=40)
//{
//	cout << "a =" << a <<endl;
//	cout << "b =" << b << endl;
//	cout << "c =" << c << endl;
//
//}
//int Add(int a, int b)
//{
//	return a + b;
//}
//double Add(int a ,int b)
//{
//	return a + b;
//}
//double Add(double a, double b)
//{
//	return a + b;
//}
//void main()
//{
//	//Add(2, 3);
//}
//void main()
//{
//	Test(100,200,300);//a=100;
//	Test(20);// a=20;b=30;c=40;
//}
//void main()
//{
//	int &res = fun(10, 20);
//	fun(1, 2);
//	int count = 9;
//	int c = count--;
//	cout << "c= " << c << endl;
//	cout << "count= " << count << endl;
//	cout << "res = " << res << endl;
//	cout << "res = " << res << endl;
//}
void Swap(  int& a,  int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
//void main()
//{
//	/*int a = 10;
//	int &ra = a;
//	int &rb = a;
//	int arr[5] = { 1, 2, 3, 4, 5 };
//	int(&br)[5] = arr;
//	cout << "ra = " << ra << endl;
//	cout << "rb= " << rb << endl;
//	cout << "a= " << a << endl;
//	cout << "ra的地址为" << &ra << endl;
//	cout << "rb的地址为" << &rb << endl; 
//	cout << "a的地址为" << &a << endl;*/
//	//const int a = 10;
//	//int &ra = a
//	//int& ra = a; // 该语句编译时会出错，a为常量
//	//const int& ra = a;
//	 //const int b = 10; // 该语句编译时会出错，b为常量
//	//const int& b = 10;
//	//double d = 12.34;
//	//int& rd = d; // 该语句编译时会出错，类型不同
//	//const int& rd = d;
//}
int& Add(int x, int y)
{
	static int c = x + y;
	return c;
}
void f(int)
{
	cout << "f(int)" << endl;
}
void f(int*)
{
	cout << "f(int*)" << endl;
}
void main()
{
	/*int a = 4;
	int b = 6;
	cout << "a= " << a << " b= " << b << endl;
	Swap(a, b);
	cout << "a= " << a << " b= " << b << endl;*/
	int &ret = Add(1, 2);
	Add(2, 3);
	cout << "ret = " << ret << endl;
	cout << "ret = " << ret << endl;
	//int *p = NULL;
	int *p = nullptr;
	f(0);
	f(nullptr);
	f((int*)NULL);
	
}
