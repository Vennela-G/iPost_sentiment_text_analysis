#include <iostream>
#include <string.h>

#include "User.h"
#include "Person.h"

using namespace std;

User::User() {
    age = 0;
    last_login_date_time = 0;
}

User::User(int arg_age, time_t arg_last_login_date_time) {
    age = arg_age;
    last_login_date_time = arg_last_login_date_time;
}

void User::set_age(int arg_age) {
    age = arg_age;
}

int User::get_age() {
    return age;
}

void User::set_last_login_date_time(time_t arg_last_login_date_time) {
    last_login_date_time = arg_last_login_date_time;
}

time_t User::get_last_login_date_time() {
    return last_login_date_time;
}

//void view_posts(const vector<Post>&);
