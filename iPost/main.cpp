#pragma warning(disable : 4996)

#include <iostream>
#include <fstream>
#include <iterator>
#include <ctime>  
#include <string>
#include <vector>
#include <map>


#include "AppDefinitions.h"
#include "FileIO.h"
#include "EnumHelper.h"
#include "Person.h"
#include "User.h"

using namespace std;

int printing_choice_options(string question, string option_1, string option_2);
void user_login(vector<User> user_data, string& user);
void user_registration(vector<User>& user_data, string& user);


int main() {

	cout << "iPost" << endl;

	vector <User> user_data;
	
	load_user_data(user_data);

	string current_user = "";

	int acct_type = printing_choice_options("What type of user are you?", "User", "Admin");

	if (acct_type == 1) {
		int acct_functionality = printing_choice_options("What would you like to do?", "Login", "Register");

		if (acct_functionality == 1) {
			user_login(user_data, current_user);
		}

		if (acct_functionality == 2) {
			user_registration(user_data, current_user);		
		}

		cout << "Welcome " << current_user << "!";
	}



	return 0;
}

int printing_choice_options(string question, string option_1, string option_2) {

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

void user_login(vector<User> user_data, string& user) {

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
			user = (*iter).get_username();
			break;
		}

	}

	if (iter == user_data.end()) {

		cout << "The username or password you have entered is incorrect." << endl << endl;
		choice = printing_choice_options("What would you like to do?", "Try logging in again", "Exit");

		if (choice == 1) {
			user_login(user_data, user);
		}

		if (choice == 2) {
			user = "ERROR";
		}
	}

}

void user_registration(vector<User>& user_data, string& user) {
	
	cout << endl << "Registration" << endl;

	User new_user;

	string f_name = "";
	string l_name = "";
	string email = "";
	string username = "";
	string password = "";
	string age = "";
	string s_pref = "";
	string last_login = "";
	
	cout << "First Name: ";
	cin >> f_name;

	cout << "Last Name: ";
	cin >> l_name;

	cout << "Email: ";
	cin >> email;

	/*
	vector<User>::iterator iter;
	for (iter = user_data.begin(); iter != user_data.end(); iter++) {

		if ((*iter).get_email_address() == email) {
			cout << "The email you have entered is already taken. Try again!" << endl;
			// TODO ALLOW USER TO REENTER EMAIL
			break;
		}

	}
	*/

	cout << "Username: ";
	cin >> username;

	/*
	vector<User>::iterator iter;
	for (iter = user_data.begin(); iter != user_data.end(); iter++) {

		if ((*iter).get_username() == username) {
			cout << "The username you have entered is already taken. Try again!" << endl;
			// TODO ALLOW USER TO REENTER USERNAME
			break;
		}

	}
	*/

	cout << "Password: ";
	cin >> password;

	cout << "Age: ";
	cin >> age;

	cout << "Sensitivity Preference (MILD, MODERATE, HIGH): ";
	cin >> s_pref;

	time_t current_time = time(nullptr);
	last_login = asctime(localtime(&current_time)); 

	cout << last_login;

	new_user.set_first_name(f_name);
	new_user.set_last_name(l_name);
	new_user.set_email_address(email);
	new_user.set_username(username);
	new_user.set_password(password);
	new_user.set_age(stoi(age));
	new_user.set_sensitivity_pref(string_to_enum_sensitivity_pref(s_pref));
	new_user.set_account_status(AccountStatusEnum::ACTIVE);
	new_user.set_last_login_date_time(current_time);

	user_data.push_back(new_user);
	user = new_user.get_username();

	save_user_data(user_data);

}





