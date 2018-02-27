//�����±������
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class String
{
private:
	char *ptrChars;//˽�е����ݳ�Ա��ָ��
	static String errorMessage;
public:
	String(char const *chars = "");//
	char &operator[](size_t index) throw(String);
	void print();
	char operator[](size_t index) const throw(String);

};
void String::print()
{
	cout << ptrChars << endl;
}

String String::errorMessage("Subscript out of limit");

char &String::operator[](size_t index) throw(String)
{
	if (index > strlen(ptrChars))
		throw errorMessage;
	else
		return ptrChars[index];
}

char String::operator[](size_t index) const throw(String)
{
	if (index > strlen(ptrChars))
		throw errorMessage;
	else
		return ptrChars[index];
}

String::String(char const *chars)
{
	chars = chars ? chars : "";
	ptrChars = new char[strlen(chars) + 1];
	strcpy(ptrChars, chars);
}

int main()
{
	String s("hello");
	cout << s[1] << endl;//�±��������
	s[1] = 'b';
	s.print();
	return 0;
}