#ifndef USER_HDR_H
#define USER_HDR_H

#include <ctime>
#include <vector>

#include "Person.h"
#include "User.h"
#include "Post.h"

class User : public Person {
private:
    
    int age;
    SensitivityPrefEnum sensitivity_pref;
    AccountStatusEnum account_status;
    char* last_login_date_time = 0;

public: 
    
    User();
    User(int arg_age, SensitivityPrefEnum arg_sensitivity_pref, AccountStatusEnum arg_account_status, char* arg_last_login_date_time);
    User(string arg_f_name, string arg_l_name, string arg_email, string arg_username, string arg_password, int arg_age, 
         SensitivityPrefEnum arg_sensitivity_pref, AccountStatusEnum arg_account_status, char* arg_last_login_date_time);

    void set_age(int arg_age);    
    int get_age();

    void set_sensitivity_pref(SensitivityPrefEnum arg_sensitivity_pref);
    SensitivityPrefEnum get_sensitivity_pref();

    void set_account_status(AccountStatusEnum arg_account_status);
    AccountStatusEnum get_account_status();

    void set_last_login_date_time(char* arg_last_login_date_time);
    char* get_last_login_date_time();

    static int printing_choice_options(string question, string option_1, string option_2);
    
    static void user_login(vector<User> user_data, User& user);
    static void user_registration(vector<User>& user_data, User& user);

    void view_all_posts(vector<Post>& posts);
    void view_user_posts(vector<Post>& posts, User user);

    //friend void take_action(User&, Admin&, AccountStatusEnum);
    //friend void delete_post(User&, Post&, Admin&);

};

#endif

