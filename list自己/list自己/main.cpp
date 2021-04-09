#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <assert.h>
#include "vld.h"
using namespace std;
namespace tianjinghua
{
	template <class T> class list; //前置声明一下;
	template <typename T, typename Ref, typename Ptr> class list_iterator;
	//template <typename T>
	//class Node
	//{
	//	friend class list<T>;
	//	friend class list_iterator<T,T&,T*>;
	//public:
	//	//Node() :_prev(nullptr),_next(nullptr),_value(T()) {}
	//	Node(Node* prev = nullptr, Node* next = nullptr, const T &val = T()) :_prev(prev), _next(next), _value(val){}
	//private:
	//	Node<T>* _prev;
	//	Node<T>* _next;
	//	T _value;
	//};
	template<class T>
	struct Node
	{
		Node(Node* prev = nullptr, Node* next = nullptr, const T &val = T()) :_prev(prev), _next(next), _value(val){}
		Node* _prev;
		Node* _next;
		T _value;
	};
	template <class T>
	class list
	{
	public:
		typedef Node<T> Node;//重新定义结点类型为Node;
		typedef Node* PNode;//定义模板结点的指针;
		typedef list_iterator<T, T&, T*> iterator;
		typedef list_iterator<T, const T&, const T*> const_iterator;
	public:
		list() :size(0)
		{
			createhead();
		}
		//构造n个这样的结点;
		list(int n, const T &value = T())
		{
			createhead();
			while (n--)
			{
				insert(begin(), value); //尾部插入T,插入n次。
			}
		}
		list(T *f, T *l)
		{
			createhead();
			while (f != l)
			{
				push_back(*f);
				++f;
			}
		}
		template <class iterator>
		list(iterator first, iterator last)
		{
			createhead();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		//拷贝构造函数
		list(list<T>& l)
		{
			/*head = l.head;
			size = l.size;*/
			this->createhead();
			//创建头结点;
			//创建临时对象;
			list tmp(l.begin(), l.end());
			//交换头结点;使得该结点指向:tmp申请的结点,而tmp指向的结点指向头结点
			//便于释放;
			swap(tmp.head,head);
			//tmp.head = nullptr;
			//swap(tmp);
			size = l.size;
		}
		~list()
		{
			clear();
			delete head;
			head = nullptr;
		}
	public:
		void swap(PNode& t1,PNode& t2)
		{
			PNode tmp = t1;
			t1 = t2;
			t2 = tmp;
		}
		/*void swap(list& l)
		{
			PNode tmp = head;
			head = l.head;
			l.head = tmp;
		}*/
		//list()
		//template <class iterator>
		////////////////////////////

		iterator begin()
		{
			return iterator(head->_next);
		}
		iterator end()
		{
			return iterator(head);
		}
		PNode _Buycode(PNode prev = 0, PNode next = 0)
		{
			PNode s = new Node;
			assert(s);
			s->_next = next != 0 ? next : s;
			s->_prev = prev != 0 ? prev : s;
			return s;
		}
		iterator insert(iterator pos, const T& val)
		{
			//zai pos之前插入，当前结点的前驱为pos内部指针的prev;当前结点的后继为pos指向的指针
			PNode z = _Buycode(pos._mynode()->_prev, pos._mynode());
			z->_prev->_next = z;
			z->_next->_prev = z;
			z->_value = val;
			size++;
			return iterator(z);
		}
		iterator erase(iterator pos)
		{
			PNode s = pos._mynode();
			//尽量使用前++,不会产生临时的无名对象,减少一次拷贝构造和析构;
			++pos;
			//前一个和后一个相连接;
			s->_next->_prev = s->_prev;
			s->_prev->_next = s->_next;
			//释放结点
			delete s;
			s = nullptr;
			size--;
			return pos;
		}
		void push_back(const T& val)
		{
			insert(end(), val);
		}
		void push_front(const T& val)
		{
			insert(begin(), val);
		}
		void pop_back()
		{
			erase(--end());
		}
		void pop_front()
		{
			erase(begin());
		}
		void clear()
		{
			iterator p = begin();
			while (p != end())
			{
				p = erase(p);
			}
		}
	private:
		void createhead()
		{
			head = new Node;
			head->_next = head;
			head->_prev = head;
			size = 0;
		}
	private:
		PNode head;
		//head的类型为模板的类型:即为类型名<模板参数>
		size_t size;
	};
	template <typename T, typename Ref, typename Ptr>
	class list_iterator
	{
		typedef Node<T>* pNode; //对模板类型重新进行定义
		typedef list_iterator<T, Ref, Ptr>  Self;// 元素值, T的引用，T的地址;
	public:
		list_iterator(pNode pNode = nullptr) :_pNode(pNode){}
		//拷贝构造函数

