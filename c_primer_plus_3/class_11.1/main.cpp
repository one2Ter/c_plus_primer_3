/*
析构函数
析构函数：获取资源
析构函数：释放资源
合成的析构函数
三法则:如果写了析构函数，就一定要写复制构造函数，赋值操作符
*/
#include<iostream>
#include<string>
using namespace std;
/*
如果一个类需要打开数据库
动态创建内存
则需要使用析构函数，否则简单的c++自带的合成的析构函数已经满足我们的需要
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
	cout << "析构函数被调用了!\n" << endl;
	delete pstring;
}

int main()
{
	NoName a;

	NoName *p = new NoName;
	cout << "Hello\n" << endl;
	return 0;
}