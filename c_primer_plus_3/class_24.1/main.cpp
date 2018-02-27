//operator int() const
/*
1.必须是成员函数
2.不能指定返回类型
3.形参表必须是空的
4.必须显示的返回一个指定的值
5.不应该改变被转换对象，通常定义为const
*/

#include<iostream>
using namespace std;

class Dog
{
public:
	Dog(string name, int age, double weight) :name(name), age(age), weight(weight) {}
	operator int() const
	{
		return age;
	}
private:
	string name;
	int age;
	double weight;
	
};
int main()
{
	int a = 20;
	Dog dog("bill", 6, 15.0);
	a = dog;//在这里将一个class数据类型转换成int类型使用的是转换操作符
	cout << a << endl;

	return 0;
}