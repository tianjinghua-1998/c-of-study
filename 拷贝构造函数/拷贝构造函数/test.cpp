//#define _CRT_SECURE_NO_WARNINGS 
//#include <iostream>
//using namespace std;
//class Test{
//public:
//	Test(int a=10)
//	{
//		m_data = a;
//		cout << "creat test obj:" << this<<endl;
//	}
//	int Getdata()
//	{
//		return m_data;
//	}
//	~Test()
//	{
//		cout << "free test obj:" << this << endl;
//	}
//private:
//	int m_data;
//};
//class Sales_data{
//public:
//	/*Sales_data(const string &s,unsigned n,double p):
//		bookno(s),unit_sold(n),price(p),revenue(p*n) {}*/
//	/*Sales_data(const string &s = "", unsigned n = 4, double p= 10):
//		bookno(s), unit_sold(n), price(p), revenue(p*n) {}*/
//private:
//	string bookno="22222";//书的编号
//	unsigned unit_sold; //数的数量
//	double price;//书的单价
//	double revenue;//书的总价格
//};
//class Test1
//{
//public:
//	//Test1(int x):m_data(x){}
//private:
//	int m_data;
//};
//class Test2
//{
//public:
//	Test1 t1;
//private:
//	int a;
//};
//struct X
//{
//	
//	X(int i, int j) :base(i), rem(base%j){}
//	int rem, base;
//	//初始化的顺序最好和成员声明的顺序保持一致。
//};
//class test
//{
//public:
//	//test(int i = 0):m_data(0){}
//	test() = default;
//private:
//	int m_data;
//};
//void main()
//{
//	/*Test t;
//	int data = t.Getdata();
//	cout << "data =" << data << endl;*/
//	//Sales_data t1;
//	//X s1(2, 3);
//	//Test2 t;
//	//test t1;
//	Test t;
//	Test t1(10);
//}