#include <iostream>
#include <fstream>
#include <algorithm>

#include "FileIO.h"
#include "AppDefinitions.h"
#include "EnumHelper.h"
#include "Post.h"

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

	string rand = "";

	time_t current_time = time(0);
	
	char last_login[26];
	ctime_s(last_login, sizeof last_login, &current_time);

	ifstream user_data_file;
	user_data_file.open("user_info.txt");


	if (user_data_file.is_open()) {
		while (getline(user_data_file, f_name, ';')) {
			getline(user_data_file, l_name, ';');
			getline(user_data_file, email, ';');
			getline(user_data_file, username, ';');
			getline(user_data_file, password, ';');
			getline(user_data_file, age, ';');
			getline(user_data_file, s_pref, ';');
			getline(user_data_file, acct_status, ';');
			getline(user_data_file, rand, '\n');

			temp.set_first_name(f_name);
			temp.set_last_name(l_name);
			temp.set_email_address(email);
			temp.set_username(username);
			temp.set_password(password);
			temp.set_age(stoi(age));
			temp.set_sensitivity_pref(EnumHelper::string_to_enum_sensitivity_pref(s_pref));
			temp.set_account_status(EnumHelper::string_to_acct_status(acct_status));
			temp.set_last_login_date_time(last_login);

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


	for (size_t i = 0; i < users.size(); i++) {
		user_data_file << users[i].get_first_name() << ';' << users[i].get_last_name() << ';'
			<< users[i].get_email_address() << ';' << users[i].get_username() << ';'
			<< users[i].get_password() << ';' << users[i].get_age() << ';' 
			<< EnumHelper::enum_sensitivity_pref_to_string(users[i].get_sensitivity_pref()) << ';'
			<< EnumHelper::enum_acct_status_to_string(users[i].get_account_status()) << ';' 
			<< users[i].get_last_login_date_time() << endl;
	}


}

void FileIO::load_post_data(vector<Post>& posts) {

	Post temp;

	string post_id;
	string username;
	string message;
	string post_date_time;
	string s_pref;

	ifstream posts_file;
	posts_file.open("posts.txt");


	if (posts_file.is_open()) {
		while (getline(posts_file, post_id, '^')) {
			getline(posts_file, username, '^');
			getline(posts_file, message, '^');
			getline(posts_file, post_date_time, '^');
			getline(posts_file, s_pref, '\n');

			temp.set_post_id(post_id);
			temp.set_username(username);
			temp.set_message(message);
			temp.set_post_date_time(post_date_time);
			temp.set_sensitivity_pref(EnumHelper::string_to_enum_sensitivity_pref(s_pref));

			posts.push_back(temp);
		}
		posts_file.close();
	}
	else {
		cout << "Unable to view iPosts at this time" << endl;
	}

}

void FileIO::save_post_data(vector<Post>& posts) {

	ofstream posts_file;
	posts_file.open("posts.txt");


	for (size_t i = 0; i < posts.size(); i++) {
		posts_file << posts[i].get_post_id() << '^' << posts[i].get_username() << '^'
			<< posts[i].get_message() << '^' << posts[i].get_post_date_time() << '^'
			<< EnumHelper::enum_sensitivity_pref_to_string(posts[i].get_sensitivity_pref()) << endl;
	}


}

string FileIO::random_string() {
				
	string temp_string;
	static const char alpha_num_arr[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	for (unsigned int i = 0; i < 6; ++i) {
		srand(time(0));
		temp_string += alpha_num_arr[(rand() % 6) + 1];
	}
	
	return temp_string;

}

