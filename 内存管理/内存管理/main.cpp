#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include "vld.h"
using namespace std;
//class Test
//{
//public:
//	Test(int x=10) :m_data(x){ cout << "this is create obj" << endl; }
//	~Test()
//	{
//		cout << "this is delete obj" << endl;
//	}
//private:
//	int m_data;
//};
//void* operator new(size_t sz)
//{
//	void *ptr = malloc(sz);
//	return ptr;
//}
//void operator delete(void *ptr)
//{
//	free(ptr);
//}
//void main()
//{
//	int *ptr = (int*)_alloca(sizeof(int)* 10);
//}
//int main()
//{
//	//int *a = new int(100);
//	//delete a;
//	//Test *ptr = new Test(10);
//	//delete ptr;
//	//申请对象数组时，必须要有默认的构造函数;
//	Test *ptr = new Test(1);
//	//delete ptr; 不完全释放
//	delete ptr;
//	return 0;
//}

////////////////////////////////////////////////////////
//定位new表达式;
//class Test
//{
//public:
//	Test(int x1=10,int x2=10) :m_data1(x1),m_data2(x2){ cout << "this is create obj" << endl; }
//	~Test()
//	{
//		cout << "this is delete obj" << endl;
//	}
//private:
//	int m_data1;
//	int m_data2;
//};
//void* operator new(size_t sz,void* ptr,int pos)
//{
//	return (Test*)ptr+pos;
//}
//int main()
//{
//	Test t1[10];
//	//new +(已经存在内存空间的地址)+类型+初始化的值;
//	new (t1,4)Test(2,0);
//	return 0;
//}

///////////////////////////////////////////////////////
//        delete[]和operator[]的重载//
//class Test
//{
//public:
//	Test(int x=10) :m_data(x){ cout << "this is create obj" << endl; }
//	~Test()
//	{
//		cout << "this is delete obj" << endl;
//	}
//private:
//	int m_data;
//};
//void* operator new[](size_t sz)
//{
//	void* ptr = malloc(sz);
//	//注意千万不要写才sizeof(sz);sz:已经是所需要空间的字节数了;
//	return ptr;
//}
//void operator delete[](void* ptr)
//{
//	free(ptr);
//	ptr = nullptr;
//}
//int main()
//{
//	Test *ptr=new Test[10];
//	delete[]ptr;
//	return 0;
//}
///////////////////////////////////////////////
///写时拷贝的问题
/////
//class String{
//public:
//	friend ostream& operator<<(ostream& out, const String& t1);
//	String(const char* str="")
//	{
//		m_data = new char[strlen(str) + 1];
//		strcpy(m_data, str);
//	}
//	String(const String& s)
//	{
//		//m_data = s.m_data;
//		m_data = new char[strlen(s.m_data) + 1];
//		strcpy(m_data, s.m_data);
//	}
//	~String()
//	{
//		delete[]m_data;
//	}
//private:
//	char* m_data;
//	static int m_count;
//}; 
//ostream& operator<<(ostream& out, const String& t1)
//{
//	out << t1.m_data;
//	return out;
//}
////代表：m_count:属于string这个作用域
//int String:: m_count = 0;
//int main()
//{
//	String s1("abc");
//	String s2 = s1;
//	cout << s1 << endl;
//	cout << s2 << endl;
//	return 0;
//}
////////这样做的结果，开辟了两个空间，浪费了内存，可以增加引用计数器
////////来实现不开辟新空间
//class String{
//public:
//	friend ostream& operator<<(ostream& out, const String& t1);
//	String(const char* str = "")
//	{
//		m_data = new char[strlen(str) + 1];
//		strcpy(m_data, str);
//		m_count++;
//	}
//	String(const String& s)
//	{
//		m_data = s.m_data;
//		strcpy(m_data, s.m_data);
//		m_count++;
//	}
//	~String()
//	{
//		while (--m_count == 0)
//		{
//			delete[]m_data;
//			m_data = nullptr;
//		}
//	}
//private:
//	char* m_data;
//	static int m_count;
//};
//int String::m_count = 0;
//ostream& operator<<(ostream& out, const String& t1)
//{
//	out << t1.m_data;
//	return out;
//}
//int main()
//{
//	String s1("abc");
//	String s2 = s1;
//	String s3("xyz"); //s3应该有自己的计数器
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << s3 << endl;
//	return 0;
//}


//////////////////////////////////////////////
//即可以实现深拷贝，也可以实现浅拷贝
class String_rep
{
	friend class String;
public:
	String_rep(const char* str="")
	{
		m_data = new char[strlen(str) + 1];
		strcpy(m_data, str);
//指针指向这块空间的首地址;开辟的内存空间是匿名的,没有名字；
//相当于char arr[strlen(str)],自带'\0';
	}
	String_rep(const String_rep& s)
	{
		m_data = s.m_data;
	}
	String_rep& operator=(const String_rep& s)
	{
		if (this != &s)
		{
			this->m_data = s.m_data;
		}
		return *this;
	}
	void increment()
	{
		m_count++;
	}
	void decrement()
	{
		if (--m_count == 0)
			delete this;
		// 这里的this其实就是pn,释放该空间时，需要调用析构函数。
		//从而释放掉m_data的内存空间。
	}
	char* getdata()const
	{
		return m_data;
	}
	~String_rep()
	{
		delete[]m_data;
		m_data = nullptr;
	}
private:

	char *m_data;
	int m_count;
};
class String{
public:
	friend ostream& operator<<(ostream& out, const String& t1);
	String(const char *str="" )
	{
		pn = new String_rep(str);
		pn->increment();
	}
	String(const String& s)
	{
		pn = s.pn;
		pn->increment();
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			pn->decrement();//引用计数器减一，因为该对象指向先前的空间。避免内存泄漏
			pn = s.pn;
			pn->increment();
		}
		return *this;
	}
	void to_upper()
	{
		//新的引用计数器
		String_rep *new_pn = new String_rep(pn->m_data);
		pn->decrement();
		//把之前的空间的引用计数器减一;
		pn = new_pn;
		//指向新的空间；
		pn->increment();
		char *p = pn->m_data;
		while (*p != '\0')
		{
			if (*p >= 'a'&& *p <= 'z')
				*p -= 32;
			p++;
		}
	}
	~String()
	{
		pn->decrement();
	}
private:
	String_rep *pn;
};
ostream& operator<<(ostream& out, const String& t1)
{
	out << t1.pn->getdata();
	return out;
}
int main()
{
	String s1("abc");
	String s2 = s1;
	String s3("xyz"); //s3应该有自己的计数器
	s2 = s3;
	//s3.to_upper();
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	return 0;
}