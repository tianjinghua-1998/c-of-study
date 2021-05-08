#define _CRT_SECURE_NO_WARNINGS 
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
namespace tianxin
{
	template<typename T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		typedef size_t size_type;
		//构造一个空的数组;
		vector() :first(nullptr), last(nullptr), _end(nullptr){}
		vector(int n, const T& value = T()) :first(nullptr), last(nullptr), _end(nullptr)
		{
			reserve(n);
			while (n--)
			{
				push_back(value);
			}
		}
		template<class InputIterator>
		vector(InputIterator start, InputIterator finish) :first(nullptr), last(nullptr), _end(nullptr)
		{
				reserve(finish - start);
				while ( start!= finish)
				{
					//push_back(*start);
					//start++;
					*last= *start;
					start++;
					last++;
				}
				_end = last;
		}
		void push_back(const T& x)
		{
			insert(last, x);
		}
		iterator begin()
		{
			return first;
		}
		iterator end()
		{
			return last;
		}
		size_type size()const
		{
			return last - first;
		}
		size_type capacity() const
		{
			return _end - first;
		}
		//x的默认参数为T();
		void reserve(size_t n)
		{
			//n大于容量
			if (n > capacity())
			{
				//以前的容量大小;
				size_type old_size = size();
				T *new_base = new T[n];
				//注意最后一个是字节数。
				memcpy(new_base, first, old_size*sizeof(T));
				delete[]first;
				first = new_base;
				last = new_base + old_size;
				_end = new_base + n;
			}
		}
		void resize(size_t n, const T& x = T())
		{
			if (n <= size())
			{
				last = first + n;
			}
			if (n > capacity())
			{
				reserve(n);
			}
			//错误代码:
			/*{
				iterator end = last;
				for (iterator end =last; end<last + n - size(); end++)
				{
				*end = x;
				}
				last = end;
				}*/
			///////////自己写的
			/*iterator end = last;
			for (;end<last+n-size();end++)
			{
			*end= x;
			}
			last = end;*/
			///////////////////////////////
			iterator cur = last;
			last = first + n;
			while (cur != last)
			{
				*cur = x;
				++cur;
			}
		}
		iterator insert(iterator it, const T& x = T())
		{
			//空间不够的话需要扩容
			//将原有的内存空间拷贝过来
			if (last == _end)
			{
				size_t p_size = it - first;
				size_t new_size = size() == 0 ? 1 : size() * 2;
				reserve(new_size);
				it = first + p_size;
			}
			iterator end = last;
			while (end > it)
			{
				*end = *(end - 1);
				end--;
			}
			*it = x;
			++last;
			return it;


		}

