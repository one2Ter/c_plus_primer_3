#include<iostream>

using namespace std;

class Date
{
private:
	int month, day, year;
public:
	Date(int m=0,int d=0,int y=0):month(m),day(d),year(y){}

	bool operator==(Date& dt) const;
	bool operator!=(Date& dt) const;
	bool operator<(Date& dt) const;
	bool operator>(Date& dt) const;
};

bool Date::operator==(Date& dt) const
{
	return (this->month == dt.month) && (this->day == dt.day) && (this->year == dt.year);
}

bool Date::operator!=(Date& dt) const
{
	return !(*this == dt);
}

bool Date::operator<(Date& dt) const
{
	if (this->year == dt.year)
	{
		if (this->month == dt.month)
			return this->day < dt.day;
		return this->month < dt.month;
	}
	return this->year < dt.year;
}

bool Date::operator>(Date& dt) const
{
	if (this->year == dt.year)
	{
		if (this->month == dt.month)
			return this->day > dt.day;
		return this->month > dt.month;
	}
	return this->year > dt.year;
}

int main()
{
	Date d1(2, 14, 2005);
	Date d2(6, 19, 2005);
	Date d3(2, 14, 2005);

	if (d1 < d2)
		cout << "d1小于d2" << endl;

	if (d1 == d3)
		cout << "d1等于d3" << endl;

	return 0;
}