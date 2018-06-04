#include "DataBase.h"

    Date::Date() {
    	this->day = 1;
    	this->month = 1;
    	this->year = 0;
    };
    
    Date::Date(int year, int month, int day) {
    	this->day = day;
    	this->month = month;
    	this->year = year;
    }
    
    int Date::GetYear() const {
    	return year;
    }
    
    int Date::GetMonth() const {
    	return month;
    }
    
    int Date::GetDay() const {
    	return day;
    }

	void DataBase::AddEvent(const Date& add_date, const string& add_event) {
		bool k = 0;
		bool f = 0;
		for (auto& date : DB) {
			if (date.first == add_date) {
				for (auto& event : date.second) {
					if (event == add_event) {
						k = 1;
					}
				}
				if (k == 0) {
					date.second.insert(add_event);
					f = 1;
				}
			}
		}
		if (f == 0) {
			DB[add_date].insert(add_event);
		}
	}

	bool DataBase::DeleteEvent(const Date& del_date, const string& del_event) {
		bool k = 0;
		for (auto& date : DB) {
			if (date.first == del_date) {
				for (const auto& event : date.second) {
					if (event == del_event) {
						date.second.erase(event);
						k = true;
						if (date.second.size() == 0) {
							DB.erase(date.first);
						}
					}
				}
			}

		}
		return k;
	}
	int  DataBase::DeleteDate(const Date& del_date) {
		int i = 0;
		for (const auto& date : DB) {
			if (date.first == del_date) {
				i = date.second.size();
				DB.erase(date.first);
			}
		}
		return i;
	}

	void DataBase::Find(const Date& search_date) const {
		for (const auto& date : DB) {
			if (date.first == search_date) {
				for (const auto& event : date.second) {
					cout << event << endl;
				}
			}
		}
	}

	void DataBase::Print() const {
		for (const auto& date : DB) {
			for (const auto& event : date.second) {
				cout << date.first << " " << event << endl;
			}
		}
	}


Date ParseOfDate(const string& input_date) {
	Date date;
	int day = 0;
	int month = 0;
	int year = 0;
	istringstream input(input_date);
	input >> year;
	if (year < 0 || year > 9999)
		throw runtime_error("Wrong date format: " + input_date);
	if (input.peek() != '-') {
		throw runtime_error("Wrong date format: " + input_date);
	}
	else {
		input.ignore(1);
		input >> month;
		if (input.peek() != '-') {
			throw runtime_error("Wrong date format: " + input_date);
		}
		else {
			input.ignore(1);
			input >> day;
			if (input.peek() != EOF) {
				throw runtime_error("Wrong date format: " + input_date);
			}
			if (month < 1 || month > 12) {
				throw invalid_argument("Month value is invalid: " + to_string(month));
			}
			if (day < 1 || day > 31) {
				throw invalid_argument("Day value is invalid: " + to_string(day));
			}
			return date = { year, month, day };
		}
	}
}

bool operator==(const Date& lhs, const Date& rhs) {
	return ((lhs.GetDay() == rhs.GetDay()) && (lhs.GetMonth() == rhs.GetMonth())
		&& (lhs.GetYear() == rhs.GetYear()));
}

bool operator<(const Date& lhs, const Date& rhs) {
	if (lhs.GetYear() != rhs.GetYear()) {
		return lhs.GetYear() < rhs.GetYear();
	}
	else {
		if (lhs.GetMonth() != rhs.GetMonth()) {
			return lhs.GetMonth() < rhs.GetMonth();
		}
		else {
			return lhs.GetDay() < rhs.GetDay();
		}
	}
}

ostream& operator<<(ostream& stream, const Date& date) {
	stream << fixed << setfill('0');
	stream << setw(4) << date.GetYear() << "-";
	stream << setw(2) << date.GetMonth() << "-";
	stream << setw(2) << date.GetDay();
	return stream;
}