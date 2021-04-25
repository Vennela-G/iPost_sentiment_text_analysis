/*
 * Author: Vennela Gudla Venkata Siva
 * Purpose: This is the main program for the iPost application
 */

#include <iostream>
#include <fstream>
#include <iterator>
#include <ctime>  
#include <string>
#include <vector>
#include <map>


#include "AppDefinitions.h"
#include "FileIO.h"
#include "UserInterface.h"
#include "EnumHelper.h"
#include "Person.h"
#include "User.h"
#include "Admin.h"

using namespace std;

int main() {

	cout << "iPost" << endl;

	vector <User> user_info;
	vector <Post> posts;

	FileIO::load_user_data(user_info); // Load user data

	int acct_type = 0;
	int entry_funct = 0;
	int acct_funct = 0;
	int view_post_funct = 0;
	int acct_management_funct = 0;

	do {
		acct_type = UserInterface::printing_choice_options("What type of user are you?", "User", "Admin"); // Prompt for iPost account type

		if (acct_type == 1) {

			User current_user;

			entry_funct = UserInterface::printing_choice_options("What would you like to do?", "Login", "Register"); // Prompt for entry functionality

			if (entry_funct == 1) { // User Login
				int login_successful = current_user.login(user_info);

				if (login_successful == 0) {
					return 0;
				}

			}

			if (entry_funct == 2) { // User Registration
				user_registration(user_info, current_user);
			}

      // Welcome user if login was successful
			cout << endl << "Welcome " << current_user.get_first_name() << "!" << endl;

      // If the User's account is disabled, automatically log them out
			if (current_user.get_account_status() == AccountStatusEnum::DISABLED) {
				cout << "Your iPost account has disabled!" << endl;
				return -1;
			}

			FileIO::load_post_data(posts); // Load post data


			do {

				acct_funct = UserInterface::printing_choice_options("What would you like to do?", "View Posts", "Make Post", "Delete Post", "Logout"); // Prompt for account functionality

				if (acct_funct == 1) {
					view_post_funct = UserInterface::printing_choice_options("What posts would you like to view", "My Posts", "All Posts");

					if (view_post_funct == 1) {
						current_user.view_user_posts(posts); // View user posts
					}

					if (view_post_funct == 2) {
						current_user.view_all_posts(posts); // View all posts
					}

				}

				if (acct_funct == 2) {
					current_user.make_post(posts); // Make post
				}

				if (acct_funct == 3) {
					current_user.delete_post(posts); // Delete post
				}

			} while (acct_funct != 4); // Data Validation

		}

		if (acct_type == 2) { // Admin login
			Admin admin;

			int login_successful = admin.login();

			if (login_successful == 0) {
				return 0;
			}

			// Welcome admin if login was successful
      cout << endl << "Welcome " << admin.get_first_name() << "!" << endl;
			FileIO::load_post_data(posts); // Load post data

			do { // Prompt for account functionality

				acct_funct = UserInterface::printing_choice_options("What would you like to do?", "View All Posts", "Delete Post", "Account Management", "Logout"); 

				if (acct_funct == 1) {
					admin.view_all_posts(posts); // View all Posts
				}

				if (acct_funct == 2) {
					admin.delete_post(posts); // Delete post
				}

				if (acct_funct == 3) {
					acct_management_funct = UserInterface::printing_choice_options("What would you like to view", "Disable Account", "Enable Account"); // Prompt for account management functionality

					if (acct_management_funct == 1) {
						admin.disable_account(user_info); // Disable Account
					}

					if (acct_management_funct == 2) {
						admin.enable_account(user_info); // Enable Account
					}

				}

			} while (acct_funct != 4); // Data Validation

		}

	} while(acct_type != 1 && acct_type != 2); // Data Validation

	return 0;
}






