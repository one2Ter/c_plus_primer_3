#include<iostream>
using namespace std;

class Screen;//������

class LinkScreen {
	Screen *window;
	LinkScreen *next;
	LinkScreen *prev;//������ڲ���ָ���౾���ָ��
};

class Y;//�����������ǰ����������ΪX������Y��Y������X

class X
{
private:
	Y *ptr;//����һ��ָ��Y��ָ�룬Y����������
};

class Y//�ඨ��
{
private:
	X *ptr;
	X obj;
};

//��¼
class Record //����һ���������ࣺ�ඨ�壬������
{
	typedef std::size_t size;

private:
	string name;//��¼������
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
}r3;//���������������֮�󴴽���Ķ���

int main()
{
	Screen *scr;
	Record r;//�ڶ�ջ�ϴ�����Ķ���
	class Record r2;//c���Ե�д��
	cout << "hello" << endl;
	return 0;
}