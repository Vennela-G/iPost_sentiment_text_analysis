#include <iostream>
#include <sstream>
#include <iterator>
#include <string.h>
#include <limits>
#include <ctime>

#include "User.h"
#include "UserInterface.h"
#include "Person.h"
#include "EnumHelper.h"
#include "FileIO.h"
#include "Request.h"

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

int User::login(vector<User>& user_data) {

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

	vector<User>::iterator iter;
	for (iter = user_data.begin(); iter != user_data.end(); iter++) {

		if (this->get_username().compare((*iter).get_username()) == 0 && this->get_password().compare((*iter).get_password()) == 0) {
			this->set_first_name((*iter).get_first_name());
      this->set_last_name((*iter).get_last_name());
			this->set_account_status((*iter).get_account_status());
      this->set_sensitivity_pref((*iter).get_sensitivity_pref());
			return 1;
		}

	}

	if (iter == user_data.end()) {

		cout << "The username or password you have entered is incorrect." << endl << endl;
		choice = UserInterface::printing_choice_options("What would you like to do?", "Try logging in again", "Exit");

		if (choice == 1) {
			login(user_data);
		}

		if (choice == 2) {
			return 0;
		}

	}

	return 0;

}

void user_registration(vector<User>& user_data, User& user) {

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

	char last_login[80];
 	strftime (last_login, 50, "%B %d, %Y %T", localtime(&current_time));
	
	
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
		else if (sensitivity_pref == SensitivityPrefEnum::MODERATE) {
			if (iter->get_sensitivity_pref() == SensitivityPrefEnum::MILD ||
				iter->get_sensitivity_pref() == SensitivityPrefEnum::MODERATE) {
				cout << *iter;
			}
		}
		else if (sensitivity_pref == SensitivityPrefEnum::HIGH) {
			if (iter->get_sensitivity_pref() == SensitivityPrefEnum::MILD) {
				cout << *iter;
			}
		}
   else {
     cout << *iter;
   }

		cout << endl;

	}

}

void User::view_user_posts(vector<Post>& posts) {
	
	vector<Post>::iterator iter;
	for (iter = posts.begin(); iter != posts.end(); iter++) {

		if (get_username() == iter->get_username()) {
			cout << *iter;
		}

		cout << endl;

	}

}

void User::make_post(vector<Post>& posts) {

	Post new_post;

	string message;
	cout << "Enter your message: ";
	cin.ignore();
	getline(cin, message);

	time_t current_time = time(0);

	char post_time[80];
  	strftime (post_time, 50, "%B %d, %Y %T", localtime(&current_time));

	new_post.set_post_id(new_post.gen_random_string());
	new_post.set_username(get_username());
	new_post.set_message(message);
	new_post.set_post_date_time(post_time);
	
	string s_pref_score = Request::make_request(message);
	
	string temp;
        string s_pref_str;
    
    	temp = s_pref_score.substr(s_pref_score.find("0") + 1);
    
    	for (char tmp : temp) {
        	if ((tmp >= 48 && tmp <= 57) || tmp == '.') {
            		s_pref_str += tmp;
        	}
    	}	

    
    	double s_pref_val = 1 - stod(s_pref_str.c_str());
	

  cout << endl << "Negative Sentiment Score: MILD - [0, 0.33], MODERATE - [0.34, 0.66], HIGH - [0.67, 1]" << endl;
  cout << "Your post has a negative sentiment score of " << s_pref_val << endl << endl;
  
  int choice = 0;

	if (s_pref_val >= 0 && s_pref_val <= 0.33) {
		new_post.set_sensitivity_pref(SensitivityPrefEnum::MILD);
	}
	else if (s_pref_val > 0.33 && s_pref_val <+ 0.66) {
		new_post.set_sensitivity_pref(SensitivityPrefEnum::MODERATE);
	}
	else {
		choice = UserInterface::printing_choice_options("Do you wish to post this message?", "Yes", "No");
    if (choice == 2) {
      cout << "iPost did not post your message!" << endl << endl;
      return;
    }
    new_post.set_sensitivity_pref(SensitivityPrefEnum::HIGH);
	} 

	posts.push_back(new_post);
	FileIO::save_post_data(posts);

}

void User::delete_post(vector<Post>& posts) {
	
	int num_user_posts = 0;

	vector<Post>::iterator iter;
	for (iter = posts.begin(); iter != posts.end() - 1; iter++) {

		if (get_username() == iter->get_username()) {
			num_user_posts++;
		}

	}
	
	cout << endl << "Here are your posts:" << endl << endl;
	view_user_posts(posts);

	string post_id = "";

	cout << endl << "Enter the ID of the post you would like to delete: ";
	cin >> post_id;

	bool post_found = false;

	int i = 0;
	for (iter = posts.begin(); iter != posts.end(); iter++) {

		if (post_id.compare(iter->get_post_id()) == 0 && get_username() == iter->get_username()) {
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

ostream& operator<<(ostream& os, User& user) {
	os << "[@" << user.get_username() << "] " << user.get_first_name() << " " << user.get_last_name() << endl;
	return os;
}

User& User::operator += (vector<User>& user_vec) {
      user_vec.push_back(*this); 
      return *this;
}
