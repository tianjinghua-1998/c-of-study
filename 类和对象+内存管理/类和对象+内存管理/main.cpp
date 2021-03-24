#define _CRT_SECURE_NO_WARNINGS
//#include "stu.h"
//#include "test.h"
#include "common.h"
#include "vld.h"
//int main()
//{
//	Test t;
//	Stu s;
//	s.fun(t);
//	t.list(s);
//	return 0;
//}
//class Date; //前置声明
//class Time
//{
//	friend class Date; //date是time的朋友，那么date可以访问time内的私有成员;
//	//是单向传递的，Time不能访问Date内的成员。
//public:
//	Time(int h = 0, int m = 0, int s = 0)
//		:m_hour(h)
//		, m_minute(m)
//		, m_second(s)
//	{}
//	int getdata()
//	{
//		return m_hour;
//	}
//private:
//	int m_hour;
//	int m_minute;
//	int m_second;
//};
//class Date
//{
//public:
//	Date(int year = 1990, int month = 1, int day = 1)
//		: m_year(year), m_month(month), m_day(day),_t(10,20,30){}
//	void Settime(Time &t)
//	{
//		_t.m_hour = t.m_hour;
//		_t.m_minute = t.m_minute;
//		_t.m_second = t.m_second;
//	}
//private:
//	int m_year;
//	int m_month;
//	int m_day;
//	Time _t;
//};
//int main()
//{
//	Time t2(12, 30, 31);
//	Date t1;
//	//t1.Settime(t2);
//	return 0;
//}
//class String1
//{
//public:
//	String1(const string &s = string()) :ps(new string(s)), i(0){};
//	String1(String1 &a)
//	{
//		ps = new string(*a.ps);
//		i = a.i;
//	}
//	~String1()
//	{
//		delete ps;
//	}
//private:
//	string *ps;
//	int i;
//};
class String1
{
public:
	String1(const char *str="")
	{
		m_data = new char[strlen(str+1)];
		strcpy(m_data, str);
	}
	String1(const String1 &s)
	{
		m_data = new char[strlen(s.m_data + 1)];
		strcpy(m_data, s.m_data);
	}
private:
	char *m_data;

};
int main()
{
	String1 t1("abcdef");
	String1 t2(t1);
	return 0;
}