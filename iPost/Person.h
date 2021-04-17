#ifndef PERSON_HDR_H
#define PERSON_HDR_H

#include <string>
#include <vector>

#include "AppDefinitions.h"

using namespace std;

class Person {
private:
	
	string first_name;
	string last_name;
	string email_address;
	string username;
	string password;

	SensitivityPrefEnum sensitivity_pref;
	AccountStatusEnum account_status;

public:
	
	Person();
	Person(string arg_f_name, string arg_l_name, string arg_email, string arg_username, string arg_password, 
		   SensitivityPrefEnum arg_sensitivity_pref, AccountStatusEnum arg_account_status);

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

	void set_sensitivity_pref(SensitivityPrefEnum arg_sensitivity_pref);
	SensitivityPrefEnum get_sensitivity_pref();

	void set_account_status(AccountStatusEnum arg_account_status);
	AccountStatusEnum get_account_status();

	//virtual void view_posts(const vector<Post>&) = 0;

};

#endif