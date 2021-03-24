#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vld.h>
using namespace::std;
#define DISPLAY
#ifdef DISPLAY
class Date
{
public:
	friend istream& operator>>(istream &in, Date &t);
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
				cout << "月份错误,请重新输入\n" << endl;
				break;
			}
		}
		return ret;
	}

	// 全缺省的构造函数
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		//cout << "create object this is:" << this << endl;
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
		*this = (*this) + day;
		return *this;
	}
	// 日期+天数
	Date operator+(int day)
	{
		Date tmp(*this);
		tmp._day += day;
		while (tmp._day > GetMonthDay(tmp._year,tmp._month))
		{
			tmp._day -= GetMonthDay(tmp._year, tmp._month);
			++tmp._month;
			if (tmp._month == 13)//跨年,如果是12月份,加1变成了1月份。
			{
				tmp._month = 1;
				tmp._year++;
			}
		}
		return tmp;
	}
	// 日期-天数
	Date operator-(int day)
	{
		Date tmp(*this);
		tmp._day = tmp._day - day;
		while (tmp._day<=0)
		{
			--tmp._month;
			if (tmp._month == 0)//跨年，如果是1月份的话，变成0，重新从12开始;
			{
				tmp._month = 12;
				tmp._year--;
			}
			tmp._day = tmp._day + GetMonthDay(tmp._year, tmp._month);
		}
		return tmp;
	}

	// 日期-=天数

	Date& operator-=(int day)
	{
		*this = (*this) - day;
		return *this;
	}
	// 前置++
	//日期+1;
	//++Date;
	Date& operator++()
	{
		*this = (*this) + 1;
		return *this;
	}
	// 后置++
	Date operator++(int)
	{
		Date tmp(*this);
		*this = (*this) + 1;
		return tmp;
	}
	// 后置--

	Date operator--(int)
	{
		Date tmp(*this);
		*this = (*this) - 1;
		return tmp;
	}
	// 前置--

	Date& operator--()
	{
		*this = (*this) - 1;
		return *this;
	}

	// >运算符重载

	bool operator>(const Date& d)
	{
		if (_year > d._year)
			return true;
		else if (_year < d._year)
			return false;
		else 
		{
			if (_month > d._month)
				return true;
			else if (_month < d._month)
				return false;
			else 
			{
				if (_day >d._day)
					return true;
				else
					return false;
			}
		}
	}
	// ==运算符重载
	bool operator==(const Date& d)
	{
		return d._year == _year && d._month == _month && d._day == _day;
	}
	// >=运算符重载

	inline bool operator >= (const Date& d)
	{
		return (*this) > d || (*this) == d;
	}
	// <运算符重载

	bool operator < (const Date& d)
	{
		return !(*this >= d);
	}
	// <=运算符重载

	bool operator <= (const Date& d)
	{
		return (*this) < d || (*this) == d;
	}

	// !=运算符重载

	bool operator != (const Date& d)
	{
		return !((*this) == d);
	}
	// 日期-日期 返回天数
	int operator-(const Date& d)
	{
		//标记位,对象的日期大于t日期
		int day = 0;
		int flag = 1;
		Date max_day = *this;
		Date min_day = d;
		if (*this < d)
		{
			flag = -1;
			max_day = d;
			min_day = *this;
		}
		while (min_day < max_day)
		{
			min_day ++;
			day++;
		}
		return flag*day;
	}
private:
	int _year;
	int _month;
	int _day;
};
//void operator<<(ostream &out, const Date &t)
//{
//	out << t._year << "年 " << t._month << "月 " << t._day << "日" << endl;
//	//return out;
//}
ostream& operator<<(ostream &out, const Date &t)
{
	out << t._year << "年 " << t._month << "月 " << t._day << "日" << endl;
	return out;
}
istream& operator >>(istream &in,  Date &t)
{
	in >> t._year >> t._month >> t._day;
	return in;
}
int main()
{
	Date t1, t2(2000, 2, 23);
	//int x1, y1, z1, x2, y2, z2;
	//Date t2 = t1 + 200;
	//Date t2 = t1 + 200;
	//cin >> x2 >> y2 >> z2;
	//Date t2(x2, y2, z2);
	//t2 ++;
	
	/*if (t2 == t1)
		cout << "t2和t1相等" << endl;
	else if (t2 < t1)
		cout << "t2的日期小于t1的日期" << endl;
	else
		cout << "t2的日期大于t1的日期" << endl;
	int day = t1 - t2;
	cout << "相差的日期为" << day << endl;*/
	return 0;
}
#endif