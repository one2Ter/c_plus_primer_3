#include<iostream>
#include<string>
using namespace std;

class Person
{
	/*
	��Ա��
	���ݳ�Ա�����ݳ�Աһ�㶼�����˽�е�
	������Ա��������Աһ�㶼����ɹ��е�
	�ܱ����ģ�

	ע�⣺�ù��еĺ�����Ա����˽�е����ݳ�Ա
		  �ڽṹ�������ֻ�ܵ�����Ĺ��к��������ǲ��ܲ���������˽�г�Ա
		  public��private�Ƿ��ʱ�ţ����ʱ��û��дĬ����˽�е�
		  ������Ķ��������װ
	*/

	//public������๫�в��ֵĽӿ�
public://�ں����ĺ�����ϣ�����ͨ��nm����ʼ��name,addr����ʼ��address
	Person(const string& nm,const string &addr) :name(nm),address(addr)
	{//����Ϊʲô�����ã������ǽ����ı���ֱ�ӵ��õ���������ڲ������ٶȸ��죬���ٵ����ݸ��ƵĹ���
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
	string isbn;//�鼮�ı���
	unsigned units_sold;//���۵�����
	double revenue;//�õ���Ǯ

public://������һ���飬���ʼ����Ҫ�鼮���ƣ����۵������Լ��õ���Ǯ
	Sales_item(string &book, unsigned units,double amount):isbn(book),units_sold(units),revenue(amount)
	{}//������غ�����ͨ���������г�ʼ��

	double avg_price() const//����ƽ���۸�
	{
		if (units_sold)
			return revenue / units_sold;
		else
			return 0;
	}

	bool same_isbn(const Sales_item &rhs) const//����鼮�ı���ǲ���һ����
	{
		return isbn == rhs.isbn;
	}

	void add(const Sales_item &rhs)//������Ϊû�н������ز�������ʹ��add��������������������ݽ������
	{
		units_sold += rhs.units_sold;
		revenue += rhs.revenue;
	}
};
int main() 
{
	Person a("Bill","��԰��5��");
	cout << a.getName() << " , " << a.getAddress() << endl;
	a.getName();
	a.getAddress();
	cout << endl;

	Sales_item x(string("0-399-82477-1"), 2, 20.00);
	Sales_item y(string("0-399-82477-1"), 6, 48.00);
	cout << y.avg_price() << endl;

	if (x.same_isbn(y))
		x.add(y);
	cout << "�������۵���ƽ���ۣ�" << x.avg_price() << endl;

	cout << "Hello �࣡" << endl;
	return 0;
}