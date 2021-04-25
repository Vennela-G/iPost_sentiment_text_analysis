/*
 * Author: Vennela Gudla Venkata Siva
 * Purpose: This is the header file for the Admin class
 */

#ifndef ADMIN_HDR_H
#define ADMIN_HDR_H

#include <string>
#include <vector>

#include "Person.h"
#include "User.h"
#include "Post.h"

using namespace std;

// The Admin class is a derived class from the base class Person
class Admin : public Person {

public:

	int login(); // A function that allows an admin to login to their iPost account if the login information they provided, is matches the admin credentials

	void view_all_users(vector<User>& users); // A function that allows the admin to view all iPost users.
	void view_disabled_users(vector<User>& users); // A function that allows the admin to view all disabled iPost user accounts.

	void view_all_posts(vector<Post>& posts); // The overridden function from the base class “Person” that allows the admin to view all posts, irrespective of their sensitivity rating.
	void delete_post(vector<Post>& posts); // The overridden function from the base class “Person” that allows the admin to delete a specific user’s posts.
	void disable_account(vector<User>& users); // A function to disable a particular user’s account and save the changes to the user data database so they cannot use their account.
	void enable_account(vector<User>& users); // A function to enable a particular user’s account and save the changes to the user data database so they can use their account again.

};

#endif
