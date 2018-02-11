/*
��ֵ���캯���͸�ֵ������
*/
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Sales_item
{
public:
	//���г�Ա
	Sales_item(const string &book) :isbn(book), units_sold(0), revenue(0) 
	{
		cout << "���캯��Sales_item(const string &book)�������ˣ�" << endl;
	}

	Sales_item() :units_sold(0), revenue(0.0) 
	{
		cout << "Ĭ�ϵĹ��캯���������ˣ�" << endl;
	}

	//���ƹ��캯��
	Sales_item(const Sales_item &orig) :isbn(orig.isbn), units_sold(orig.units_sold), revenue(orig.revenue) 
	{
		cout << "���ƹ��캯���������ˣ�" << endl;
	}

	Sales_item& operator=(const Sales_item &rhs)
	{
		cout << "��ֵ�������������ˣ�" << endl;
		isbn = rhs.isbn;
		units_sold = rhs.units_sold;
		revenue = rhs.revenue;
		return *this;
	}
private:
	string isbn;
	unsigned units_sold;
	double revenue;
};

Sales_item foo(Sales_item item)//һ��ʼ��ʵ�θ�ֵ���βΣ����ƹ��캯����������
{
	Sales_item temp;//Ĭ�ϵĹ��캯����������
	temp = item;//��ֵ���캯����������
	return temp;//����ʱ��temp���Ƹ�һ��ȫ�ֵı��������ƹ��캯����������
}

class NoName
{
public:
	NoName() :pstring(new string), i(0), d(0) {}
	NoName(const NoName& other) :pstring(new string(*(other.pstring))), i(other.i), d(other.d)
	{
		cout << "NoName Copy Constructor" << endl;
	}
	//�����ǵ���������һ�����ݳ�Ա��һ��ָ���ʱ��������Ҫд��ֵ������
	//һ������£�c++�ϳ������������������Ҫ��
	NoName& operator=(const NoName &rhs)
	{
		cout << "NoName ��ֵ������" << endl;
		pstring = new string;
		*pstring = *(rhs.pstring);
		i = rhs.i;
		d = rhs.d;
		return *this;
	}
private:
	string *pstring;
	int i;
	double d;
};

int main()
{
	NoName x, y;
	NoName z(x);//���ƹ��캯��
	x = y;//��ֵ������


	Sales_item a;//Ĭ�Ϲ��캯����������
	cout << endl;

	Sales_item b("0-201-78345-X");//�ض��Ĺ��캯����������
	cout << endl;

	Sales_item c(b);//���ƹ��캯����������
	cout << endl;

	a = b;//��ֵ���캯����������
	cout << endl;

	Sales_item item = string("9-999-99999-9");//�ض��Ĺ��캯����������
	cout << endl;

	cout << endl << "��һ��foo:" << endl;
	Sales_item ret;//Ĭ�Ϲ��캯����������
	ret = foo(item);
	//����ǵȺţ���ֵ���캯����������
	
	vector<Sales_item> svec(5);
	//vector<Sales_item>���ȴ�����һ����ʱ���������õ���Ĭ�ϵĹ��캯��
	//���洴����5��vector���󣬶Դ�������ʱ����������5�θ��ƣ������˸��ƹ��캯��

	cout << endl << "��һ�����飺" << endl;
	Sales_item primer_eds[] = { string("0-201-16487-6"),string("0-201-54848-8"),string("0-201-82470-1"),Sales_item() };
	//ǰ�������ض��Ĺ��캯������class,���һ����ͨ��Ĭ�ϵĹ��캯������һ��class
	return 0;
}