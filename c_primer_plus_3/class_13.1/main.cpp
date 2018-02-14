#include<iostream>
#include"plain-ptr.h"
#include"value-ptr.h"
#include"smart-ptr.h"

using namespace std;
int test_AHasPtr()
{
	int i = 42;
	AHasPtr p1(&i, 42);
	AHasPtr p2 = p1;
	cout << p2.get_ptr_val() << endl;

	p1.set_ptr_val(0);
	cout << p2.get_ptr_val() << endl;

	int *ip = new int(42);
	AHasPtr ptr(ip, 10);
	cout << ptr.get_ptr_val() << endl;
	delete ip;
	cout << ptr.get_ptr_val() << endl;
}

void test_BHasPtr()
{
	int obj = 0;
	BHasPtr ptr1(&obj, 42);
	BHasPtr ptr2(ptr1);
	cout << ptr1.get_ptr_val() << ',' << ptr1.get_int() << endl;
	cout << ptr2.get_ptr_val() << ',' << ptr2.get_int() << endl;

	cout << "ÐÞ¸ÄÒÔºó£º" << endl;
	ptr2.set_ptr_val(2);
	ptr2.set_int(22);
}

void VHasPtr()
{

}