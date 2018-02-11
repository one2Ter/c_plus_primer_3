/*
赋值构造函数和赋值操作符
*/
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Sales_item
{
public:
	//共有成员
	Sales_item(const string &book) :isbn(book), units_sold(0), revenue(0) 
	{
		cout << "构造函数Sales_item(const string &book)被调用了！" << endl;
	}

	Sales_item() :units_sold(0), revenue(0.0) 
	{
		cout << "默认的构造函数被调用了！" << endl;
	}

	//复制构造函数
	Sales_item(const Sales_item &orig) :isbn(orig.isbn), units_sold(orig.units_sold), revenue(orig.revenue) 
	{
		cout << "复制构造函数被调用了！" << endl;
	}

	Sales_item& operator=(const Sales_item &rhs)
	{
		cout << "赋值操作符被调用了！" << endl;
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

Sales_item foo(Sales_item item)//一开始将实参赋值给形参，复制构造函数被调用了
{
	Sales_item temp;//默认的构造函数被调用了
	temp = item;//赋值构造函数被调用了
	return temp;//返回时将temp复制跟一个全局的变量，复制构造函数被调用了
}

class NoName
{
public:
	NoName() :pstring(new string), i(0), d(0) {}
	NoName(const NoName& other) :pstring(new string(*(other.pstring))), i(other.i), d(other.d)
	{
		cout << "NoName Copy Constructor" << endl;
	}
	//当我们的类里面有一个数据成员是一个指针的时候，我们需要写赋值操作符
	//一般情况下，c++合成运算操作符是满足需要的
	NoName& operator=(const NoName &rhs)
	{
		cout << "NoName 赋值操作符" << endl;
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
	NoName z(x);//复制构造函数
	x = y;//赋值操作符


	Sales_item a;//默认构造函数被调用了
	cout << endl;

	Sales_item b("0-201-78345-X");//特定的构造函数被调用了
	cout << endl;

	Sales_item c(b);//复制构造函数被调用了
	cout << endl;

	a = b;//赋值构造函数被调用了
	cout << endl;

	Sales_item item = string("9-999-99999-9");//特定的构造函数被调用了
	cout << endl;

	cout << endl << "试一下foo:" << endl;
	Sales_item ret;//默认构造函数被调用了
	ret = foo(item);
	//最后是等号，赋值构造函数被调用了
	
	vector<Sales_item> svec(5);
	//vector<Sales_item>首先创建了一个临时变量，调用的是默认的构造函数
	//后面创建了5个vector对象，对创建的临时变量进行了5次复制，调用了复制构造函数

	cout << endl << "试一下数组：" << endl;
	Sales_item primer_eds[] = { string("0-201-16487-6"),string("0-201-54848-8"),string("0-201-82470-1"),Sales_item() };
	//前三个是特定的构造函数创建class,最后一个是通过默认的构造函数创建一个class
	return 0;
}