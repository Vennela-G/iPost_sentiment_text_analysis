/*
 * Author: Vennela Gudla Venkata Siva
 * Purpose: This is the header file for the User class
 */

#ifndef USER_HDR_H
#define USER_HDR_H

#include <ctime>
#include <vector>

#include "Person.h"
#include "Post.h"

class User : public Person {
private:
    
    int age;
    SensitivityPrefEnum sensitivity_pref;
    AccountStatusEnum account_status;
    char* last_login_date_time = 0;

public: 
    
    User(); // Default constructor for the User class
    User(int arg_age, SensitivityPrefEnum arg_sensitivity_pref, AccountStatusEnum arg_account_status, char* arg_last_login_date_time); // Constructor for the User class
    User(string arg_f_name, string arg_l_name, string arg_email, string arg_username, string arg_password, int arg_age, 
         SensitivityPrefEnum arg_sensitivity_pref, AccountStatusEnum arg_account_status, char* arg_last_login_date_time); // Constructor for the User class

    // Setters & Getters for attributes of a User object
    void set_age(int arg_age);    
    int get_age();

    void set_sensitivity_pref(SensitivityPrefEnum arg_sensitivity_pref);
    SensitivityPrefEnum get_sensitivity_pref();

    void set_account_status(AccountStatusEnum arg_account_status);
    AccountStatusEnum get_account_status();

    void set_last_login_date_time(char* arg_last_login_date_time);
    char* get_last_login_date_time();

    // A function that allows a user to login to their iPost account if the login information they provided, is found in the existing user data
    int login(vector<User>& user_data);
    
    // A friend function that allows a user to register for an iPost account if the email and username they provided is unique, among other account information. 
    // If registration is successful the user is saved among the existing user data
    friend void user_registration(vector<User>& user_data, User& user);

    // The overridden function from the base class “Person” that allows the user to view all posts, respective to their sensitivity preference, made by other users on iPost
    void view_all_posts(vector<Post>& posts); 
    
    // A function that allows users to view just their own posts
    void view_user_posts(vector<Post>& posts);
    
    // A function that allows users to make a post and save it to the existing posts so it is available to be seen by other users (if their sensitivity preference allows it)
    void make_post(vector<Post>& posts);
    
    // The overridden function from the base class “Person” that allows the user to delete their own posts
    void delete_post(vector<Post>& posts);

    // A friend function to overload the << (insertion) operator.
    friend ostream& operator<<(ostream& os, User& user);
    
    // An overloaded operator to easily append/push back new users to the users vector
    User& operator += (vector<User>& user_vec);

};

#endif