		list_iterator(const Self& l)
		{
			_pNode = l._pNode;
		}
		T& operator*()
		{
			return _pNode->_value;
		}
		//取对应的链表元素的地址
		T* operator->()
		{
			return &(*this);
		}
		Self& operator++()
		{
			_pNode = _pNode->_next;
			return *this;//返回该迭代器;
		}
		Self operator++(int)
		{
			Self tmp(*this);
			++(*this);
			return tmp;
		}
		Self& operator--()
		{
			_pNode = _pNode->_prev;
			return *this;
		}
		//前面加了const,代表该引用为常引用，即不能通过l改变它引用的对象。
		bool operator==(const Self& l)
		{
			return _pNode->_value == l._pNode->_value;
		}
		bool operator !=(const Self& l)
		{
			return !(*this == l);
		}
		pNode _mynode()
		{
			return _pNode;
		}
	private:
		pNode _pNode;
	};

}

//int main()
//{
//	tianjinghua::list <int> mylist;
//	mylist.push_back(1);
//	mylist.push_back(2);
//	mylist.push_back(3);
//	tianjinghua::list<int>::iterator it = mylist.begin();
//	cout << *it << endl;
//	cout << *(++it) << endl;
//	return 0;
//}

//int main()
//{
//	tianjinghua::list <int> mylist;
//	mylist.push_back(1);
//	mylist.push_back(2);
//	mylist.push_back(3);
//	tianjinghua::list <int> mylist2(mylist.begin(), mylist.end());
//	auto it = mylist2.begin();
//	while (it != mylist2.end())
//	{
//		cout << *it << endl;
//		it++;
//	}
//	return 0;
//}
//int main()
//{
//	/*tianjinghua::list <int> mylist(10, 2);
//	auto it = mylist.begin();
//	while (it != mylist.end())
//	{
//		cout << *it<<" "; 
//		it++;
//	}*/
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	size_t sz = sizeof(arr) / sizeof(arr[0]);
//	tianjinghua::list<int> mylist(arr, arr + 10);
//	auto it = mylist.begin();
//	while (it != mylist.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;	
//	return 0;
//}
//int main()
//{
//	tianjinghua::list<int> mylist;
//	mylist.push_front(1);
//	mylist.push_front(2);
//	mylist.push_front(3);
//	mylist.push_front(4);
//	auto it = mylist.begin();
//	while (it != mylist.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//	return 0;
//}
//int main()
//{
//	tianjinghua::list<int> mylist;
//	mylist.push_front(1);
//	mylist.push_front(2);
//	mylist.push_front(3);
//	mylist.push_front(4);
//	mylist.pop_front();
//	auto it = mylist.begin();
//	while (it != mylist.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//	return 0;
//}
//int main()
//{
//	tianjinghua::list<int> mylist;
//	mylist.push_front(1);
//	mylist.push_front(2);
//	mylist.push_front(3);
//	mylist.push_front(4);
//	tianjinghua::list<int> mylist2 = mylist;
//	auto it = mylist2.begin();
//	while (it != mylist2.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//	return 0;
//}
//int main()
//{
//	tianjinghua::list<int> mylist;
//	mylist.push_front(1);
//	mylist.push_front(2);
//	mylist.push_front(3);
//	mylist.push_front(4);
//	int arr[5] = { 10, 2, 3, 4, 5 };
//	tianjinghua::list<int> mylist2(arr, arr + 5);
//	auto it = mylist.begin();
//	auto it2 = mylist2.begin();
//	if (it == it2)
//		cout << "it和it2相等" << endl;
//	else
//		cout << "两者不相等" << endl;
//	return 0;
//}
#include <list>
int main()
{
	int ar[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int n = sizeof(ar) / sizeof(int);
	list<int> mylist(ar, ar + n);
	list<int>::iterator pos = find(mylist.begin(), mylist.end(), 5);
	reverse(mylist.begin(), pos);
	reverse(pos, mylist.end());
	for (auto & e :mylist)
		cout << e << " ";
	cout << endl;
}