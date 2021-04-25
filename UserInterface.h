/*
 * Author: Vennela Gudla Venkata Siva
 * Purpose: This is the header file for the UserInterface class
 */

#ifndef USERINTERFACE_HDR_H
#define USERINTERFACE_HDR_H

#include <string>

using namespace std;

class UserInterface {

	public:

    // Function that returns the choice made by a Person when presented with two distinct options to navigate the application
		static int printing_choice_options(string question, string option_1, string option_2);
		
    // Function that returns the choice made by a Person when presented with four distinct options to navigate the application
    static int printing_choice_options(string question, string option_1, string option_2, string option_3, string option_4);

};

#endif
