/*
��������
������������ȡ��Դ
�����������ͷ���Դ
�ϳɵ���������
������:���д��������������һ��Ҫд���ƹ��캯������ֵ������
*/
#include<iostream>
#include<string>
using namespace std;
/*
���һ������Ҫ�����ݿ�
��̬�����ڴ�
����Ҫʹ����������������򵥵�c++�Դ��ĺϳɵ����������Ѿ��������ǵ���Ҫ
*/

class Sales_item
{
public:
private:
	double units_sold;
};

class NoName
{
private:
	string *pstring;
	int i;
	double d;
public:
	NoName() :pstring(new string), i(0), d(0) {}
	~NoName();

	NoName(const NoName& rhs);
	NoName& operator=(const NoName &rhs);
};

NoName::NoName(const NoName &other)
{
	pstring = new string;
	*pstring = *(other.pstring);
	i = other.i;
	d = other.d;
}

NoName& NoName::operator=(const NoName &rhs)
{
	pstring = new string;
	*pstring = *(rhs.pstring);
	i = rhs.i;
	d = rhs.d;
	return *this;
}

NoName::~NoName()
{
	cout << "����������������!\n" << endl;
	delete pstring;
}

int main()
{
	NoName a;

	NoName *p = new NoName;
	cout << "Hello\n" << endl;
	return 0;
}