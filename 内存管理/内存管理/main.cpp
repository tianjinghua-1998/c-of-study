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
//	//�����������ʱ������Ҫ��Ĭ�ϵĹ��캯��;
//	Test *ptr = new Test(1);
//	//delete ptr; ����ȫ�ͷ�
//	delete ptr;
//	return 0;
//}

////////////////////////////////////////////////////////
//��λnew���ʽ;
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
//	//new +(�Ѿ������ڴ�ռ�ĵ�ַ)+����+��ʼ����ֵ;
//	new (t1,4)Test(2,0);
//	return 0;
//}

///////////////////////////////////////////////////////
//        delete[]��operator[]������//
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
//	//ע��ǧ��Ҫд��sizeof(sz);sz:�Ѿ�������Ҫ�ռ���ֽ�����;
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
///дʱ����������
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
////����m_count:����string���������
//int String:: m_count = 0;
//int main()
//{
//	String s1("abc");
//	String s2 = s1;
//	cout << s1 << endl;
//	cout << s2 << endl;
//	return 0;
//}
////////�������Ľ���������������ռ䣬�˷����ڴ棬�����������ü�����
////////��ʵ�ֲ������¿ռ�
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
//	String s3("xyz"); //s3Ӧ�����Լ��ļ�����
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << s3 << endl;
//	return 0;
//}


//////////////////////////////////////////////
//������ʵ�������Ҳ����ʵ��ǳ����
class String_rep
{
	friend class String;
public:
	String_rep(const char* str="")
	{
		m_data = new char[strlen(str) + 1];
		strcpy(m_data, str);
//ָ��ָ�����ռ���׵�ַ;���ٵ��ڴ�ռ���������,û�����֣�
//�൱��char arr[strlen(str)],�Դ�'\0';
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
		// �����this��ʵ����pn,�ͷŸÿռ�ʱ����Ҫ��������������
		//�Ӷ��ͷŵ�m_data���ڴ�ռ䡣
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
			pn->decrement();//���ü�������һ����Ϊ�ö���ָ����ǰ�Ŀռ䡣�����ڴ�й©
			pn = s.pn;
			pn->increment();
		}
		return *this;
	}
	void to_upper()
	{
		//�µ����ü�����
		String_rep *new_pn = new String_rep(pn->m_data);
		pn->decrement();
		//��֮ǰ�Ŀռ�����ü�������һ;
		pn = new_pn;
		//ָ���µĿռ䣻
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
	String s3("xyz"); //s3Ӧ�����Լ��ļ�����
	s2 = s3;
	//s3.to_upper();
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	return 0;
}