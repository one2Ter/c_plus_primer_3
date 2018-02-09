#include<iostream>
using namespace std;

class Screen;//类声明

class LinkScreen {
	Screen *window;
	LinkScreen *next;
	LinkScreen *prev;//在类的内部有指向类本身的指针
};

class Y;//类声明（类的前置声明）因为X里面有Y，Y里面有X

class X
{
private:
	Y *ptr;//定义一个指向Y的指针，Y至少先声明
};

class Y//类定义
{
private:
	X *ptr;
	X obj;
};

//记录
class Record //这是一个完整的类：类定义，类声明
{
	typedef std::size_t size;

private:
	string name;//记录的名称
	size byte_count;
public:
	Record():byte_count(0) {}
	Record(size s) :byte_count(s) {}
	Record(string s) :name(s), byte_count(0) {}

	size get_count() const
	{
		return byte_count;
	}

	string get_name() const
	{
		return name;
	}
}r3;//在类的声明，定义之后创建类的对象

int main()
{
	Screen *scr;
	Record r;//在堆栈上创建类的对象
	class Record r2;//c语言的写法
	cout << "hello" << endl;
	return 0;
}