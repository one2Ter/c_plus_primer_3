//重载操作符，赋值操作符
//重载赋值必须返回*this指针

#define _CRT_SECURE_NO_WARNINGS
//对于error C4996类型的报错，可以调用这条语句屏蔽错误
#include<iostream>
#include<string.h>
using namespace std;

class String
{
public:
	String(char const *chars = "");//构造函数，String初始化之后数据存储在指针里面
	String &operator=(String const&);
	//String &operator=(char const *);//s="cat"
	//String &operator=(char);//s='A';
	//上面的两种赋值操作符重载，虽然参数都不一样

	void print();
private:
	char *ptrChars;//字符指针
};

String::String(char const *chars)
{
	chars = chars?chars:"";
	ptrChars = new char[strlen(chars) + 1];//字符数组最后一个字符串是/0所以要加1
	strcpy(ptrChars, chars);
}

String& String::operator=(String const &str)
{
	//赋值操作符，检测赋值两侧的数据长度是不是一样长的，如果数据不是一样长的
	//放弃原来自身的指针，初始化指针指针一段动态数据，用来保存数据
	if (strlen(ptrChars) != strlen(str.ptrChars))
	{
		char *ptrHold = new char[strlen(str.ptrChars) + 1];
		delete[] ptrChars;
		ptrChars = ptrHold;
	}
	strcpy(ptrChars, str.ptrChars);
	return *this;
	//c++内置类型的操作
}
void String::print()
{
	cout << *ptrChars << endl;
}

int main()
{
	String s("hello");
	String s2("Dog");
	s.print();
	s2.print();
	s = s2;//赋值操作

	cout << "hello" << endl;

	return 0;
}