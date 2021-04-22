#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <queue>
using namespace std;
#include <functional>
namespace bit
{
	//bit::priority_queue<int> 
	template < class T, class Container = vector<T>,
	class Compare=less<T>>
	class priority_queue
	{
	public:
		priority_queue()
		{}
		priority_queue(const T *first, const T *last, const Compare& pr = Compare()) :
			c(first, last), comp(pr)
		{
			//���һ����֧�Ľ��;
			//int curpos = c.size() - 2 / 2 = c.size() / 2 - 1;
			int curpos = c.size() / 2 - 1;
			while (curpos >= 0)
			{
				_adjustdown(curpos);
				curpos--;
			}
		}
		bool empty() const
		{
			return c.empty();
		}
		size_t size() const
		{
			return c.size();
		}
		T& top()const
		{
			return c.front();
		}
		void push(const T& x)
		{
			c.push_back(x);
			_adjustup(c.size() - 1);
		}
		void pop()
		{
			std::swap(*c.begin(), *--c.end());
			c.pop_back();//ɾ�����һ��Ԫ�أ�
			_adjustdown(0);
		}
		void Show()const
		{
			for (int i = 0; i < c.size(); ++i)
				cout << c[i] << " ";
			cout << endl;
		}
	protected:
		void _adjustdown(int start)
		{
			int i = start, j = 2 * i + 1;
			//�ӽڵ㣬���ڵ�;
			int n = c.size();
			T tmp = c[i];
			while (j < n) //����Ƿ����λ��,�������Ƿ����
			{
				//j+1С��n�������Ҳ��ֵܽ����ڵ�ǰ���£��Ƚϣ����j<j+1;
				
				if (j + 1 < n&& comp(c[j],c[j+1]))
					j++;
				if (comp(tmp,c[j]))
				{
					c[i] = c[j];
					i = j;
					j = 2 * i + 1;
				}
				else
					break;
			}
			c[i] = tmp;
		}
		void _adjustup(int start)
		{
			//�ӽڵ�
			int j = start;
			//�����
			int i = (j - 1) / 2;

			while (j > 0)
			{
				//�����ڵ�С���ӽڵ��ʱ�򣬽��н���
				if (comp(c[i],c[j]))
				{
					T tmp = c[i];
					c[i] = c[j];
					c[j] = tmp;
					j = i;
					i = (j - 1) / 2;
				}
				else
					break;
			}
		}
	private:
		Container c;
		Compare comp;
	};
};
void main()
{
	int ar[] = { 53, 17, 78, 9, 45,30};
	int n = sizeof(ar) / sizeof(ar[0]);
	/*bit::priority_queue<int, vector<int>, greater<int>>
		pq(ar, ar + n, greater<int>());*/
	bit::priority_queue<int, vector<int>> pq(ar, ar + n);
	//bit::priority_queue<int> pq(ar, ar+n);
	//pq.pop();
	//bit::priority_queue<int> pq;
	//pq.push(50);
	//pq.pop();
	pq.Show();
}
//namespace bit
//{
//	template<class T, class Cont = vector<T>, class Pred = less<T> >
//	class priority_queue
//	{
//	public:
//		typedef T value_type;
//		typedef size_t size_type;
//	public:
//		explicit priority_queue(const Pred& pr = Pred()) : sz(0)
//		{}
//		//��ʱ����
//		priority_queue(const value_type *first, const value_type *last,
//			const Pred& pr = Pred()) :c(first, last)
//		{
//			//less ��    ��   greater С
//			make_heap(c.begin(), c.end(), pr);
//			sz = c.size();
//		}
//
//		bool empty() const
//		{
//			return sz == 0;
//		}
//		size_type size() const
//		{
//			return sz;
//		}
//		value_type& top()
//		{
//			return c.front();
//		}
//		const value_type& top() const
//		{
//			return c.front();
//		}
//
//		void pop()
//		{
//			pop_heap(c.begin(), c.end());
//			sz--;
//		}
//
//		void push(const value_type& x)
//		{
//			c.push_back(x);
//			push_heap(c.begin(), c.end());
//			sz++;
//		}
//
//		void Show()const
//		{
//			for (int i = 0; i<c.size(); ++i)
//				cout << c[i] << " ";
//			cout << endl;
//		}
//	protected:
//		Cont c;
//		Pred comp;
//		size_t sz;
//	};
//};
//void main()
//{
//	int ar[] = { 5, 9, 2, 4, 1 };
//	int n = sizeof(ar) / sizeof(ar[0]);
//
//	//bit::priority_queue<int,vector<int>, greater<int>> 
//	//	pq(ar, ar+n, greater<int>());
//
//	bit::priority_queue<int,vector<int>,greater<int>> pq(ar, ar + n,greater<int>());
//
//	pq.Show();
//}
//struct int_less
//{
//	bool operator()(void* elem1, void *elem2)
//	{
//		return *(int*)elem1 < *(int*)elem2;
//	}
//};
//void my_qsort(void *base,
//	size_t num,
//	size_t width,
//	int_less Pr = int_less())
//{
//	void *tmp = malloc(width);
//	for (int i = 0; i<num - 1; ++i)
//	{
//		for (int j = 0; j<num - i - 1; ++j)
//		{
//			//base[j]                       base[j+1]
//			//if(((char*)base)+j*width > ((char*)base)+(j+1)*width)
//			if (Pr(((char*)base) + j*width, ((char*)base) + (j + 1)*width))
//			{
//				memcpy(tmp, ((char*)base) + j*width, width);
//				memcpy(((char*)base) + j*width, ((char*)base) + (j + 1)*width, width);
//				memcpy(((char*)base) + (j + 1)*width, tmp, width);
//			}
//		}
//	}
//}

//void main()
//{
//	int ar[] = { 5, 8, 30, 2, 1, 4, 9, 7 }; //
//	int n = sizeof(ar) / sizeof(ar[0]);
//
//	for (int i = 0; i<n; ++i)
//		cout << ar[i] << " ";
//	cout << endl;
//
//	my_qsort(ar, n, sizeof(int), int_less());
//
//	for (int i = 0; i<n; ++i)
//		cout << ar[i] << " ";
//	cout << endl;
//}
//int main()
//{
//	vector<int> v{ 3, 4, 2, 10, 8, 9, 20 };
//	std::priority_queue<int> q1;
//	for (auto& e : v)
//	{
//		q1.push(e);
//	}
//	cout << q1.top() << endl;
//	priority_queue<int, vector<int>, greater<int>> q2(v.begin(), v.end());
//	cout << q2.top() << endl;
//	return 0;
//}