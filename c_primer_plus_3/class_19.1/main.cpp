//���ز���������ֵ������
//���ظ�ֵ���뷵��*thisָ��

#define _CRT_SECURE_NO_WARNINGS
//����error C4996���͵ı������Ե�������������δ���
#include<iostream>
#include<string.h>
using namespace std;

class String
{
public:
	String(char const *chars = "");//���캯����String��ʼ��֮�����ݴ洢��ָ������
	String &operator=(String const&);
	//String &operator=(char const *);//s="cat"
	//String &operator=(char);//s='A';
	//��������ָ�ֵ���������أ���Ȼ��������һ��

	void print();
private:
	char *ptrChars;//�ַ�ָ��
};

String::String(char const *chars)
{
	chars = chars?chars:"";
	ptrChars = new char[strlen(chars) + 1];//�ַ��������һ���ַ�����/0����Ҫ��1
	strcpy(ptrChars, chars);
}

String& String::operator=(String const &str)
{
	//��ֵ����������⸳ֵ��������ݳ����ǲ���һ�����ģ�������ݲ���һ������
	//����ԭ�������ָ�룬��ʼ��ָ��ָ��һ�ζ�̬���ݣ�������������
	if (strlen(ptrChars) != strlen(str.ptrChars))
	{
		char *ptrHold = new char[strlen(str.ptrChars) + 1];
		delete[] ptrChars;
		ptrChars = ptrHold;
	}
	strcpy(ptrChars, str.ptrChars);
	return *this;
	//c++�������͵Ĳ���
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
	s = s2;//��ֵ����

	cout << "hello" << endl;

	return 0;
}