#include<iostream>
#include<set>
#include<string>
#include<algorithm>
using namespace std;

class CCompareStringNoCase
{
public://这个二元谓词数据参数是两个字符串，将两个字符串都变成小写形式，然后进行比较
	bool operator()(const string& str1, const string& str2) const
	{
		string str1LowerCase;
		str1LowerCase.resize(str1.size());
		transform(str1.begin(), str1.end(), str1LowerCase.begin(), towlower);

		string str2LowerCase;
		str2LowerCase.resize(str2.size());
		transform(str2.begin(), str2.end(), str2LowerCase.begin(), tolower);

		return (str1LowerCase < str2LowerCase);
		//class函数可以像外面的函数一样，对于输入的数据有类似于函数对象的方式返回处理之后的数据
	}
};
int main()
{
	//set里面第一个参数时数据的类型，第二个数据是一个二元谓词，这里是通过class创建二元谓词
	set<string, CCompareStringNoCase> names;
	names.insert("Tina");
	names.insert("jim");
	names.insert("jack");
	names.insert("Sam");
	names.insert("hello");

	set<string, CCompareStringNoCase>::iterator iNameFound = names.find("Jim");
	if (iNameFound != names.end())
	{
		cout << "找到了：" << *iNameFound << endl;
	}
	else
	{
		cout << "没找到！" << endl;
	}
	return 0;
}