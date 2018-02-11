//c++ static类成员
#include<iostream>

//static类成员的特点是：对于同一个类创建了多个对象，多个对象的static数据是相通的
//对于int/const类型的static数据成员可以在类里面直接赋值，否则都不可以
//需要在class外面double Account::interestRate = 0.015;的形式赋值
using namespace std;

class Dog
{
private:
	static double interestRate;
};

class Account
{
public:
	Account(string name, double money) :owner(name), amount(money) {}

	double getAmount() const
	{
		return this->amount;
	}

	void applyint() { amount += amount*interestRate; }
	void deposit(double money)
	{
		this->amount += money;
	}
	static double rate() { return interestRate; }
	//这里因为操作对象是static成员，所以相应的控制函数也是static类型的

	static void rate(double newRate)
	{
		interestRate = newRate;
	}

private:
	string owner;
	double amount;
	static double interestRate;
	static const int period = 30;
	//对于static const int数据类型可以在clas中直接赋值初始化
};

double Account::interestRate = 0.015;//static数据成员正确的初始化方式

int main()
{
	Account::rate(0.026);

	Account a("张三", 1000);
	Account b("李四", 2000);

	a.deposit(500);
	b.deposit(600);
	cout << a.getAmount() << endl;
	cout << b.getAmount() << endl;

	cout << a.rate() << endl;
	a.rate(0.018);
	cout << b.rate() << endl;

	Account::rate(0.02);
	a.applyint();
	b.applyint();

	cout << a.getAmount() << endl;
	cout << b.getAmount() << endl;

	return 0;
}