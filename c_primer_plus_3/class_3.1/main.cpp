/*
�ඨ�壨2��
ͬһ���͵Ķ�����ݳ�Ա
ʹ�����ͱ���������
��Ա�����ɱ�����-�������س�Ա����
�Է�ָʾinline��Ա���������ַ���
*/
#include<iostream>

using namespace std;
class Screen {
public://д��������ĺ���������������
	typedef std::string::size_type index;//ʹ�����ͱ���������

	//�����ڳ�ʼ����ʱ��contents������ht*wd��A,cursor��0����ʾ���������λ�ã�height��ʾ���ݵĸ߶ȣ�width��ʾ���ݵĿ��
	Screen(index ht = 0, index wd = 0) :contents(ht*wd, 'A'), cursor(0), height(ht), width(wd){}
	Screen(index ht, index wd, const string &conts);

	char get() const;//���غ���1
	inline char get(index r, index c) const;//���غ���2
	//������дinlineҲ���Խ�������д���������
	

private:
	string contents;
	index cursor;
	index height, width;

};

//get�����Ƕ����ڳ����ڲ��ĺ���������Ҳ����д������ⲿ��д������ⲿ��Ҫinline����ʾ(ָ��)
inline char Screen::get() const//���غ���1
{//�������λ����0����ʾ��һ�����ݹ�����0��λ�õ���������
	return contents[cursor];
}

char Screen::get(index r, index c) const//���غ���2
{
	index row = r*width;
	return contents[row + c];
}

inline Screen::Screen(index ht, index wd, const string &conts):contents(conts),cursor(0),height(ht),width(wd)
{
}

int main()
{
	Screen a(10,100);
	//���ع������λ�õ�����
	cout << a.get() << endl;
	cout << a.get(2, 8) << endl;//����ָ��λ�ù�������

	Screen b(3, 6, "hello screen class");
	//����������ݱ��3��6�е�Ԫ�أ�Ԫ�ص���Ҫ��0��ʼ
	cout << b.get() << endl;
	cout << b.get(1, 4) << endl;

	cout << "����һ��" << endl;
	return 0;
}