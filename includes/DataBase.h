#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <iostream>
#include <exception>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;


class Date {
public:
	Date();

	Date(int year, int month, int day);

	int GetYear() const;
	int GetMonth() const;
	int GetDay() const;

private:
	int day;
	int month;
	int year;
};

class DataBase {
public:

	void AddEvent(const Date& add_date, const string& add_event);

	bool DeleteEvent(const Date& del_date, const string& del_event);
	
	int  DeleteDate(const Date& del_date);

	void Find(const Date& search_date) const ;

	void Print() const ;


private:
	map<Date, set<string>> DB;
};

Date ParseOfDate(const string& input_date);

bool operator==(const Date& lhs, const Date& rhs);

bool operator<(const Date& lhs, const Date& rhs);

ostream& operator<<(ostream& stream, const Date& date);

#endif