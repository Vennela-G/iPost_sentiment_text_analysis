/*
 * Author: Vennela Gudla Venkata Siva
 * Purpose: This is the header file for the FileIO class
 */

#ifndef FILEIO_HDR_H
#define FILEIO_HDR_H

#include <vector>

#include "User.h"
#include "Post.h"

using namespace std;

class FileIO {

public:

	static void load_user_data(vector<User>& users); // A static function to read user data from the “user_info.txt” file and use it to populate a vector of Users.
	static void save_user_data(vector<User>& users); // A static function to write user data to the “user_info.txt” file from the input User vector, to save any changes

	static void load_post_data(vector<Post>& posts); // A static function to read post data from the “posts.txt” file and use it to populate a vector of Posts.
	static void save_post_data(vector<Post>& posts); // A static function to write post data to the “posts.txt” file from the input Posts vector, to save any changes

};

#endif
