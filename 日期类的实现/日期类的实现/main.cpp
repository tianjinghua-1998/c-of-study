#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vld.h>
using namespace::std;
class Date
{
public:
	friend ostream& operator<<(ostream &out, const Date &t);
	// 获取某年某月的天数
	int GetMonthDay(const int year, const int month)
	{
		int ret = 0;
		if (month == 2)
		{
			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
			{
				ret = 29;
			}
			else
				ret = 28;
		}
		else
		{
			switch (month)
			{
			case 1:case 3:case 5:case 7:case 8:case 10:case 12:
				ret = 31;
				break;
			case 4: case 6 :case 9:case 11:
				ret = 30;
				break;
			default:
				cout << "输入月份错误,请重新输入\n" << endl;
				break;
			}
		}
		return ret;
		//int arr[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	}

	// 全缺省的构造函数
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "create object this is:" << this << endl;
	}
	// 拷贝构造函数
	// d2(d1)

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}



	// 赋值运算符重载

	// d2 = d3 -> d2.operator=(&d2, d3)

	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	// 析构函数

	~Date()
	{

	}



	// 日期+=天数

	Date& operator+=(int day)
	{

	}
	// 日期+天数
	Date operator+(int day)
	{
		int ret = GetMonthDay(_year, _month);
		
		if ((this->_day + day) <= ret)
		{
			_day = _day + day;
			return *this;
		}
		else
		{
			Date tmp(*this);
			int tmp1 = tmp._day + GetMonthDay(this->_year, this->_month);
			int tmpd = day;
			while (tmp1 <= tmpd)
			{
				day = day - GetMonthDay(tmp._year, tmp._month);
				tmp._month++;
				tmp1 += GetMonthDay(tmp._year, tmp._month);
			}
			tmp._month++;
			day = day - GetMonthDay(tmp._year, tmp._month - 1);
			tmp._day = tmp._day + day;
			return tmp;
		}
		
	}



	// 日期-天数

	Date operator-(int day);



	// 日期-=天数

	Date& operator-=(int day);



	// 前置++

	Date& operator++();



	// 后置++

	Date operator++(int);



	// 后置--

	Date operator--(int);



	// 前置--

	Date& operator--();

	// >运算符重载

	bool operator>(const Date& d);



	// ==运算符重载

	bool operator==(const Date& d);



	// >=运算符重载

	inline bool operator >= (const Date& d);



	// <运算符重载

	bool operator < (const Date& d);



	// <=运算符重载

	bool operator <= (const Date& d);



	// !=运算符重载

	bool operator != (const Date& d);



	// 日期-日期 返回天数

	int operator-(const Date& d);

private:

	int _year;

	int _month;

	int _day;

};
ostream& operator<<(ostream &out, const Date &t)
{
	out << t._year << "年 " << t._month << "月 " << t._day << "日" << endl;
	return out;
}
int main()
{
	Date t1(2020, 4, 29);
	Date t2 = t1 + 200;
	cout << t2 << endl;
	return 0;
}
