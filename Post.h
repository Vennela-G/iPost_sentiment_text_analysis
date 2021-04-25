/*
 * Author: Vennela Gudla Venkata Siva
 * Purpose: This is the header file for the Post class
 */

#ifndef POST_HDR_H
#define POST_HDR_H

#include <string>
#include <vector>

#include "AppDefinitions.h"

using namespace std;

class Post {
private:

	string post_id;
	string username;
	string message;
	string post_date_time;

	SensitivityPrefEnum sensitivity_pref;

public:

	Post(); // Default constructor for the Post class.
	Post(string arg_post_id, string arg_username, string arg_message, string arg_post_date_time,
		SensitivityPrefEnum arg_sensitivity_pref); // Constructor for the Post class.

  // Setters & Getter for each attribute in the Post Object
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
 
  // A function to generate a random string of six-character length to create a unique post id
  string gen_random_string();
  
  // A friend function to overload the << (insertion) operator
	friend ostream& operator<<(ostream& os, Post& p);
  
  // An overloaded operator to easily append/push back new posts to the posts vector
  Post& operator += (vector<Post>& post_vec);

};

#endif
