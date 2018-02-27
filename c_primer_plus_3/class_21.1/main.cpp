#include<iostream>
#include<list>
#include<vector>
#include<algorithm>

using namespace std;
struct absInt//也就是说一个struct或者是class也可以像正常的函数一样，像一个函数对象一样操作
{
	int operator()(int val)
	{
		return val > 0 ? val : -val;
	}
};
template<typename elementType>
void Funcdisplayelement(elementType& element)
{
	cout << element << ' ';
}

template<typename elementType>
struct displayElement
{
	void operator()(elementType& element) const
	{
		cout << element <<' ';//数据输入的数据
	}
};

int main()
{
	vector<int> a;
	list<char> b;

	for (int i = 1; i < 9; i++)
		a.push_back(i);

	for (char i = 'a'; i < 'k'; i++)
		b.push_back(i);

	//for_each函数让向量里面所有的数据都输出出来，同时
	for_each(a.begin(), a.end(), displayElement<int>());
	cout << endl;

	for_each(b.begin(), b.end(), displayElement<char>());
	cout << endl;//通过for_each函数将list里面所有的数据都输出出来

	int i = -42;
	absInt absObj;//创建一个struct对象
	unsigned int ui = absObj(i);
	cout << ui << endl;

	return 0;
}