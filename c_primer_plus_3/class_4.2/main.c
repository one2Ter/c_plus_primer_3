#include<stdio.h>
struct Person {
	char name[30];
	char address[100];
};
int main()
{
	struct Person p;
	strcpy(p.name, "Bill");
	strcpy(p.address, "��԰��5��");
	printf("hello C!\n");
	return 0;
}