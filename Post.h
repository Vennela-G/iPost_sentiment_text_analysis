#ifndef POST_HDR_H
#define POST_HDR_H

#include <string>
#include <vector>

#include "AppDefinitions.h"
//#include "Admin.h"

using namespace std;

class Post {
private:

	string post_id;
	string username;
	string message;
	string post_date_time;

	SensitivityPrefEnum sensitivity_pref;

public:

	Post();
	Post(string arg_post_id, string arg_username, string arg_message, string arg_post_date_time,
		SensitivityPrefEnum arg_sensitivity_pref);

	void set_post_id(string arg_post_id);
	string get_post_id();

	void set_username(string arg_username);
	string get_username();

	void set_message(string arg_message);
	string get_message();

	void set_post_date_time(string arg_post_date_time);
	string get_post_date_time();

	void set_sensitivity_pref(SensitivityPrefEnum arg_sensitivity_pref);
	SensitivityPrefEnum get_sensitivity_pref();

	//friend void delete_post(User&, Post&, Admin&);
	friend ostream& operator<<(ostream& os, Post& p);

};

#endif