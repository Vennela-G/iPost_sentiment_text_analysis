#include <iostream>

#include "Person.h"
#include "AppDefinitions.h"
#include "Post.h"

using namespace std;

Person::Person() {
	first_name = "";
	last_name = "";
	email_address = "";
	username = "";
	password = "";
}

Person::Person(string arg_f_name, string arg_l_name, string arg_email, string arg_username, string arg_password) {
	first_name = arg_f_name;
	last_name = arg_l_name;
	email_address = arg_email;
	username = arg_username;
	password = arg_password;
}

void Person::set_first_name(string arg_f_name) {
	first_name = arg_f_name;
}

string Person::get_first_name() {
	return first_name;
}

void Person::set_last_name(string arg_l_name) {
	last_name = arg_l_name;
}

string Person::get_last_name() {
	return last_name;
}

void Person::set_email_address(string arg_email) {
	email_address = arg_email;
}

string Person::get_email_address() {
	return email_address;
}

void Person::set_username(string arg_username) {
	username = arg_username;
}

string Person::get_username() {
	return username;
}

void Person::set_password(string arg_password) {
	password = arg_password;
}

string Person::get_password() {
	return password;
}

int Person::printing_choice_options(string question, string option_1, string option_2) {

	int response = 0;

	do {
		cout << endl << question << endl;
		cout << "[1] " << option_1 << endl;
		cout << "[2] " << option_2 << endl << endl;

		cout << "Option: ";
		cin >> response;

		if (response == 1 || response == 2) {
			return response;
		}
		else {
			cout << "ERROR: You have entered an invalid option! Please try again." << endl << endl;
		}

	} while (true);

}

int Person::printing_choice_options(string question, string option_1, string option_2, string option_3, string option_4) {

	int response = 0;

	do {
		cout << endl << question << endl;
		cout << "[1] " << option_1 << endl;
		cout << "[2] " << option_2 << endl;
		cout << "[3] " << option_3 << endl;
		cout << "[4] " << option_4 << endl << endl;

		cout << "Option: ";
		cin >> response;

		if ((response == 1 || response == 2) || (response == 3 || response == 4)) {
			return response;
		}
		else {
			cout << "ERROR: You have entered an invalid option! Please try again." << endl << endl;
		}

	} while (true);

	return response;

}
