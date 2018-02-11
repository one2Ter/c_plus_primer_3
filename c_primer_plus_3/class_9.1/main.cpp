//c++ static���Ա
#include<iostream>

//static���Ա���ص��ǣ�����ͬһ���ഴ���˶�����󣬶�������static��������ͨ��
//����int/const���͵�static���ݳ�Ա������������ֱ�Ӹ�ֵ�����򶼲�����
//��Ҫ��class����double Account::interestRate = 0.015;����ʽ��ֵ
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
	//������Ϊ����������static��Ա��������Ӧ�Ŀ��ƺ���Ҳ��static���͵�

	static void rate(double newRate)
	{
		interestRate = newRate;
	}

private:
	string owner;
	double amount;
	static double interestRate;
	static const int period = 30;
	//����static const int�������Ϳ�����clas��ֱ�Ӹ�ֵ��ʼ��
};

double Account::interestRate = 0.015;//static���ݳ�Ա��ȷ�ĳ�ʼ����ʽ

int main()
{
	Account::rate(0.026);

	Account a("����", 1000);
	Account b("����", 2000);

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