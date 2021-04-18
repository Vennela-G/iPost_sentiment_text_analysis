#ifndef POSTHELPER_HDR_H
#define POSTHELPER_HDR_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "AppDefinitions.h"
#include "Post.h"
#include "User.h"

using namespace std;

class PostHelper {

public:

	static void print_posts(vector<Post>& posts, User user);
	static void print_my_posts(vector<Post>& posts, User);

};

#endif