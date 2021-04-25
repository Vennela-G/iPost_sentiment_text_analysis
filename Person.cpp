/*
 * Author: Vennela Gudla Venkata Siva
 * Purpose: This is the impementation file for the Person class. The purpose of this
 *          class is to provide Person base class constructor and getter/setters. The Person
 *          class is an abstract class because it has 2 pure virtual functions which the derived
 *          classes must override.
 */

#include <iostream>

#include "Person.h"
#include "AppDefinitions.h"
#include "Post.h"

using namespace std;

// Default constructor for the Person class 
Person::Person() {
	first_name = "";
	last_name = "";
	email_address = "";
	username = "";
	password = "";
}

// Constructor for the Person class
Person::Person(string arg_f_name, string arg_l_name, string arg_email, string arg_username, string arg_password) {
	first_name = arg_f_name;
	last_name = arg_l_name;
	email_address = arg_email;
	username = arg_username;
	password = arg_password;
}

// Setters & Getter for each attribute in the Person Object

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

