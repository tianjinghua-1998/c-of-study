#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <assert.h>
#include <vld.h>
using namespace::std;
//#define DISPLAY 
class String
{
public:
	String(char const* str="")
	{
		data = (char*)malloc(strlen(str) + 1);
		strcpy(data, str);
#ifdef DISPLAY
		cout << "create object:" << this << endl;
#endif
	}
	//拷贝构造函数
	String(const String &s)
	{
		this->data = (char*)malloc(strlen(s.data) + 1);
		assert(data);
		strcpy(this->data, s.data);
#ifdef DISPLAY
		cout << "copy object:" << this << endl;
#endif
	}
	String& operator=(const String &s)
	{
		if (this != &s)
		{
			free(this->data);//释放原先所指向的空间
			//无论拷贝也好，赋值也罢，都会申请出来指针所指向的空间;
			this->data = (char*)malloc(strlen(s.data) + 1);
			strcpy(this->data, s.data);
		}
#ifdef DISPLAY
		cout << "fuzhi object:" << this << endl;
#endif
		return *this;
	}
	~String()
	{
		free(data);
		data = nullptr;
#ifdef DISPLAY
		cout << "delete object:" << this << endl;
#endif

	}
private:
	char* data;
};
int main()
{
	char arr[] = "hello,c++";
	String s1(arr);
	//String s2 = s1;
	String s3;
	s3 = s1;
	return 0;
}