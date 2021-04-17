#ifndef USER_HDR_H
#define USER_HDR_H

#include <ctime>

#include "Person.h"
//#include "Post.h"

class User : public Person {
private:
    
    int age;
    SensitivityPrefEnum sensitivity_pref;
    AccountStatusEnum account_status;
    time_t last_login_date_time;

public: 
    
    User();
    User(int arg_age, SensitivityPrefEnum arg_sensitivity_pref, AccountStatusEnum arg_account_status, time_t arg_last_login_date_time);

    void set_age(int arg_age);    
    int get_age();

    void set_sensitivity_pref(SensitivityPrefEnum arg_sensitivity_pref);
    SensitivityPrefEnum get_sensitivity_pref();

    void set_account_status(AccountStatusEnum arg_account_status);
    AccountStatusEnum get_account_status();

    void set_last_login_date_time(time_t arg_last_login_date_time);
    time_t get_last_login_date_time();

    //void view_posts(const vector<Post>&);
    //friend void take_action(User&, Admin&, AccountStatusEnum);
    //friend void delete_post(User&, Post&, Admin&);

};

#endif

