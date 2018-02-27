#include<iostream>
#include<set>
#include<string>
#include<algorithm>
using namespace std;

class CCompareStringNoCase
{
public://�����Ԫν�����ݲ����������ַ������������ַ��������Сд��ʽ��Ȼ����бȽ�
	bool operator()(const string& str1, const string& str2) const
	{
		string str1LowerCase;
		str1LowerCase.resize(str1.size());
		transform(str1.begin(), str1.end(), str1LowerCase.begin(), towlower);

		string str2LowerCase;
		str2LowerCase.resize(str2.size());
		transform(str2.begin(), str2.end(), str2LowerCase.begin(), tolower);

		return (str1LowerCase < str2LowerCase);
		//class��������������ĺ���һ������������������������ں�������ķ�ʽ���ش���֮�������
	}
};
int main()
{
	//set�����һ������ʱ���ݵ����ͣ��ڶ���������һ����Ԫν�ʣ�������ͨ��class������Ԫν��
	set<string, CCompareStringNoCase> names;
	names.insert("Tina");
	names.insert("jim");
	names.insert("jack");
	names.insert("Sam");
	names.insert("hello");

	set<string, CCompareStringNoCase>::iterator iNameFound = names.find("Jim");
	if (iNameFound != names.end())
	{
		cout << "�ҵ��ˣ�" << *iNameFound << endl;
	}
	else
	{
		cout << "û�ҵ���" << endl;
	}
	return 0;
}