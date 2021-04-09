#define _CRT_SECURE_NO_WARNINGS 
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
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
void printvector(const vector<int>& v)
{
	auto it = v.begin();
	while (it != v.end())
	{
		cout << *it << endl;
		it++;
	}
	cout << endl;
}
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
int main()
{
	//int arr[] = { 2, 3, 4, 10, 8, 9 };
	int arr[] = { 2, 3, 4, 10, 9 };
	int n = sizeof(arr) / sizeof(int);
	vector<int> v(arr, arr + n);
	auto it = find(v.begin(), v.end(), 10);
	v.erase(it);
	cout << *it << endl;
	for (auto &e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}