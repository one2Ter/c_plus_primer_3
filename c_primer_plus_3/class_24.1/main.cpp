//operator int() const
/*
1.�����ǳ�Ա����
2.����ָ����������
3.�βα�����ǿյ�
4.������ʾ�ķ���һ��ָ����ֵ
5.��Ӧ�øı䱻ת������ͨ������Ϊconst
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
	a = dog;//�����ｫһ��class��������ת����int����ʹ�õ���ת��������
	cout << a << endl;

	return 0;
}