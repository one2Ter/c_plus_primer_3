#include<stdio.h>
struct Person {
	char name[30];
	char address[100];
};
int main()//c��������ṹ��û�й��еĺ�˽�еĸ���
{
	struct Person p;
	strcpy(p.name, "Bill");
	strcpy(p.address, "��԰��5��");

	printf("%s,%s", p.name, p.address);
	printf("hello C!\n");
	return 0;
}