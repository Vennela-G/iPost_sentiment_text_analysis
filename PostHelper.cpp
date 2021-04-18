#include <iostream>
#include <fstream>
#include <vector>

#include "Post.h"
#include "PostHelper.h"
#include "EnumHelper.h"

void PostHelper::print_posts(vector<Post>& posts, User user) {

	SensitivityPrefEnum s_pref = user.get_sensitivity_pref();
	
	for (size_t i = 0; i < posts.size(); i++) {
				
		if (s_pref == SensitivityPrefEnum::MILD) {
			cout << posts[i];
		}

		if (s_pref == SensitivityPrefEnum::MODERATE) {	
			if (posts[i].get_sensitivity_pref() == SensitivityPrefEnum::MILD ||
				posts[i].get_sensitivity_pref() == SensitivityPrefEnum::MODERATE) {
				cout << posts[i];
			}
		}

		if (s_pref == SensitivityPrefEnum::HIGH) {
			if (posts[i].get_sensitivity_pref() == SensitivityPrefEnum::MILD) {
				cout << posts[i];
			}
		}

		cout << endl;
	}

}

void PostHelper::print_my_posts(vector<Post>& posts, User user) {

	string username = user.get_username();

	for (size_t i = 0; i < posts.size(); i++) {

		if (posts[i].get_username() == username) {
			cout << posts[i];
		}

		cout << endl;
	}

}