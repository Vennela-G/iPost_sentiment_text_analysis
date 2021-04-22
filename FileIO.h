#ifndef FILEIO_HDR_H
#define FILEIO_HDR_H

#include <vector>

#include "User.h"
#include "Post.h"

using namespace std;

class FileIO {

public:

	static void load_user_data(vector<User>& users);
	static void save_user_data(vector<User>& users);

	static void load_post_data(vector<Post>& posts);
	static void save_post_data(vector<Post>& posts);

	static string random_string();

};

#endif