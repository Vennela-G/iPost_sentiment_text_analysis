#include <iostream>
#include <fstream>
#include <map>

#include "FileIO.h"
#include "AppDefinitions.h"

using namespace std;

void FileIO::load_user_data(vector<User>& users) {

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

void FileIO::save_user_data(vector<User>& users) {

	ofstream user_data_file;
	user_data_file.open("user_info.txt");


	for (int i = 0; i < users.size(); i++) {
		user_data_file << users[i].get_first_name() << ';' << users[i].get_last_name() << ';'
			<< users[i].get_email_address() << ';' << users[i].get_username() << ';'
			<< users[i].get_password() << ';' << enum_sensitivity_pref_to_string(users[i].get_sensitivity_pref()) << ';'
			<< enum_acct_status_to_string(users[i].get_account_status()) << ';' << "04/16/2021" << endl;
	}


}
