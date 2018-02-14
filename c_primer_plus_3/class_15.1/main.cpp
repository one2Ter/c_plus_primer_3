//操作符重载
#include<iostream>
#include<string>
using namespace std;

class Dog
{

};

class Sales_item
{
public:
	friend ostream& operator<<(ostream& out, const Sales_item& s);
	friend istream& operator >> (istream& in, Sales_item& s);

	Sales_item(string &book,unsigned units,double price):
		isbn(book),units_sold(units),revenue(units*price){}
	Sales_item() :units_sold(0), revenue(0.0) {}

private:
	string isbn;
	unsigned units_sold;
	double revenue;
};

ostream& operator<<(ostream& out, const Sales_item& s)
{
	out << s.isbn << "\t" << s.units_sold << "\t" << s.revenue;
	return out;
}

istream& operator >> (istream& in, Sales_item& s)
{
	double price;
	in >> s.isbn >> s.units_sold >> price;

	if (in)//检查输入有没有错误
		s.revenue = s.units_sold*price;
	else
		s = Sales_item();//如果输入有错误创建一个新的空的class

	return in;
}

int main()
{
	Dog a;
	int b;
	Sales_item item;
	cout << "hello" << endl;

	cin >> b;
	cout << b << endl;

	cin >> item;
	cout << item << endl;
	return 0;
}