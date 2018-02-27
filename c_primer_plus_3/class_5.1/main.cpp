/*
隐含的this指针
何时使用this指针
返回*this
基于const的重载函数
可变数据成员
*/
#include<iostream>
#include<string>
using namespace std;

class Person
{
private:
	string name;
	string address;

public:
	Person(const string &nm, const string &addr)
	{
		this->name = nm;
		this->address = addr;
	}
	string getName() const
	{
		return this->name;
	}
	string getAddress() const
	{
		return this->address;
	}
	//this相当于一个指向自身class的指针
};

class Screen//屏幕上面的窗口
{
public:
	typedef string::size_type index;
	Screen(index ht=0,index wd=0):contents(ht*wd,'A'),cursor(ht),width(wd),access_ctr(0){}
	
	char get() const
	{
		return contents[cursor];
	}
	char get(index r, index c) const
	{
		index row = r*width;
		return contents[row + c];
	}
	Screen& move(index r, index c);
	//返回值是引用类型是作用在于可以多次调用类里面的函数，简化程序
	void set(index, index, char);
	Screen& set(char);
	const Screen& display(ostream &os) const
	{
		access_ctr++;//const只能读取，不能修改，但是mulable数据类型的可以修改
		do_display(os);
		return *this;
	}//const类型的class只读不能写，所以如果程序是单纯的显示，会优先调用这个程序
	//但是如果class后面存在二次调用，需要修改class里面的数据，编译器会选择下面的 
	//程序，这个是基于class的重载函数

	Screen& display(ostream &os)
	{
		do_display(os);
		return *this;
	}//

	void do_display(ostream &os) const
	{
		os << contents;
	}

private:
	string contents;
	index cursor;
	index height, width;
	mutable size_t access_ctr;//计数器
	
};

Screen& Screen::move(index r, index c)
{
	index row = r*width;
	cursor = row + c;
	return *this;//返回这个对象本身，这种方法必须写this指针
}

Screen& Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}

void Screen::set(index r, index c, char ch)
{
	index row = r*width;
	contents[row + c] = ch;
}

int main()
{
	Person p("张飞", "花园街5号");
	Person p2("刘备", "花园街6号");
	cout << p.getName() << endl;
	cout << p2.getName() << endl;

	Screen myScreen(5, 3);
	cout << myScreen.get() << endl;

	//上面这行改成更简单的写法 
	myScreen.set(3, 2, 'B');
	cout << myScreen.get(3, 2) << endl;

	myScreen.move(3, 2).set('C').display(cout).set('K').display(cout);
	//在这一行中，本身修改的存储在class中的数据，将原来的void返回值修改为&引用类型，返回的是clas本身
	//对于class本身可以再次调用class里面的数据
	cout << endl;

	cout << myScreen.get(3, 2) << endl;

	myScreen.move(4, 0).set('A').move(4, 1).set('B').move(4, 2).set('C').display(cout);
	cout << endl;

	myScreen.move(2, 3);
	myScreen.set('C');
	cout << myScreen.get() << endl;

	return 0;
}