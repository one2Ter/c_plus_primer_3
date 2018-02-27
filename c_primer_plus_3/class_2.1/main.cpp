#include<iostream>
#include<string>
using namespace std;

class Person
{
	/*
	成员：
	数据成员：数据成员一般都定义成私有的
	函数成员：函数成员一般都定义成共有的
	受保护的：

	注意：用共有的函数成员操作私有的数据成员
		  在结构体的外面只能调用类的公有函数，但是不能操作函数的私有成员
		  public和private是访问标号，访问标号没有写默认是私有的
		  整个类的定义叫做封装
	*/

	//public定义的类公有部分的接口
public://在函数的后面加上：可以通过nm来初始化name,addr来初始化address
	Person(const string& nm,const string &addr) :name(nm),address(addr)
	{//这里为什么是引用，引用是将外界的变量直接调用到这个函数内部来，速度更快，减少的数据复制的过程
	};
	string getName() const
	{
		return name;
	}

	string getAddress() const
	{
		return address;
	}

private:string name;
		string address;

};

class Sales_item
{
private:
	string isbn;//书籍的编码
	unsigned units_sold;//销售的数量
	double revenue;//拿到的钱

public://定义了一本书，书初始化需要书籍名称，销售的数量以及拿到的钱
	Sales_item(string &book, unsigned units,double amount):isbn(book),units_sold(units),revenue(amount)
	{}//类的重载函数，通过参数进行初始化

	double avg_price() const//计算平均价格
	{
		if (units_sold)
			return revenue / units_sold;
		else
			return 0;
	}

	bool same_isbn(const Sales_item &rhs) const//检查书籍的编号是不是一样的
	{
		return isbn == rhs.isbn;
	}

	void add(const Sales_item &rhs)//这里因为没有进行重载操作符，使用add函数将两个类里面的数据进行相加
	{
		units_sold += rhs.units_sold;
		revenue += rhs.revenue;
	}
};
int main() 
{
	Person a("Bill","花园街5号");
	cout << a.getName() << " , " << a.getAddress() << endl;
	a.getName();
	a.getAddress();
	cout << endl;

	Sales_item x(string("0-399-82477-1"), 2, 20.00);
	Sales_item y(string("0-399-82477-1"), 6, 48.00);
	cout << y.avg_price() << endl;

	if (x.same_isbn(y))
		x.add(y);
	cout << "两个销售单的平均价：" << x.avg_price() << endl;

	cout << "Hello 类！" << endl;
	return 0;
}