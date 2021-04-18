#include <iostream>
#include <string.h>

#include "User.h"
#include "Person.h"
#include "EnumHelper.h"
#include "FileIO.h"

using namespace std;

User::User() {
    age = 0;
    sensitivity_pref = SensitivityPrefEnum::MILD;
    account_status = AccountStatusEnum::ACTIVE;
    last_login_date_time = 0;
}

User::User(int arg_age, SensitivityPrefEnum arg_sensitivity_pref, AccountStatusEnum arg_account_status, char* arg_last_login_date_time) {
    age = arg_age;
    sensitivity_pref = arg_sensitivity_pref;
    account_status = arg_account_status;
    last_login_date_time = arg_last_login_date_time;
}

User::User(string arg_f_name, string arg_l_name, string arg_email, string arg_username, string arg_password, int arg_age, 
	       SensitivityPrefEnum arg_sensitivity_pref, AccountStatusEnum arg_account_status, char* arg_last_login_date_time) 
		   : Person(arg_f_name, arg_l_name, arg_email, arg_username, arg_password) {
	age = arg_age;
	sensitivity_pref = arg_sensitivity_pref;
	account_status = arg_account_status;
	last_login_date_time = arg_last_login_date_time;
}

void User::set_age(int arg_age) {
    age = arg_age;
}

int User::get_age() {
    return age;
}

void User::set_sensitivity_pref(SensitivityPrefEnum arg_sensitivity_pref) {
    sensitivity_pref = arg_sensitivity_pref;
}

SensitivityPrefEnum User::get_sensitivity_pref() {
    return sensitivity_pref;
}

void User::set_account_status(AccountStatusEnum arg_account_status) {
    account_status = arg_account_status;
}

AccountStatusEnum User::get_account_status() {
    return account_status;
}

void User::set_last_login_date_time(char* arg_last_login_date_time) {
    last_login_date_time = arg_last_login_date_time;
}

char* User::get_last_login_date_time() {
    return last_login_date_time;
}

int User::printing_choice_options(string question, string option_1, string option_2) {

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

void User::user_login(vector<User> user_data, User& user) {

	cout << endl << "Login" << endl;

	int choice = 0;

	string username = "";
	cout << "Username: ";
	cin >> username;

	string password = "";
	cout << "Password: ";
	cin >> password;

	vector<User>::iterator iter;
	for (iter = user_data.begin(); iter != user_data.end(); iter++) {

		if ((*iter).get_username() == username && (*iter).get_password() == password) {
			
			User user_temp((*iter).get_first_name(), (*iter).get_last_name(), (*iter).get_email_address(), (*iter).get_username(),
				           (*iter).get_password(), (*iter).get_age(), (*iter).get_sensitivity_pref(), (*iter).get_account_status(), (*iter).get_last_login_date_time());
				
				user = user_temp;
				break;
		}

	}

	if (iter == user_data.end()) {

		cout << "The username or password you have entered is incorrect." << endl << endl;
		choice = printing_choice_options("What would you like to do?", "Try logging in again", "Exit");

		if (choice == 1) {
			user_login(user_data, user);
		}

	}

}

void User::user_registration(vector<User>& user_data, User& user) {

	cout << endl << "Registration" << endl;

	string f_name = "";
	string l_name = "";
	string email = "";
	string username = "";
	string password = "";
	string age = "";
	string s_pref = "";


	cout << "First Name: ";
	cin >> f_name;

	cout << "Last Name: ";
	cin >> l_name;

	cout << "Email: ";
	cin >> email;

	vector<User>::iterator iter;
	for (iter = user_data.begin(); iter != user_data.end(); iter++) {

		while ((*iter).get_email_address() == email) {
			cout << "The email you have entered is already taken. Try again!" << endl;
			cout << "Re-Enter Email: ";
			cin >> email;
			break;
		}

	}

	cout << "Username: ";
	cin >> username;

	for (iter = user_data.begin(); iter != user_data.end(); iter++) {

		while ((*iter).get_username() == username) {
			cout << "The username you have entered is already taken. Try again!" << endl;
			cout << "Re-Enter Username: ";
			cin >> username;
			break;
		}

	}

	cout << "Password: ";
	cin >> password;

	cout << "Age: ";
	cin >> age;

	cout << "Sensitivity Preference (MILD, MODERATE, HIGH): ";
	cin >> s_pref;

	time_t current_time = time(0);

	char last_login[26];
	ctime_s(last_login, sizeof last_login, &current_time);
	
	User temp_user(f_name, l_name, email, username,
		password, stoi(age.c_str()),
		EnumHelper::string_to_enum_sensitivity_pref(s_pref),
		AccountStatusEnum::ACTIVE, last_login);

	user = temp_user;

	user_data.push_back(user);

	FileIO::save_user_data(user_data);

}

void User::view_all_posts(vector<Post>& posts) {

	vector<Post>::iterator iter;
	for (iter = posts.begin(); iter != posts.end(); iter++) {

		if (sensitivity_pref == SensitivityPrefEnum::MILD) {
			cout << *iter;
		}

		if (sensitivity_pref == SensitivityPrefEnum::MODERATE) {
			if (iter->get_sensitivity_pref() == SensitivityPrefEnum::MILD ||
				iter->get_sensitivity_pref() == SensitivityPrefEnum::MODERATE) {
				cout << *iter;
			}
		}

		if (sensitivity_pref == SensitivityPrefEnum::HIGH) {
			if (iter->get_sensitivity_pref() == SensitivityPrefEnum::MILD) {
				cout << *iter;
			}
		}

		cout << endl;
	}

}

void User::view_user_posts(vector<Post>& posts, User user) {
	
	string username = user.get_username();
	
	vector<Post>::iterator iter;
	for (iter = posts.begin(); iter != posts.end(); iter++) {

		if (username == iter->get_username()) {
			cout << *iter;
		}

		cout << endl;
	}
}