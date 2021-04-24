#ifndef ADMIN_HDR_H
#define ADMIN_HDR_H

#include <string>
#include <vector>

#include "Person.h"
#include "User.h"
#include "Post.h"

using namespace std;

class Admin : public Person {

public:

	int login();

	void view_all_users(vector<User>& users);
	void view_disabled_users(vector<User>& users);

	void view_all_posts(vector<Post>& posts);
	void delete_post(vector<Post>& posts);
	void disable_account(vector<User>& users);
	void enable_account(vector<User>& users);

};

#endif
