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
#include "PostHelper.h"
#include "Person.h"
#include "User.h"

using namespace std;

int printing_choice_options(string question, string option_1, string option_2);
int printing_choice_options(string question, string option_1, string option_2, string option_3, string option_4);

int main() {

	cout << "iPost" << endl;

	vector <User> user_data;
	vector <Post> posts;
	
	FileIO::load_user_data(user_data);

	User current_user;
	int acct_type = 0;
	int entry_funct = 0;
	int acct_funct = 0;
	int view_post_funct = 0;

	acct_type = printing_choice_options("What type of user are you?", "User", "Admin");

	if (acct_type == 1) {
		entry_funct = printing_choice_options("What would you like to do?", "Login", "Register");

		if (entry_funct == 1) {
			User::user_login(user_data, current_user);

			if (current_user.get_username() == "") {
				return 0;
			}

		}

		if (entry_funct == 2) {
			User::user_registration(user_data, current_user);		
		}

		cout << endl << "Welcome " << current_user.get_first_name() << "!" << endl;
		FileIO::load_post_data(posts);

		acct_funct = printing_choice_options("What would you like to do?", "View Posts", "Make Post", "Delete Post", "Logout");

		if (acct_funct == 1) {
			view_post_funct = printing_choice_options("What posts would you like to view", "My Posts", "All Posts");

			if (view_post_funct == 1) {
				User::view_all_posts(posts);
			}

			if (view_post_funct == 2) {
				User::view_user_posts(posts);
			}

		}

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

	return response;

}

int printing_choice_options(string question, string option_1, string option_2, string option_3, string option_4) {

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





