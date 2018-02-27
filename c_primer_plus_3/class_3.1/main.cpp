/*
类定义（2）
同一类型的多个数据成员
使用类型别名来简化类
成员函数可被重载-定义重载成员函数
显法指示inline成员函数：三种方法
*/
#include<iostream>

using namespace std;
class Screen {
public://写在类里面的函数都是内联函数
	typedef std::string::size_type index;//使用类型别名来简化类

	//程序在初始化的时候contents里面是ht*wd个A,cursor是0，表示光标所在是位置，height表示内容的高度，width表示内容的宽度
	Screen(index ht = 0, index wd = 0) :contents(ht*wd, 'A'), cursor(0), height(ht), width(wd){}
	Screen(index ht, index wd, const string &conts);

	char get() const;//重载函数1
	inline char get(index r, index c) const;//重载函数2
	//在这里写inline也可以将函数体写在类的外面
	

private:
	string contents;
	index cursor;
	index height, width;

};

//get本来是定义在程序内部的函数，但是也可以写在类的外部，写在类的外部需要inline来提示(指定)
inline char Screen::get() const//重载函数1
{//这里光标的位置是0，表示这一组数据光标等于0的位置的数据内容
	return contents[cursor];
}

char Screen::get(index r, index c) const//重载函数2
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
	//返回光标所在位置的内容
	cout << a.get() << endl;
	cout << a.get(2, 8) << endl;//返回指定位置光标的内容

	Screen b(3, 6, "hello screen class");
	//将输入的数据变成3行6列的元素，元素的需要从0开始
	cout << b.get() << endl;
	cout << b.get(1, 4) << endl;

	cout << "测试一下" << endl;
	return 0;
}