//操作符重载
/*
算数操作符重载
+	+=	-	-=	*	*=	/	/=	%	&=
*/
#include<iostream>
#include<string>
using namespace std;
class Dog
{
	
};

class Cat
{

};

class Sales_item {
private:
	string isbn;
	unsigned units_sold;
	double revenue;
public:
	Sales_item() :units_sold(0), revenue(0) {}
	Sales_item(const string &book, const unsigned units, const double price)
		:isbn(book), units_sold(units), revenue(price) {}
	Sales_item& operator+=(const Sales_item&);
	Sales_item& operator-=(const Sales_item&);
	friend ostream& operator<<(ostream&out, const Sales_item&);
};
Sales_item operator+(const Sales_item&, const Sales_item&);
Sales_item operator-(const Sales_item&, const Sales_item&);
Sales_item& Sales_item::operator+=(const Sales_item& rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}
Sales_item& Sales_item::operator-=(const Sales_item& rhs)
{
	units_sold -= rhs.units_sold;
	revenue -= rhs.revenue;
	return *this;
}
Sales_item operator+(const Sales_item& lhs, const Sales_item& rhs)
{
	Sales_item ret(lhs);
	ret += rhs;
	return ret;
	//加法操作会返回一个新的对象
}
Sales_item operator-(const Sales_item& lhs, const Sales_item& rhs)
{
	Sales_item ret(lhs);
	ret -= rhs;
	return ret;
}

ostream& operator<<(ostream&out, const Sales_item& s)
{
	out << s.isbn << "\t" << s.units_sold << "\t" << s.revenue << endl;
	return out;
}

int main()
{
	int a = 12, b = 6, c;
	c = a + b;
	cout << "Hello" << endl;

	Sales_item item1(string("0-202-12345-X"), 10, 120.0);
	Sales_item item2(string("0-202-12345-X"), 20, 200.0);

	Sales_item result=item1+item2;
	cout << result << endl;

	Sales_item item3(string("0-202-12345-X"), 5, 70.00);
	result += item3;
	cout << result;

	result -= item2;
	cout << result << endl;

	result = item2 - item1;
	cout << result << endl;

	return 0;
}