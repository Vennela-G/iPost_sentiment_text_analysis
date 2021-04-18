#ifndef ENUMHELPER_HDR_H
#define ENUMHELPER_HDR_H

#include <string>

#include "AppDefinitions.h"

using namespace std;

class EnumHelper {

public:

    static SensitivityPrefEnum string_to_enum_sensitivity_pref(string enum_str);
    static AccountStatusEnum string_to_acct_status(string enum_str);
    
    static string enum_sensitivity_pref_to_string(SensitivityPrefEnum s_pref);
    static string enum_acct_status_to_string(AccountStatusEnum acct_status);

};

#endif

