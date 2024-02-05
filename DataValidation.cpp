#include <iostream>
using namespace std;

class DataValidation{
    public:
    
        bool validate_num(int num) {
			if (cin.fail() || num <= 0) {
				return false;
			}
			else {
				return true;
			}
		}

		int get_num() {
			int num;
			while (true) {
				cin >> num;
				if (!validate_num(num)) {
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "Error: invalid" << endl;
					
				}
				else {

					return num;
				}

			}

		}

		// check year condition
		bool validateYear(int year) {
			if (cin.fail() || (year < 1 || year > 4)) {
				return false;
			}
			else {
				return true;
			}
		}

		int getYear() {
			int year;
			while (true) {
				cin >> year;
				if (!validateYear(year)) {
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "Error: invalid" << endl;
					
				}
				else {

					return year;
				}

			}

		}

		// check phone number condition
		bool validatPhoneNumber(string st){
				if (st.length() <= 3) {
				return false;
			}

			for (int i = 0; i < st.length(); i++) {
				if (!(st[i] >= 48 && st[i] <= 57)) {
					return false;
				}
			}
			return true;
		}

		string getPhoneNumber(){
			string st;
			while (true) {
				cin >> st;
				if (!validatPhoneNumber(st)) {
					cout << "Error: invalid" << endl;
				}
				else {
					
					return st;
				}
			}
		}

		bool validate_st(string st) {
			if (st.length() <= 3) {
				return false;
			}

			for (int i = 0; i < st.length(); i++) {
				if (!(st[i] >= 65 && st[i] <= 122)) {
					return false;
				}
			}
			return true;
		}
		// Return String Function
		string get_st() {
			string st;
			while (true) {
				cin >> st;
				if (!validate_st(st)) {
					cout << "Error: invalid" << endl;
				}
				else {
					
					return st;
				}
			}

		}

		
};




