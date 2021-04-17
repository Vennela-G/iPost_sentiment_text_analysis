#include <iostream>
#include <string.h>

#include "User.h"
#include "Person.h"

using namespace std;

User::User() {
    age = 0;
    sensitivity_pref = SensitivityPrefEnum::MILD;
    account_status = AccountStatusEnum::ACTIVE;
    last_login_date_time = 0;
}

User::User(int arg_age, SensitivityPrefEnum arg_sensitivity_pref, AccountStatusEnum arg_account_status, time_t arg_last_login_date_time) {
    age = arg_age;
    sensitivity_pref = arg_sensitivity_pref;
    account_status = arg_account_status;
    last_login_date_time = arg_last_login_date_time;
}

void User::set_age(int arg_age) {
    age = arg_age;
}

int User::get_age() {
    return age;
}

void User::set_sensitivity_pref(SensitivityPrefEnum arg_sensitivity_pref) {
    sensitivity_pref = arg_sensitivity_pref;
}

SensitivityPrefEnum User::get_sensitivity_pref() {
    return sensitivity_pref;
}

void User::set_account_status(AccountStatusEnum arg_account_status) {
    account_status = arg_account_status;
}

AccountStatusEnum User::get_account_status() {
    return account_status;
}

void User::set_last_login_date_time(time_t arg_last_login_date_time) {
    last_login_date_time = arg_last_login_date_time;
}

time_t User::get_last_login_date_time() {
    return last_login_date_time;
}

//void view_posts(const vector<Post>&);
