/*
 * Author: Vennela Gudla Venkata Siva
 * Purpose: This is the impementation file for the Admin class. The purpose of Admin class
 *          is to provide implementation for the Admin functions like viewing all users,
 *          view disabled users, enable and disable accounts and delete posts.
 */

#include <iostream>
#include "Admin.h"
#include "User.h"
#include "FileIO.h"
#include "UserInterface.h"

using namespace std;

// A function that allows an admin to login to their iPost account if the login information they provided, is matches the admin credentials
int Admin::login() {

	cout << endl << "Login" << endl;

	int choice = 0;

	string username = "";
	cout << "Username: ";
	cin >> username;
	this->set_username(username); // set the inputted username to the current admin object's username

	string password = "";
	cout << "Password: ";
	cin >> password;
	this->set_password(password); // set the inpuutted password to the current admin object's password

	// iPost only has 1 Admin
	// If the Admin credentials match, successfully log in the Admin
	if (this->get_username() == "admin" && this->get_password() == "password") {
		this->set_first_name("Admin Bot"); // Set the name "Admin Bot" to the current admin object's first name
		return 1;
	}
	
	// If the login attempt is unsuccessful, provide other options to allow the admin to try again or exit the application
	cout << "The username or password you have entered is incorrect." << endl << endl;
	choice = UserInterface::printing_choice_options("What would you like to do?", "Try logging in again", "Exit");

	if (choice == 1) {
		login();
	}

	if (choice == 2) {
		return 0;
	}

}

// A function that allows the admin to view all iPost users.
void Admin::view_all_users(vector<User>& users) {

	vector<User>::iterator iter;

	// Iterate through the users vector and print the respective user information for all user accounts
	for (iter = users.begin(); iter != users.end(); iter++) {
		cout << *iter << endl;
	}

}

// A function that allows the admin to view all disabled iPost user accounts.
void Admin::view_disabled_users(vector<User>& users) {

	vector<User>::iterator iter;

	// Iterate through the users vector and print the respective user information for all disabled user accounts
	for (iter = users.begin(); iter != users.end(); iter++) {
		if ((*iter).get_account_status() == AccountStatusEnum::DISABLED) {
			cout << *iter << endl;
		}
	}

}

// The overridden function from the base class “Person” that allows the admin to view all posts, irrespective of their sensitivity rating.
void Admin::view_all_posts(vector<Post>& posts) {
	
	vector<Post>::iterator iter;
	
	// Iterate through the posts vector and print the respective post data for all current posts on iPost
	for (iter = posts.begin(); iter != posts.end(); iter++) {
		cout << *iter << endl;
	}

}

// The overridden function from the base class “Person” that allows the admin to delete a specific user’s posts.
void Admin::delete_post(vector<Post>& posts) {

	// Print all current posts on iPost
	cout << endl << "Here are all the user posts:" << endl << endl;
	view_all_posts(posts);

	string post_id = "";

	// Prompt for / Take in the ID of the post to be deleted
	cout << endl << "Enter the ID of the post you would like to delete: ";
	cin >> post_id;

	bool post_found = false;

	int i = 0;
	vector<Post>::iterator iter;
	
	// Iterate through all the current posts on iPost and if a post in the vector has an ID that matches the inputted value, break out of the loop
	for (iter = posts.begin(); iter != posts.end(); iter++) {

		if (post_id.compare(iter->get_post_id()) == 0) {
			post_found = true;
			break;
		}

		i++;

	}

	if (post_found) {
		posts.erase(posts.begin() + i); // Delete the respective post using the erase() vector method and the i value that kept track of the Post's location
		cout << "Deletion Successful!" << endl;
		FileIO::save_post_data(posts); // Save the post data 
	}
	else {
		cout << "ERROR: The post ID you have entered is invalid" << endl; // Alert the Admin if the post ID could not be found
	}

}

// A function to disable a particular user’s account and save the changes to the user data database so they cannot use their account.
void Admin::disable_account(vector<User>& users) {
	
	// Print all current iPost users
	cout << endl << "Here are all the users" << endl << endl;
	view_all_users(users);

	string username = "";

	// Prompt for / Take in the username of the account to be disabled
	cout << endl << "Enter the username of the account you would like to disable: ";
	cin >> username;

	bool account_found = false;

	int i = 0;
	vector<User>::iterator iter;

	// Iterate through all the current users on iPost and if a user in the given vector has a username that matches the inputted value,
	// change their account status and break out of the loop
	for (iter = users.begin(); iter != users.end(); iter++) {

		if (username.compare(iter->get_username()) == 0) {
			(*iter).set_account_status(AccountStatusEnum::DISABLED); // Change the accout status of the respective user
			account_found = true;
			break;
		}

		i++;

	}

	if (account_found) {
		cout << "Account Disabling Successful!" << endl; // Alert the Admin that the account disabling was successful
		FileIO::save_user_data(users); // Save the user data
	}
	else {
		cout << "ERROR: The username you have entered is invalid" << endl; // Alert the Admin that the inputted username could not be found
	}

}

// A function to enable a particular user’s account and save the changes to the user data database so they can use their account again.
void Admin::enable_account(vector<User>& users) {

	// Print the respective information for all currently disabled iPost user accounts
  cout << endl << "Here are all the disabled users" << endl << endl;
	view_disabled_users(users);

	string username = "";

	// Prompt for / Take in the username of the account to be enabled
  cout << endl << "Enter the username of the account you would like to enable: ";
	cin >> username;

	bool account_found = false;

	int i = 0;
	vector<User>::iterator iter;
	
	// Iterate through all the current users on iPost and if a user in the given vector has a username that matches the inputted value,
	// change their account status and break out of the loop
  for (iter = users.begin(); iter != users.end(); iter++) {

		if (username.compare(iter->get_username()) == 0) {
			(*iter).set_account_status(AccountStatusEnum::ACTIVE); // Change the accout status of the respective user
			account_found = true;
			break;
		}

		i++;

	}

	if (account_found) {
		cout << "Account Enabling Successful!" << endl; // Alert the Admin that the account enabling was successful
		FileIO::save_user_data(users); // Save the user data
	}
	else {
		cout << "ERROR: The username you have entered is invalid" << endl; // Alert the Admin that the inputted username could not be found
	}

}
