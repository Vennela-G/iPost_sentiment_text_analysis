/*
 * Author: Vennela Gudla Venkata Siva
 * Purpose: This is the impementation file for the UserInterface class. 
 *          The purpose of this class is to provide methods that allows
 *          the users to interact and navigate through the iPost application.
 */

#include <iostream>

#include "UserInterface.h"

using namespace std;

// // Function that returns the choice made by a Person when presented with two distinct options to navigate the application
int UserInterface::printing_choice_options(string question, string option_1, string option_2) {

        int response = 0;

        do {
                cout << endl << question << endl;
                cout << "[1] " << option_1 << endl;
                cout << "[2] " << option_2 << endl << endl;

                cout << "Option: ";
                cin >> response;

                if (response == 1 || response == 2) {
                        return response;
                }
                else {
                        cout << "ERROR: You have entered an invalid option! Please try again." << endl << endl;
      response = -1;
                }

        } while (response == -1);

}

// Function that returns the choice made by a Person when presented with four distinct options to navigate the application
int UserInterface::printing_choice_options(string question, string option_1, string option_2, string option_3, string option_4) {

        int response = 0;

        do {
                cout << endl << question << endl;
                cout << "[1] " << option_1 << endl;
                cout << "[2] " << option_2 << endl;
                cout << "[3] " << option_3 << endl;
                cout << "[4] " << option_4 << endl << endl;

                cout << "Option: ";
                cin >> response;

                if ((response == 1 || response == 2) || (response == 3 || response == 4)) {
                        return response;
                }
                else {
                        cout << "ERROR: You have entered an invalid option! Please try again." << endl << endl;
      response = -1;
                }

        } while (response == -1);

        return response;

}
