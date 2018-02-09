#include<stdio.h>
struct Person {
	char name[30];
	char address[100];
};
int main()//c语言里面结构体没有公有的和私有的概念
{
	struct Person p;
	strcpy(p.name, "Bill");
	strcpy(p.address, "花园街5号");

	printf("%s,%s", p.name, p.address);
	printf("hello C!\n");
	return 0;
}