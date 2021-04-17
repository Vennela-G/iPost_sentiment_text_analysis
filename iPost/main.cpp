#pragma warning(disable : 4996)

#include <iostream>
#include <fstream>
#include <iterator>
#include <ctime>  
#include <string>
#include <vector>
#include <map>


#include "AppDefinitions.h"
#include "Person.h"
#include "User.h"

using namespace std;

void initializeEnumsToMap(map<string, AccountStatusEnum>& arg1, map<string, SensitivityPrefEnum>& arg2);
SensitivityPrefEnum string_to_enum_sensitivity_pref(string enum_str);
string enum_sensitivity_pref_to_string(SensitivityPrefEnum s_pref);
string enum_acct_status_to_string(AccountStatusEnum acct_status);

void load_user_data(vector<User>& users);
void save_user_data(vector<User>& users);

map<string, AccountStatusEnum> acctStatusEnumMap;
map<string, SensitivityPrefEnum> sensitivityPrefEnumMap;

int printing_choice_options(string question, string option_1, string option_2);
void user_login(vector<User> user_data, string& user);
void user_registration(vector<User>& user_data, string& user);


int main() {

	cout << "iPost" << endl;

	initializeEnumsToMap(acctStatusEnumMap, sensitivityPrefEnumMap);

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

void initializeEnumsToMap(map<string, AccountStatusEnum>& acctStatusEnumMap, map<string, SensitivityPrefEnum>& sensitivityPrefEnumMap)
{
	acctStatusEnumMap["ACTIVE"] = AccountStatusEnum::ACTIVE;
	acctStatusEnumMap["INACTIVE"] = AccountStatusEnum::INACTIVE;
	acctStatusEnumMap["DISABLED"] = AccountStatusEnum::DISABLED;


	sensitivityPrefEnumMap["MILD"] = SensitivityPrefEnum::MILD;
	sensitivityPrefEnumMap["MODERATE"] = SensitivityPrefEnum::MODERATE;
	sensitivityPrefEnumMap["HIGH"] = SensitivityPrefEnum::HIGH;

}

SensitivityPrefEnum string_to_enum_sensitivity_pref(string enum_str) {

	map<string, SensitivityPrefEnum>::iterator sensPrefMapIter;

	SensitivityPrefEnum temp;
	sensPrefMapIter = sensitivityPrefEnumMap.find(enum_str);
	
	if (sensPrefMapIter != sensitivityPrefEnumMap.end())
		temp = sensPrefMapIter->second;
	else
		temp = SensitivityPrefEnum::MILD;

	return temp;
}

string enum_sensitivity_pref_to_string(SensitivityPrefEnum s_pref) {

	switch (s_pref)
	{
	case SensitivityPrefEnum::MILD:
		return "MILD";
	case SensitivityPrefEnum::MODERATE:
		return "MODERATE";
	case SensitivityPrefEnum::HIGH:
		return "HIGH";
	}

}

string enum_acct_status_to_string(AccountStatusEnum acct_status) {

	switch (acct_status)
	{
	case AccountStatusEnum::ACTIVE:
		return "ACTIVE";
	case AccountStatusEnum::INACTIVE:
		return "INACTIVE";
	case AccountStatusEnum::DISABLED:
		return "DISABLED";
	}

}

void load_user_data(vector<User>& users) {

	User temp;

	string f_name = "";
	string l_name = "";
	string email = "";
	string username = "";
	string password = "";
	string age = "";
	string s_pref = "";
	string acct_status = "";
	string last_login = "";


	ifstream user_data_file;
	user_data_file.open("user_info.txt");
	map<string, AccountStatusEnum>::iterator acctStatusMapIter;
	map<string, SensitivityPrefEnum>::iterator sensPrefMapIter;


	if (user_data_file.is_open()) {
		while (getline(user_data_file, f_name, ';')) {
			getline(user_data_file, l_name, ';');
			getline(user_data_file, email, ';');
			getline(user_data_file, username, ';');
			getline(user_data_file, password, ';');
			getline(user_data_file, age, ';');
			getline(user_data_file, s_pref, ';');
			getline(user_data_file, acct_status, ';');
			getline(user_data_file, last_login, '\n');

			acctStatusMapIter = acctStatusEnumMap.find(acct_status);
			sensPrefMapIter = sensitivityPrefEnumMap.find(s_pref);

			temp.set_first_name(f_name);
			temp.set_last_name(l_name);
			temp.set_email_address(email);
			temp.set_username(username);
			temp.set_password(password);
			temp.set_age(stoi(age));

			if (acctStatusMapIter != acctStatusEnumMap.end()) {
				temp.set_account_status(acctStatusMapIter->second);
			}
			else {
				temp.set_account_status(AccountStatusEnum::ACTIVE);
			}

			if (sensPrefMapIter != sensitivityPrefEnumMap.end()) {
				temp.set_sensitivity_pref(sensPrefMapIter->second);
			}
			else {
				temp.set_sensitivity_pref(SensitivityPrefEnum::MILD);
			}

			users.push_back(temp);
		}
		user_data_file.close();
	}
	else {
		cout << "Unable to sign in to iPost at this time" << endl;
	}

}

void save_user_data(vector<User>& users) {

	ofstream user_data_file;
	user_data_file.open("user_info.txt");


	for (int i = 0; i < users.size(); i++) {
		user_data_file << users[i].get_first_name() << ';' << users[i].get_last_name() << ';'
			<< users[i].get_email_address() << ';' << users[i].get_username() << ';'
			<< users[i].get_password() << ';' << enum_sensitivity_pref_to_string(users[i].get_sensitivity_pref()) << ';'
			<< enum_acct_status_to_string(users[i].get_account_status()) << ';' << "04/16/2021" << endl;
	}


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





