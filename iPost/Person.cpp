#include <iostream>

#include "Person.h"
#include "AppDefinitions.h"
//#include "Post.H"

using namespace std;

Person::Person() {
	first_name = "";
	last_name = "";
	email_address = "";
	username = "";
	password = "";

	sensitivity_pref = SensitivityPrefEnum::MILD;
	account_status = AccountStatusEnum::ACTIVE;
}

Person::Person(string arg_f_name, string arg_l_name, string arg_email, string arg_username, string arg_password,
			   SensitivityPrefEnum arg_sensitivity_pref, AccountStatusEnum arg_account_status) {
	first_name = arg_f_name;
	last_name = arg_l_name;
	email_address = arg_email;
	username = arg_username;
	password = arg_password;

	sensitivity_pref = arg_sensitivity_pref;
	account_status = arg_account_status;
}

void Person::set_first_name(string arg_f_name) {
	first_name = arg_f_name;
}

string Person::get_first_name() {
	return first_name;
}

void Person::set_last_name(string arg_l_name) {
	last_name = arg_l_name;
}

string Person::get_last_name() {
	return last_name;
}

void Person::set_email_address(string arg_email) {
	email_address = arg_email;
}

string Person::get_email_address() {
	return email_address;
}

void Person::set_username(string arg_username) {
	username = arg_username;
}

string Person::get_username() {
	return username;
}

void Person::set_password(string arg_password) {
	password = arg_password;
}

string Person::get_password() {
	return password;
}

void Person::set_sensitivity_pref(SensitivityPrefEnum arg_sensitivity_pref) {
	sensitivity_pref = arg_sensitivity_pref;
}

SensitivityPrefEnum Person::get_sensitivity_pref() {
	return sensitivity_pref;
}

void Person::set_account_status(AccountStatusEnum arg_account_status) {
	account_status = arg_account_status;
}

AccountStatusEnum Person::get_account_status() {
	return account_status;
}