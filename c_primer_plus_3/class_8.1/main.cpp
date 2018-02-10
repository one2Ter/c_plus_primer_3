#include<iostream>
#include<string>
using namespace std;

class Screen;

class Dog
{
public:
	int foo(Screen& screen);
	
};

class Screen
{
public:
	friend int calcArea(Screen &);//ͨ����Ԫ��һ����������һ����class
	friend class Window_Mgr;//ͨ����Ԫ��һ����class��������һ����class
	friend int Dog::foo(Screen& screen);//ͨ����Ԫ��һ����class�ĺ�����������һ����class

	typedef string::size_type index;

	Screen(int ht = 0, int wd = 0) :contents(ht*wd, ' '), cursor(0), height(ht), width(wd) {}

	int area() const
	{
		return height*width;
	}
	friend int calcArea(Screen &);
private:
	string contents;
	index cursor;
	int height, width;
};

class Window_Mgr
{
public:
	void relocate(int r, int c, Screen& s)
	{
		s.height += r;
		s.width += c;
	}
};

inline int Dog::foo(Screen& screen)
{
	return screen.height*screen.width;
}

int calcArea(Screen & screen)
{
	return screen.height*screen.width;
}
int main()
{
	Screen a(60, 100);
	cout << a.area() << endl;
	Window_Mgr wm;
	wm.relocate(20, 100, a);
	cout << calcArea(a) << endl;

	return 0;
}