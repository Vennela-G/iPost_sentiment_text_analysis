/*
 * Author: Vennela Gudla Venkata Siva
 * Purpose: This is the header file for the Person class
 */

#ifndef PERSON_HDR_H
#define PERSON_HDR_H

#include <string>
#include <vector>

#include "AppDefinitions.h"
#include "Post.h"

using namespace std;

// Base class for which User and Admin are derived

class Person {
private:
	
	string first_name;
	string last_name;
	string email_address;
	string username;
	string password;

public:
	
	Person(); // Default constructor for the Person class 
	Person(string arg_f_name, string arg_l_name, string arg_email, string arg_username, string arg_password); // Constructor for the Person class

  // Setters & Getter for each attribute in the Person Object
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

  // Virtual function to view posts, that will be overridden by the derived classes User and Admin since both have different “viewing” capabilities
	virtual void view_all_posts(vector<Post>& posts) = 0; 
	
  // Virtual function to delete posts, that will be overridden by the derived classes User and Admin since both have different “deletion” capabilities
  virtual void delete_post(vector<Post>& posts) = 0;

};

#endif
