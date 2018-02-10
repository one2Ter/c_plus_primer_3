#include<iostream>
#include<string>

using namespace std;

class Person
{
public:
	Person() :age(0) {}//默认的构造函数
	Person(const string &nm) :name(nm), age(0) {}
public:
	string name;
	int age;
};

class Cat
{
public:
	Cat() {}
	Cat(string &nm) :name(nm), age(0) {}

	string getName() { return this->name; }
	int getAge() { return this->age; }
private:
	string name;
	int age;
};

class Dog
{
public:
	Dog() :legs(4) {}
private:
	string name;
	const int legs;
};

//因为在class中存在一个输入参数和一个输出Sales_item的类型
//对于myobj.same_isbn("0-201-82470-1")理论上不会接收这样的数据类型
//但是在class里面有一个输入字符串创建一个class，这里会将"0-201-82470-1"转变成一个class
//同时再里检测same_isbn(class),隐式的创建一个string->class的转变，所以在单个输入变量的前面
//加上一个explicit来拒绝隐式的创建一个转变，只允许一个显式的转变

class Sales_item
{
public:
	Sales_item(const string &book,int units,double price)
		:revenue(units*price),units_sold(units),isbn(book){}
	Sales_item(const string &book = "") :isbn(book), units_sold(0), revenue(0.0) {}
	Sales_item(istream &is) { is >> *this; }
	Sales_item(int units, double price)
	{
		this->units_sold = units;
		this->revenue = units*price;
	}
	bool same_isbn(const Sales_item &rhs) const
	{
		return isbn == rhs.isbn;
	}

	friend istream& operator >> (istream&, Sales_item&);
private:
	string isbn;
	unsigned units_sold;
	double revenue;

};
inline istream& operator >> (istream& in, Sales_item& s)
{
	double price;
	in >> s.isbn >> s.units_sold >> price;
	if (in)
		s.revenue = s.units_sold*price;
	else
		s = Sales_item();
	return in;
}
int main()
{
	const int k = 100;
	Cat aCat;
	Person a("张飞");
	Person b;
	Sales_item item1;
	Sales_item item2("0-201-82470-1");
	Sales_item *p = new Sales_item;
	const Sales_item item3;

	Sales_item myobj;

	if (myobj.same_isbn(item2))
	{
		cout << "相同" << endl;
	}
	cout << a.name << endl;
	cout << a.age << endl;

	delete p;
	
	return 0;
}