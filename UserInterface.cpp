#include <iostream>

#include "UserInterface.h"

using namespace std;

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
