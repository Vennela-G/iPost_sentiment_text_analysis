#include <iostream>
#include "Admin.h"
#include "User.h"
#include "FileIO.h"

using namespace std;

Admin::Admin() {};

int Admin::login() {

	cout << endl << "Login" << endl;

	int choice = 0;

	string username = "";
	cout << "Username: ";
	cin >> username;
	this->set_username(username);

	string password = "";
	cout << "Password: ";
	cin >> password;
	this->set_password(password);

	if (this->get_username() == "admin" && this->get_password() == "password") {
		this->set_first_name("Admin Bot");
		return 1;
	}
	
	cout << "The username or password you have entered is incorrect." << endl << endl;
	choice = printing_choice_options("What would you like to do?", "Try logging in again", "Exit");

	if (choice == 1) {
		login();
	}

	if (choice == 2) {
		return 0;
	}

}

void Admin::view_all_users(vector<User>& users) {

	vector<User>::iterator iter;

	for (iter = users.begin(); iter != users.end(); iter++) {
		cout << *iter << endl;
	}

}

void Admin::view_disabled_users(vector<User>& users) {

	vector<User>::iterator iter;

	for (iter = users.begin(); iter != users.end(); iter++) {
		if ((*iter).get_account_status() == AccountStatusEnum::DISABLED) {
			cout << *iter << endl;
		}
	}

}

void Admin::view_all_posts(vector<Post>& posts) {
	
	vector<Post>::iterator iter;
	
	for (iter = posts.begin(); iter != posts.end(); iter++) {
		cout << *iter << endl;
	}

}

void Admin::delete_post(vector<Post>& posts) {

	cout << endl << "Here are all the user posts:" << endl << endl;
	view_all_posts(posts);

	string post_id = "";

	cout << endl << "Enter the ID of the post you would like to delete: ";
	cin >> post_id;

	bool post_found = false;

	int i = 0;
	vector<Post>::iterator iter;
	for (iter = posts.begin(); iter != posts.end(); iter++) {

		if (post_id.compare(iter->get_post_id()) == 0) {
			post_found = true;
			break;
		}

		i++;

	}

	if (post_found) {
		posts.erase(posts.begin() + i);
		cout << "Deletion Successful!" << endl;
		FileIO::save_post_data(posts);
	}
	else {
		cout << "ERROR: The post ID you have entered is invalid" << endl;
	}

}

void Admin::disable_account(vector<User>& users) {
	
	cout << endl << "Here are all the users" << endl << endl;
	view_all_users(users);

	string username = "";

	cout << endl << "Enter the username of the account you would like to disable: ";
	cin >> username;

	bool account_found = false;

	int i = 0;
	vector<User>::iterator iter;
	for (iter = users.begin(); iter != users.end(); iter++) {

		if (username.compare(iter->get_username()) == 0) {
			(*iter).set_account_status(AccountStatusEnum::DISABLED);
			account_found = true;
			break;
		}

		i++;

	}

	if (account_found) {
		cout << "Account Disabling Successful!" << endl;
		FileIO::save_user_data(users);
	}
	else {
		cout << "ERROR: The username you have entered is invalid" << endl;
	}

}

void Admin::enable_account(vector<User>& users) {

	cout << endl << "Here are all the disabled users" << endl << endl;
	view_disabled_users(users);

	string username = "";

	cout << endl << "Enter the username of the account you would like to enable: ";
	cin >> username;

	bool account_found = false;

	int i = 0;
	vector<User>::iterator iter;
	for (iter = users.begin(); iter != users.end(); iter++) {

		if (username.compare(iter->get_username()) == 0) {
			(*iter).set_account_status(AccountStatusEnum::ACTIVE);
			account_found = true;
			break;
		}

		i++;

	}

	if (account_found) {
		cout << "Account Enabling Successful!" << endl;
		FileIO::save_user_data(users);
	}
	else {
		cout << "ERROR: The username you have entered is invalid" << endl;
	}

}