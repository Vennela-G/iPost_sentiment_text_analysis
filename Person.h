#ifndef PERSON_HDR_H
#define PERSON_HDR_H

#include <string>
#include <vector>

#include "AppDefinitions.h"
#include "Post.h"

using namespace std;

class Person {
private:
	
	string first_name;
	string last_name;
	string email_address;
	string username;
	string password;

public:
	
	Person();
	Person(string arg_f_name, string arg_l_name, string arg_email, string arg_username, string arg_password);

	void set_first_name(string arg_f_name);
	string get_first_name();

	void set_last_name(string arg_l_name);
	string get_last_name();

	void set_email_address(string arg_email);
	string get_email_address();

	void set_username(string arg_username);
	string get_username();

	void set_password(string arg_password);
	string get_password();

	virtual void view_all_posts(vector<Post>& posts) = 0;

	static int printing_choice_options(string question, string option_1, string option_2);
	static int printing_choice_options(string question, string option_1, string option_2, string option_3, string option_4);

};

#endif