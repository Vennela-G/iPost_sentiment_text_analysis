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
#include "Admin.h"

using namespace std;

int main() {

	cout << "iPost" << endl;

	vector <User> user_info;
	vector <Post> posts;
	
	FileIO::load_user_data(user_info);

	int acct_type = 0;
	int entry_funct = 0;
	int acct_funct = 0;
	int view_post_funct = 0;
	int acct_management_funct = 0;

	acct_type = Person::printing_choice_options("What type of user are you?", "User", "Admin");

	if (acct_type == 1) {
		
		User current_user;

		entry_funct = Person::printing_choice_options("What would you like to do?", "Login", "Register");

		if (entry_funct == 1) {
			int login_successful = current_user.login(user_info);

			if (login_successful == 0) {
				return 0;
			}

		}

		if (entry_funct == 2) {
			User::user_registration(user_info, current_user);
		}

		cout << endl << "Welcome " << current_user.get_first_name() << "!" << endl;

		if (current_user.get_account_status() == AccountStatusEnum::DISABLED) {
			cout << "Your iPost account has disabled!" << endl;
			return -1;
		}

		FileIO::load_post_data(posts);

		do {
			
			acct_funct = Person::printing_choice_options("What would you like to do?", "View Posts", "Make Post", "Delete Post", "Logout");

			if (acct_funct == 1) {
				view_post_funct = Person::printing_choice_options("What posts would you like to view", "My Posts", "All Posts");

				if (view_post_funct == 1) {
					current_user.view_user_posts(posts);
				}

				if (view_post_funct == 2) {
					current_user.view_all_posts(posts);
				}

			}

			if (acct_funct == 2) {
				current_user.make_post(posts);
			}

			if (acct_funct == 3) {
				current_user.delete_post(posts);
			}

		} while (acct_funct != 4);

	}

	if (acct_type == 2) {
		Admin admin;

		int login_successful = admin.login();

		if (login_successful == 0) {
			return 0;
		}

		cout << endl << "Welcome " << admin.get_first_name() << "!" << endl;
		FileIO::load_post_data(posts);

		do {

			acct_funct = Person::printing_choice_options("What would you like to do?", "View All Posts", "Delete Post", "Account Management", "Logout");

			if (acct_funct == 1) {
				admin.view_all_posts(posts);
			}

			if (acct_funct == 2) {
				admin.delete_post(posts);
			}

			if (acct_funct == 3) {
				acct_management_funct = Person::printing_choice_options("What would you like to view", "Disable Account", "Enable Account");
				
				if (acct_management_funct == 1) {
					admin.disable_account(user_info);
				}

				if (acct_management_funct == 2) {
					admin.enable_account(user_info);
				}
				
			}

		} while (acct_funct != 4);

	}

	return 0;
}