	private:
		iterator first;
		iterator last;
		iterator _end;
	};
}
int main()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	tianxin::vector<int> v(arr,arr+5);
	/*v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);*/
	

	for (auto &e : v)
		cout << e << " ";
	cout << endl;
	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;
	//v.reserve(10);
	v.resize(10, 10);
	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;
	for (auto &e : v)
		cout << e << " ";
	cout << endl;
}
//int main()
//{
//	std::vector<int> myvector;
//
//	// set some initial content:
//	for (int i = 1; i<10; i++) myvector.push_back(i);
//
//	myvector.resize(5);
//	myvector.resize(8);
//	//myvector.resize(12);
//	std::cout << "myvector contains:";
//	for (int i = 0; i<myvector.size(); i++)
//		std::cout << ' ' << myvector[i];
//	std::cout << '\n';
//
//	return 0;
//}
/*
void main()
{
	vector<int> v;
	auto pos = v.begin();
	pos=v.insert(pos, 10);
	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;
	pos=v.insert(pos, 20);
	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;
	v.reserve(50);
	//迭代器会失效,如果不添加pos=v.begin()的话。因为重新开辟了空间
	//之前的pos所指向的空间已经被释放了。
	//让迭代器重新指向现在开辟的空间
	pos = v.begin();
	v.insert(pos, 30);
	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;
	for (auto &e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	
}
*/
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 0, 6, 7, 8, 9, 10 };
//	int n = sizeof(arr) / sizeof(int);
//	vector<int> v(arr, arr + n);
//	auto it = v.begin();
//	while (it != v.end())
//	{
//		if (*it != 0)
//		{
//			cout << *it;
//		}
//		else
//			v.erase(it);
//		it++;
//	}
//	return 0;
//}
//int main()
//{
//	int arr[] = { 10,10,20,20,20,30,40 };
//	int n = sizeof(arr) / sizeof(int);
//	vector<int> v(arr, arr + n);
//	auto it2=unique(v.begin(), v.end());
//	cout << *it2 << endl;
//	/*v.resize(distance(v.begin(),it2));
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;*/
//	return 0;
//}
//int main()
//{
//	vector<int>array;
//	array.push_back(100);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(500);
//	vector<int>::iterator itor;
//	for (itor = array.begin(); itor != array.end(); itor++)
//	{
//		if (*itor == 300)
//		{
//			itor = array.erase(itor);
//		}
//	}
//	for (itor = array.begin(); itor != array.end(); itor++)
//	{
//		cout << *itor << " ";
//	}
//	return 0;
//}
//void printvector(const vector<int>& v)
//{
//	auto it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << endl;
//		it++;
//	}
//	cout << endl;
//}
//int main()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	auto it = v.begin();
//	while (it != v.begin())
//	{
//		*it *= 2;
//		++it;
//	}
//	vector<int>::reverse_iterator rit = v.rbegin();
//	while (rit != v.rend())
//	{
//		cout << *rit << endl;
//		++rit;
//	}
//	cout << endl;
//	printvector(v);
//	return 0;
//}
//int main()
//{
//	int arr[] = { 2, 3, 4, 10, 8, 9 };
//	int n = sizeof(arr) / sizeof(int);
//	vector<int> v(arr, arr + n);
//	cout << "size = " << v.size() << endl;
//	cout << "capcity= " << v.capacity() << endl;
//	//v.reserve(20);
//	auto it = find(v.begin(), v.end(), 10);
//	cout << "*it= " << *it << endl;
//	//重新申请了一块空间，之前的迭代器会失效。大小为20
//	//v.reserve(20);
//	//当size大小不够时,会自动扩容;
//	v.push_back(3);
//	it = find(v.begin(), v.end(), 10);
//	cout << "capcity= " << v.capacity() << endl;
//	//list的插入不会导致迭代器失效;
//	cout << "*it=" << *it << endl;
//}
//int main()
//{
//	//int arr[] = { 2, 3, 4, 10, 8, 9 };
//	int arr[] = { 2, 3, 4, 10, 9 };
//	int n = sizeof(arr) / sizeof(int);
//	vector<int> v(arr, arr + n);
//	auto it = find(v.begin(), v.end(), 10);
//	v.erase(it);
//	cout << *it << endl;
//	for (auto &e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
//int main()
//{
//	vector<int> empty;
//	vector<int> second(4, 100);
//	vector<int> third(second);
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
//	int n = sizeof(arr) / sizeof(int);
//	vector<int> four(arr, arr + n);
//	four.push_back(78);
//	cout << "weibu=" << four.back() << endl;
//	vector<int> five(four.begin(), four.end());
//	for (auto it = four.begin(); it != four.end(); ++it)
//	{
//		cout << " " << *it;
//	}
//	cout << endl;
//	for (vector<int>::iterator it = five.begin(); it != five.end(); ++it)
//	{
//		cout << " " << *it;
//	}
//	cout << endl;
//	vector<string> fruit{ "apple", "banana", "orange" };
//	cout << "first fruit=" << *fruit.begin() << endl;
//	//cout << endl;
//	//vector<string> words1{ "I", "love", "you" };
//	//cout << "words" << words1.begin() << endl;
//}