#include<iostream>
#include<list>
#include<vector>
#include<algorithm>

using namespace std;
struct absInt//Ҳ����˵һ��struct������classҲ�����������ĺ���һ������һ����������һ������
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
		cout << element <<' ';//�������������
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

	//for_each�����������������е����ݶ����������ͬʱ
	for_each(a.begin(), a.end(), displayElement<int>());
	cout << endl;

	for_each(b.begin(), b.end(), displayElement<char>());
	cout << endl;//ͨ��for_each������list�������е����ݶ��������

	int i = -42;
	absInt absObj;//����һ��struct����
	unsigned int ui = absObj(i);
	cout << ui << endl;

	return 0;
}