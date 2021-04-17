#ifndef FILEIO_HDR_H
#define FILEIO_HDR_H

#include <vector>

#include "User.h"

using namespace std;

class FileIO {

public:

	void load_user_data(vector<User>& users);
	void save_user_data(vector<User>& users);

};

#endif