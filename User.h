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

    int login(vector<User>& user_data);
    friend void user_registration(vector<User>& user_data, User& user);

    void view_all_posts(vector<Post>& posts);
    void view_user_posts(vector<Post>& posts);
    void make_post(vector<Post>& posts);
    void delete_post(vector<Post>& posts);

    friend ostream& operator<<(ostream& os, User& user);
    User& operator += (vector<User>& user_vec);

};

#endif

