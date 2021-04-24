#ifndef USERINTERFACE_HDR_H
#define USERINTERFACE_HDR_H

#include <string>

using namespace std;

class UserInterface {

public:
	
	static int printing_choice_options(string question, string option_1, string option_2);
  static int printing_choice_options(string question, string option_1, string option_2, string option_3, string option_4);
 
};

#endif
