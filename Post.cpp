#include <iostream>

#include "Post.h"
#include "EnumHelper.h"

using namespace std;

Post::Post() {
	post_id = "";
	username = "";
	message = "";
	post_date_time = "";

	sensitivity_pref = SensitivityPrefEnum::MILD;
}

Post::Post(string arg_post_id, string arg_username, string arg_message, string arg_post_date_time,
	SensitivityPrefEnum arg_sensitivity_pref) {
	post_id = arg_post_id;
	username = arg_username;
	message = arg_message;
	post_date_time = arg_post_date_time;

	sensitivity_pref = arg_sensitivity_pref;
}

void Post::set_post_id(string arg_post_id) {
	post_id = arg_post_id;
}

string Post::get_post_id() {
	return post_id;
}

void Post::set_username(string arg_username) {
	username = arg_username;
}

string Post::get_username() {
	return username;
}

void Post::set_message(string arg_message) {
	message = arg_message;
}

string Post::get_message() {
	return message;
}

void Post::set_post_date_time(string arg_post_date_time) {
	post_date_time = arg_post_date_time;
}

string Post::get_post_date_time() {
	return post_date_time;
}

void Post::set_sensitivity_pref(SensitivityPrefEnum arg_sensitivity_pref) {
	sensitivity_pref = arg_sensitivity_pref;
}

SensitivityPrefEnum Post::get_sensitivity_pref() {
	return sensitivity_pref;
}

string Post::gen_random_string() {
				
	string temp_string;
	static const char alpha_num_arr[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	for (unsigned int i = 0; i < 6; ++i) {
		srand(time(0));
		temp_string += alpha_num_arr[(rand() % 6) + 1];
	}
	
	return temp_string;

}

ostream& operator<<(ostream& os, Post& post) {
	os << "[ID: " << post.get_post_id() << "]  @" << post.get_username() << " " << post.get_post_date_time() << endl << post.get_message() << endl;
	return os;
}

Post& Post::operator += (vector<Post>& post_vec) {
     post_vec.push_back(*this); 
     return *this;
}
