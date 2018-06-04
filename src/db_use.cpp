#include "DataBase.h"

int main() {
	DataBase db;
	string command;
	try {
		while (getline(cin, command)) {
			istringstream input(command);
			string com = "";
			input >> com;
			if (com.size() == 0) {
			}
			else {
				if (com == "Add") {
					string date = "";
					string event;
					input >> date >> event;
					Date new_date = ParseOfDate(date);
					if (event.size() != 0) {
						db.AddEvent(new_date, event);
					}
				}
				else {
					if (com == "Del") {
						string date = "";
						input >> date;
						Date new_date = ParseOfDate(date);
						if (input.peek() != EOF) {
							string event;
							input >> event;
							bool k = db.DeleteEvent(new_date, event);
							if (k == true) {
								cout << "Deleted successfully" << endl;
							}
							else {
								cout << "Event not found" << endl;
							}
						}
						else {
							int num = db.DeleteDate(new_date);
							cout << "Deleted " << num << " events" << endl;
						}
					}
					else {
						if (com == "Find") {
							string date = "";
							input >> date;
							Date new_date = ParseOfDate(date);
							db.Find(new_date);
						}
						else {
							if (com == "Print") {
								db.Print();
							}
							else {
								throw runtime_error("Unknown command: " + com);
							}
						}
					}
				}
			}

		}
	}
	catch (exception& ex) {
		cout << ex.what();
	}
	
	//system("pause");
	return 0;
}