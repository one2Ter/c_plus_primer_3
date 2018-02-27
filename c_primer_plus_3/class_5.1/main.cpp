/*
������thisָ��
��ʱʹ��thisָ��
����*this
����const�����غ���
�ɱ����ݳ�Ա
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
	//this�൱��һ��ָ������class��ָ��
};

class Screen//��Ļ����Ĵ���
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
	//����ֵ�������������������ڿ��Զ�ε���������ĺ������򻯳���
	void set(index, index, char);
	Screen& set(char);
	const Screen& display(ostream &os) const
	{
		access_ctr++;//constֻ�ܶ�ȡ�������޸ģ�����mulable�������͵Ŀ����޸�
		do_display(os);
		return *this;
	}//const���͵�classֻ������д��������������ǵ�������ʾ�������ȵ����������
	//�������class������ڶ��ε��ã���Ҫ�޸�class��������ݣ���������ѡ������� 
	//��������ǻ���class�����غ���

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
	mutable size_t access_ctr;//������
	
};

Screen& Screen::move(index r, index c)
{
	index row = r*width;
	cursor = row + c;
	return *this;//����������������ַ�������дthisָ��
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
	Person p("�ŷ�", "��԰��5��");
	Person p2("����", "��԰��6��");
	cout << p.getName() << endl;
	cout << p2.getName() << endl;

	Screen myScreen(5, 3);
	cout << myScreen.get() << endl;

	//�������иĳɸ��򵥵�д�� 
	myScreen.set(3, 2, 'B');
	cout << myScreen.get(3, 2) << endl;

	myScreen.move(3, 2).set('C').display(cout).set('K').display(cout);
	//����һ���У������޸ĵĴ洢��class�е����ݣ���ԭ����void����ֵ�޸�Ϊ&�������ͣ����ص���clas����
	//����class��������ٴε���class���������
	cout << endl;

	cout << myScreen.get(3, 2) << endl;

	myScreen.move(4, 0).set('A').move(4, 1).set('B').move(4, 2).set('C').display(cout);
	cout << endl;

	myScreen.move(2, 3);
	myScreen.set('C');
	cout << myScreen.get() << endl;

	return 0;
}